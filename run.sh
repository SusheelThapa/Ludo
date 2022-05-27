#! /usr/bin/bash

# Useful variables
file_to_compile="main.cpp window.cpp ludo_piece.cpp ludo.cpp"
output_filename="main"
compiler_flags="-w"
SDL_library="-lSDL2 -lSDL2_image -lSDL2_ttf"

# print the command to compile files with SDL
echo "g++ $file_to_compile $compiler_flags $SDL_library -o $output_filename"

# Compiling command
g++ $file_to_compile $compiler_flags $SDL_library -o $output_filename

# run the compiled file
./main