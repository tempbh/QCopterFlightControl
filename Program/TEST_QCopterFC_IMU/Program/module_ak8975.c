/*==============================================================================================*/
/*==============================================================================================*/
#include "stm32f4_system.h"
#include "stm32f4_i2c.h"
#include "module_ak8975.h"
/*==============================================================================================*/
/*==============================================================================================*
**函數 : AK8975_Init
**功能 : 初始化 AK8975
**輸入 : None
**輸出 : None
**使用 : AK8975_Init()
**==============================================================================================*/
/*==============================================================================================*/
void AK8975_Init( void )
{
  u8 i = 0;
  u8 AK8975_Init_Data[3][2] = {
      {0x01, MPU6050_PWR_MGMT_1},   // 
      {0x03, MPU6050_CONFIG},       // 
      {0x18, MPU6050_GYRO_CONFIG}   // 
    };

  for(i=0; i<3; i++) {
    I2C_DMA_WriteReg(AK8975_I2C_ADDR, AK8975_Init_Data[i][1], AK8975_Init_Data[i], 1);
    Delay_1ms(10);
  }
}
/*==============================================================================================*/
/*==============================================================================================*/
