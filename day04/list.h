#ifndef _LIST_H
#define _LIST_H
//包含公共的头文件
#include <stdio.h>
#include <stdlib.h>
//声明描述结点信息的结构体类型
typedef struct node{
    int data;//结点数据
    struct node* next;//保存下一个结点的首地址
}node_t;
//声明描述单链表的结构体类型
typedef struct list{
    struct node* head;//保存头结点的首地址
    struct node* tail;//保存尾结点的首地址
}list_t;
//声明单链表的操作函数
extern void list_init(list_t* list);//初始化
extern void list_travel(list_t* list);//遍历
extern void list_deinit(list_t* list);//释放
extern void list_add(list_t* list, int data);//插入
extern void list_add_head(list_t* list, int data);//头插入
extern void list_add_tail(list_t* list, int data);//尾插入
extern void list_del(list_t* list, int data);//删除
#endif

