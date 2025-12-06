

# Single Board Computer for 6502 Microprocessors (SBC6502)

## <sub>[Overview](README_Overview.md) &nbsp;&nbsp;</sub> <sub>[Hardware](README_SBC6502.md)</sub> &nbsp;&nbsp; [Virtual Memory Kernel](README_VMK.md)

<!--- MARKUP.INSERT.TEXT.START: ID=SBC6502.Header -->
***A lifelong learning experience ...***

---
<!--- MARKUP.INSERT.TEXT.STOP: ID=SBC6502.Header -->

<!--- MARKUP.MARK.TEXT.START: ID=VMK.Reqs -->

Requirements for the Virtual Memory Kernel (VMK) are:

*   Multi-Tasking – More than one active process in memory at a time.

*   Preemptive Tasking – Processes are blocked to allow other processes access to computer resources.

*   Kernel Mode – Processes may run in an unprotected mode allowing access to all computing resources.

*   User Mode – Processes may run in protected mode protecting computing resources from other processes.

*   Virtual Memory – Each process sees a continuous 64KB memory environment.

<!--- MARKUP.MARK.TEXT.STOP: ID=VMK.Reqs -->
