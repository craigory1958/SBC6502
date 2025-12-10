

# Single Board Computer for 6502 Microprocessors (SBC6502)

## <sub>[Overview](README_Overview.md) &nbsp;&nbsp;</sub> [SBC6502 Hardware](README_SBC6502.md) &nbsp;&nbsp; <sub>[Virtual Memory Kernel (VMK)](README_VMK.md)</sub>

## <sub>[Bus/Backplane](README_SBC6502_Backplane.md)</sub> &nbsp;&nbsp; <sub>[Processor/Memory Managment Unit (MMU)](README_SBC6502_MemoryManagmentUnit.md)</sub> &nbsp;&nbsp; <sub>[Memory Map](README_SBC6502_MemoryMap.md)</sub>

<!--- MARKUP.INSERT.TEXT.START: ID=SBC6502.Header -->
***A lifelong learning experience ...***

---
<!--- MARKUP.INSERT.TEXT.STOP: ID=SBC6502.Header -->

The 6502 is an 8-bit processor from the 70's with a 16-bit 65KB memory model. The address space is proportioned off for the Zero Page (256 bytes), Stack (256 bytes) and interrupt vectors (6 bytes) and uses memory mapped I/O. The goal of this project is to develop the hardware to support a full fledge preemptive multi-tasking kernel that presents each process with the full 6502 64KB address space.

Why a 6502 and not a more modern, more powerful microprocessor?  I want to study the hardware (and software) requirements of providing a modern computer system. I also have fond memories of owning a KIM-1 and using it in my undergraduate studies. The 6502 is my favorite microprocessor.

Rather than trying to develop a single large PCB board implementing all functions of the SBC6502 computer, a backplane will be used. Functions of the SBC6502 such as MMU, ROM/RAM, and I/O can be debugged independently as modular logic boards slotted into the backplane.