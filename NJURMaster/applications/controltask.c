#include "main.h"


//values for PID Calculate.
float GimbalPitchPosRef=0.0f;
float GimbalPitchGyrRef=0.0f;
float GimbalYawPosRef=0.0f;
float GimbalYawGyrRef=0.0f;
float ChassisGoToward=0.0f;
float ChassisGoLeftRight=0.0f;


/**
  * @brief ���̿��Ƴ���
  * @param _T�����������(s)
  * @retval None
  * @details 	���ݵ�ǰ�����������ƶ��ٶȺ͵�ǰ���̹���
	*						���ĸ����̵���ĵ������п���
  */
void ChassisControl(float _T)
{
    ChassisSpeedSet(CAN1, 0, 0, 0, 0);
}

/**
  * @brief ��̨���Ƴ���
  * @param _T�����������
  * @retval None
  * @details ���ݵ�ǰ��̨�������Ƕ�������������̨������������
  */
void GimbalControl(float _T)
{


}

/**
  * @brief ����������Ƴ���
  * @param _T�����������(s)
  * @retval None
  * @details ���ݸ���ң�������������źſ���Ħ���ֺͲ��������ת��
  */
void FireControl(float _T)
{


}

