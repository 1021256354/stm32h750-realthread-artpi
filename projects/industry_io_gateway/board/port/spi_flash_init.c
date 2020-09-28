/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-27     SummerGift   add spi flash port file
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "spi_flash.h"
#include "spi_flash_sfud.h"
#include "drv_spi.h"

static int rt_hw_spi_flash_init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    rt_hw_spi_device_attach("spi1", "spi10", GPIOA, GPIO_PIN_4);

    if (RT_NULL == rt_sfud_flash_probe("norflash0", "spi10"))
        return -RT_ERROR;

    return RT_EOK;
}
INIT_APP_EXPORT(rt_hw_spi_flash_init);
