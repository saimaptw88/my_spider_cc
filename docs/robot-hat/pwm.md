## Import
- smbus
- math
- I2C from .i2c

## Execute
- test() method

## Impement
- Global valiables
  - timer = [{"arr": 0}] * 4

- PWM(I2C) class
  - valiables
    - REG_CHN = 0x20
    - REG_FRE = 0x30
    - REG_PSC = 0x40
    - REG_ARR = 0x44
    - ADDR = 0x14
    - CLOCK = 72000000

  - methods
    - __init__
    - i2c_write
    - freq
    - prescaler
    - period
    - pulse_width
    - pulse_width_percent

- functions
  - test
  - test2
