# CZ Machine
**This project is supported by the CZ Protection Association**

CZ机是一个玩具级的虚拟机（？）使用哈佛结构，运行三地址指令。

opt r s t

所有寄存器均为通用寄存器，共 8 个，PC 为 "寄存器 7"


## 指令集
```
	IN,			从终端模拟输入
	OUT,			从终端模拟输出

	ADD,			regs[r] = regs[s] + regs[t]
	SUB,			regs[r] = regs[s] - regs[t]
	MUL,			regs[r] = regs[s] * regs[t]
	DIV,			regs[r] = regs[s] / regs[t]

    	LD,			regs[r] = dmem[regs[s]+t]
	ST,			dmem[regs[s]+t] = regs[r]
	LDA,			regs[r] = regs[s]+t 
	LDC,			regs[r] = t
```
未完，待续...
