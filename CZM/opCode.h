//
//  opCode.h
//  CZM
//
//  Created by FrostMiKu on 2020/2/18.
//  Copyright © 2020 FrostMiKu. All rights reserved.
//

typedef enum{
    stateCor,
    stateErr
} opState;

typedef enum{
    opADD,
    opSUB,
    opMUL,
    opDIV,
    
    opIN,
    opOUT,
    
    opLD,
    opST,
    opLDA,
    opLDC,
    
    opERROR,
    opEND
} opCode;

typedef struct{
    opCode opv;
    int r;
    int s;
    int t;
} op_t;

opCode map_opCode(char *op) {
    if (!strcmp(op,"ADD")) return opADD;
    if (!strcmp(op,"SUB")) return opSUB;
    if (!strcmp(op,"MUL")) return opMUL;
    if (!strcmp(op,"DIV")) return opDIV;
    
    if (!strcmp(op,"IN")) return opIN;
    if (!strcmp(op,"OUT")) return opOUT;
    
    if (!strcmp(op,"LD")) return opLD;
    if (!strcmp(op,"ST")) return opST;
    if (!strcmp(op,"LDA")) return opLDA;
    if (!strcmp(op,"LDC")) return opLDC;
    
    return opERROR;
}



opState exec_add(op_t *op) {
    regs[op->r] = regs[op->s] + regs[op->t];
    return stateCor;
}
opState exec_sub(op_t *op) {
    regs[op->r] = regs[op->s] - regs[op->t];
    return stateCor;
}
opState exec_mul(op_t *op) {
    regs[op->r] = regs[op->s] * regs[op->t];
    return stateCor;
}
opState exec_div(op_t *op) {
    regs[op->r] = regs[op->s] / regs[op->t];
    return stateCor;
}

opState exec_in(op_t *op) {
    scanf("%d",&regs[op->r]);
    return stateCor;
}
opState exec_out(op_t *op) {
    printf("%d",regs[op->r]);
    return stateCor;
}

opState exec_ld(op_t *op) {
    regs[op->r] = dmem[regs[op->s]+op->t];
    return stateCor;
}
opState exec_st(op_t *op) {
    dmem[regs[op->s]+op->t] = regs[op->r];
    return stateCor;
}
opState exec_lda(op_t *op) {
    regs[op->r] = regs[op->s]+op->t;
    return stateCor;
}
opState exec_ldc(op_t *op) {
    regs[op->r] = op->t;
    return stateCor;
}

opState op_exec(op_t *op) {
    switch (op->opv) {
        case opADD: return exec_add(op);
        case opSUB: return exec_sub(op);
        case opMUL: return exec_mul(op);
        case opDIV: return exec_div(op);
            
        case opIN: return exec_in(op);
        case opOUT: return exec_out(op);
            
        case opLD: return exec_ld(op);
        case opST: return exec_st(op);
        case opLDA: return exec_lda(op);
        case opLDC: return exec_ldc(op);
            
        default: return stateErr;
    }
}
