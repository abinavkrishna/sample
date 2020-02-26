#include<stdio.h>
#include<stdlib.h>
#include "motorControl.h"

int main( int argc, char** argv) {
    Packet display_packet[] = {0x1, 0x34, 0x05, 0x0, 0x48, 0x65, 0x6c, 0x6c, 0x6f};    
    Packet motor_packet[] = {0x2, 0x80, 0x08, 0x0, 0x0, 0x0, 0x80, 0x3f, 0x0, 0x0, 0x0, 0xbf};
    if(motor_packet[1] == MOTOR_MESSAGE) {
        printf("Received a motor packet\n");
        update_motor(motor_packet);
    }   
    else if(motor_packet[1] == DISPLAY_MESSAGE) {
        printf("Received a display packet\n");
        display_message(display_packet);
    }   
    //printf("%u\n",motor_packet[i]);
        
    return 0;
} 

