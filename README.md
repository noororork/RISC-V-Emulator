# RISC-V Emulator in C++

## 📖 Overview
This project is a **RISC-V emulator written in C++**.  
It loads a machine program from a hex file, simulates memory and registers, decodes instructions, and executes them as a real CPU would.  

The emulator fetches 32-bit instructions from memory, decodes them according to the RISC-V ISA, and updates registers, memory, and the program counter — replicating the instruction cycle of a processor.  

This project is still in the production stage, so not all features are complete- see next steps below.

---

## 🚀 Features
- Load program data from **hex files** into simulated memory
- Simulate **32 general-purpose RISC-V registers**
- Support for core instructions such as:
  - **Arithmetic/logic** (e.g., `addi`, `add`)
  - **Memory access** (`lw`, `sw`)
  - **Control flow** (`beq`, `jal`(not completed yet))
- Instruction **fetch → decode → execute** pipeline
- Proper handling of **sign-extension**, **immediate fields**, and **bit masking**
- Enforced **x0 hardwired to zero** rule
- Memory abstraction for both instructions and data
- PC (program counter) simulation

---

## 🛠️ Skills Demonstrated

### 💻 Programming Skills
- **C++ system-level programming**
  - Pass-by referencing and memory simulation
  - Bit masking & shifting to decode instruction fields
  - Strong use of types (`uint32_t`)
- **Low-level simulation**
  - Implementing the fetch-decode-execute cycle
  - Designing register and memory abstractions
- **Software architecture**
  - Clear separation of responsibilities (decoder, memory, execution engine)
  - Modular and extendable design for supporting more instructions

### ⚡ Embedded Systems & Computer Architecture Knowledge
- **Instruction Set Architecture (ISA)**
  - Understanding of RISC-V instruction formats: R, I, S, B, J types
  - Familiarity with binary encoding of opcodes, funct3, funct7
- **CPU design concepts**
  - Instruction cycle: Fetch, Decode, Execute, Memory
  - Role of program counter, register file, and memory interface
- **Memory models**
  - Word-aligned memory access
  - Handling of endianness and data width
- **Register file semantics**
  - Hardwiring x0 to zero
  - Managing general-purpose registers during execution
- **Practical embedded concepts**
  - How binary machine code is executed directly by hardware
  - How software tools (assemblers/compilers) interface with hardware at the binary level

## 📂 Project Structure
- **src**
  - cpu.cpp
  - decoder.cpp
  - main.cpp
  - memory.cpp
  - registers.cpp
  - **instructions**
    - b.cpp
    - i_imm.cpp
    - i.cpp
    - r.cpp
    - s.cpp
- **include**
  - cpu.h
  - decoder.h
  - memory.h
  - registers.h
  - **instructions**
    - b.h
    - i_imm.h
    - i.h
    - r.h
    - s.h

## ▶️ Usage
Compile the project:
    `g++ src/*.cpp src/instructions/*.cpp -Iinclude -o main.exe`

## 🌱 Next stages
Currently the project is in the late developement stages, my next steps will be to implement j instructions and system instructions.

After that I will work on improving implementation to make it sleeker and to use better coding practice. I plan to implement pointer-arithmetic rather than basic indexing when using the program counter to load and execute instructions, as well as using enums for the different bit-codes of instructions.

Please note that most testing hasn't occurred past loading the instructions and translating it to its specific instruction function. Currently uses main method which makes a one-instruction hex file, but once I have completed implementation of all instructions I will be able to load in full hex files to test on. This means that I have yet to complete exception-handling, but I plan to get the whole model working smoothly as my next steps.

## 📌 Takeaways

This project demonstrates both software engineering skills and a strong understanding of computer architecture / embedded systems.
It bridges the gap between theory (ISA, CPU design) and practice (implementing an emulator in C++), showing the ability to work close to the hardware/software boundary.


