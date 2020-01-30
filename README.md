# liblogger

This library provides a mechanism for easy data logging. The structure of the log is defined before hand. It accepts 16-bit values that are stored in a predefined, fixed location. The accepted entries are defined in the header file. Changing, removing or adding entries in the log requires editing it. The interface is designed to be used with [libspi](https://github.com/TheFormulaCruisers/libspi).

Once initialized it may be called from anywhere in the program, logging data to a single globally available buffer. Initializing two individual logs is not supported.

## Operation

Liblogger reserves two equally sized global buffers used to store log data. Their size is a multiple of two bytes, since it stores two-byte values, and is automatically calculated during compilation. To only one of the two buffers is written at a time, allowing the other to be read without getting corrupted by a write operation. The two buffers may be swapped (rotated), in order to readout newly acquired data.

## Usage

Functions are defined in the header files located in _inc_. Each function is supplemented with documentational block comments that describe their usage. A block comment may contain the following tags:

  * @brief
  * @param
  * @return
  * @note
  * @bug

## Build

The _tools_ folder contains an ATMEL Studio project that may be used to build the test program located in _tests_. The project is setup to link to the original files in _inc_ and _src_, thus avoiding unnecessary copies. Its build-in compiler includes _inc_ as well (_Properties > Toolchain > Directories_). Macros are defined at _Properties > Toolchain > Symbols_.

A makefile is provided, but is not setup to generate a programmable image. By using _make_, one may easily check whether the program compiles correctly and without warnings using a terminal or command-prompt.

## Devices

Device | Status
--- | ---
AT90CAN128 | Supported
