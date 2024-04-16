#include "queue.h"

int main(void){
    queue_t queue;

    queue_init(&queue, 4);
    //入队
    for(int i = 10; i <= 40; i += 10){
        if(!queue_full(&queue))
            queue_push(&queue, i);//入队:10(0) 20(1) 30(2) 40(3) 
    }
    printf("队列有效数据个数为:%d\n", queue_size(&queue));
    //出队两个数据 - 10(0), 20(1)
    for(int i = 0; i < 2; i++){
        if(!queue_empty(&queue))
            printf("%d ", queue_pop(&queue));
    }
    printf("\n");
    printf("队列有效数据个数为:%d\n", queue_size(&queue));
    //入队 50 60
    //50(0) 60(1) 30(2) 40(3)
    for(int i = 50; i <= 60; i += 10){
        if(!queue_full(&queue))
            queue_push(&queue, i);
    }
    //出队
    while(!queue_empty(&queue))
        printf("%d ", queue_pop(&queue));//30 40 50 60 - 出队顺序
    printf("\n");
    queue_deinit(&queue);

    return 0;
}

