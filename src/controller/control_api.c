#include "controller/control_api.h"
#include "controller/pid.h"
#include "uart.h"

extern bool controllerEnable;
extern float setPoint[NUM_RC_IN];
extern pid_context_t pids[NUM_AXIS];
extern float sensorData[NUM_AXIS];
extern float mFR,mBL,mFL,mBR;

void setPidParameter( enum Axis axis, enum PID_K param, float value){
    pid_context_t *context = &pids[axis];
    switch( param ){
        case KP: context->kp = value;break;
        case KI: context->ki = value;break;
        case KD: context->kd = value;break;
        case MAX: context->max = value;break;
        case MIN: context->min = value;break;
        default:;
    }
}

float getPidParameter(enum Axis axis, enum PID_K param){
    pid_context_t *context = &pids[axis];
    float value = 0.0f;
    switch( param ){
        case KP: context->kp = value;break;
        case KI: context->ki = value;break;
        case KD: context->kd = value;break;
        case MAX: context->max = value;break;
        case MIN: context->min = value;break;
        default:;
    }
    return value;
}

void setSetPoint( enum RC_IN a, float value){
    setPoint[a] = value;
}

void setControllerEnable( bool set ){
    controllerEnable = set;
}

void sendControlInfo(){
    uint8_t head = 0x02;
    UART_send((uint8_t []){head,0x00},2);
    UART_send((uint8_t *)(float []){ mFR, mFL, mBL, mBR },16);
    UART_send((uint8_t []){head,0x01},2);
    UART_send((uint8_t *)(float []){pids[ROLL_RATE].out,
        pids[PITCH_RATE].out,pids[YAW_RATE].out},12);
    UART_send((uint8_t []){head,0x02},2);
    UART_send((uint8_t *)(float []){pids[ROLL].out,
        pids[PITCH].out,pids[YAW].out},12);
}
