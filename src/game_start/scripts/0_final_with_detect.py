#!/usr/bin/env python
#encoding=UTF-8
import cv2
import numpy as np
import cv2.aruco as aruco
import os
from smach import user_data

from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

from xf_mic_tts_offline.srv import *

from std_msgs.msg import String
import rospy
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
import smach
import smach_ros
import threading

# import xunfei_aruco_2 as ht
import xunfei_publish_detect as detect_flag
from ht_msg.msg import Ht
import shutil

import xunfei_laser as ht_waypoints


voiceflag = False
longhair=glasses=0
# longhair =  0
# glasses = 0

def ht_aruco():
    bridge = CvBridge()
    ht_aruco_list = []
    for i in range(4):
        data = rospy.wait_for_message('/ht_image_biaoding_view/ht_image_biaoding_raw', Image, timeout=None)
        frame = bridge.imgmsg_to_cv2(data, "bgr8")
        img_gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        aruco_dict = aruco.Dictionary_get(aruco.DICT_4X4_250)
        parameters = aruco.DetectorParameters_create()
        corners, ids, _ = aruco.detectMarkers(img_gray, aruco_dict,parameters=parameters)
        if ids is not None:
            for i in range(len(ids)):
                print('find aruco:', ids[i][0])
                ht_aruco_list.append(ids[i][0])
        if len(ht_aruco_list) != 0:
            ht_aruco_list_array = np.array(ht_aruco_list)
            ht_aruco_num = np.median(ht_aruco_list_array)
        else:
            ht_aruco_num = -1
    # out.release()
    print('final find aruco:{}'.format(int(ht_aruco_num)))
    return int(ht_aruco_num)


def thread_job():
    rospy.spin()

def voicecallback(data):
    global voiceflag
    if data.data == "start":
        print('Start navigating!')
        rospy.sleep(1)
        voiceflag = True
        return voiceflag

    else:
        print('Waiting for voiceAwake......')
        rospy.sleep(1)
        voiceflag = False
        return voiceflag


    
class Wait4Awake(smach.State):
    #global voiceflag
    def __init__(self):
        smach.State.__init__(self, outcomes=['navigating', 'wait'],output_keys=['navpoints'])
    
    def execute(self, userdata):
        add_thread = threading.Thread(target = thread_job)
        add_thread.start()
        rospy.Subscriber("voiceAwake",String, voicecallback)
        userdata.navpoints = -1
        rospy.sleep(2)

        if voiceflag:
            return 'navigating'
        else:
            return 'wait'




class Navigate(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['navigating', 'arrived', 'end'],input_keys=['navpoints'])

        self.client = actionlib.SimpleActionClient('move_base', MoveBaseAction) 
        self.client.wait_for_server()
    
    def execute(self, userdata):
        if rospy.is_shutdown():
            return 'end'
        else:
        
            waypoints = self.get_waypoints(userdata.navpoints+1) 
            goal = self.goal_pose(waypoints)
            self.client.send_goal(goal)
            self.client.wait_for_result()
            # rospy.sleep(1.5)
            if (userdata.navpoints+1) == 0:
               return 'arrived'
            elif (userdata.navpoints+1) == 1:
                return 'end'
            elif (userdata.navpoints+1) ==2:
                return 'end'
            elif (userdata.navpoints+1) ==3:
                return 'end'
            
    
    def goal_pose(self, pose): 
        goal_pose = MoveBaseGoal()

        goal_pose.target_pose.header.frame_id = 'map'

        goal_pose.target_pose.pose.position.x = pose[0][0]
        goal_pose.target_pose.pose.position.y = pose[0][1]
        goal_pose.target_pose.pose.position.z = pose[0][2]
        
        goal_pose.target_pose.pose.orientation.x = pose[1][0]
        goal_pose.target_pose.pose.orientation.y = pose[1][1]
        goal_pose.target_pose.pose.orientation.z = pose[1][2]
        goal_pose.target_pose.pose.orientation.w = pose[1][3]

        return goal_pose
    
    def get_waypoints(self,num):
        waypoints = [
            # [[2.328, -2.802, 0.000],[0.000, 0.000, 0.976, 0.219]],
            [[2.328, -2.74, 0.000],[0.000, 0.000, 0.976, 0.219]],           #B区目标点
            # [[1.014, -1.108, 0.000],[0.000, 0.000, 0.732, 0.681]],  #1.014, -1.108
            # [[0.529, -1.109, 0.000],[0.000, 0.000, 0.749, 0.663]],     #0.529, -1.109       
            # [[-0.074, -1.049, 0.000],[0.000, 0.000, 0.680, 0.733]]  #-0.074, -1.049
            [[0.975, -1.109, 0.000],[0.000, 0.000, 0.732, 0.681]],        #D1
            [[0.475, -1.109, 0.000],[0.000, 0.000, 0.749, 0.663]],         #D2
            [[-0.025, -1.109, 0.000],[0.000, 0.000, 0.680, 0.733]]        #D3
            
            ]
        return waypoints[num]

