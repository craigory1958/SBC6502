

#include <Mega2560.h>
#include <PortIO.h>
#include "MMU.h"


//
// 6502 Microprocessor (uP) GPIO/Pin assignments
//

/*  ---Mega2560----       --6502--  */
/*                                  */
/*  PIN   ARD  GPIO       LBL  PIN  */
/*   52   D52   PB1       CLK0  37  */  #define   uP_CLK0   D52
/*    2   ~D2   PE4       CLK0  37  */  #define   uP_CLK0_  D2
/*    3   ~D3   PE5       CLK2  39  */  #define   uP_CLK2   D3
/*   50   D50   PB3       ~IRQ   4  */  #define   uP_IRQ    D50
/*   51   D51   PB2       ~NMI   6  */  #define   uP_NMI    D51
/*   38   D38   PD7       ~RST  40  */  #define   uP_RESET  D38
/*   39   D39   PG2       RDY    2  */  #define   uP_RDY    D39
/*   40   D40   PG1       R/~W  34  */  #define   uP_RW     D40
/*   41   D41   PG0       ~SO   38  */  #define   uP_SOB    D41
/*    4   ~D4   PG5       SYNC   7  */  #define   uP_SYNC   D4

//  Pin   ARD  GPIO       LBL  Pin
/*   22   D22   PA0       A0     9  */  #define   uP_ADDR_L   PA
/*   23   D23   PA1       A1    10  */
/*   24   D24   PA2       A2    11  */
/*   25   D25   PA3       A3    12  */
/*   26   D26   PA4       A4    13  */
/*   27   D27   PA5       A5    14  */
/*   28   D28   PA6       A6    15  */
/*   29   D29   PA7       A7    16  */

//  Pin   ARD  GPIO       LBL  Pin
/*   37   D37   PC0       A8    17  */  #define   uP_ADDR_H   PC
/*   36   D36   PC1       A9    18  */
/*   35   D35   PC2       A10   19  */
/*   34   D34   PC3       A11   20  */
/*   33   D33   PC4       A12   22  */
/*   32   D32   PC5       A13   23  */
/*   31   D31   PC6       A14   24  */
/*   30   D30   PC7       A15   25  */

//  Pin   ARD  GPIO       LBL  Pin
/*   49   D49   PL0       D0    33  */  #define   uP_DATA     PL
/*   48   D48   PL1       D1    32  */
/*   47   D47   PL2       D2    31  */
/*   46  ~D46   PL3       D3    30  */
/*   45  ~D45   PL4       D4    29  */
/*   44  ~D44   PL5       D5    28  */
/*   43   D43   PL6       D6    27  */
/*   42   D42   PL7       D7    26  */

#define   uP_ADDR()   ( (unsigned int) (pio__PortToPORT(PC) << 8 | pio__PortToPORT(PA)) )


bool RW ;
bool SYNC ;
word ADDR ;
byte DATA ;

void setup() {

    // pio_setPinAsInput_wPullup(uP_CLK0) ;
    pio_attachInterruptToPin(uP_CLK2, RISING, uP_CLK2_Rising) ;
    pio_attachInterruptToPin(uP_CLK2, FALLING, uP_CLK2_Falling) ;

    pio_setPortIO(uP_ADDR_L, pio_PortDirIn) ;
    pio_setPortIO(uP_ADDR_H, pio_PortDirIn) ;

    debug() ;
}


void loop() {}



//
// uP control and ADDR pins are ready and stable
//
//    * Read control and ADDR pins
//    * Compute effective address
//    * Set DATA bus I/O direction
//
void uP_CLK2_Rising() {

    ADDR = uP_ADDR() ;
    SYNC = pio_readPin(uP_SYNC) ;
    RW = pio_readPin(uP_RW) ;

    mmu_mapEffectiveAddress(SYNC, RW, ADDR) ;

    if ( RW ) {   // Pin HIGH, uP will read byte from DATA bus

        DATA = mmu_readByteFromMemory() ;

        pio_setPortIO(uP_DATA, pio_PortDirOut) ;   // Set DATA bus for output from Arduino
        pio_writePort(uP_DATA, DATA) ;   // Write to DATA bus (data will be read by uP on falling edge)

    } else {    // Pin LOW, uP writes byte to bus
        pio_setPortIO(uP_DATA, pio_PortDirIn) ;   // Set DATA bus for input into Arduino
    }
}


