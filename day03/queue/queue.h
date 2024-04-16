#ifndef _QUEUE_H
#define _QUEUE_H

//包含公共的头文件 
#include <stdio.h>
#include <stdlib.h>
//声明描述队列的数据结构
typedef struct queue{
    int* arr;//首地址
    int cap;//容量
    int size;//有效数据个数
    int front;//队首,出队
    int rear;//队尾,入队
}queue_t;
//声明操作函数
extern void queue_init(queue_t* queue, int cap);//初始化
extern void queue_deinit(queue_t* queue);//释放内存
extern int queue_full(queue_t* queue);//判断满, 满,返回1;非满, 0;
extern int queue_empty(queue_t* queue);//判断空 空,返回1;非空, 0;
extern void queue_push(queue_t* queue, int data);//入队
extern int queue_pop(queue_t* queue);//出队
extern int queue_size(queue_t* queue);//出队


#endif

