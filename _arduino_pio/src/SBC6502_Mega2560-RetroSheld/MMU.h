//
//
//  R0 - Mode Register (0x0200)
//
//  ┌─┬─┬───────────┐
//  │7 6 5 4 3 2 1 0│
//  └┬┴┬┴─────┬─────┘
//   │ │      └───────┤ PID (1-6 bits) 
//   │ │              
//   │ └──────────────┤ ~Kernal Mode (0 is enabled) / User Mode (1 is enabled)
//   │                
//   └────────────────┤ ~Boot Mode (0 is enabled) / Address Translate Mode (1 is enanled)
//                    
//       
//
//  R1 - Status Register (0x0201)
//
//  ┌─┬─┬─┬─┬─┬─┬─┬─┐
//  │7 6 5 4 3 2 1 0│
//  └┬┴┬┴┬┴┬┴┬┴┬┴┬┴┬┘
//   │ │ │ │ │ │ │ └──┤ Boot Address Error
//
//
//
//  CR0 - Config Register 0 (0x0202)
//
//  ┌───────┬───────┐
//  │7 6 5 4 3 2 1 0│
//  └───┬───┴───┬───┘
//      │       └─────┤ # Page Offset Bits (0-15 bits)
//      │             
//      └─────────────┤ # Page Segment Bits (0-15 bits)
//                    
//
//
//  CR1 - Config Register 1 (0x0203)
//
//  ┌───────────────┐
//  │7 6 5 4 3 2 1 0│
//  └──┬──┴────┬────┘
//     │       └──────┤ # Effective Address Bits (0-31 bits)
//     │             
//     └──────────────┤ # PID Bits (0-6 bits)
//                   
//
//
//  MVR(s) - Memory Vector Register(s)  (0xFFFF - 0xFFFF)
//
//                  ┌───────────────┐
//                  │7 6 5 4 3 2 1 0│─┤ MVRlow (0xFFEE)
//                  └───────────────┘
//                  .               .
//  ┌───────────────┐               .
//  │7 6 5 4 3 2 1 0│─────────────────┤ MVRhigh (0xFFEF)
//  └───────────────┘               .
//  .               .               .
//  ┌─┬─┬─┬─────────────────────────┐
//  │5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0│
//  └┬┴┬┴┬┴────────────┬────────────┘
//   │ │ │             └──────────────┤ Upper Effective Address Bits (0-13 bits)
//   │ │ │                   
//   │ │ └────────────────────────────┤ Vector Active
//   │ │                 
//   │ └──────────────────────────────┤ Write Enable
//   │
//   └────────────────────────────────┤ Page Dirty
//                   
//
//
//  MVP - Memory Vector Pointer
//
//  ┌───────┬───────────────────────┐
//  │5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0│
//  └───────┴───────────┬───────────┘
//


#include <Arduino.h>


//
// RAM (1KB)
//

#define   mmu_RAM_START       0x00000
#define   mmu_RAM_END         0x003FF

#define   mmu_RAM_START_      0x0000
#define   mmu_RAM_END_        0x03FF

byte mmu_ram[mmu_RAM_END - mmu_RAM_START +1] ;


//
// MMU (1KB)
//

// Control Register (R0)

#define   mmu_R0              0xEF800
#define   mmu_R0_             0xE800

byte mmu_r0 ;

#define   mmu_boot(r0)        ( (r0 & BIT7) >> 7 )
#define   mmu_kernal(r0)      ( (r0 & BIT6) >> 6 )
#define   mmu_PID(r0, r3)     ( r0 & mmu_PIDMask(r3) )


// Status Register (R1)

#define   mmu_R1              0xEF801
#define   mmu_R1_             0xE801

byte mmu_r1 ;   

#define   mmu_R1_BootAddressRangeError   BIT0


// Config Register (CR0)

#define   mmu_CR0             0xEF802
#define   mmu_CR0_            0xE802

byte mmu_cr0 ;   

#define   mmu_numSegBits(cr0) ( (cr0 & BitMask(7, 4)) >> 4 )
#define   mmu_numOffBits(cr0) (  cr0 & BitMask(3, 0)       )

#define   mmu_offMask(cr0)    ( BitMask(mmu_numOffBits(cr0) -1, 0) )
#define   mmu_segMask(cr0)    ( BitMask(mmu_numSegBits(cr0) + mmu_numOffBits(cr0) -1, mmu_numOffBits(cr0)) )


// Config Register (CR1)

