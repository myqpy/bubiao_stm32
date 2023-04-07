#ifndef __ST7567_H

#define __ST7567_H

#include "sys.h"
#include "stdlib.h"


// -------------------------------inital parameter Definition--------------------------
#define DispON          0xAF	// Turn on LCD panel high
#define DispOFF         0xAE    // Turn off LCD panel high
#define NormalDisp      0xA6	// normal display
#define ReverseDisp     0xA7	// reverse display
#define EntireDispON    0xA5	// entire display on
#define EntireDispOFF   0xA4	// entire display off(normal display)

#define StartLine	    0x60	// Start line set  40--7fh
#define ColumnAddrH	    0x10	// Column address high set 10--18h
#define ColumnAddrL     0x00	// Column address low set 00--0fh
#define PageAddr        0xB0	// Page address set  B0--B8h

#define BiasSet         0xA3	// bias set A2-A3h  A2  
//#define SegDirection    0xA1	// Column address direction set  A0--A1h
//#define ComDirection    0xC0	// C0h(Com0--Com64), C8h(Com64--Com0)
#define SegDirection    0xA0	// Column address direction set  A0--A1h
#define ComDirection    0xC8	// C0h(Com0--Com64), C8h(Com64--Com0)
#define RratioSet       0x27	// V0 voltage regulator internal ratio set 20h-27h   //27
#define EVcomd          0x81	// electronic volume set comd
#define EVcomdValue     0x17      // 01h--3fh     0X19                                //18

#define PowerControl1   0x2c	// 28--2fh ,booster circuit on
#define PowerControl2   0x2e	// 28--2fh ,booster circuit and regulator circuit on
#define PowerControl3   0x2f	// 28--2fh ,booster circuit and regulator circuit and follower circuit on

#define BoostTimes      0x89	//
#define BoostValue      0x01	// 00h-5times,01h-4times,03h,04h-3times

#define FrequencySet    0xE4	// E4h(31.4KHz),E5h(26.3KHz)
#define ResetSet        0xE2	//

#define StaticON        0xAD	//
#define StaticOFF       0xAC	//
#define StaticValue     0x00	// 00h--03h

#define NlineInversion  0x85	// electronic volume set comd
#define NlineValue      0x20	// 00h--1fh
#define NlineExit       0x84	// exit N line inversion,frame inversion

// -------------------------------------------------------------------------

//---------------(ST7567)---------------//

#define ST7567_CS_0 GPIO_ResetBits(GPIOF, GPIO_Pin_3)//CS
#define ST7567_CS_1 GPIO_SetBits(GPIOF, GPIO_Pin_3)  //

#define ST7567_RST_0 GPIO_ResetBits(GPIOF, GPIO_Pin_2)//RST
#define ST7567_RST_1 GPIO_SetBits(GPIOF, GPIO_Pin_2)

#define ST7567_A0_0 GPIO_ResetBits(GPIOF, GPIO_Pin_1)//A0
#define ST7567_A0_1 GPIO_SetBits(GPIOF, GPIO_Pin_1)

#define ST7567_SCLK_0 GPIO_ResetBits(GPIOC, GPIO_Pin_3)//SCL
#define ST7567_SCLK_1 GPIO_SetBits(GPIOC, GPIO_Pin_3)

#define ST7567_SDIN_0 GPIO_ResetBits(GPIOC, GPIO_Pin_1)//SDA
#define ST7567_SDIN_1 GPIO_SetBits(GPIOC, GPIO_Pin_1)

#define LCD_light_1  GPIO_ResetBits(GPIOC,GPIO_Pin_13)//�����--PB1
#define LCD_light_0  GPIO_SetBits(GPIOC,GPIO_Pin_13)

//#define LED_ON   GPIO_ResetBits(GPIOA,GPIO_Pin_15)//ָʾ��
//#define LED_OFF  GPIO_SetBits(GPIOA,GPIO_Pin_15)


#define ST7567_CMD   0    //д����
#define ST7567_DATA  1    //д����





extern  unsigned char shu1[];
extern  unsigned char shu2[];
extern  unsigned char shu3[];


extern unsigned char icon_test[][16];
extern unsigned char icon_4G[][16];
extern unsigned char icon_beidou[][16];
extern unsigned char icon_ppl[][16];
extern unsigned char icon_SD[][16];
extern unsigned char icon_charged[][16];
extern unsigned char icon_battery[][16];


void Delay_nms(uint16_t nms);
void LcdInitial(void);
//void LcdFrame(); 
void dispchar(unsigned char page,unsigned char CaddrH,unsigned char CaddrL,unsigned char StartL, unsigned char num);
void LcdFill(unsigned char buffera,unsigned char bufferb,unsigned char bufferc,unsigned char bufferd);
void ShowString(unsigned char page,unsigned char CaddrH,unsigned char CaddrL,unsigned char *chr,u8 size1);
void displayChineseSpeed(unsigned char page,unsigned char CaddrH,unsigned char CaddrL);
void displayChineseBreak(unsigned char page,unsigned char CaddrH,unsigned char CaddrL);
void displayWeekday(unsigned char page,unsigned char CaddrH,unsigned char CaddrL,int weekday);

void displayIcon(unsigned char page,unsigned char CaddrH,unsigned char CaddrL, unsigned char arr[2][16]);

void displayIcon4G(unsigned char page,unsigned char CaddrH,unsigned char CaddrL);
void displayBeidou(unsigned char page,unsigned char CaddrH,unsigned char CaddrL);
void displayPPL(unsigned char page,unsigned char CaddrH,unsigned char CaddrL);
int WeekYearday(int years, int months, int days);


//void ST7567_WR_Byte(uint8_t chData , uint8_t chCmd);
//void ST7567_Init();
//void ST7567_Clear(uint8_t a);
//void ST7567_Refresh_Gram(void);

//void ST7567_battery_show(void);
//void ST7567_disk_show(void);
//void ST7567_memory_show(void);
//void ST7567_laser_show(void);
//void ST7567_temperature_show(void);
//void ST7567_image_show(void);
//void ST7567_symbol_show(void);
//void ST7567_data1_show(uint8_t temp);
//void ST7567_data2_show(uint8_t temp);
//void ST7567_data3_show(uint8_t temp);
//void ST7567_data4_show(uint8_t temp);

//void ST7567_data1_small_show(uint8_t temp);
//void ST7567_data2_small_show(uint8_t temp);
//void ST7567_data3_small_show(uint8_t temp);
//void ST7567_data4_small_show(uint8_t temp);

//void Unit_show(uint8_t row,uint8_t a);

#endif 
