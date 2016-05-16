/********************       (C) COPYRIGHT 2016      **************************
 * �ļ���  ��ChipID.c
 * ����    ����ȡCPU STM32 Ψһ 96bits ID       
 * ʵ��ƽ̨��STM32F429
 * ��汾  ��V1.6.1
 *
 * ��д���ڣ�2016-05-10
 * �޸����ڣ�
 * ����    ��
****************************************************************************/
#include "chipid.h"

uint32_t ChipUniqueID[3];

/*
 * ��������Get_ChipID
 * ����  ����ȡоƬID
 * ����  ����
 * ���  ����
 */
void Get_ChipID(void)
{
	ChipUniqueID[0] = *(__IO uint32_t *)(0X1FFF7A18); // ��4�ֽ�
	ChipUniqueID[1] = *(__IO uint32_t *)(0X1FFF7A14); // ��4�ֽ�
	ChipUniqueID[2] = *(__IO uint32_t *)(0X1FFF7A10); // ��4�ֽ�
}


/*******************    (C) COPYRIGHT 2016     *****END OF FILE************/
