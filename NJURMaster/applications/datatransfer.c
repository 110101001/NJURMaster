#include "main.h"

/**
  * @brief ����ͨѶtask
  * @param ϵͳ�ӿ������������еĺ�����
  * @retval None
  * @details ����������λ�������ϲ�Ӳ�����͵�ǰ�����˵�״̬�򴫸���������
  */
void DatatransferTask(u32 _time_sys)
{



}

/**
  * @brief ����2����Ԥ����
  * @param data	��DR�Ĵ����ж�ȡ��������
  * @retval None
	*	@details �������ɹ�����ת��BasicProtocolAnalysis���д���
  */
void Usart2_DataPrepare(u8 data)
{
	static u8 RxBuffer[50];
	static u8 _data_len = 0,_data_cnt = 0;
	static u8 state = 0;
	
	if(state==0&&data==0xAA)						//�ж�֡ͷ
	{
		state=1;
		RxBuffer[0]=data;
	}
	else if(state==1&&data==0xAF)			//֡ͷ
	{
		state=2;
		RxBuffer[1]=data;
	}
	else if(state==2&&data<0XF1)			//֡����
	{
		state=3;
		RxBuffer[2]=data;
	}
	else if(state==3&&data<50)				//֡��
	{
		state = 4;
		RxBuffer[3]=data;
		_data_len = data;
		_data_cnt = 0;
	}
	else if(state==4&&_data_len>0)		//����֡
	{
		_data_len--;
		RxBuffer[4+_data_cnt++]=data;
		if(_data_len==0)
			state = 5;
	}
	else if(state==5)								//У��֡
	{
		state = 0;
		RxBuffer[4+_data_cnt]=data;
		BasicProtocolAnalysis(RxBuffer,_data_cnt+5);
		
	}
	else
		state = 0;

}

/**
  * @brief ����3����Ԥ����
  * @param data	��DR�Ĵ����ж�ȡ��������
  * @retval None
	*	@details �������ɹ�����ת��BasicProtocolAnalysis���д���
  */
void Usart3_DataPrepare(u8 data)
{
	static u8 RxBuffer[50];
	static u8 _data_len = 0,_data_cnt = 0;
	static u8 state = 0;
	
	if(state==0&&data==0xAA)						//�ж�֡ͷ
	{
		state=1;
		RxBuffer[0]=data;
	}
	else if(state==1&&data==0xAF)			//֡ͷ
	{
		state=2;
		RxBuffer[1]=data;
	}
	else if(state==2&&data<0XF1)			//֡����
	{
		state=3;
		RxBuffer[2]=data;
	}
	else if(state==3&&data<50)				//֡��
	{
		state = 4;
		RxBuffer[3]=data;
		_data_len = data;
		_data_cnt = 0;
	}
	else if(state==4&&_data_len>0)		//����֡
	{
		_data_len--;
		RxBuffer[4+_data_cnt++]=data;
		if(_data_len==0)
			state = 5;
	}
	else if(state==5)								//У��֡
	{
		state = 0;
		RxBuffer[4+_data_cnt]=data;
		BasicProtocolAnalysis(RxBuffer,_data_cnt+5);
		
	}
	else
		state = 0;


}

/**
  * @brief ����6����Ԥ����
  * @param data	��DR�Ĵ����ж�ȡ��������
  * @retval None
	*	@details �������ɹ�����ת��BasicProtocolAnalysis���д���
  */
void Usart6_DataPrepare(u8 data)
{
	static u8 RxBuffer[50];
	static u8 _data_len = 0,_data_cnt = 0;
	static u8 state = 0;
	
	if(state==0&&data==0xAA)						//�ж�֡ͷ
	{
		state=1;
		RxBuffer[0]=data;
	}
	else if(state==1&&data==0xAF)			//֡ͷ
	{
		state=2;
		RxBuffer[1]=data;
	}
	else if(state==2&&data<0XF1)			//֡����
	{
		state=3;
		RxBuffer[2]=data;
	}
	else if(state==3&&data<50)				//֡��
	{
		state = 4;
		RxBuffer[3]=data;
		_data_len = data;
		_data_cnt = 0;
	}
	else if(state==4&&_data_len>0)		//����֡
	{
		_data_len--;
		RxBuffer[4+_data_cnt++]=data;
		if(_data_len==0)
			state = 5;
	}
	else if(state==5)								//У��֡
	{
		state = 0;
		RxBuffer[4+_data_cnt]=data;
		BasicProtocolAnalysis(RxBuffer,_data_cnt+5);
		
	}
	else
		state = 0;


}

