// Target definition
#define RG_TARGET_NAME             "ESP32S3-ST7735"

// Storage
#define RG_STORAGE_ROOT             "/sd"
#define RG_STORAGE_SDSPI_HOST       SPI3_HOST
#define RG_STORAGE_SDSPI_SPEED      SDMMC_FREQ_PROBING // SLOWED DOWN to guarantee SD card mount

// Audio
#define RG_AUDIO_USE_INT_DAC        0
#define RG_AUDIO_USE_EXT_DAC        0  

// Video
#define RG_SCREEN_DRIVER            0   
#define RG_SCREEN_HOST              SPI2_HOST
#define RG_SCREEN_SPEED             SPI_MASTER_FREQ_20M
#define RG_SCREEN_BACKLIGHT         1
#define RG_SCREEN_WIDTH             160
#define RG_SCREEN_HEIGHT            128
#define RG_SCREEN_ROTATE            1   
#define RG_SCREEN_MARGIN_TOP        0   
#define RG_SCREEN_MARGIN_BOTTOM     0
#define RG_SCREEN_MARGIN_LEFT       24  
#define RG_SCREEN_MARGIN_RIGHT      24  

#define RG_SCREEN_INIT() \
    ILI9341_CMD(0x01); /* Software Reset */ \
    ILI9341_CMD(0x11); /* Sleep Out */ \
    ILI9341_CMD(0xB1, 0x01, 0x2C, 0x2D); /* Frame Rate Control */ \
    ILI9341_CMD(0xB2, 0x01, 0x2C, 0x2D); \
    ILI9341_CMD(0xB3, 0x01, 0x2C, 0x2D, 0x01, 0x2C, 0x2D); \
    ILI9341_CMD(0xB4, 0x07); /* Inversion Control */ \
    ILI9341_CMD(0xC0, 0xA2, 0x02, 0x84); /* Power Control */ \
    ILI9341_CMD(0xC1, 0xC5); \
    ILI9341_CMD(0xC2, 0x0A, 0x00); \
    ILI9341_CMD(0xC3, 0x8A, 0x2A); \
    ILI9341_CMD(0xC4, 0x8A, 0xEE); \
    ILI9341_CMD(0xC5, 0x0E); /* VCOM Control */ \
    ILI9341_CMD(0x36, 0x68); /* MADCTL - Changed to 0x68 to flip 180 degrees */ \
    ILI9341_CMD(0xE0, 0x0F, 0x1A, 0x0F, 0x18, 0x2F, 0x28, 0x20, 0x22, 0x1F, 0x1B, 0x23, 0x37, 0x00, 0x07, 0x02, 0x10); \
    ILI9341_CMD(0xE1, 0x0F, 0x1B, 0x0F, 0x17, 0x33, 0x2C, 0x29, 0x2E, 0x30, 0x30, 0x39, 0x3F, 0x00, 0x07, 0x03, 0x10); \
    ILI9341_CMD(0x29); /* Display ON */

// Input
#define RG_GAMEPAD_GPIO_MAP {\
    {RG_KEY_UP,     GPIO_NUM_38, GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_DOWN,   GPIO_NUM_39, GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_LEFT,   GPIO_NUM_47, GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_RIGHT,  GPIO_NUM_48, GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_A,      GPIO_NUM_6,  GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_B,      GPIO_NUM_19, GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_START,  GPIO_NUM_4,  GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_SELECT, GPIO_NUM_5,  GPIO_PULLUP_ONLY, 0},\
}

// Battery
#define RG_BATTERY_DRIVER           0
#define RG_GPIO_LED                 GPIO_NUM_NC

// SPI Display
#define RG_GPIO_LCD_MISO            GPIO_NUM_NC
#define RG_GPIO_LCD_MOSI            GPIO_NUM_42
#define RG_GPIO_LCD_CLK             GPIO_NUM_40
#define RG_GPIO_LCD_CS              GPIO_NUM_45
#define RG_GPIO_LCD_DC              GPIO_NUM_21
#define RG_GPIO_LCD_BCKL            GPIO_NUM_2
#define RG_GPIO_LCD_RST             GPIO_NUM_14

// SD Card
#define RG_GPIO_SDSPI_MISO          GPIO_NUM_41
#define RG_GPIO_SDSPI_MOSI          GPIO_NUM_42
#define RG_GPIO_SDSPI_CLK           GPIO_NUM_40
#define RG_GPIO_SDSPI_CS            GPIO_NUM_1
