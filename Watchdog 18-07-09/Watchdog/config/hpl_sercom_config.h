/* Auto-generated config file hpl_sercom_config.h */
#ifndef HPL_SERCOM_CONFIG_H
#define HPL_SERCOM_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

#include <peripheral_clk_config.h>

#ifndef SERCOM_I2CM_CTRLA_MODE_I2C_MASTER
#define SERCOM_I2CM_CTRLA_MODE_I2C_MASTER (5 << 2)
#endif

#ifndef CONF_SERCOM_1_I2CM_ENABLE
#define CONF_SERCOM_1_I2CM_ENABLE 1
#endif

// <h> Basic

// <o> I2C Bus clock speed (Hz) <1-400000>
// <i> I2C Bus clock (SCL) speed measured in Hz
// <id> i2c_master_baud_rate
#ifndef CONF_SERCOM_1_I2CM_BAUD
#define CONF_SERCOM_1_I2CM_BAUD 100000
#endif

// </h>

// <e> Advanced
// <id> i2c_master_advanced
#ifndef CONF_SERCOM_1_I2CM_ADVANCED_CONFIG
#define CONF_SERCOM_1_I2CM_ADVANCED_CONFIG 0
#endif

// <o> TRise (ns) <0-300>
// <i> Determined by the bus impedance, check electric characteristics in the datasheet
// <i> Standard Fast Mode: typical 215ns, max 300ns
// <i> Fast Mode +: typical 60ns, max 100ns
// <i> High Speed Mode: typical 20ns, max 40ns
// <id> i2c_master_arch_trise

#ifndef CONF_SERCOM_1_I2CM_TRISE
#define CONF_SERCOM_1_I2CM_TRISE 215
#endif

// <q> Master SCL Low Extended Time-Out (MEXTTOEN)
// <i> This enables the master SCL low extend time-out
// <id> i2c_master_arch_mexttoen
#ifndef CONF_SERCOM_1_I2CM_MEXTTOEN
#define CONF_SERCOM_1_I2CM_MEXTTOEN 0
#endif

// <q> Slave SCL Low Extend Time-Out (SEXTTOEN)
// <i> Enables the slave SCL low extend time-out. If SCL is cumulatively held low for greater than 25ms from the initial START to a STOP, the slave will release its clock hold if enabled and reset the internal state machine
// <id> i2c_master_arch_sexttoen
#ifndef CONF_SERCOM_1_I2CM_SEXTTOEN
#define CONF_SERCOM_1_I2CM_SEXTTOEN 0
#endif

// <q> SCL Low Time-Out (LOWTOUT)
// <i> Enables SCL low time-out. If SCL is held low for 25ms-35ms, the master will release it's clock hold
// <id> i2c_master_arch_lowtout
#ifndef CONF_SERCOM_1_I2CM_LOWTOUT
#define CONF_SERCOM_1_I2CM_LOWTOUT 0
#endif

// <o> Inactive Time-Out (INACTOUT)
// <0x0=>Disabled
// <0x1=>5-6 SCL cycle time-out(50-60us)
// <0x2=>10-11 SCL cycle time-out(100-110us)
// <0x3=>20-21 SCL cycle time-out(200-210us)
// <i> Defines if inactivity time-out should be enabled, and how long the time-out should be
// <id> i2c_master_arch_inactout
#ifndef CONF_SERCOM_1_I2CM_INACTOUT
#define CONF_SERCOM_1_I2CM_INACTOUT 0x0
#endif

// <o> SDA Hold Time (SDAHOLD)
// <0=>Disabled
// <1=>50-100ns hold time
// <2=>300-600ns hold time
// <3=>400-800ns hold time
// <i> Defines the SDA hold time with respect to the negative edge of SCL
// <id> i2c_master_arch_sdahold
#ifndef CONF_SERCOM_1_I2CM_SDAHOLD
#define CONF_SERCOM_1_I2CM_SDAHOLD 0x2
#endif

// <q> Run in stand-by
// <i> Determine if the module shall run in standby sleep mode
// <id> i2c_master_arch_runstdby
#ifndef CONF_SERCOM_1_I2CM_RUNSTDBY
#define CONF_SERCOM_1_I2CM_RUNSTDBY 0
#endif

// <o> Debug Stop Mode
// <i> Behavior of the baud-rate generator when CPU is halted by external debugger.
// <0=>Keep running
// <1=>Halt
// <id> i2c_master_arch_dbgstop
#ifndef CONF_SERCOM_1_I2CM_DEBUG_STOP_MODE
#define CONF_SERCOM_1_I2CM_DEBUG_STOP_MODE 0
#endif

// </e>

