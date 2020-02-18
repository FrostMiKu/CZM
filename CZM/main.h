//
//  main.h
//  CZM
//
//  Created by FrostMiKu on 2020/2/18.
//  Copyright © 2020 FrostMiKu. All rights reserved.
//

#define DMEM_SIZE 1024
#define IMEM_SIZE 1024
#define REG_NUM 8
#define REG_PC 7

typedef int word_t;

word_t dmem[DMEM_SIZE];
word_t regs[REG_NUM];

#include "opCode.h"

op_t imem[IMEM_SIZE];

FILE *fp;


