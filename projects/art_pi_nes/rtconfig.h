#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* Automatically generated file; DO NOT EDIT. */
/* RT-Thread Configuration */

/* RT-Thread Kernel */

#define RT_NAME_MAX 8
#define RT_ALIGN_SIZE 4
#define RT_THREAD_PRIORITY_32
#define RT_THREAD_PRIORITY_MAX 32
#define RT_TICK_PER_SECOND 1000
#define RT_USING_OVERFLOW_CHECK
#define RT_USING_HOOK
#define RT_HOOK_USING_FUNC_PTR
#define RT_USING_IDLE_HOOK
#define RT_IDLE_HOOK_LIST_SIZE 4
#define IDLE_THREAD_STACK_SIZE 1024
#define RT_USING_TIMER_SOFT
#define RT_TIMER_THREAD_PRIO 4
#define RT_TIMER_THREAD_STACK_SIZE 512

/* kservice optimization */

#define RT_KSERVICE_USING_STDLIB
#define RT_DEBUG
#define RT_DEBUG_COLOR

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE

/* Memory Management */

#define RT_USING_MEMPOOL
#define RT_USING_MEMHEAP
#define RT_MEMHEAP_FAST_MODE
#define RT_USING_MEMHEAP_AS_HEAP
#define RT_USING_MEMHEAP_AUTO_BINDING
#define RT_USING_HEAP

/* Kernel Device Object */

#define RT_USING_DEVICE
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE 512
#define RT_CONSOLE_DEVICE_NAME "uart4"
#define RT_VER_NUM 0x40101
#define ARCH_ARM
#define RT_USING_CPU_FFS
#define ARCH_ARM_CORTEX_M
#define ARCH_ARM_CORTEX_M7

/* RT-Thread Components */

#define RT_USING_COMPONENTS_INIT
#define RT_USING_USER_MAIN
#define RT_MAIN_THREAD_STACK_SIZE 4096
#define RT_MAIN_THREAD_PRIORITY 10
#define RT_USING_LEGACY
#define RT_USING_MSH
#define RT_USING_FINSH
#define FINSH_USING_MSH
#define FINSH_THREAD_NAME "tshell"
#define FINSH_THREAD_PRIORITY 20
#define FINSH_THREAD_STACK_SIZE 4096
#define FINSH_USING_HISTORY
#define FINSH_HISTORY_LINES 5
#define FINSH_USING_SYMTAB
#define FINSH_CMD_SIZE 80
#define MSH_USING_BUILT_IN_COMMANDS
#define FINSH_USING_DESCRIPTION
#define FINSH_ARG_MAX 10
#define RT_USING_DFS
#define DFS_USING_POSIX
#define DFS_USING_WORKDIR
#define DFS_FILESYSTEMS_MAX 6
#define DFS_FILESYSTEM_TYPES_MAX 6
#define DFS_FD_MAX 32
#define RT_USING_DFS_ELMFAT

/* elm-chan's FatFs, Generic FAT Filesystem Module */

#define RT_DFS_ELM_CODE_PAGE 936
#define RT_DFS_ELM_WORD_ACCESS
#define RT_DFS_ELM_USE_LFN_3
#define RT_DFS_ELM_USE_LFN 3
#define RT_DFS_ELM_LFN_UNICODE_0
#define RT_DFS_ELM_LFN_UNICODE 0
#define RT_DFS_ELM_MAX_LFN 255
#define RT_DFS_ELM_DRIVES 2
#define RT_DFS_ELM_MAX_SECTOR_SIZE 4096
#define RT_DFS_ELM_REENTRANT
#define RT_DFS_ELM_MUTEX_TIMEOUT 3000
#define RT_USING_DFS_DEVFS
#define RT_USING_DFS_ROMFS
#define RT_USING_FAL
#define FAL_DEBUG_CONFIG
#define FAL_DEBUG 1
#define FAL_PART_HAS_TABLE_CFG
#define FAL_USING_SFUD_PORT
#define FAL_USING_NOR_FLASH_DEV_NAME "norflash0"

/* Device Drivers */

#define RT_USING_DEVICE_IPC
#define RT_USING_SYSTEM_WORKQUEUE
#define RT_SYSTEM_WORKQUEUE_STACKSIZE 2048
#define RT_SYSTEM_WORKQUEUE_PRIORITY 23
#define RT_USING_SERIAL
#define RT_USING_SERIAL_V1
#define RT_SERIAL_USING_DMA
#define RT_SERIAL_RB_BUFSZ 64
#define RT_USING_I2C
#define RT_USING_I2C_BITOPS
#define RT_USING_PIN
#define RT_USING_MTD_NOR
#define RT_USING_SDIO
#define RT_SDIO_STACK_SIZE 512
#define RT_SDIO_THREAD_PRIORITY 15
#define RT_MMCSD_STACK_SIZE 1024
#define RT_MMCSD_THREAD_PREORITY 22
#define RT_MMCSD_MAX_PARTITION 16
#define RT_USING_SPI
#define RT_USING_SFUD
#define RT_SFUD_USING_SFDP
#define RT_SFUD_USING_FLASH_INFO_TABLE
#define RT_SFUD_SPI_MAX_HZ 50000000
#define RT_USING_AUDIO
#define RT_AUDIO_REPLAY_MP_BLOCK_SIZE 4096
#define RT_AUDIO_REPLAY_MP_BLOCK_COUNT 2
#define RT_AUDIO_RECORD_PIPE_SIZE 2048
#define RT_USING_TOUCH

