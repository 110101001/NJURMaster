#include "main.h"
/**
  * @brief main���������ڳ�ʼ��ִ����ѭ����
  * @param None
  * @retval �ɹ�����0��ʧ�ܷ��ش�����
  */
int main()
{
	int j=0;
	char buffer[200];
	AppInit();
	All_Init();

	while (1)
	{
		j = sprintf(buffer," Init ok, this time is %.2f\n",Get_Time_Micros()/1000.f);
		Usart2_Send((u8*)buffer,j);
		delay_ms(1000);
	}
}

