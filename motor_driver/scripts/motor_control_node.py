#!/usr/bin/env python3
import rospy
from armcontrol_demo_pkg.msg import hdrarm_msg


def main():
    rospy.init_node('motor_control_node')

    pub = rospy.Publisher('/armcontrol_Info', hdrarm_msg, queue_size=10)

    msg = hdrarm_msg()
    msg.motor_state = 'enable'
    msg.arm_mode = 'arm_control_demo'
    msg.Emergency_Stop = False
    msg.drag_teachin = 'false'
    msg.drag_teachin_name = 'drag_teachin_1.txt'

    msg.joint1_angle = 0.0
    msg.joint2_angle = 0.0
    msg.joint3_angle = 0.0
    msg.joint4_angle = 0.0
    msg.joint5_angle = 0.0
    msg.joint6_angle = 0.0

    msg.arm_position_x = 0.0
    msg.arm_position_y = 0.0
    msg.arm_position_z = 0.0
    msg.arm_orientation_x = 0.0
    msg.arm_orientation_y = 0.0
    msg.arm_orientation_z = 0.0
    msg.arm_orientation_w = 1.0

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        pub.publish(msg)
        rate.sleep()


if __name__ == '__main__':
    main()
