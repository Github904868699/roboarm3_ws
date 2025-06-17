#ifndef _MOTOR_CONFIG_H_
#define _MOTOR_CONFIG_H_

#include <iostream>
#include "stdint.h"
#include "can_msgs/Frame.h"

using namespace std;

class MotorControlSet {
public:
    uint8_t motor_id;
    float pos_target, vel_target, kp, kv, t_target;
    float pos, vel, t; // 添加缺失的成员变量
    float P_MIN, P_MAX, V_MIN, V_MAX, T_MIN, T_MAX;
    can_msgs::Frame cansendata;

    MotorControlSet(uint8_t id, const string &type) : motor_id(id) {
        // 根据电机类型初始化参数
        if (type == "DM4310") {
            P_MIN = -12.5; P_MAX = 12.5;
            V_MIN = -30.0; V_MAX = 30.0;
            T_MIN = -10.0; T_MAX = 10.0;
        } else if (type == "DM4340") {
            P_MIN = -12.5; P_MAX = 12.5;
            V_MIN = -10.0; V_MAX = 10.0;
            T_MIN = -28.0; T_MAX = 28.0;
        } else if (type == "NEW_MOTOR") {
            P_MIN = -15.0; P_MAX = 15.0;
            V_MIN = -20.0; V_MAX = 20.0;
            T_MIN = -12.0; T_MAX = 12.0;
        }
    }

    float Uint_to_float(int x_int, float x_min, float x_max, int bits);
    uint16_t float_to_uint(float x, float x_min, float x_max, int bits);
    void get_motor_ctrl_parameter(void);
    void motor_enable(void);
    void motor_disable(void);
};

//DM电机 MIT控制协议限幅参数
#define KP_MAX 500
#define KP_MIN 0
#define KD_MAX 5
#define KD_MIN 0

//DM4310电机
#define DM4310_P_MAX  12.5
#define DM4310_P_MIN -12.5
#define DM4310_V_MAX  30.0
#define DM4310_V_MIN -30.0
#define DM4310_T_MAX  10.0
#define DM4310_T_MIN -10.0

//DM4340电机
#define DM4340_P_MAX  12.5
#define DM4340_P_MIN -12.5
#define DM4340_V_MAX  10.0
#define DM4340_V_MIN -10.0
#define DM4340_T_MAX  28.0
#define DM4340_T_MIN -28.0

//DM6006电机
#define DM6006_P_MAX  12.5
#define DM6006_P_MIN -12.5
#define DM6006_V_MAX  45.0
#define DM6006_V_MIN -45.0
#define DM6006_T_MAX  12.0
#define DM6006_T_MIN -12.0

//DM8006电机
#define DM8006_P_MAX  12.5
#define DM8006_P_MIN -12.5
#define DM8006_V_MAX  25.0
#define DM8006_V_MIN -25.0
#define DM8006_T_MAX  20.0
#define DM8006_T_MIN -20.0

//新增电机类型参数
#define NEW_MOTOR_P_MAX  15.0
#define NEW_MOTOR_P_MIN -15.0
#define NEW_MOTOR_V_MAX  20.0
#define NEW_MOTOR_V_MIN -20.0
#define NEW_MOTOR_T_MAX  12.0
#define NEW_MOTOR_T_MIN -12.0

//关节电机ID
#define MOTOR_1 0x01
#define MOTOR_2 0x02
#define MOTOR_3 0x03
#define MOTOR_4 0x04
#define MOTOR_5 0x05
#define MOTOR_6 0x06
#define MOTOR_7 0x07

//使能标志位
#define MOTOR_ENABLED 16

//关节偏置矫正系数
//ps:数学模型上的零位是竖直向上姿态
//ps:电机标定的零位是卧式姿态
#define MOTOR_2_OFFSET 0
#define MOTOR_3_OFFSET 0
#define MOTOR_4_OFFSET 0

//电机控制参数
#define MOTOR_1_kp 200
#define MOTOR_1_kv 1.2
#define MOTOR_2_kp 280
#define MOTOR_2_kv 1.8
#define MOTOR_3_kp 220
#define MOTOR_3_kv 1.4
#define MOTOR_4_kp 50
#define MOTOR_4_kv 0.4
#define MOTOR_5_kp 50
#define MOTOR_5_kv 0.2
#define MOTOR_6_kp 10
#define MOTOR_6_kv 0.1
#define MOTOR_7_kp 100

//位置跟踪力矩限制
#define MOTOR_1_ENERGY_LIMIT 8
#define MOTOR_2_ENERGY_LIMIT 8
#define MOTOR_3_ENERGY_LIMIT 7
#define MOTOR_4_ENERGY_LIMIT 6
#define MOTOR_5_ENERGY_LIMIT 5
#define MOTOR_6_ENERGY_LIMIT 4
#define MOTOR_7_ENERGY_LIMIT 6

