

# Single Board Computer for 6502 Microprocessors (SBC6502)

## [Overview](README_Overview.md) &nbsp;&nbsp; <sub>[SBC6502 Hardware](README_SBC6502.md)</sub> &nbsp;&nbsp; <sub>[Virtual Memory Kernel (VMK)](README_VMK.md)</sub>

<!--- MARKUP.INSERT.TEXT.START: ID=SBC6502.Header -->
***A lifelong learning experience ...***

---
<!--- MARKUP.INSERT.TEXT.STOP: ID=SBC6502.Header -->

<!--- MARKUP.MARK.TEXT.START: ID=SBC6502.Teaser -->

The *Single Board Computer for 6502 Microprocessors* * is my amateur project to explore and understand the computer-science around multi-tasking operating systems and virtual memory hardware.  The 6502 processor was chosen for its software and hardware simplicity (and challenges.)  And as a nod to the KIM-1 used in an undergraduate project assignment.  All design decisions lean towards simplicity and implementing the minimum needed to study the stated topics using small to medium scale integration (7400 series logic).

> *Click bait - after thinking about the goals of this project, I scraped the idea (at this time) of a single board computer.  I may want to swap out the virtual memory hardware to try out different solutions, for example.  And the projected chip count of the memory management logic necessitates the use of a computer backplane design with modular logic cards.  A backplane allows the replacement of logic sections until the final design is hammered out.  Although “SBC6502” is a misnomer, it will continue to be used as the project name (and GitHub repo name.)

<!--- MARKUP.MARK.TEXT.STOP: ID=SBC6502.Teaser -->

Ultimately this is both a hardware and software project.  Yes, hardware is needed to map the 6502’s physical 16-bit address space into a 24-bit virtual memory address space.  But software is required to manage and monitor virtual memory as processes are executed by the 6502 microprocessor. 

The Memory Management Unit (MMU) provides architectural enhancements to the 6502 that the Virtual Memory Kernel (VMK) relies on to meet its required goals.    VMK requirements are listed here to remind me of the what the MMU must support in the end.  [VMK6502](https://github.com/craigory1958/VMK6502.git) is a separate GitHub project supporting the development of the Virtual Memory Kernel.


<!--- MARKUP.INSERT.TEXT.START: ID=VMK.Reqs -->
Requirements for the Virtual Memory Kernel (VMK) are:

*   Multi-Tasking – More than one active process in memory at a time.

*   Preemptive Tasking – Processes are blocked to allow other processes access to computer resources.

*   Kernel/User Mode – Certain system resources are protected from processes running in user mode.

*   Virtual Memory – Each process sees a continuous 64KB memory environment.
<!--- MARKUP.INSERT.TEXT.STOP: ID=VMK.Reqs -->

<!--- MARKUP.INSERT.TEXT.START: ID=MMU.Reqs -->
Requirements for the Memory Management Unit (MMU) are:

*   A configurable MMU allowing variable address bus widths and page sizes.

*   Up to a 24-bit 4294MB address space shared by RAM, ROM and memory mapped I/O.

*   Page sizes vary from 512 bytes thru 4KB.

*   Support for Kernel/User modes.

*   Support for a boot mode.

*   All primary control logic will be implemented with 7400 series ICs.
<!--- MARKUP.INSERT.TEXT.STOP: ID=MMU.Reqs -->

Other general goals and requirements:

* All control logic will be implemented with Small Scale Integration (SSI) 7400 series ICs.  (We will not be using the 74610, 611, 612 or 631 ICs.)

* However, LSI devices (and Arduinos) may be used for complex functions such as video, mass storage and serial communication.
