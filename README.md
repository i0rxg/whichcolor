
# Whichcolor

A simple C program that allows users to select a pixel on the screen and retrieve its color information on Linux using Xorg.

## Features

- Allows users to drag the mouse and select a pixel on the screen
- Retrieves the color information of the selected pixel
- Displays the color in RGB and HEX formats
- Can be installed globally for easy access from anywhere in the terminal

## Requirements

- Linux operating system with Xorg
- GCC compiler
- Xlib library

## Installation

1. Clone the repository:

   \`\`\`sh
   git clone https://github.com/yourusername/color-picker.git
   \`\`\`

2. Navigate to the project directory:

   \`\`\`sh
   cd color-picker
   \`\`\`

3. Install the necessary dependencies. On Ubuntu or Debian-based systems, run:

   \`\`\`sh
   sudo apt install libx11-dev
   \`\`\`

   On Arch-based systems, run:

   \`\`\`sh
   sudo pacman -S libx11
   \`\`\`

4. Build the program:

   \`\`\`sh
   make
   \`\`\`

5. Install the program globally:

   \`\`\`sh
   sudo make install
   \`\`\`

   This will copy the compiled binary to /usr/local/bin, allowing you to run the program from anywhere in the terminal.

## Usage

1. Run the program from anywhere in the terminal:

   \`\`\`sh
   whichcolor
   \`\`\`

2. The program will grab the mouse pointer. Drag the mouse to the desired pixel on the screen.

3. Click the left mouse button to select the pixel.

4. The program will display the color information for the selected pixel, including RGB values and HEX code.

5. To copy the HEX code to the clipboard, run the program with the -c option:

   \`\`\`sh
   whichcolor -c
   \`\`\`

## Uninstallation

To uninstall the program, navigate to the project directory and run:

\`\`\`sh
sudo make uninstall
\`\`\`

This will remove the program from /usr/local/bin.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them with descriptive commit messages.
4. Push your changes to your forked repository.
5. Submit a pull request to the main repository.

Please ensure that your code follows the project's coding style and conventions.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

- [Xlib](https://www.x.org/releases/current/doc/libX11/libX11/libX11.html) - The X Window System library used in this project.
- [GCC](https://gcc.gnu.org/) - The GNU Compiler Collection used to compile the program.

## Contact

If you have any questions, suggestions, or feedback, please feel free to contact the project maintainer:

- Name: Rammah Alensari
- Email: alensari@pm.me
- GitHub: [rxmmah](https://github.com/rxmmah)

---
