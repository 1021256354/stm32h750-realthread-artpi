/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date            Author           Notes
 * 2020-12-10      liuda123.club
 */

#include <connect_mqtt.h>
#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"

#define LED_PIN GET_PIN(I, 8)

#define SAMPLE_UART_NAME       "uart6"      //�����Ĵ�������

/* ���ڽ�����Ϣ���ź��� */
static struct rt_semaphore rx_sem;
static rt_device_t serial;

uint16_t temp = 0;  //�����¶ȱ���
uint16_t humi = 0;  //����ʪ�ȱ���

char tem[10]={0};   //����¶����ݵ�����
char hum[10]={0};   //���ʪ�����ݵ�����

/* �������ݻص����� */
static rt_err_t uart_input(rt_device_t dev, rt_size_t size)
{
    /* ���ڽ��յ����ݺ�����жϣ����ô˻ص�������Ȼ���ͽ����ź��� */
    rt_sem_release(&rx_sem);
    return RT_EOK;
}

static void serial_thread_entry(void *parameter)
{
    char ch=0;
    char sensor[20]={0};
    uint8_t i = 0;
    char sensor_T_H[] = {0x01,0x04,0x00,0x00,0x00,0x02,0x71,0xCB};  //�������485��������ѯ���ݵ�ָ���޸�
    while (1)
    {

        rt_device_write(serial, 0, sensor_T_H, sizeof(sensor_T_H));  //���Ͳɼ�����ָ��
        rt_thread_mdelay(1000);  //1s �ɼ�һ��
        /* �Ӵ��ڶ�ȡһ���ֽڵ����ݣ�û�ж�ȡ����ȴ������ź��� */
        while (rt_device_read(serial, -1, &ch, 1) != 1)
        {
            /* �����ȴ������ź������ȵ��ź������ٴζ�ȡ���� */
            rt_sem_take(&rx_sem, RT_WAITING_FOREVER);   //���û���յ����ݾ������ȴ�
        }
        /* ��ȡ��������ͨ�����ڴ�λ��� */

        sensor[i] = ch;
         i++;

        if(i==8)
        {
          i=0;     //����
//          for(uint8_t a=0;a<8; a++)
//          {
//           rt_kprintf("sensor[%d] = %.2x \r\n",a,sensor[a]);
//          }

          //��������
          temp = (sensor[2]<<8)  + sensor[3];
          humi = (sensor[4]<<8)  + sensor[5];
          sprintf((char*)tem,"%.2f",(float)temp/100);  //ƴ�ӵ��¶�������
          sprintf((char*)hum,"%.2f",(float)humi/100);  //ƴ�ӵ�ʪ��������
        }
    }
}

static int uart_sample(int argc, char *argv[])
{
    rt_err_t ret = RT_EOK;
    char uart_name[RT_NAME_MAX];
    char str[] = "hello RT-Thread!\r\n";

    if (argc == 2)
    {
        rt_strncpy(uart_name, argv[1], RT_NAME_MAX);
    }
    else
    {
        rt_strncpy(uart_name, SAMPLE_UART_NAME, RT_NAME_MAX);
    }

    /* ����ϵͳ�еĴ����豸 */
    serial = rt_device_find(uart_name);
    if (!serial)
    {
        rt_kprintf("find %s failed!\n", uart_name);
        return RT_ERROR;
    }

    /* ��ʼ���ź��� */
    rt_sem_init(&rx_sem, "rx_sem", 0, RT_IPC_FLAG_FIFO);
    /* ���жϽ��ռ���ѯ����ģʽ�򿪴����豸 */
    rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
    /* ���ý��ջص����� */
    rt_device_set_rx_indicate(serial, uart_input);
    /* �����ַ��� */
    rt_device_write(serial, 0, str, (sizeof(str) - 1));

    /* ���� serial �߳� */
    rt_thread_t thread = rt_thread_create("serial", serial_thread_entry, RT_NULL, 1024, 25, 10);
    /* �����ɹ��������߳� */
    if (thread != RT_NULL)
    {
        rt_thread_startup(thread);
    }
    else
    {
        ret = RT_ERROR;
    }

    return ret;
}


int main(void)
{
    rt_uint32_t count = 1;

    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);
    uart_sample(1,"uart6");             //���ô���
    mqtt_emqx();                        //����mqtt�߳�

    while(count++)
    {
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_LOW);
    }
    return RT_EOK;
}


#include "stm32h7xx.h"
static int vtor_config(void)
{
    /* Vector Table Relocation in Internal QSPI_FLASH */
    SCB->VTOR = QSPI_BASE;
    return 0;
}
INIT_BOARD_EXPORT(vtor_config);


