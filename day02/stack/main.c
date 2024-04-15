#include "stack.h"

int main(void){
    //定义栈变量
    stack_t stack;
    //栈的初始化
    stack_init(&stack, 20);
    int data = 520;
    while(!stack_full(&stack))//压栈
        stack_push(&stack, data++);
    printf("栈中的有效数据个数是:%d个\n", stack_size(&stack));
    printf("栈中的数据为:");
    //循环出栈
    while(!stack_empty(&stack))//非空
        printf("%d ", stack_pop(&stack));
    printf("\n");
    printf("栈中的有效数据个数是:%d个\n", stack_size(&stack));

    //栈的内存释放
    stack_deinit(&stack);
    

    return 0;
}

