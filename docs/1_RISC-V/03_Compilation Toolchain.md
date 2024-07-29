# Compilation toolchain
## 1. ELF


## 2. Bin




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



# 嵌入式开发的介绍
## 什么是嵌入式开发
嵌入式开发是一个比较综合性的技术，它不单指纯粹的软件技术开发，也不是一种硬件配置技术；它是在特定的硬件环境下针对某款硬件进行开发，是一种系统级别的与硬件结合比较紧密的软件开发技术。

可能是通过路由器把PC和Target Board连起来。

搞操作系统其实也是嵌入式开发的一种。


## 交叉编译
- Build：生成编译器可执行程序的计算机
- Host：运行编译器可执行程序，编译链接应用程序的计算机
- Target：运行应用程序的计算机


- 本地编译：Build == Host == Target
- 交叉编译：Build == Host != target

GNU交叉编译工具链Toolchain

命名格式：arch-vendor-os1-[os2-]XXX 

## 调试工具GDB
GNU的Debug的缩写，用于查看另一个程序在执行过程中正在执行的操作，或者该程序崩溃时正在执行的操作。

调试分为本地调试和远程调试，本地调试是我们用的最多一种调试方法，远程调试的话会使用到gdbserver来对目标机器进行调试。



## 模拟器QEMU
那什么又是模拟器呢？
我们主要用的模拟器是QEMU(Quick Emulation)。这个软件主要用在Linux下边，主要有两种模式，用户模式和系统模式。


QEMU可以只开一个进程来运行。
```bash
qemu-riscv32 ./a.out
```
如果是用这种方式的话，QEMU模拟的是U模式

System mode 模拟整个计算机系统，包括中央处理器及其他周边设备。

如果做系统开发，则一般来说使用System mode。


## 项目构造工具Make
make工具是一种自动化工程管理工具。
Makefile是配合make用于描述构建工程过程中所管理的对象以及如何构建工程。

Makefile三要素：target、prerequisites、command

关于如何速成Makefile，之后我也会写一个博客来简单讲解一下这个Makefile的规则。

规则分为缺省规则和伪规则。



除了学习这些之外，还得学习一些bash的语法。