#ifndef CONF_SERCOM_1_I2CM_SPEED
#define CONF_SERCOM_1_I2CM_SPEED 0x00 // Speed: Standard/Fast mode
#endif
#if CONF_SERCOM_1_I2CM_TRISE < 215 || CONF_SERCOM_1_I2CM_TRISE > 300
#warning Bad I2C Rise time for Standard/Fast mode, reset to 215ns
#undef CONF_SERCOM_1_I2CM_TRISE
#define CONF_SERCOM_1_I2CM_TRISE 215
#endif

//                  gclk_freq - (i2c_scl_freq * 10) - (gclk_freq * i2c_scl_freq * Trise)
// BAUD + BAUDLOW = --------------------------------------------------------------------
//                  i2c_scl_freq
// BAUD:    register value low  [7:0]
// BAUDLOW: register value high [15:8], only used for odd BAUD + BAUDLOW
#define CONF_SERCOM_1_I2CM_BAUD_BAUDLOW                                                                                \
	(((CONF_GCLK_SERCOM1_CORE_FREQUENCY - (CONF_SERCOM_1_I2CM_BAUD * 10)                                               \
	   - (CONF_SERCOM_1_I2CM_TRISE * (CONF_SERCOM_1_I2CM_BAUD / 100) * (CONF_GCLK_SERCOM1_CORE_FREQUENCY / 10000)      \
	      / 1000))                                                                                                     \
	      * 10                                                                                                         \
	  + 5)                                                                                                             \
	 / (CONF_SERCOM_1_I2CM_BAUD * 10))
#ifndef CONF_SERCOM_1_I2CM_BAUD_RATE
#if CONF_SERCOM_1_I2CM_BAUD_BAUDLOW > (0xFF * 2)
#warning Requested I2C baudrate too low, please check
#define CONF_SERCOM_1_I2CM_BAUD_RATE 0xFF
#elif CONF_SERCOM_1_I2CM_BAUD_BAUDLOW <= 1
#warning Requested I2C baudrate too high, please check
#define CONF_SERCOM_1_I2CM_BAUD_RATE 1
#else
#define CONF_SERCOM_1_I2CM_BAUD_RATE                                                                                   \
	((CONF_SERCOM_1_I2CM_BAUD_BAUDLOW & 0x1)                                                                           \
	     ? (CONF_SERCOM_1_I2CM_BAUD_BAUDLOW / 2) + ((CONF_SERCOM_1_I2CM_BAUD_BAUDLOW / 2 + 1) << 8)                    \
	     : (CONF_SERCOM_1_I2CM_BAUD_BAUDLOW / 2))
#endif
#endif

#include <peripheral_clk_config.h>

#ifndef CONF_SERCOM_5_USART_ENABLE
#define CONF_SERCOM_5_USART_ENABLE 1
#endif

// <h> Basic Configuration

// <q> Receive buffer enable
// <i> Enable input buffer in SERCOM module
// <id> usart_rx_enable
#ifndef CONF_SERCOM_5_USART_RXEN
#define CONF_SERCOM_5_USART_RXEN 1
#endif

// <q> Transmitt buffer enable
// <i> Enable output buffer in SERCOM module
// <id> usart_tx_enable
#ifndef CONF_SERCOM_5_USART_TXEN
#define CONF_SERCOM_5_USART_TXEN 1
#endif

// <o> Frame parity
// <0x0=>No parity
// <0x1=>Even parity
// <0x2=>Odd parity
// <i> Parity bit mode for USART frame
// <id> usart_parity
#ifndef CONF_SERCOM_5_USART_PARITY
#define CONF_SERCOM_5_USART_PARITY 0x0
#endif

// <o> Character Size
// <0x0=>8 bits
// <0x1=>9 bits
// <0x5=>5 bits
// <0x6=>6 bits
// <0x7=>7 bits
// <i> Data character size in USART frame
// <id> usart_character_size
#ifndef CONF_SERCOM_5_USART_CHSIZE
#define CONF_SERCOM_5_USART_CHSIZE 0x0
#endif

// <o> Stop Bit
// <0=>One stop bit
// <1=>Two stop bits
// <i> Number of stop bits in USART frame
// <id> usart_stop_bit
#ifndef CONF_SERCOM_5_USART_SBMODE
#define CONF_SERCOM_5_USART_SBMODE 0
#endif

// <o> Baud rate <1-3000000>
// <i> USART baud rate setting
// <id> usart_baud_rate
#ifndef CONF_SERCOM_5_USART_BAUD
#define CONF_SERCOM_5_USART_BAUD 9600
#endif

// </h>

// <e> Advanced configuration
// <id> usart_advanced
#ifndef CONF_SERCOM_5_USART_ADVANCED_CONFIG
#define CONF_SERCOM_5_USART_ADVANCED_CONFIG 0
#endif

// <q> Run in stand-by
// <i> Keep the module running in standby sleep mode
// <id> usart_arch_runstdby
#ifndef CONF_SERCOM_5_USART_RUNSTDBY
#define CONF_SERCOM_5_USART_RUNSTDBY 0
#endif

