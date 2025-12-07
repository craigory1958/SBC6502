

# Single Board Computer for 6502 Microprocessors (SBC6502)

## <sub>[Overview](README_Overview.md) &nbsp;&nbsp;</sub> [SBC6502 Hardware](README_SBC6502.md) &nbsp;&nbsp; <sub>[Virtual Memory Kernel (VMK)](README_VMK.md)</sub>

## [Bus/Backplane](README_SBC6502_Backplane.md) &nbsp;&nbsp; <sub>[Processor/Memory Managment Unit (MMU)](README_SBC6502_MemoryManagmentUnit.md)</sub> &nbsp;&nbsp; <sub>[Memory (ROM/RAM)](README_SBC6502_Memory.md)</sub> &nbsp;&nbsp; <sub>[I/O](README_SBC6502_IO.md)</sub>

<!--- MARKUP.INSERT.TEXT.START: ID=SBC6502.Header -->
***A lifelong learning experience ...***

---
<!--- MARKUP.INSERT.TEXT.STOP: ID=SBC6502.Header -->

Because of the projected number of ICs needed and the difficulty of developing a single monolithic PCB, an organization of modular logic cards plugged into a backplane was chosen. Modularity allows the development and debugging of sub-functions, like memory or clock circuitry without having to re-produce a monolithic PCB.

The RCBus standard developed by [Small Computer Central](https://smallcomputercentral.com/) for homebrew 8-bit retro computing provides a turnkey backplane that will work for this project.  They offer 6 slot backplane kit [SC701 Backplane Kit for RCBus](https://www.tindie.com/products/tindiescx/sc701-backplane-kit-for-rcbus-80pin/).  The RCBus specification was developed for Z80 based microprocessors. It is basically an 80-line bus, some lines will be repurposed for a 6502 based project.  Some lines will not be used.  The only short fall of renaming some of the bus lines is that they will be misnamed on the backplane’s silkscreen.

<img src="_assets/images/sc701-assembled-c-w600.jpg">

| Header 1 | Header 2 | Header 3 |
|---|---|---|
| Row 1 Col 1 | Row 1 Col 2 | Row 1 Col 3 |
| Row 2 Col 1 | Row 2 Col 2 | Row 2 Col 3 |