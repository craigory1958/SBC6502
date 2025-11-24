# Single Board Computer for 6502 Microprocessors (SBC6502)

## <sub>[Overview](README_Overview.md) &nbsp;&nbsp;</sub> <sub>[SBC6502 Hardware](README_SBC6502Hardware.md)</sub> &nbsp;&nbsp; <sub>[Virtual Memory Kernel](README_VirtualMemoryKernel.md)</sub>


*A lifelong learning experience ...*

The Single Board Computer for 6502 is an amateur project to explore and understand the computer-science around multi-tasking operating systems and virtual memory hardware.  The 6502 processor was chosen for its software and hardware simplicity.  And as a nod to the KIM-1 used in my undergraduate work.  All design decisions lean towards simplicity and implementing minimum needed to research the stated topics using small to medium scale integration (7400 series logic).

## Virtual Memory Kernel and Memory Management Unit

The Virtual Memory Kernel (VMK) and Memory Management Unit (MMU) will support:

•   Multi-Tasking – More than one active process in memory at a time.

•   Preemptive Tasking – Processes are blocked to allow other processes access to computer resources.

•   Kernel Mode – Processes may run in an unprotected mode allowing access to all computing resources.

•   User Mode – Processes may run in protected mode protecting computing resources from other processes.

•   Virtual Memory – Each process sees a continuous virtual 64KB memory environment.

The Single Board Computer for 6502 (SBC6502) will have the following characteristics:

•   A configurable MMU allowing variable address bus with and page sizes.

•   Up to a 32-bit 4294MB address space divided into RAM, ROM and memory mapped I/O.

•   Page sizes vary from 512 bytes thru 4KB.

•   All primary control logic (MMU, memory decoding, etc.) will be implemented with 7400 series ICs.

•   Arduinos may be used to implement complex I/O devices such as video, mass storage and serial communication.
