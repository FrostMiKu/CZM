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
    int arg1;
    int arg2;
    int arg3;
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
    dmem[op->arg1] = dmem[op->arg2] + dmem[op->arg3];
    return stateCor;
}
opState exec_sub(op_t *op) {
    dmem[op->arg1] = dmem[op->arg2] - dmem[op->arg3];
    return stateCor;
}
opState exec_mul(op_t *op) {
    dmem[op->arg1] = dmem[op->arg2] * dmem[op->arg3];
    return stateCor;
}
opState exec_div(op_t *op) {
    dmem[op->arg1] = dmem[op->arg2] / dmem[op->arg3];
    return stateCor;
}

opState exec_in(op_t *op) {
    scanf("%d",&dmem[op->arg1]);
    return stateCor;
}
opState exec_out(op_t *op) {
    printf("%d",dmem[op->arg1]);
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
            
        default:return stateErr;
    }
}
