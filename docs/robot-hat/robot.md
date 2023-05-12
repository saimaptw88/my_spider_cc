## import
- PWM from .pwm
- Servo from .servo
- time
- fileDB from .filedb
- os

## Execute
None

## Implements
- Global valiables
  - User
  - UserHome
  - config_file ("$UserHome/.config/robot-hat/robot-hat.conf")

- Robot() class
  - values
    - move_list = {}
    - PINS

  - methods
    - __init__
    - new_list
    - angle_list
    - servo_write_all
    - servo_move
    - servo_move2
    - do_action
    - set_offset
    - calibration
    - reset
    - soft_reset
