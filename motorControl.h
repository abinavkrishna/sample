#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <stdio.h>
#include <stdlib.h>

#define MOTOR_MESSAGE 0x80
#define DISPLAY_MESSAGE 0x34

typedef uint8_t Packet;

void update_motor(Packet* packet,uint16_t);
void display_message(Packet* packet,uint16_t);
void LCD_display(Packet* ,uint16_t); 
void forward_back(float);
void left_right(float);
#endif
