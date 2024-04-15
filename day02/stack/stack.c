//stack.c
#include "stack.h"
//栈的初始化
void stack_init(stack_t* stack, int cap){
    //给栈分配内存
    stack->arr = malloc(sizeof(int)*cap);
    //初始化容量
    stack->cap = cap;
    //初始化top
    stack->top = 0;
}
//栈的内存的释放
void stack_deinit(stack_t* stack){
    free(stack->arr);//释放内存
    stack->cap = 0;
    stack->top = 0;
}
//判断栈是否为满
int stack_full(stack_t* stack){
    //满, 1
    //非满, 0
    return stack->top == stack->cap;
}
//判断栈是否为空
int stack_empty(stack_t* stack){
    //空, 1
    //非空, 0
    return stack->top == 0;
}
//定义入栈函数
void stack_push(stack_t* stack, int data){
    //将数据data放到下表为top的位置
    stack->arr[stack->top] = data;
    stack->top++;
}
//定义出栈函数
int stack_pop(stack_t* stack){
    stack->top--;
    return stack->arr[stack->top];
}
//判断栈中有效数据个数的函数
int stack_size(stack_t* stack){
    return stack->top;
}





