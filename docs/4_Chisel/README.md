# Chisel编程指北

目前国内针对Chisel的了解还是比较少的，为了方便未来的编程，本系列笔记旨在速成对于Chisel的了解与学习，帮助大家快速的开发。

首先我们需要看一下Chisel究竟是什么东东，为什么我们需要用这个玩意来学习。下边我们开始吧，始吧，吧~


我们的学习路径分为以下几个部分，首先是对于Scala的学习，其次是对于Verilog的学习，最后再使用Chisel进行快速的开发。

Chisel是伯克利在发明RISC-V的时候顺带产生的一个硬件描述语言， 它是Scala嵌入式语言的子集。

![al  t text](image/1.png)

可以将设计硬件转换为Verilog等低层次HDL描述

Chisel本质实际上是“Verilog Generator”，具有高可配等优点，函数式编程并不是为了掩盖电路设计细节，相反，为了用Chisel写出更高效的语言，需要对数字电路设计更熟悉，同时还要熟悉scala语法。

1. [硬件描述语言和高级编程语言区别](https://chhzh123.github.io/blogs/2019-02-08-hll-and-hdl/)

基本信息，
