#include "main.h"

/**
  * @brief main���������ڳ�ʼ��ִ����ѭ����
  * @param None
  * @retval �ɹ�����0��ʧ�ܷ��ش�����
  */
int main()
{
	//int i=0;
	AppInit();
	All_Init();
	//GimbalCurrentSet(CAN1,0,0,0);
	while (1)
	{
		if (ParaSavingFlag)
		{
			ParametersSave();
			ParaSavingFlag=0;
		}
		delay_ms(1000);
	}
}

