#include "list.h"

int main(void){
    //创建单链表
    list_t list;
    list_init(&list);
    //各种插入和遍历
    list_add(&list, 10);
    list_add(&list, 20);
    list_add(&list, 30);
    list_add(&list, 40);
    list_travel(&list);
    list_add(&list, 80);
    list_add(&list, 50);
    list_add(&list, 90);
    //删除结点
    list_del(&list, 30);
    list_travel(&list);
    //释放单链表
    list_deinit(&list);

    return 0;
}

