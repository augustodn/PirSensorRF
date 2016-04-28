Changelog
* Added library to handle RrTransmit, checked with alarm system.
* Check AnalogReading threshold and trigger RF signal if it's lower than
  specified value

The purpose of this project is to emulate RF433 sensors commercialy available
for alarm systems.

It was tested with arduino MEGA 2560 and compiled with ino. Please check
ino.ini file to match with your board/serial port and serial port baud rate

$ tree
.
├── ino.ini
├── lib
│   └── RfTransmit
│       ├── RfTransmit.cpp
│       └── RfTransmit.h
└── src
    └── sketch.ino
