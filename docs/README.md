

# Single Board Computer for 6502 Microprocessors (SBC6502)

## <sub>[Overview](README_Overview.md) &nbsp;&nbsp;</sub> <sub>[SBC6502 Hardware](README_SBC6502.md)</sub> &nbsp;&nbsp; <sub>[Virtual Memory Kernel (VMK)](README_VMK.md)</sub>

<!--- MARKUP.MARK.TEXT.START: ID=SBC6502.Header -->
***A lifelong learning experience ...***

---
<!--- MARKUP.MARK.TEXT.STOP: ID=SBC6502.Header -->

<!--- MARKUP.INSERT.TEXT.START: ID=SBC6502.Teaser -->
The *Single Board Computer for 6502 Microprocessors*\* is my amateur project to explore and understand the computer-science around multi-tasking operating systems and virtual memory hardware.  The 6502 processor was chosen for its software and hardware simplicity (and challenges.)  And as a nod to the KIM-1 I used in an undergraduate project assignment.  All design decisions lean towards simplicity and implementing the minimum needed to study the stated topics using only small to medium scale integration ICs (7400 series logic).

> \* Click bait - after thinking about the goals of this project, I scraped the idea (at this time) of a single board computer.  I may want to swap out the virtual memory hardware to try out different solutions, for example.  And the projected chip count of the memory management logic necessitates the use of a computer backplane design with modular logic cards.  A backplane allows the replacement of isolated logic sections until a final design is hammered out.  Although single board computer is a misnomer,  “SBC6502” will continue to be used as the project name (and GitHub repo name.)
<!--- MARKUP.INSERT.TEXT.STOP: ID=SBC6502.Teaser -->

---

# RetroShield 6502

A [*RetroShield 6502*](https://github.com/craigory1958/RetroShield-6502.git) is used to develop and debug software and hardware sniplets.  For example, the setup below is an experiment to test if toggling the RDY line could be used to single-step the 6502.  (It looks promising.)

<img src="_assets/images/RetroShield 6502.jpg">
