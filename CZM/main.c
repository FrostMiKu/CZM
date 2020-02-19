//
//  main.c
//  CZM
//
//  Created by FrostMiKu on 2020/2/18.
//  Copyright © 2020 FrostMiKu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void cz_init(){
    for (int i = 0; i < IMEM_SIZE; i++) {
        imem[i].opv = opEND;
        imem[i].r = 0;
        imem[i].s = 0;
        imem[i].t = 0;
    }
    memset(dmem, 0, sizeof(dmem));
    memset(regs, 0, sizeof(regs));
}

void cz_load(){
    int i = 0;
    int r,s,t;
    char op[20];
    while (fscanf(fp, "%s", op)!=EOF) {
        //printf("%s\n",op);
        imem[i].opv = map_opCode(op);
        
        fscanf(fp, "%d", &r);
        if (r<0 || r>=REG_NUM) {
            printf("寄存器 %d 不存在！\n",r);
            exit(-1);
        }
        fscanf(fp, "%d", &s);
        if (s<0 || s>=REG_NUM) {
            printf("寄存器 %d 不存在！\n",s);
            exit(-1);
        }
        fscanf(fp, "%d", &t);
        if (t<0 || t>=REG_NUM) {
            printf("寄存器 %d 不存在！\n",t);
            exit(-1);
        }
        imem[i].r=r;imem[i].s=s;imem[i].t=t;
        
        i++;
    }
    fclose(fp);
}

void cz_run() {
    opState st;
    while (imem[regs[REG_PC]].opv != opEND) {
        st = op_exec(&imem[regs[REG_PC]]);
        if (st == stateErr) {
            printf("指令存在错误！PC:%d\n",regs[REG_PC]);
            exit(-1);
        }
        regs[REG_PC]++;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    if (argc < 1) {
        printf("需要加载文件！\n");
        return -1;
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        exit(-1);
    }
    cz_init();
    cz_load();
    cz_run();
}