//电机转动角度限制
#define MOTOR_1_ANGLE_LIMIT 3.14
#define MOTOR_2_ANGLE_LIMIT 1.67
#define MOTOR_3_ANGLE_LIMIT 3.14
#define MOTOR_4_ANGLE_LIMIT 3.14
#define MOTOR_5_ANGLE_LIMIT 3.14
#define MOTOR_6_ANGLE_LIMIT 3.14
#define MOTOR_7_ANGLE_LIMIT 3.14

// 更新1号电机参数
#define MOTOR_1_P_MAX  0x39        // 最大位置：通过寄存器0x39设置，单位为弧度
#define MOTOR_1_P_MIN  0x3A        // 最小位置：通过寄存器0x3A设置，单位为弧度
#define MOTOR_1_V_MAX  0x32        // 最大速度：通过寄存器0x32设置，单位为弧度/秒
#define MOTOR_1_V_MIN  0           // 最小速度：理论上为0，单位为弧度/秒
#define MOTOR_1_T_MAX  0x30        // 最大力矩：通过寄存器0x30设置，单位为牛米
#define MOTOR_1_T_MIN  0           // 最小力矩：理论上为0，单位为牛米

// 更新2号电机参数
#define MOTOR_2_P_MAX  (2 * M_PI)  // 最大位置：2π弧度
#define MOTOR_2_P_MIN  0           // 最小位置：0弧度
#define MOTOR_2_V_MAX  0xFFFF      // 最大速度：需通过指令设置，单位为脉冲/秒
#define MOTOR_2_V_MIN  0           // 最小速度：理论上接近0，单位为脉冲/秒
#define MOTOR_2_T_MAX  0x30        // 最大力矩：需通过电流限制设置并转换
#define MOTOR_2_T_MIN  (-0x30)     // 最小力矩：负的最大力矩值

// 更新3号电机参数
#define MOTOR_3_P_MAX  0x39        // 最大位置：通过寄存器0x39设置，单位为弧度
#define MOTOR_3_P_MIN  0x3A        // 最小位置：通过寄存器0x3A设置，单位为弧度
#define MOTOR_3_V_MAX  0x32        // 最大速度：通过寄存器0x32设置，单位为弧度/秒
#define MOTOR_3_V_MIN  0           // 最小速度：理论上为0，单位为弧度/秒
#define MOTOR_3_T_MAX  0x30        // 最大力矩：通过寄存器0x30设置，单位为牛米
#define MOTOR_3_T_MIN  0           // 最小力矩：理论上为0，单位为牛米

// 更新4号电机参数
#define MOTOR_4_P_MAX  0x39        // 最大位置：通过寄存器0x39设置，单位为弧度
#define MOTOR_4_P_MIN  0x3A        // 最小位置：通过寄存器0x3A设置，单位为弧度
#define MOTOR_4_V_MAX  0x32        // 最大速度：通过寄存器0x32设置，单位为弧度/秒
#define MOTOR_4_V_MIN  0           // 最小速度：理论上为0，单位为弧度/秒
#define MOTOR_4_T_MAX  0x30        // 最大力矩：通过寄存器0x30设置，单位为牛米
#define MOTOR_4_T_MIN  0           // 最小力矩：理论上为0，单位为牛米

// 更新5号电机参数
#define MOTOR_5_P_MAX  0x39        // 最大位置：通过寄存器0x39设置，单位为弧度
#define MOTOR_5_P_MIN  0x3A        // 最小位置：通过寄存器0x3A设置，单位为弧度
#define MOTOR_5_V_MAX  0x32        // 最大速度：通过寄存器0x32设置，单位为弧度/秒
#define MOTOR_5_V_MIN  0           // 最小速度：理论上为0，单位为弧度/秒
#define MOTOR_5_T_MAX  0x30        // 最大力矩：通过寄存器0x30设置，单位为牛米
#define MOTOR_5_T_MIN  0           // 最小力矩：理论上为0，单位为牛米

// 更新6号电机参数
#define MOTOR_6_P_MAX  0x39        // 最大位置：通过寄存器0x39设置，单位为弧度
#define MOTOR_6_P_MIN  0x3A        // 最小位置：通过寄存器0x3A设置，单位为弧度
#define MOTOR_6_V_MAX  0x32        // 最大速度：通过寄存器0x32设置，单位为弧度/秒
#define MOTOR_6_V_MIN  0           // 最小速度：理论上为0，单位为弧度/秒
#define MOTOR_6_T_MAX  0x30        // 最大力矩：通过寄存器0x30设置，单位为牛米
#define MOTOR_6_T_MIN  0           // 最小力矩：理论上为0，单位为牛米

#endif
