//双链表测试
#include "list.h"

int main(void){
    list_t list;
    list_init(&list);//初始化 
    
    //各种插入
    list_add_head(&list, 100);
    list_add_head(&list, 30);
    list_add_tail(&list, 70);
    list_add_tail(&list, 50);
    list_add(&list, 80);
    list_add(&list, 20);
    list_add(&list, 40);
    list_add(&list, 90);
    list_add(&list, 60);
    list_add(&list, 10);
    list_add(&list, 110);

    //获取链表内容
    int size = list_size(&list);
    for(int i = 0; i < size; i++)
        printf("%d ", list_get(&list, i));
    printf("\n");

    //各种删除结点
    list_del(&list, 90);
    list_del_head(&list);
    list_del_tail(&list);

    //获取链表内容
    size = list_size(&list);
    for(int i = 0; i < size; i++)
        printf("%d ", list_get(&list, i));
    printf("\n");


    list_deinit(&list);//释放
    return 0;
}


