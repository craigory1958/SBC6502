

# Single Board Computer for 6502 Microprocessors (SBC6502)

## <sub>[Overview](README_Overview.md) &nbsp;&nbsp;</sub> [SBC6502 Hardware](README_SBC6502.md) &nbsp;&nbsp; <sub>[Virtual Memory Kernel (VMK)](README_VMK.md)</sub>

## <sub>[Bus/Backplane](README_SBC6502_Backplane.md)</sub> &nbsp;&nbsp; [Processor/Memory Managment Unit (MMU)](README_SBC6502_MemoryManagmentUnit.md) &nbsp;&nbsp; <sub>[Memory (ROM/RAM)](README_SBC6502_Memory.md)</sub> &nbsp;&nbsp; <sub>[I/O](README_SBC6502_IO.md)</sub>

*A lifelong learning experience ...*

The requirement for the Memory Management Unit (MMU) are:
<!--- MARKUP.MARK.TEXT.START: ID=MMU.Reqs -->

•   Multi-Tasking – More than one active process in memory at a time.

•   Preemptive Tasking – Processes are blocked to allow other processes access to computer resources.

•   Kernel Mode – Processes may run in an unprotected mode allowing access to all computing resources.

•   User Mode – Processes may run in protected mode protecting computing resources from other processes.

•   Virtual Memory – Each process sees a continuous 64KB memory environment.
<!--- MARKUP.MARK.TEXT.STOP: ID=MMU.Reqs -->


The MMU’s Configuration Registers (CR0 & CR1) are programmable at boot time and determine how the MMU will function.

The MMU has 2 memory-mapped configuration registers that control:

* The number of effective memory bits; the total address space of the SBC6502
* The number of bits in a Process ID (PID)
* The size of each memory page
* The number of process bits used to address a page segment

The MMU provides a protected Kernal Mode by intercepting the BRK and RTI instructions. 
