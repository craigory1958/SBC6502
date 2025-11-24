

# SBC6502 Hardware

*A lifelong learning experience ...*

## <sub>[Overview](README_Overview.md) &nbsp;&nbsp;</sub> [SBC6502 Hardware](README_SBC6502Hardware.md) &nbsp;&nbsp; <sub>[Virtual Memory Kernel](README_VirtualMemoryKernel.md)</sub>

### <sub>[Processor](README_SBC6502Hardware_Processor.md)</sub> &nbsp;&nbsp; <sub>[Memory Managment Unit (MMU)](README_SBC6502Hardware_MMU.md)</sub> &nbsp;&nbsp; &nbsp;&nbsp; <sub>[I/O](README_SBC6502HardwareIO.md)</sub>

## Virtual Memory Kernel and Memory Management Unit

The Virtual Memory Kernel (VMK) and Memory Management Unit (MMU) will support:

•   Multi-Tasking – More than one active process in memory at a time.

•   Preemptive Tasking – Processes are blocked to allow other processes access to computer resources.

•   Kernel Mode – Processes may run in an unprotected mode allowing access to all computing resources.

•   User Mode – Processes may run in protected mode protecting computing resources from other processes.

•   Virtual Memory – Each process sees a continuous 64KB memory environment.

The Single Board Computer for 6502 (SBC6502) will have the following characteristics:

•   A configurable MMU allowing variable address bus widths and page sizes.

•   Up to a 32-bit 4294MB address space divided into RAM, ROM and memory mapped I/O.

•   Page sizes varying from 512 bytes thru 4KB.

•   All primary control logic (MMU, memory decoding, etc.) will be implemented with 7400 series ICs.

•   Arduinos may be used to implement complex I/O devices such as video, mass storage and serial communication.
