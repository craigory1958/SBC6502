

# Single Board Computer for 6502 Microprocessors (SBC6502)

## <sub>[Overview](README_Overview.md) &nbsp;&nbsp;</sub> [SBC6502 Hardware](README_SBC6502.md) &nbsp;&nbsp; <sub>[Virtual Memory Kernel (VMK)](README_VMK.md)</sub>

## <sub>[Bus/Backplane](README_SBC6502_Backplane.md)</sub> &nbsp;&nbsp; [Processor/Memory Managment Unit (MMU)](README_SBC6502_MemoryManagmentUnit.md) &nbsp;&nbsp; <sub>[Memory Map](README_SBC6502_MemoryMap.md)</sub>

<!--- MARKUP.INSERT.TEXT.START: ID=SBC6502.Header -->
***A lifelong learning experience ...***

---
<!--- MARKUP.INSERT.TEXT.STOP: ID=SBC6502.Header -->

<!--- MARKUP.MARK.TEXT.START: ID=MMU.Reqs -->

Requirements for the Memory Management Unit (MMU) are:

*   A configurable MMU allowing variable address bus widths and page sizes.
*   Up to a 24-bit 16MB address space shared by RAM, ROM and memory mapped I/O.
*   Page sizes varying from 128 thru 32768 bytes.
*   Support of Kernel and User modes.
*   Support of a boot mode.
*   All control logic implemented with Small Scale Integration (SSI) 7400 series ICs.  (We will not be using the 74610, 611, 612 or 631 ICs.)  However, LSI devices (and Arduinos) may be used for complex functions such as video, mass storage and serial communication; objectives not stated within the scope of this project.

<!--- MARKUP.MARK.TEXT.STOP: ID=MMU.Reqs -->

> V1 will implement a fixed 20-bit 1MB address space, fixed 1024 byte page size, and a fixed 8K segment lookup table.


The MMU’s Configuration Registers (CR0 & CR1) are programmable at boot time and determine how the MMU will function.

The MMU has 2 memory-mapped configuration registers that control:

* The number of effective memory bits; the total address space of the SBC6502
* The number of bits in a Process ID (PID)
* The size of each memory page
* The number of process bits used to address a page segment

The MMU provides a protected Kernal Mode by intercepting the BRK and RTI instructions. 


* R0 - Mode Register (0x0200)

```
  ┌─┬─┬───────────┐
  │7 6 5 4 3 2 1 0│
  └┬┴┬┴─────┬─────┘
   │ │      └───────┤ PID (1-6 bits) 
   │ │              
   │ └──────────────┤ ~Kernel Mode (0 is enabled) / User Mode (1 is enabled)
   │                
   └────────────────┤ ~Boot Mode (0 is enabled) / Address Translate Mode (1 is enabled)
```
