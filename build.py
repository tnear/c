#!/usr/bin/env python3
import os
import subprocess

# Usage:
# ./build.py

class Options:
    def __init__(self, filename, flags):
        self.filename = filename
        self.objectName = filename.replace('.c', '.o')
        self.flags = flags

    def getCommand(self):
        return f'gcc {self.filename} {self.flags} -o {self.objectName}'

def main():
    # Get every .c file
    cFiles = [filename for filename in os.listdir() if filename.endswith('.c')]

    # Group compile command into a class
    options = []
    for cFile in cFiles:
        flags = getFlags(cFile)
        option = Options(cFile, flags)
        options.append(option)

    # Run build in a loop
    for option in options:
        command = option.getCommand()
        subprocess.call(command, shell=True)

def getFlags(filename):
    flags = '-g -Wall'
    if filename == 'curl.c':
        flags += ' -lcurl'

    return flags

if __name__ == '__main__':
    main()