//
// uP DATA pins are ready and stable
//    * if uP write, read DATA bus
//
void uP_CLK2_Falling() {

    if ( RW ) {   // Pin HIGH, uP reading byte from bus (do nothing, DATA bus was setup on rising edge))

    } else {    // Pin LOW, uP writing to bus  
        DATA = pio_readPort(uP_DATA) ;   // Read from DATA bus
        mmu_writeByteToMemory(DATA) ;
    }
}

//
//
//
void debug() {

    serial_begin(115200) ; 
    Serial.println("\n\n\n\n\n\n\n\n\n\n\n\n");


    // 4 PID Bits, 5 Segment Bits, 8 Offset Bits, 23 EA Bits
    mmu_cr0 = 0x58;    
    mmu_cr1 = 0x97;    
    Serial.println("\n 4 PID Bits, 5 Segment Bits, 8 Offset Bits, 23 EA Bits");
    printf("pidMask:   0x%04X \n", mmu_PIDMask(mmu_cr1));
    printf("offMask:   0x%04X \n", mmu_offMask(mmu_cr0));
    printf("segMask:   0x%04X \n", mmu_segMask(mmu_cr0));
    printf(" eaMask: 0x%06lX \n", mmu_EAMask(mmu_cr1));


    // Boot Mode
    Serial.println("\n Boot Mode");

    mmu_r0 = 0x00;

    SYNC = 0 ;
    RW = 1 ;

    ADDR = 0x00FF ;
    mmu_mapEffectiveAddress(SYNC, RW, ADDR) ;
    printf("\nSYNC:  0x%X,  RW: 0x%X,  ADDR: 0x%04X \n", SYNC, RW, ADDR);
    mmu_dump();

    ADDR = 0xE804 ;
    mmu_mapEffectiveAddress(SYNC, RW, ADDR) ;
    printf("\nSYNC:  0x%X,  RW: 0x%X,  ADDR: 0x%04X \n", SYNC, RW, ADDR);
    mmu_dump();

    ADDR = 0xFCDD ;
    mmu_mapEffectiveAddress(SYNC, RW, ADDR) ;
    printf("\nSYNC:  0x%X,  RW: 0x%X,  ADDR: 0x%04X \n", SYNC, RW, ADDR);
    mmu_dump();
 
    ADDR = 0xE800 ;
    mmu_mapEffectiveAddress(SYNC, RW, ADDR) ;
    printf("\nSYNC:  0x%X,  RW: 0x%X,  ADDR: 0x%04X \n", SYNC, RW, ADDR);
    mmu_dump();

    ADDR = 0xEEEE ;
    mmu_mapEffectiveAddress(SYNC, RW, ADDR) ;
    printf("\nSYNC:  0x%X,  RW: 0x%X,  ADDR: 0x%04X \n", SYNC, RW, ADDR);
    mmu_dump();


    // Kernal Mode
    Serial.println("\n Kernal Mode");

    SYNC = 0 ;
    RW = 1 ;

    mmu_r0 = 0x80;

    mmu_VECTORS[0] = 0x00;
    mmu_VECTORS[1] = 0x00;
    mmu_VECTORS[2] = 0xF8;
    mmu_VECTORS[3] = 0xCC;
    
    ADDR = 0x00FF ;
    mmu_mapEffectiveAddress(SYNC, RW, ADDR) ;
    printf("\nSYNC:  0x%X,  RW: 0x%X,  ADDR: 0x%04X \n", SYNC, RW, ADDR);
    mmu_dump();
    
    ADDR = 0x01FF ;
    mmu_mapEffectiveAddress(SYNC, RW, ADDR) ;
    printf("\nSYNC:  0x%X,  RW: 0x%X,  ADDR: 0x%04X \n", SYNC, RW, ADDR);
    mmu_dump();


    // User Mode
    Serial.println("\n User Mode");

    SYNC = 0 ;
    RW = 1 ;

    mmu_r0 = 0xC1;

    mmu_VECTORS[0] = 0x00;
    mmu_VECTORS[1] = 0x00;
    mmu_VECTORS[2] = 0xEE;
    mmu_VECTORS[3] = 0xDD;
    
    ADDR = 0x0FD0 ;
    mmu_mapEffectiveAddress(SYNC, RW, ADDR) ;
    printf("\nSYNC: 0x%X,  RW: 0x%X,  ADDR: 0x%04X \n", SYNC, RW, ADDR);
    mmu_dump();
}
