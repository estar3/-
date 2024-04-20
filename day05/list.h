#ifndef _LIST_H
#define _LIST_H
//包含公共的头文件
#include <stdio.h>
#include <stdlib.h>
//声明描述结点的结构体
typedef struct node{
    int data;
    struct node* next;//保存下一个结点首地址
    struct node* prev;//保存上一个结点首地址
}node_t;
//声明描述双链表的结构体
typedef struct list{
    struct node head;
    struct node tail;
}list_t;
extern void list_init(list_t* list);//初始化函数
extern int list_empty(list_t* list);//判断链表是否为空的函数
extern int list_size(list_t* list);//结点个数
extern void list_add(list_t* list, int data);//按照顺序插入
extern void list_add_head(list_t* list, int data);//头插
extern void list_add_tail(list_t* list, int data);//尾插
extern void list_del(list_t* list, int data);//删除指定结点
extern void list_del_head(list_t* list);//头删
extern void list_del_tail(list_t* list);//尾删
extern int list_get(list_t* list, int index);//根据结点编号获取数据
extern void list_deinit(list_t* list);//释放内存


#endif