class Navigate2C(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['navigating', 'arrived', 'end'],output_keys=['navpoints'])

        self.client = actionlib.SimpleActionClient('move_base', MoveBaseAction) 
        self.client.wait_for_server()
    
    def execute(self, userdata):
        if rospy.is_shutdown():
            return 'end'
        else:
            waypoints = self.get_waypoints() 
            for pose in waypoints:                   
                goal = self.goal_pose(pose)
                self.client.send_goal(goal)
                self.client.wait_for_result()
                # rospy.sleep(1.5)
                # add_thread = threading.Thread(target = thread_detect_pub)
                # add_thread.start()
            return 'arrived'

    def goal_pose(self,pose):
        goal_pose = MoveBaseGoal()
        goal_pose.target_pose.header.frame_id = 'map'
        goal_pose.target_pose.pose.position.x = pose[0][0]
        goal_pose.target_pose.pose.position.y = pose[0][1]
        goal_pose.target_pose.pose.position.z = pose[0][2]
        goal_pose.target_pose.pose.orientation.x = pose[1][0]
        goal_pose.target_pose.pose.orientation.y = pose[1][1]
        goal_pose.target_pose.pose.orientation.z = pose[1][2]
        goal_pose.target_pose.pose.orientation.w = pose[1][3]

        return goal_pose


    def get_waypoints(self):
        waypoints = [
            # [[-0.025, -2.65, 0.000],[0.000, 0.000, 0.70710678, 0.70710678]]
            [[-0.025, -2.60, 0.000],[0.000, 0.000, 0.70710678, 0.70710678]]            #C区目标点
            # [[-0.075, -2.433, 0.000],[0.000, 0.000, 0.70710678, 0.70710678]]
            ]
        return waypoints


class Navigate2Pic(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['navigating', 'arrived', 'end'],output_keys=['navpoints'])
        # self.waypoints = []
        self.client = actionlib.SimpleActionClient('move_base', MoveBaseAction) 
        self.client.wait_for_server()
    
    def execute(self, userdata):
        if rospy.is_shutdown():
            return 'end'
        else:
            aimlist=ht_waypoints.listener()
            # print (aimlist)
            # for points in aimlist:
            #     self.waypoints.append(points)
            # aim = self.waypoints() 
            
            ht_count=1
            for pose in aimlist:                   
                goal = self.goal_pose(pose)
                self.client.send_goal(goal)
                # self.ht_save_image(ht_count)
                self.client.wait_for_result()
                rospy.sleep(1)    #停车拍照时间
                self.ht_save_image(ht_count)
                ht_count+=1
            
            # add_thread = threading.Thread(target = thread_detect_pub)
            # add_thread.start()

                
            return 'arrived'

    def goal_pose(self,pose):
        goal_pose = MoveBaseGoal()
        goal_pose.target_pose.header.frame_id = 'map'
        goal_pose.target_pose.pose.position.x = pose[0][0]
        goal_pose.target_pose.pose.position.y = pose[0][1]
        goal_pose.target_pose.pose.position.z = pose[0][2]
        goal_pose.target_pose.pose.orientation.x = pose[1][0]
        goal_pose.target_pose.pose.orientation.y = pose[1][1]
        goal_pose.target_pose.pose.orientation.z = pose[1][2]
        goal_pose.target_pose.pose.orientation.w = pose[1][3]

        return goal_pose

    def ht_save_image(self,i):
    # cap = cv2.VideoCapture(0)
        # start = time.time()
        # rospy.init_node('ht_save_image')
        # img = '/home/ucar/ROS_xunfei/ucar_ws/src/ht_image/scripts/xunfei_detect_img/x.jpg'
        data = rospy.wait_for_message('/ht_image_biaoding_view/ht_image_biaoding_raw', Image, timeout=None)
        bridge = CvBridge()
        frame = bridge.imgmsg_to_cv2(data, "bgr8")
        frame=frame[0:640,640:1280]
        # cv2.rectangle(frame, (180, 160), (460, 320), (0, 255, 0), 2)
        cv2.imwrite('/home/ucar/ROS_xunfei/ucar_ws/src/ht_image/scripts/xunfei_detect_img/x_{}.jpg'.format(i), frame)


        # cv2.waitKey(0)
        # cv2.destroyAllWindows()
        return True

    # def get_waypoints(self):
    #     waypoints = [
           
    #         ]
    #     return waypoints


