#include "main.h"

/**
  * @brief main函数，用于初始化执行主循环等
  * @param None
  * @retval 成功返回0，失败返回错误码
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

