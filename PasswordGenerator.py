#!/usr/bin/env python3
import subprocess
import pyperclip

platform = input('What are you generating a password for?: ')
output = subprocess.check_output(['/Users/tate-minch/Documents/misc/Passwords/passwordGenerator/generatePassword', platform])

print(str(output, 'utf-8').strip())

pyperclip.copy(str(output, 'utf-8').strip())
