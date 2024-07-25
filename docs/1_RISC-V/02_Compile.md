# Compile and Link
**It's about xxxx words, if there are any errors or problems, email me! 1416642324@bupt.edu.cn**

> Hello everyone, have a nice day! 
> Let's study together. 

## 1. GCC & GDB
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

| Tools | Function |
| --- | --- |
| GCC |  |
|  |  |
|  |  |
|  |  |
|  |  |


### GCC的命令格式
GCC 常用的选项有-E、-c、-S、-o、-g、-v等等
- -E，用来做预处理
- -c，只编译不链接，生成目标文件"-o"
- -S, 生成汇编代码
- -o file，把输出文件指定到文件名中
- -g，在输出文件中加入支持调试的信息
- -v，显示详细的命令执行过程信息
```bash
gcc [options] [filenames]
```


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

