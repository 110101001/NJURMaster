#include "main.h"
u8 data_to_send[50];
/**
  * @brief ����ͨѶtask
  * @param ϵͳ�ӿ������������еĺ�����
  * @retval None
  * @details ����������λ�������ϲ�Ӳ�����͵�ǰ�����˵�״̬�򴫸���������
  */
void DatatransferTask(u32 sys_time)
{
	int j=0;
	char buff[200];
	
	if(sys_time%200==0){
	j=sprintf(buff,"%.2f  %.2f  %.2f  %.2f  %.2f  %.2f\n",MPU6500_Acc.x,MPU6500_Acc.y,MPU6500_Acc.z,MPU6500_Gyro.x,MPU6500_Gyro.y,MPU6500_Gyro.z);
	Usart2_Send((u8*)buff,j);
	}
	if (sys_time%10==0)
	{
		
	}
	else if((sys_time+1)%10==0)
	{
	
	}
	else if((sys_time+2)%10==0)
	{

	}
	else if ((sys_time+5)%10==0)
	{
		
	}
	else
	{
		if (send_check)
		{
			send_check = 0;
			ANO_DT_Send_Check(checkdata_to_send,checksum_to_send);
		}
	}
}

/**
  * @brief ����2����Ԥ����
  * @param data	��DR�Ĵ����ж�ȡ��������
  * @retval None
  * @details �������ɹ�����ת��BasicProtocolAnalysis���д���
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
  * @details �������ɹ�����ת��BasicProtocolAnalysis���д���
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
  * @details �������ɹ�����ת��BasicProtocolAnalysis���д���
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

/**
  * @brief ����attack
  * @param head ֡����
  * @param check_sum У��λ
  * @retval None
  */
void ANO_DT_Send_Check(u8 head, u8 check_sum)
{
	u8 sum = 0;
	u8 i;
	data_to_send[0]=0xAA;
	data_to_send[1]=0xAA;
	data_to_send[2]=0xEF;
	data_to_send[3]=2;
	data_to_send[4]=head;
	data_to_send[5]=check_sum;
	
	

	for(i=0;i<6;i++)
		sum += data_to_send[i];
	data_to_send[6]=sum;

	Usart2_Send(data_to_send, 7);
}
