### User manual

genius_sensor/
├── CMakeLists.txt          # main build file
├── README.md
├── include/                # headers
│   ├── gpio_interface.h    # abstract GPIO interface
│   ├── sensor.h            # sensor class
├── src/                    # main source
│   ├── main.cpp
│   ├── sensor.cpp
│   ├── gpio_mock.cpp       # Mac / testing
│   └── gpio_lgpio.cpp      # Raspberry Pi implementation
├── tests/                  # unit tests
├── scripts/                # helper scripts (setup, csv handling)
├── csv/                    # optional: sample output
├── cmake/                  # optional: CMake modules
└── .gitignore

##### Package management
`apt-mark showmanual > requirements.txt`