/* Using USB */


/* C/C++ and POSIX layer */

#define RT_LIBC_DEFAULT_TIMEZONE 8

/* POSIX (Portable Operating System Interface) layer */

#define RT_USING_POSIX_FS

/* Interprocess Communication (IPC) */


/* Socket is in the 'Network' category */


/* Network */


/* Utilities */

#define RT_USING_RYM

/* RT-Thread online packages */

/* IoT - internet of things */


/* Wi-Fi */

/* Marvell WiFi */


/* Wiced WiFi */


/* IoT Cloud */


/* security packages */


/* language packages */

/* JSON: JavaScript Object Notation, a lightweight data-interchange format */


/* XML: Extensible Markup Language */


/* multimedia packages */

/* LVGL: powerful and easy-to-use embedded GUI library */

#define PKG_USING_LITTLEVGL2RTT
#define PKG_USING_LITTLEVGL2RTT_V001

/* LittlevGL2RTT Options */

#define LV_MEM_DYNAMIC
#define LV_MEM_CUSTOM 1
#define LV_COLOR_DEPTH_32
#define LV_COLOR_DEPTH 32
#define LV_HOR_RES 480
#define LV_VER_RES 320
#define LV_DPI 50
#define LV_GC_DISABLE
#define LV_ENABLE_GC 0

/* u8g2: a monochrome graphic library */

#define PKG_USING_HELIX
#define PKG_USING_HELIX_V100

/* PainterEngine: A cross-platform graphics application framework written in C language */


/* tools packages */

#define PKG_USING_GBK2UTF8
#define PKG_USING_GBK2UTF8_V100

/* system packages */

/* enhanced kernel services */


/* POSIX extension functions */


/* acceleration: Assembly language or algorithmic acceleration packages */


/* CMSIS: ARM Cortex-M Microcontroller Software Interface Standard */


/* Micrium: Micrium software products porting for RT-Thread */

#define PKG_USING_LITTLEFS
#define PKG_USING_LITTLEFS_V205
#define LFS_READ_SIZE 256
#define LFS_PROG_SIZE 256
#define LFS_BLOCK_SIZE 4096
#define LFS_CACHE_SIZE 256
#define LFS_BLOCK_CYCLES 0
#define LFS_THREADSAFE
#define LFS_LOOKAHEAD_MAX 128

/* peripheral libraries and drivers */

#define PKG_USING_TOUCH_DRIVERS
#define PKG_USING_FT6236
#define PKG_USING_FT6236_V100
#define PKG_USING_NES
#define PKG_NES_DFS
#define PKG_NES_FRAME_SKIP 3
#define PKG_NES_DOUBLE_FRAMEBUFFER
#define PKG_USING_NES_V100

/* AI packages */


/* miscellaneous packages */

/* project laboratory */

/* samples: kernel and components samples */


/* entertainment: terminal games and other interesting software packages */


/* Hardware Drivers Config */

#define SOC_STM32H750XB
#define SOC_SERIES_STM32H7

/* Board extended module */

#define ART_PI_USING_MEDIA_IO
#define BSP_USING_SPI_LCD_ILI9488
#define PKG_USING_PERSIMMON_SRC
#define MEDIA_IO_USING_SCREEN
#define MEDIA_IO_USING_TOUCH
#define MEDIA_IO_USING_AUDIO
#define AUDIO_MP3

/* Onboard Peripheral */

#define BSP_USING_USB_TO_USART
#define BSP_USING_SPI_FLASH
#define BSP_USING_FS
#define BSP_USING_SDCARD_FS
#define BSP_USING_SPI_FLASH_FS

/* On-chip Peripheral */

#define BSP_USING_GPIO
#define BSP_USING_UART
#define BSP_USING_UART4
#define BSP_USING_SPI
#define BSP_USING_SPI1
#define BSP_USING_SPI2
#define BSP_USING_I2C
#define BSP_USING_I2C2

/* Notice: PH13 --> 125; PH15 --> 127 */

#define BSP_I2C2_SCL_PIN 127
#define BSP_I2C2_SDA_PIN 125
#define BSP_USING_I2C3

/* Notice: PH12 --> 124; PH11 --> 123 */

#define BSP_I2C3_SCL_PIN 123
#define BSP_I2C3_SDA_PIN 124
#define BSP_USING_SDIO
#define BSP_USING_SDIO1
#define BSP_USING_SDRAM

/* External Libraries */

#define FIRMWARE_EXEC_USING_QSPI_FLASH
#define RT_STUDIO_BUILT_IN

#endif
