

# Single Board Computer for 6502 Microprocessors (SBC6502)

## [Overview](README_Overview.md) &nbsp;&nbsp; <sub>[SBC6502 Hardware](README_SBC6502.md)</sub> &nbsp;&nbsp; <sub>[Virtual Memory Kernel (VMK)](README_VMK.md)</sub>

*A lifelong learning experience ...*

<!--- MARKUP.MARK.TEXT.START: ID=SBC6502.Teaser -->

The *Single Board Computer for 6502 Microprocessors** is my amateur project to explore and understand the computer-science around multi-tasking operating systems and virtual memory hardware.  The 6502 processor was chosen for its software and hardware simplicity (and challanges.)  And as a nod to the KIM-1 used in an undergraduate project assignment.  All design decisions lean towards simplicity and implementing the minimum needed to study the stated topics using small to medium scale integration (7400 series logic).

*Click bait - after thinking about the goals of this project, I scraped the idea (at this time) of a single board computer.  I want to swap out the virtual memory hardware trying out different designs.  And the projected chip count of the necessitates the use of a computer backplane design with inserted logic cards.  A backplane allows the replacement of modular logic sections until a final design is hammered out.  Although SBC6502 is a misnomer, it will continue to be used as the project name (and GitHub repo name.)

<!--- MARKUP.MARK.TEXT.STOP: ID=SBC6502.Teaser -->

This is both a hardware and software project.

### Virtual Memory Kernel (VMK)
<!--- MARKUP.INSERT.TEXT.START: ID=MMU.Reqs -->
•   Multi-Tasking – More than one active process in memory at a time.

•   Preemptive Tasking – Processes are blocked to allow other processes access to computer resources.

•   Kernel Mode – Processes may run in an unprotected mode allowing access to all computing resources.

•   User Mode – Processes may run in protected mode protecting computing resources from other processes.

•   Virtual Memory – Each process sees a continuous 64KB memory environment.
<!--- MARKUP.INSERT.TEXT.STOP: ID=MMU.Reqs -->


### Memory Management Unit (MMU)

•   A configurable MMU allowing variable address bus widths and page sizes.

•   Up to a 24-bit 4294MB address space shared by RAM, ROM and memory mapped I/O.

•   Page sizes vary from 512 bytes thru 4KB.

•   All primary control logic (MMU, memory decoding, etc.) will be implemented with 7400 series ICs.

•   Arduinos may be used to implement complex I/O devices such as video, mass storage and serial communication.