// <q> Immediate Buffer Overflow Notification
// <i> Controls when the BUFOVF status bit is asserted
// <id> usart_arch_ibon
#ifndef CONF_SERCOM_5_USART_IBON
#define CONF_SERCOM_5_USART_IBON 0
#endif

// <q> Start of Frame Detection Enable
// <i> Will wake the device from any sleep mode if usart_init and usart_enable was run priort to going to sleep. (receive buffer must be enabled)
// <id> usart_arch_sfde
#ifndef CONF_SERCOM_5_USART_SFDE
#define CONF_SERCOM_5_USART_SFDE 0
#endif

// <q> Collision Detection Enable
// <i> Collision detection enable
// <id> usart_arch_cloden
#ifndef CONF_SERCOM_5_USART_CLODEN
#define CONF_SERCOM_5_USART_CLODEN 0
#endif

// <o> Operating Mode
// <0x0=>USART with external clock
// <0x1=>USART with internal clock
// <i> Drive the shift register by an internal clock generated by the baud rate generator or an external clock supplied on the XCK pin.
// <id> usart_arch_clock_mode
#ifndef CONF_SERCOM_5_USART_MODE
#define CONF_SERCOM_5_USART_MODE 0x0
#endif

// Does not do anything in USRT mode
#define CONF_SERCOM_5_USART_SAMPR 0x0
#define CONF_SERCOM_5_USART_SAMPA 0x0
#define CONF_SERCOM_5_USART_FRACTIONAL 0x0

// <o> Data Order
// <0=>MSB is transmitted first
// <1=>LSB is transmitted first
// <i> Data order of the data bits in the frame
// <id> usart_arch_dord
#ifndef CONF_SERCOM_5_USART_DORD
#define CONF_SERCOM_5_USART_DORD 1
#endif

// <o> Clock Polarity
// <0=>TX rising edge
// <1=>TX falling edge
// <i> Define the relationship between TX and RX in USRT mode
// <id> usart_arch_cpol
#ifndef CONF_SERCOM_5_USART_CPOL
#define CONF_SERCOM_5_USART_CPOL 0
#endif

// Does not do anything in USRT mode
#define CONF_SERCOM_5_USART_ENC 0

// Does not do anything in USRT mode
#define CONF_SERCOM_5_USART_LIN_SLAVE_ENABLE 0

// <o> Debug Stop Mode
// <i> Behavior of the baud-rate generator when CPU is halted by external debugger.
// <0=>Keep running
// <1=>Halt
// <id> usart_arch_dbgstop
#ifndef CONF_SERCOM_5_USART_DEBUG_STOP_MODE
#define CONF_SERCOM_5_USART_DEBUG_STOP_MODE 0
#endif

// </e>

#ifndef CONF_SERCOM_5_USART_CMODE
#define CONF_SERCOM_5_USART_CMODE 1
#endif

#ifndef CONF_SERCOM_5_USART_RXPO
#define CONF_SERCOM_5_USART_RXPO 2 /* RX is on PIN_PB18 */
#endif

#ifndef CONF_SERCOM_5_USART_TXPO
#define CONF_SERCOM_5_USART_TXPO 0 /* TX is on PIN_PB16 */
#endif

/* Set correct parity settings in register interface based on PARITY setting */
#if CONF_SERCOM_5_USART_LIN_SLAVE_ENABLE == 1
#if CONF_SERCOM_5_USART_PARITY == 0
#define CONF_SERCOM_5_USART_PMODE 0
#define CONF_SERCOM_5_USART_FORM 4
#else
#define CONF_SERCOM_5_USART_PMODE CONF_SERCOM_5_USART_PARITY - 1
#define CONF_SERCOM_5_USART_FORM 5
#endif
#else /* #if CONF_SERCOM_5_USART_LIN_SLAVE_ENABLE == 0 */
#if CONF_SERCOM_5_USART_PARITY == 0
#define CONF_SERCOM_5_USART_PMODE 0
#define CONF_SERCOM_5_USART_FORM 0
#else
#define CONF_SERCOM_5_USART_PMODE CONF_SERCOM_5_USART_PARITY - 1
#define CONF_SERCOM_5_USART_FORM 1
#endif
#endif

// Calculate BAUD register value in USRT mode
#ifndef CONF_SERCOM_5_USART_BAUD_RATE
#define CONF_SERCOM_5_USART_BAUD_RATE (CONF_GCLK_SERCOM5_CORE_FREQUENCY) / (2 * CONF_SERCOM_5_USART_BAUD) - 1
#endif
#ifndef CONF_SERCOM_5_USART_RECEIVE_PULSE_LENGTH
#define CONF_SERCOM_5_USART_RECEIVE_PULSE_LENGTH 0
#endif

// <<< end of configuration section >>>

#endif // HPL_SERCOM_CONFIG_H