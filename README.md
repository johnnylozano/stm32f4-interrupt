# STM32 F411RE NUCLEO Bare Metal Template for VSCode

This template is designed for bare metal programming on the STM32 F411RE NUCLEO board using Visual Studio Code on Windows OS. It is set up for developers who prefer to work directly with the hardware without the abstraction of HAL (Hardware Abstraction Layer).

---

## Download Requirements

- **OpenOCD** (tested with v0.11.0-5-win32-x64): Used for on-chip debugging, in-system programming, and boundary-scan testing. [Download here](#).
- **gcc-arm-none-eabi** (tested with v10.3.2021.10-win32): ARM GCC toolchain for embedded projects. [Download here](#).
- **Make**: A build automation tool. Ensure it's added to your system PATH. [Download here](#).

## VSCode Extensions Needed

- **C/C++ by Microsoft**: Provides IntelliSense, debugging, and code browsing.
- **Cortex-Debug by marus25**: Enhances debugging support for ARM Cortex-M microcontrollers.
- **Makefile Tools by Microsoft**: Provides features for working with Makefiles.

## VSCode Configurations

- **c_cpp_properties.json**: Configure the path to your compiler.
   ```json
   {
       "configurations": [
           ...
           "compilerPath": "Path to gcc-arm-none-eabi.exe"
           // Example: "compilerPath": "C:\\gcc-arm-none-eabi\\bin\\arm-none-eabi-gcc.exe"
       ]
   }
    ```

 - **launch.json**: Configure the debugger paths.
   ```json
   {
       "version": "0.2.0",
       "configurations": [
           {
               "name": "Debug Microcontroller",
               "type": "cortex-debug",
               "request": "launch",
               "servertype": "openocd",
               "cwd": "${workspaceRoot}",
               "executable": "./build/your_executable.elf",
               "device": "STM32F411RE",
               "configFiles": [
                   "interface/stlink.cfg",
                   "target/stm32f4x.cfg"
               ],
               "preLaunchTask": "build",
               "gdbPath": "Path to arm-none-eabi-gdb",
               "openOcdPath": "Path to OpenOCD"
               // Example:
               // "gdbPath": "C:/gcc-arm-none-eabi/bin/arm-none-eabi-gdb",
               // "openOcdPath": "C:/openocd/bin/openocd"
           }
       ]
   }


## Getting Started

Todo

## Troubleshooting

Todo
