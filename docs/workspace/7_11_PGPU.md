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

