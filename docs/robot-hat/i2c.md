## Import
- _Basic_class from .basic
- SMBus from smbus

## Execute
- None

## Impements
- I2C(_Basic_class) class
  - valiables
    - MASTER = 0
    - SLAVE = 1
    - RETRY = 5

  - methods
    - __init__
    - _i2c_write_byte
    - _i2c_write_byte_data
    - _i2c_write_word_data
    - _i2c_write_i2c_block_data
    - _i2c_read_byte
    - _i2c_read_i2c_block_data
    - is_ready
    - scan
    - send
    - recv
    - mem_write
    - mem_read
    - readfrom_mem_into
    - writeto_mem

- functions
  - _retry_wrapper
