#include "main.h"

/**
  * @brief 1ms����
  * @param ϵͳ�ӿ��������ھ����ĺ�����
  * @retval None
  */
static void Duty_1ms(u32 _time)
{
	//u32 loop_time = GetInnerLoop(Task_1ms_Time);
	DatatransferTask(_time);
	
}

/**
  * @brief 2ms����
  * @param ϵͳ�ӿ��������ھ����ĺ�����
  * @retval None
  */
static void Duty_2ms(u32 _time)
{
	//u32 loop_time = GetInnerLoop(Task_2ms_Time);
	MPU6500_Data_Prepare();
	
}

/**
  * @brief 5ms����
  * @param ϵͳ�ӿ��������ھ����ĺ�����
  * @retval None
  */
static void Duty_5ms(u32 _time)
{
	u32 loop_time = GetInnerLoop(Task_5ms_Time);
	CheckDog();
	ChassisControl(loop_time/1000000.0f);
	GimbalControl(loop_time/1000000.0f);
}

/**
  * @brief 10ms����
  * @param ϵͳ�ӿ��������ھ����ĺ�����
  * @retval None
  */
static void Duty_10ms(u32 _time)
{
	u32 loop_time = GetInnerLoop(Task_10ms_Time);
	FireControl(loop_time/1000000.0f);
}

/**
  * @brief 20ms����
  * @param ϵͳ�ӿ��������ھ����ĺ�����
  * @retval None
  */
static void Duty_20ms(u32 _time)
{
	u32 loop_time = GetInnerLoop(Task_20ms_Time);

}

/**
  * @brief 50ms����
  * @param ϵͳ�ӿ��������ھ����ĺ�����
  * @retval None
  */
static void Duty_50ms(u32 _time)
{

	//u32 loop_time = GetInnerLoop(Task_50ms_Time);
//	if (IsDeviceLost(DEVICE_INDEX_RC))
//	BOTH_LED_TOGGLE();
//	int j=0;
//	char buffer[200];
//	j = sprintf(buffer," Hello World !\nthis time is %d\nj=%d\n\n",Get_Time_Micros(),j);
//		Usart2_Send((u8*)buffer,j);
	if (IsDeviceLost(DEVICE_INDEX_NOCALI))
	{
		BOTH_LED_TOGGLE();
	}
}

/**
  * @brief ϵͳ������ѭ��
  * @param None
  * @retval None
  * @details �ɶ�ʱ��ÿ����׼ʱ���ã�������������task
  */
void Duty_loop(void)
{
	static u32 systime_ms=0;
	//if (GetInnerLoop(DutyLoop_Time)>1000);
	systime_ms++;
	Duty_1ms(systime_ms);
	if (systime_ms%2==0)Duty_2ms(systime_ms);
	if (systime_ms%5==0)Duty_5ms(systime_ms);
	if (systime_ms%10==0)Duty_10ms(systime_ms);
	if (systime_ms%20==0)Duty_20ms(systime_ms);
	if (systime_ms%50==0)Duty_50ms(systime_ms);
	
}
	
	