def thread_detect_pub():
    detect_flag.detect_publisher()

class Aruco(smach.State):
    def __init__(self):
        smach.State.__init__(self,outcomes=['NAV2C','nav2D1','nav2D2','nav2D3','Aruco','end'],output_keys=['navpoints'])

    def execute(self, userdata):
        # count = 0
        # count = count+1

        add_thread = threading.Thread(target = thread_detect_pub)
        add_thread.start()

        client = rospy.ServiceProxy('xf_mic_tts_offline_node/voiceopen', Play_TTS_srv)
        code = ht_aruco()
        if code == 0:
            userdata.navpoints = 1          #目标点D1  navpoints=0           D2  navpoints=1     D3  navpoints=2
            # return 'nav2D1'    
            client.call('蔬菜','xiaoyan')        
            return 'NAV2C'
        elif code == 1:
            userdata.navpoints = 1        #抽签后修改
            # return 'nav2D2'            
            client.call('水果','xiaoyan')
            return 'NAV2C'
        elif code == 2:
            userdata.navpoints = 1          #抽签后修改
                # return'nav2D3'            
            client.call('肉类','xiaoyan')
            return 'NAV2C'

        elif code == -1:
        #     if count <10:
            return 'Aruco'
            # else:
            # return 'end'





# class detect(smach.State):
#     def __init__(self):
#         smach.State.__init__(self,outcomes=['success'])
        

#     def execute(self, userdata):
#         # detect_flag.detect_publisher()
#         rospy.Subscriber("ht_num_info",Ht, detectcallback)
#         return 'success'


def detectcallback(ht):
    global longhair, glasses
    glasses = ht.glasses_people
    longhair = ht.longhair_people
    print(glasses)
    print(longhair)
    # rospy.signal_shutdown('shut down')

class voiceSuccess(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['end'])
        global longhair
        global glasses

    def execute(self, userdata):
        #   rospy.init_node("voiceSuccess")
        
        # longhair = 1
        # glasses = 2
        get_data = rospy.wait_for_message("ht_num_info", Ht, timeout=None)
        glasses,longhair = get_data.glasses_people, get_data.longhair_people
        client = rospy.ServiceProxy('xf_mic_tts_offline_node/play_txt_wav', Play_TTS_srv)
        data = '本次送餐任务途中遇到2个人，其中长头发：'+str(longhair)+'人。'+'戴眼镜：'+str(glasses)+'人。'
        # data = str(data) 
        client.call(data,'xiaoyan')
        client.call('您的餐品已送达，请您取餐！','xiaoyan')
        
        shutil.copy('/home/ucar/ROS_xunfei/ucar_ws/src/ht_image/scripts/xunfei_control/a_end.jpg', '/home/ucar/ROS_xunfei/ucar_ws/src/ht_image/scripts/xunfei_detect_img/a_end.jpg')
        return 'end'
        

         
def thread_detect():
    os.system('python3 /home/ucar/ROS_xunfei/ucar_ws/src/ht_image/scripts/xunfei_b_s.py') #c区持续检测


def main():
    rospy.init_node('first_try')
    sm = smach.StateMachine(outcomes=['end'])

    add_thread = threading.Thread(target = thread_detect)
    add_thread.start()

    with sm:        
        smach.StateMachine.add('WAIT', Wait4Awake(),transitions={'navigating':'NAV', 'wait':'WAIT' })
        smach.StateMachine.add('NAV', Navigate(), transitions={'arrived':'ARUCO', 'navigating':'NAV','end':'VOISUCC'})
        smach.StateMachine.add('ARUCO', Aruco(), transitions={'NAV2C': 'NAV2C','nav2D1':'NAV', 'nav2D2':'NAV','nav2D3':'NAV','Aruco':'ARUCO','end':'end'})
        smach.StateMachine.add('VOISUCC',voiceSuccess(),transitions={'end':'end'})
        smach.StateMachine.add('NAV2C',Navigate2C(),transitions={'navigating':'NAV2C','arrived':'NAV2PIC','end':'end'})
        smach.StateMachine.add('NAV2PIC',Navigate2Pic(),transitions={'navigating':'NAV2PIC','arrived':'NAV','end':'end'})


        sis = smach_ros.IntrospectionServer('FIRST_TRY', sm, '/SM_ROOT')
        sis.start()
        
    outcome = sm.execute()

    rospy.spin()
    sis.stop()

if __name__ == "__main__":
    # g_targets = None
    # g_start = None
    main()
