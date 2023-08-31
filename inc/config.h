#ifndef __CONFIG_H__
#define __CONFIG_H__

/* Global configuration options for PicoMemcard */
#define TUD_MOUNT_TIMEOUT	3000			// max time (in ms) before giving up on MSC mode (USB) and starting memcard simulation
#define MSC_WRITE_SYNC_TIMEOUT 1 * 1000		// time (in ms) expired since last MSC write before exporting RAM disk into LFS
#define IDLE_AUTOSYNC_TIMEOUT 5 * 1000		// time (in ms) the memory card must be inactive before automatic sync from RAM to LFS
#define MAX_MC_FILENAME_LEN	32				// max length of memory card file name
#define MAX_MC_INDEX	255					// maximum number of different mc images
#define MC_RECONNECT_TIME	1000				// time (in ms) the memory card stays disconnected when simulating reconnection

/* Board targeted by build */
//#define PICO
//#define WAVESHARE_RP2040_ZERO
#define ADAFRUIT_QTPY_RP2040
#ifndef PICO_BOARD
#define PICO
#endif

/* PSX Interface Pinout */
#ifdef PICO
	#define PIN_DAT 5
	#define PIN_CMD PIN_DAT + 1		// must be immediately after PIN_DAT
	#define PIN_SEL PIN_CMD + 1		// must be immediately after PIN_CMD
	#define PIN_CLK PIN_SEL + 1		// must be immediately after PIN_SEL
	#define PIN_ACK 9
#endif

#ifdef WAVESHARE_RP2040_ZERO
	#define PIN_DAT 9
	#define PIN_CMD PIN_DAT + 1		// must be immediately after PIN_DAT
	#define PIN_SEL PIN_CMD + 1		// must be immediately after PIN_CMD
	#define PIN_CLK PIN_SEL + 1		// must be immediately after PIN_SEL
	#define PIN_ACK 13
#endif

#ifdef ADAFRUIT_QTPY_RP2040
    #define PIN_CLK 2
    #define PIN_SEL PIN_CLK + 1	   // must be immediately after PIN_CLK
    #define PIN_CMD PIN_SEL + 1    // must be immediately after PIN_SEL
    #define PIN_DAT PIN_CMD + 1    // must be immediately after PIN_CMD
    #define PIN_ACK 17
#endif

/* SD Card Configuration */
#define BLOCK_SIZE	512				// SD card communicate using only 512 block size for consistency
#define BAUD_RATE	5000 * 1000
#ifdef PICO
	#define PIN_MISO	16
	#define PIN_MOSI	19
	#define PIN_SCK		18
	#define PIN_SS		17
#endif

#ifdef WAVESHARE_RP2040_ZERO
	#define PIN_MISO	0
	#define PIN_MOSI	3
	#define PIN_SCK		2
	#define PIN_SS		1
#endif

#ifdef ADAFRUIT_QTPY_RP2040
	#define PIN_MISO	9
	#define PIN_MOSI	10
	#define PIN_SCK		8
	#define PIN_SS		7
#endif

#endif
