# Compile and Link
**It's about xxxx words, if there are any errors or problems, email me! 1416642324@bupt.edu.cn**

> Hello everyone, have a nice day! 
> Let's study together. 

## 1. GCC & GDB

### 1.1. GCC
**GCC (GNU Compiler Collection)** is a suite of compilers developed by GNU under the GPL license. It supports front-ends in C/C++/Objective-C, Ada, and Go languages, and has been ported to a variety of computer architectures, such as X86, ARM, RISC-V, and so on.

Now, let's look at the gcc version of the system first！

```bash
riscv@riscv-virtual-machine:~$ gcc --version

gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
Copyright (C) 2021 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
Before we happily use gcc, let's write a Hello world!
```c
#include <stdio.h>

int main() {
    printf("Hello world!\n");

    return 0;
}
```

This is a very, very simple code, we want to display Hello world on bash, so how do we use gcc?

Let me guess, maybe you want to use these command directly
```bash
gcc hello.c
./a.out

Hello world!
```
Woooo! The process is so easy that people think compiling events is a simple matter. Is this really the case? Let's take a closer look at how the C compilation process really works.

In fact, GCC has performed four steps：
1. Preprocessing
2. Compilation
3. Assemble
4. Linking

<p align="center">
  <img src="./image/image1_1.png" alt="alt text" />
</p>

This table includes some of the most commonly used tools in the GNU Compiler Collection suite, along with their primary functions.

| **Tool** | **Name** | **Function** |
|---|---|---|
| `gcc`    | GNU Compiler Collection | Compiles C, C++, and other languages into executable binaries.                             |
| `g++`    | GNU C++ Compiler  | Specifically compiles C++ programs.                                                          |
| `gdb`    | GNU Debugger      | Debugs programs by allowing the inspection and control of program execution.                 |
| `make`   | Make              | Automates the build process by reading a file called Makefile which specifies how to build the program. |
| `as`     | GNU Assembler     | Assembles assembly language source code into machine code.                                   |
| `ld`     | GNU Linker        | Links compiled object files into a single executable or library.                             |
| `ar`     | GNU Archiver      | Creates, modifies, and extracts from archives (collections of files) typically used for libraries. |
| `nm`     | Name List         | Lists symbols from object files, providing information about the contents of binaries.       |
| `objdump`| Object Dump       | Displays information about object files, such as disassembled code, symbols, and sections.   |
| `strip`  | Strip             | Removes symbols and other information from object files to reduce their size.                |

GCC is the front-end program for compilation, it is achieved by calling other programs to compile the program source files into target files. 

When compiling it first calls the `preprocessor program (cpp)` to process the input source program; then calls `cc1` to compile the preprocessed program into assembly code; and finally compiles the assembly code into target code by `as`.


Command format is as follows:
```bash
gcc [options] file......
```
The command gcc is followed by one or more options separated by spaces, and then by one or more target files.

such as:
```bash
gcc -g -c -o hello.o hello.c
```

### 1.2. GCC Usage 
There are some common options when using gcc
| Option | Implication | Example |
| --- | --- | --- |
| `-E` | Preprocess the specified source file without compiling it and generate a .i file | gcc -E hello.c| 
| -S | Compile the specified source file, but do not assemble it, and generate a .s file | gcc -S hello.c|
| -c | Compile and assemble but do not link, generate .o files| gcc -c test1.c test2.c test3.c |
| -o file| Save the output content in the file file| gcc main.c func.c -o ans.out|
| -I dir| Specify the search directory for include files| gcc hello.c -I ./include/ |
| -g | Generate debugging information, the program can be debugged by a debugger| gcc -g hello.c | 
| -v | Print out the commands executed during the compilation process | gcc -v hello.c  | 




## 2. ELF & Bin


## 3. Make


## 4. Cross Compile


## 5. QEMU










![alt text](image/image1.png)


### GCC执行步骤


### GCC涉及的文件类型


## ELF
ELF(Executable Linkable Format)是一种Unix-like系统上的二进制文件格式标准。

ELF标准中定义的采用ELF格式的文件有4类：
1. .o文件：可重定位文件，包含了代码和数据，可以被链接成可执行文件或共享目标文件。
2. a.out文件：可执行文件
3. .so文件：共享目标文件
4. core文件：核心转储文件，进程意外终止时，系统可以将该进程的部分内容和终止时的其他状态信息保存到该文件中以供分析调试。
![alt text](image/image2.png)

Program Header Table是一个运行视图，这个地方不是很懂，还是需要再查询一下


下边是一个ELF文件处理的相关工具
[Binutils](https://www.gnu.org/software/binutils)


查看ELF的头信息，应该如何看呢？
```bash
readelf -h hello.o
```

这个可以查看一个.o文件的头

那如何查看链接视图呢？
```bash
readelf -SW hello.o
```
这个就能看到整个文件有多少个节。


那如何反汇编呢？
先用
```bash
gcc -g -c hello.c 
objdump -S hello.o
```
可以将hello.o进行反汇编，查看汇编代码，不过是有一内内痛苦的。

