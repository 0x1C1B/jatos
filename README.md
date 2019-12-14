# JatOS
> Just another toy operating system

## Table of Contents

- [Introduction](#introduction)
  - [Background Story](#background-story)
- [Project](#project)
  - [Structure](#structure)
- [License](#license)
  - [Forbidden](#forbidden)
  
## Introduction
Welcome, this is the repository of the *JatOS (**J**ust **A**nother **T**oy **O**peration **S**ystem)* learning project. The project is in active development and is updated from time to time.
The project, which was mainly implemented in `C` and `Assembler`, originally aimed at gaining a deeper understanding of the internal
processes of an operating system as well as the functionality of the hardware.
In the course of time, however, the project increasingly developed into a personal undertaking with the ambition of creating
a lightweight *"toy"* operating system. So feel free to contribute or writing extensions in any kind.

### Background Story
What is it, what isn't? A good question especially on such a complex topic. What drives me? Hmm, the interest in hardware near development, a hint of [naivety](https://wiki.osdev.org/Beginner_Mistakes)?! Everyone agrees on one thing: A mammoth project for a student of Applied Computer Science in the third semester. Now I see this project less as a project with a fixed goal and more as a way towards a deeper understanding of kernel, bootloader and co.

Personally, I am someone who prefers to try it out for himself and apply the theory he has learned. Well, admittedly not quite as easy for such a complex topic as computer engineering. However I developed promptly, admittedly not exactly according to textbook, but for me in every perspective very rich in experience.

So this project should be seen as what it actually is: *The diary of a student on his way to a better understanding of the world of operating systems.*

## Project
Even if only the `x86 (i386)` architecture is supported so far and this will not change in the foreseeable future,
the project is basically structured in such a way that several architectures can be supported and developed in a uniform repository.

### Structure
```bash
/jatos
├── arch                    # Architecture dependant code
│   └── ${ARCH}
│       └── src
│           ├── boot        # Multiboot header + Kernel entry
│           └── cpu         # ${ARCH} dependant CPU interface
├── boot                    # Bootloader/Multiboot configuration
├── include                 # Header files (*.h) for all sources
├── libc                    # C library used by JatOS kernel
└── platform                # Platform dependant code
    └── ${PLATFORM}
        └── src
            ├── cpu         # Platform related CPU utilities
            ├── driver      # Device Drivers for ${PLATFORM}
            └── io          # Hardware I/O access
```

## License

Copyright (c) 2019 0x1C1B

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

[MIT License](https://opensource.org/licenses/MIT) or [LICENSE](LICENSE) for
more details.

### Forbidden

**Hold Liable**: Software is provided without warranty and the software
author/license owner cannot be held liable for damages.
