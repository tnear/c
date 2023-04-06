#!/usr/bin/env python3
import os
import subprocess

# Usage:
# ./build.py

def main():
    # Get every .c file
    c_files = [filename for filename in os.listdir() if filename.endswith('.c')]

    # Create a .o file for each file
    object_files = [filename.replace('.c', '.o') for filename in c_files]

    # Build command
    compile_commands = ['gcc {} -g -Wall -o {}'.format(c_file, o_file) for
                        c_file, o_file in zip(c_files, object_files)]

    # Run build in a loop
    for compile_command in compile_commands:
        subprocess.call(compile_command, shell=True)

if __name__ == '__main__':
    main()
