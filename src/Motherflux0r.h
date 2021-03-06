#include <inttypes.h>
#include <stdint.h>

#ifndef __MOTHERFLUX0R_H__
#define __MOTHERFLUX0R_H__

#define TEST_PROG_VERSION          "v1.2"
#define TOUCH_DWELL_LONG_PRESS       1000  // Milliseconds for "long-press".
#define E_VAL                      1.0184

/*******************************************************************************
* Pin definitions and hardware constants.
*******************************************************************************/
#define GPS_TX_PIN           0   // Teensy RX
#define GPS_RX_PIN           1   // Teensy TX
#define IMU_CS_PIN           2
#define IMU_IRQ_PIN          3
#define DRV425_ADC_IRQ_PIN   4
#define VIBRATOR_PIN         5
#define TOUCH_IRQ_PIN        6
#define DAC_DIN_PIN          7
#define TSL2561_IRQ_PIN    255 // 8
#define PSU_SX_IRQ_PIN       9   // Presently unused.
#define DISPLAY_CS_PIN      10
#define SPIMOSI_PIN         11
#define SPIMISO_PIN         12
#define SPISCK_PIN          13
#define LED_R_PIN           14
#define LED_G_PIN           15
#define SCL1_PIN            16   // Sensor service bus.
#define SDA1_PIN            17   // Sensor service bus.
#define SDA0_PIN            18
#define SCL0_PIN            19
#define DAC_LCK_PIN         20   // XMT is tied high.
#define DAC_BCK_PIN         21   // FLT, FMT are tied low.
#define ANA_LIGHT_PIN       22   // PIN_A8
#define DAC_SCL_PIN         23
#define COMM_RX_PIN         24
#define COMM_TX_PIN         25
#define DISPLAY_DC_PIN      26
#define MIC_ANA_PIN         27   // A16
#define TOUCH_RESET_PIN     28
#define DRV425_GPIO_IRQ_PIN 29
#define DRV425_CS_PIN       30
#define AMG8866_IRQ_PIN     255  //31
#define DISPLAY_RST_PIN     32
#define LED_B_PIN           33

/* Common 16-bit colors */
#define	BLACK           0x0000
#define	BLUE            0x001F
#define	RED             0xF800
#define	GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF


/*******************************************************************************
* Types
*******************************************************************************/
enum class AppID : uint8_t {
  APP_SELECT   =  0,  // For choosing the app.
  TOUCH_TEST   =  1,  // For diagnostics of the touch pad.
  CONFIGURATOR =  2,  // For tuning all the things.
  DATA_MGMT    =  3,  // For managing recorded datasets.
  SYNTH_BOX    =  4,  // Sound synthesis from data.
  COMMS_TEST   =  5,  // Connecting to the outside world.
  META         =  6,  // Shutdown/reboot/reflash, profiles.
  I2C_SCANNER  =  7,  // Tool for non-intrusively scanning foreign i2c buses.
  TRICORDER    =  8,  // This is the primary purpose of the device.
  HOT_STANDBY  =  9,  // Full operation with powered-down UI elements.
  SUSPEND      = 10   // Minimal power without an obligatory reboot.
};

enum class SensorID : uint8_t {
  BARO          = 0,  //
  MAGNETOMETER  = 1,  //
  IMU           = 2,  //
  LIGHT         = 3,  //
  MIC           = 4,  //
  UV            = 5,  //
  GPS           = 6,  //
  THERMOPILE    = 7,  //
  TEMP          = 8,  // TMP102
  BATT_VOLTAGE  = 9   //
};

/* Struct for tracking application state. */
typedef struct {
  const char* const title;           // Name of tha application.
  const AppID       id;              // ID of the application.
  uint8_t           page_count;      // Total page count.
  uint8_t           page_top;        // The currently visible page.
  uint8_t           slider_val;      // Cached slider value.
  uint8_t           frame_rate;      // App's frame rate.
  bool              screen_refresh;  // Set to indicate a refresh is needed.
  bool              app_active;      // This app is active.
  bool              locked;          // This app is locked into its current state.
} AppHandle;

/* Struct for defining global hotkeys. */
typedef struct {
  uint8_t id;        // Uniquely IDs this hotkey combo.
  uint8_t buttons;   // To trigger, the button state must equal this...
  uint32_t duration; // ...for at least this many milliseconds.
} KeyCombo;


#define ICON_CANCEL    0
#define ICON_ACCEPT    1
#define ICON_THERMO    2
#define ICON_IMU       3
#define ICON_GPS       4
#define ICON_LIGHT     5
#define ICON_UVI       6
#define ICON_SOUND     7
#define ICON_RH        8
#define ICON_MIC       9
#define ICON_MAGNET   10
#define ICON_BATTERY  11

uint8_t* bitmapPointer(unsigned int idx);
inline uint16_t strict_max(uint16_t a, uint16_t b) { return (a > b) ? a:b; };
inline uint16_t strict_min(uint16_t a, uint16_t b) { return (a > b) ? b:a; };
//inline uint32_t strict_max(uint32_t a, uint32_t b) { return (a > b) ? a:b; };
//inline uint32_t strict_min(uint32_t a, uint32_t b) { return (a > b) ? b:a; };
inline float strict_max(float a, float b) { return (a > b) ? a:b; };
inline float strict_min(float a, float b) { return (a > b) ? b:a; };


#endif    // __MOTHERFLUX0R_H__
