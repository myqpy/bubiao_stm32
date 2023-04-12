#include "key.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEK Mini STM32������
//�������� ��������
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2014/3/06
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2009-2019
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////

//������ʼ������
//PA15��PC5 ���ó�����
void KEY_Init(void)
{

    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);//ʹ��PORTA,PORTCʱ��

//    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//�ر�jtag��ʹ��SWD��������SWDģʽ����

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;//PE2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
    GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE2

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3;//PE3
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
    GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE3

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4;//PE4
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
    GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE4

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5;//PE5
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
    GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE5

}
//������������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//����ֵ��
//0��û���κΰ�������
//KEY0_PRES��KEY0����
//KEY1_PRES��KEY1����
//KEY2_PRES��KEY2����
//KEY3_PRES��KEY3����
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>WK_UP!!
u8 KEY_Scan(u8 mode)
{
    static u8 key_up=0;//�������ɿ���־
    if(mode)
	{
		key_up=1;  //֧������
	}
    if(key_up&&(KEY0==0||KEY1==0||KEY2==0||KEY3==0))
    {
        delay_ms(10);//ȥ����
        key_up=0;
        if(KEY0==0)return KEY_confirmed_PRES;
		
		else if(KEY2==0)return KEY_UpArrow_PRES;
		
        else if(KEY1==0)return KEY_DownArrow_PRES;
        
		else if(KEY3==0)return KEY_menu_PRES;
    } 
	else if(KEY0==1&&KEY1==1&&KEY2==1&&KEY3==1)
	{
		key_up=1;
	}
    return 0;// �ް�������
}