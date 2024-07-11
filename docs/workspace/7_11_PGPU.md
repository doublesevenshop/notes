# 摘要
熟练提升FPGA和Chiesl，在推理的过程中。
主要提升Rust和FPGA代码。


## 架构分析
### 开普勒
提供了双精度吞吐量。开普勒架构的特点
- 动态并行性
- Hyper Q 多个核心向单个CPU发送
- Grid Management Unit 网格管理和调度控制，不用返回CPU，强调控制。相当于hardware control
- NVIDIA GPUDirect 允许第三方设备直接访问同一系统内多个GPU的内存

15 SMX支持CUDA3.5
开普勒优化功耗、
编译器可以预先确定好何时发出、
shuffle、
原子和并行化、

ECC校验位会在DRAM上进行校验，有消耗

数据分布不均匀，CPU用driver，GPU用hardware control

现在再试一次

需要了解到IO相关的。

RDMA是有比赛的

what is the MPI?

### Scale-model simulation
架构模拟如果直接物理模拟，可能会消耗大量的资源。

比例模型模拟：构建一个比目标系统小得多的缩放版本，称为Scale Model。
什么是缩放？在local机器上进行模拟

Strong scaling：问题规模固定，看硬件的性能与规模的变化
Weak scaling：问题规模随着硬件变化，看性能变化

计算密集型和SM相关。

pre-cliff、   cliff、   post cliff


miss rate具体看一下。

一定要把文章看懂。一般的创新点都是两到三个点。



