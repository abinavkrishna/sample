#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <stdio.h>
#include <stdlib.h>

#define MOTOR_QUALIFIER 0x80
#define DISPLAY_QUALIFIER 0x34

typedef uint8_t Packet;

/*Alternate packet structure*/
typedef struct
{
    uint8_t packet_ID;
    uint16_t packet_qualifier;
    uint16_t packet_length;
    uint8_t* packet_message;
    uint8_t CRC_byte;
} Alternate_Packet_Structure;

void update_motor(Packet* packet,uint16_t);
void display_message(Packet* packet,uint16_t);
void LCD_display(Packet* ,uint16_t); 
void forward_back(float);
void left_right(float);
#endif

