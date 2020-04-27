

**DMA1**
```
Purpose: Transfer ADC to DAC directly.
From:   @ADRESH     0x03EB  (Auto-triggered with ADIF)
To:     @DAC1DATL   0x007D  (Stops when CNT=1)
```

**DMA2**
```
Purpose: Transfer ADC to GPR bank (ping/pong)
From:   @ADRESH     0x03EB  (Auto-triggered with ADIF)
To:     @gpr_bank11 0x0B00  (Stops when CNT=1, Increments DPTR)

Notes:
SSZ = 1 and DSZ = 512 (2 banks for ping and pong).
TMR0 interrupt callback fires every 256 transfers to kick in DMA transfer
to buffer RAM.
```

**DMA3**
```
Purpose: Transfer SPIRX to DAC
From:   @SPI1RXB    0x0080  (Auto-triggered with TMR0)
To:     @DAC1DATL   0x007D  (Stops when CNT=1)

Notes:
SSZ = 256 (1 bank of data from Ext Mem via SPI1RXB SFR)
DSZ = 1 (DAC1DATL SFR)
```

**DMA4**
```
Purpose: Transfer GPR bank (ping/pong) to SPITX
From:   @gpr_bank11 0x0B00  (SIRQ=SPI1TX, Increments SPTR, Set SPI.RXR=0 and SPI1TCNT=256)
To:     @SPI1TXB    0x0081  (Stops when CNT=1)

Notes:
SSZ = 256 (1 bank for ping OR pong)
DSZ = 1 (SPI1TXB SFR)
SSA = @gpr11_ping 0x0B00 or @gpr12_pong 0x0C00
SSA needs to be updated after every block of DMA transfer.
```

**DMA5**
```
Purpose: Transfer GPR bank (ping/pong) to GPR bank (buffer RAM)
From:   @gpr_bank11 0x0B00  (Manual start, Increments SPTR)
To:     @gpr_bank37 0x2500  (Stops when DCNT=1, Increments DPTR)

Notes: 
SSZ = 512 (2 banks for ping and pong)
DSZ = 256 (1 bank for buffer RAM)
DGO is set in software manually and clears when DCNT rolls over (ping transfer).
DGO is set again in software, SPTR continues from where left off. DGO clears
when DCNT rolls over (pong transfer).
```

**DMA6**
```
Purpose: Transfer PFM page to DAC
From:   @pfm        0x4000  (Manual start, SIRQ=TMR0, Increments SPTR)
To:     @DAC1DATL   0x007D  (Stops when CNT=1)

Notes:
This transfer is TMR0-triggered to maintain consistent sampling rate.
SSA needs to be updated before previous transaction is complete for SPTR to
roll over to the new PFM page.
```

### Notes

1. Remove "static" from FLASH_WritePage() in memory.c
2. SPI must operate in Mode 0 to communicate with SST26VF064B (external memory) in Flash 2 Click.
3. PWMOUT for audio amplifier is Open Drain.
4. DMA4 needs to be disabled before SPI kicks in because it is triggered by SPITX.