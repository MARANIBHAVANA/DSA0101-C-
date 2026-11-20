# Assignment 5 – CO5
**Name:** M. Bhavana  
**Register number:** 192472252  
**Compiler:** g++ C++17 (record your installed version with `g++ --version`).

## Contents
Task01_A1 to Task05_A5 contain Part A design answers. Task06_B1 to Task09_B4 contain Part B C++ starter implementations and notes.

## Compile and run (PowerShell, from this Assignment5 folder)
Example:
```powershell
g++ -std=c++17 -Wall -Wextra -pedantic Task06_B1/B1.cpp -o Task06_B1/B1.exe
.\Task06_B1\B1.exe
```
Optimized benchmark:
```powershell
g++ -std=c++17 -O2 -Wall -Wextra Task08_B3/B3.cpp -o Task08_B3/B3.exe
.\Task08_B3\B3.exe
```
AddressSanitizer (requires a GCC build with ASan support):
```powershell
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address Task06_B1/B1.cpp -o Task06_B1/B1_asan.exe
.\Task06_B1\B1_asan.exe
```

## Before submission
You MUST run every program yourself, save actual output screenshots, record your own machine's B3 timings, and save actual sanitizer output. Timings and sanitizer messages vary by machine/compiler; this package does not fabricate them. Commit progressively, at least once per task.
