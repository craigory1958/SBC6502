

# Single Board Computer for 6502 Microprocessors (SBC6502)

## <sub>[Overview](README_Overview.md) &nbsp;&nbsp;</sub> [SBC6502 Hardware](README_SBC6502.md) &nbsp;&nbsp; <sub>[Virtual Memory Kernel (VMK)](README_VMK.md)</sub>

## <sub>[Bus/Backplane](README_SBC6502_Backplane.md)</sub> &nbsp;&nbsp; <sub>[Processor/Memory Managment Unit (MMU)](README_SBC6502_MemoryManagmentUnit.md)</sub> &nbsp;&nbsp; [Memory Map](README_SBC6502_MemoryMa[].md)
<!--- MARKUP.INSERT.TEXT.START: ID=SBC6502.Header -->
***A lifelong learning experience ...***

---
<!--- MARKUP.INSERT.TEXT.STOP: ID=SBC6502.Header -->

```
           ┌───────────────┐
    0x0000 │               │
           │               │
           │     44 KB     │ 
           │      RAM      │
           │               │
           │               │ 0xA9FF
           ├───────────────┤ 
    0xB000 │               │ 
           │     16 KB     │ 
           │    MMU I/O    │
           │               │ 0xEFFF
           ├───────────────┤
    0xF000 │      4 KB     │ 
           │    VMK ROM    │ 0xFFFF
           └───────────────┘ 
```



```
           ┌───────────────┐
  0x000000 │               │
           │               │
           │    920 KB     │ 
           │      RAM      │
           │               │
           │               │ 0x0FBFFF
           ├───────────────┤
  0x0FC000 │     16 KB     │ 
           │    MMU I/O    │ 0x0EFFFF
           ├───────────────┤
  0x0F0000 │               │ 
           │     32 KB     │ 
           │      ROM      │
           │               │ 0x0F7FFF
           ├───────────────┤
  0x0F8000 │               │ 
           │     32 KB     │ 
           │      ROM      │
           │               │ 0x0FFFFF
           └───────────────┘ 
```
