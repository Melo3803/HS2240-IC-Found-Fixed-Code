# HS2240 RF Remote Signal Decoder with Arduino

This project demonstrates how to decode RF remote control signals from an HS2240 chip using an Arduino. The TXD pin of the HS2240 is tapped and analyzed to extract binary data representing button presses.

## Overview

Many cheap RF remotes use HS2240 or similar encoder chips. These chips output a **fixed 24-bit signal** via the TXD pin whenever a button is pressed. By connecting this pin to an Arduino, we can **capture and analyze** these signals.

## Hardware Required

- Arduino UNO or Nano
- HS2240-based RF remote control
- Some wires

## Wiring

| HS2240 Pin | Arduino Pin | Description              |
|------------|-------------|--------------------------|
| TXD        | D2          | Signal input from remote |


> Note: TXD is a digital output pin from HS2240 so it's safe for direct connection.

## How It Works

1. When a button is pressed on the remote, HS2240 outputs a **burst of pulses** on TXD.
2. Arduino reads these pulses and **measures pulse width** (HIGH and LOW duration).
3. The binary pattern is reconstructed based on timing.
4. The decoded bits are printed via Serial Monitor.

## Example Output

```
Captured bits: 010110100101010101100101
```

## Uploading the Code

1. Open `txd_receiver.ino` in Arduino IDE.
2. Upload to your board.
3. Open Serial Monitor at **9600 baud**.
4. Press a button on your remote for once – decoded signal will appear. // Do not hold button just press


## Notes

- The HS2240 outputs **the same code** for the same button every time.

## References

- HS2240 Datasheet

