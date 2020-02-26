#include "motorControl.h"


void LCD_display(Packet* message, uint16_t length)
{
    int char_pos = 0;
    /*Code for display on device*/
    printf("Message to be displayed is: ");
    for(char_pos = 0;char_pos<length; ++char_pos)
    {
        printf("%c",(char)message[char_pos]);
    }
    printf("\n");
}

void forward_back(float message)
{
    /*Code for motor manipulation*/
}
void left_right(float message)
{
    /*Code for motor manipulation*/
}

/* Check the display message and calls the LCD display function*/
void display_message(Packet* packet, uint16_t length)
{
    int curr = 0;
    uint16_t message_length = *(uint16_t*)(packet+2);
    if(message_length != length - 4)
    {
        printf("Invalid display packet!\n");
        exit(-1);
    }
    Packet message[message_length];
    for(curr = 0; curr < message_length; ++curr)
    {
        message[curr] = packet[4+curr];
    }
    LCD_display(message,message_length);
}

/* Check the motor message and calls appropriate manipulator functions*/
void update_motor(Packet* packet,uint16_t length)
{
    uint16_t message_length = *(uint16_t*)(packet+2);
    if(message_length != length - 4)
    {
        printf("Invalid motor packet!\n");
        exit(-1);
    }
    float fwd_bwd_message = (float)*(uint32_t*)(packet+4);
    float left_right_message = (float)*(uint32_t*)(packet+8);
    printf("Forward - backward manipulators to be updated with %f\n",fwd_bwd_message);
    printf("Left - right manipulators to be updated with %f\n",left_right_message);
    forward_back(fwd_bwd_message);
    left_right(left_right_message);
}

/* Main function for testing*/

int main( int argc, char** argv)
{
    Packet packet1[] = {0x1, 0x34, 0x0b, 0x0, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x74, 0x68, 0x65, 0x72, 0x65};
    Packet packet2[] = {0x2, 0x80, 0x08, 0x0, 0x0, 0x0, 0x80, 0x3f, 0x0, 0x0, 0x0, 0xbf};
    unsigned int size_packet1 = sizeof(packet1)/sizeof(packet1[0]);
    unsigned int size_packet2 = sizeof(packet2)/sizeof(packet2[0]);
    
    /* Check for message type and call appropriate function*/
    if(packet1[1] == MOTOR_MESSAGE)
    {
        printf("Received a motor packet ID: %d\n",packet1[0]);
        update_motor(packet1,size_packet1);
    }
    else if(packet1[1] == DISPLAY_MESSAGE)
    {
        printf("Received a display packet ID: %d\n",packet1[0]);
        display_message(packet1,size_packet1);
    }
    if(packet2[1] == MOTOR_MESSAGE)
    {
        printf("Received a motor packet ID: %d\n",packet2[0]);
        update_motor(packet2,size_packet2);
    }
    else if(packet2[1] == DISPLAY_MESSAGE)
    {
        printf("Received a display packet ID: %d\n",packet2[0]);
        display_message(packet2,size_packet2);
    }
    return 0;
} 