#define   mmu_CR1              0xEF803
#define   mmu_CR1_             0xE803

byte mmu_cr1 ;   

#define   mmu_numPIDBits(cr1) ( (cr1 & BitMask(7, 5)) >> 5 )
#define   mmu_numEABits(cr1)  (  cr1 & BitMask(4, 0)       )

#define   mmu_PIDMask(cr1)    ( BitMask(mmu_numPIDBits(cr1) -1, 0) )
#define   mmu_EAMask(cr1)     ( BigBitMask(mmu_numEABits(cr1) -1, 0) )


// MMU Vectors (1KB -4)

#define   mmu_VECTORS_START   0xEF804
#define   mmu_VECTORS_END     0xEFBFF

#define   mmu_VECTORS_START_  0xE804
#define   mmu_VECTORS_END_    0xEBFF

byte mmu_VECTORS[mmu_VECTORS_END - mmu_VECTORS_START +1 -2] ;


//
// ROM (1KB)
//

#define   mmu_ROM_START       0xFFC00
#define   mmu_ROM_END         0xFFFFF

#define   mmu_ROM_START_      0xFC00
#define   mmu_ROM_END_        0xFFFF

byte mmu_rom[] = {
#include "SBC6502_ROM.h"
};






#define   BREAK               0x00


uint32_t mmu_ea;
uint32_t mmu_off;
uint32_t mmu_seg;
uint32_t mmu_tag;


void mmu_mapEffectiveAddress(bool sync, bool rw, word addr) {

  mmu_r1 = 0;
  mmu_ea = 0;
  mmu_off = 0;
  mmu_seg = 0;
  mmu_tag = 0;

  if ( !mmu_boot(mmu_r0) ) {

    if ( addr >= mmu_RAM_START_ && addr <= mmu_RAM_END_ ) {
      mmu_ea = mmu_RAM_START + addr - mmu_RAM_START_;
      return;
    }

    if ( addr >= mmu_R0_ && addr <= mmu_VECTORS_END_ ) {
      mmu_ea = mmu_R0 + addr - mmu_R0_;
      return;
    }

    if ( addr >= mmu_ROM_START_ && addr <= mmu_ROM_END_ ) {
      mmu_ea = mmu_ROM_START + addr - mmu_ROM_START_;
      return;
    }

    // Boot mode address out of range
    mmu_r1 |= mmu_R1_BootAddressRangeError ;
    return ;
  }

  mmu_off = addr & mmu_offMask(mmu_cr0) ;
  mmu_seg = (addr & mmu_segMask(mmu_cr0)) >> mmu_numOffBits(mmu_cr0) ;
  mmu_tag = ((mmu_PID(mmu_r0, mmu_cr1) << mmu_numSegBits(mmu_cr0)) | mmu_seg) << 1 ;
  
  mmu_ea = (((uint32_t)mmu_VECTORS[mmu_tag] << (mmu_numOffBits(mmu_cr0) +8)) |((uint32_t)mmu_VECTORS[mmu_tag +1] << mmu_numOffBits(mmu_cr0)) | mmu_off) & mmu_EAMask(mmu_cr1) ;
}


byte mmu_readByteFromMemory() {

  if ( !mmu_r1 )
    return BREAK;
}


void mmu_writeByteToMemory(byte data) {}


void mmu_dump(){

    printf("  R0:  0x%02X,    Boot: 0x%X,  Kernal: 0x%X,    PID: 0x%02X \n",
       mmu_r0, mmu_boot(mmu_r0), mmu_kernal(mmu_r0),     mmu_PID(mmu_r0, mmu_r1));
    printf("  R1:  0x%02X \n", mmu_r1) ;

    printf(" CR0:  0x%02X,  #segBits: %d,  #offBits: %d \n",
       mmu_cr0, mmu_numSegBits(mmu_cr0), mmu_numOffBits(mmu_cr0));
    printf(" CR1:  0x%02X,  #pidBits: %d,  #eaBits: %d \n",
       mmu_cr1, mmu_numPIDBits(mmu_cr1), mmu_numEABits(mmu_cr1));

    printf(" seg:  0x%05lX \n", mmu_seg);
    printf(" off:  0x%05lX \n", mmu_off);
    printf(" tag:  0x%05lX   0x%X  0x%X \n", mmu_tag, mmu_VECTORS[mmu_tag], mmu_VECTORS[mmu_tag +1]);
    printf("  EA: 0x%06lX \n", mmu_ea);
}
