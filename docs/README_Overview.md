

# Single Board Computer for 6502 Microprocessors (SBC6502)

## [Overview](README_Overview.md) &nbsp;&nbsp; <sub>[SBC6502 Hardware](README_SBC6502.md)</sub> &nbsp;&nbsp; <sub>[Virtual Memory Kernel (VMK)](README_VMK.md)</sub>

*A lifelong learning experience ...*

<br/>

The *Single Board Computer for 6502 Microprocessors* is my amateur project to explore and understand the computer-science around multi-tasking operating systems and virtual memory hardware.  The 6502 processor was chosen for its software and hardware simplicity.  And as a nod to the KIM-1 used in an undergraduate term assignment.  All design decisions lean towards simplicity and implementing minimum needed to research the stated topics using small to medium scale integration (7400 series logic).

### Virtual Memory Kernel (VNK)

•   Multi-Tasking – More than one active process in memory at a time.

•   Preemptive Tasking – Processes are blocked to allow other processes access to computer resources.

•   Kernel Mode – Processes may run in an unprotected mode allowing access to all computing resources.

•   User Mode – Processes may run in protected mode protecting computing resources from other processes.

•   Virtual Memory – Each process sees a continuous 64KB memory environment.


### Memory Management Unit (MMU)

•   A configurable MMU allowing variable address bus widths and page sizes.

•   Up to a 32-bit 4294MB address space divided into RAM, ROM and memory mapped I/O.

•   Page sizes varying from 512 bytes thru 4KB.

•   All primary control logic (MMU, memory decoding, etc.) will be implemented with 7400 series ICs.

•   Arduinos may be used to implement complex I/O devices such as video, mass storage and serial communication.
