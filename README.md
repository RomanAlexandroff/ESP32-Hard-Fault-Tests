# ESP32-Hard-Fault-Tests

Hard faults and crashes are the bogeymen of novice embedded software developers. This project serves as an educational resource designed to confront these fears head-on by exploring a comprehensive range of scenarios that can lead to crashes on the ESP32.

The primary objective of this project is to identify, document and experience all possible causes of program execution crashes firsthand. By allowing inexperienced developers to encounter various program crashes in a controlled environment, the project aims to normalize these issues, demystifying them and making them a routine part of development. This approach seeks to reduce the stress associated with encountering crashes, empowering developers to handle them with confidence.


## Features

The project includes the following tests:

- Dividing by zero
- Writing to a memory address pointed to by an uninitialized global pointer
- Writing to a memory address pointed to by a null pointer
- Calling an invalid function pointer
- Trying to access memory outside the valid range
- Causing a stack overflow with a recursive function with no limit
- Returning a pointer to the stack-allocated memory
- Returning a pointer to the heap-allocated and freed memory
- Freeing the same memory twice
- Assigning a 32-bit value to an 8-bit variable
- Unaligned memory access
- Trying to delete a watchdog task that does not exist or is already deleted

## File Structure

- `ESP32_Hard_Fault_Tests.ino`: Main Arduino sketch file that sets up and runs the tests.
- `ESP32_Hard_Fault_Tests.h`: Header file containing function declarations necessary includes and a compiler optimisation level macro.
- `functions.cpp`: Implementation of the various fault-inducing functions.
- `LICENSE`: MIT License for the project.
- `README.md`: This file.
- `.gitignore`: Git ignore file to exclude certain files from version control.

## Usage

**Disclaimer**. The usage of this sketch might harm or even break an ESP32. Use this sketch is at your own risk. I will not undertake any accountability for any damages caused by the use of this sketch.
If you are not willing to risk testing the sketch on your own development board, I suggest you to try a free online ESP32 simulator such as [Wokwi](https://wokwi.com).

1. Clone the repository to your local machine.
2. Open the project in the Arduino IDE.
3. Upload the `ESP32_Hard_Fault_Tests.ino` sketch to your ESP32 board.
4. Open the Serial Monitor to observe the results of the tests.

## Contributions

Contributions are welcome! If you have new cases of ESP32 crashing or hard-failing, please feel free to submit a pull request or open an issue. Your contributions will help make this project more comprehensive and useful for the community.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author

Roman Alexandrov - [r.aleksandroff@gmail.com](mailto:r.aleksandroff@gmail.com)