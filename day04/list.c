#include "list.h"

//定义分配新结点并且初始化新结点的函数
static node_t* create_node(int data){
    //分配结点内存
    node_t* pnew = (node_t *)malloc(sizeof(node_t));
    //初始化结点内存
    pnew->data = data;
    pnew->next = NULL;
    //返回新结点内存的首地址
    return pnew;
}

void list_init(list_t* list){
    //给头结点分配内存
    list->head = create_node(0);
    //给尾结点分配内存
    list->tail = create_node(0);
    //首尾相连
    list->head->next = list->tail;
    list->tail->next = NULL;
}
//定义单链表的遍历函数
void list_travel(list_t* list){
    for(node_t* pnode = list->head; pnode != list->tail; pnode = pnode->next){
        //1.定义三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        //2.判断pmid
        if(pmid != list->tail)
            printf("%d ", pmid->data);
    }
    printf("\n");
}
//定义顺序插入函数
void list_add(list_t* list, int data){
    //1.创建新的结点
    node_t* pnew = create_node(data);
    //2.遍历查找要插入的位置
    for(node_t* pnode = list->head; pnode != list->tail; pnode = pnode->next){
        //1.定义三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        //2.找到要插入到的位置, 插入到pfirst和pmid之间
        //head---->10----->20----------->30---->tail
        //               pfirst        pmid
        //                     pnew(25)
        //head---->10----->20----------->30----------->tail
        //                             pfirst          pmid
        //                                   pnew(40)
        if(pmid->data >= pnew->data || pmid == list->tail/* 新结点数据在整个链表最大*/){
            pfirst->next = pnew;
            pnew->next = pmid;
            break;
        }
    }
}
//定义头插函数-新的节点插入到头结点和第一个有效节点之间
void list_add_head(list_t* list, int data){
    //构造新的结点
    node_t* pnew = create_node(data);
    //将新的结点插入到头结点和第一个有效结点之间
    //head---------->10---->20---->tail
    //      pnew
    //head          ptmp    
    node_t* ptmp = list->head->next;//临时备份原先的第一个结点
    list->head->next = pnew;
    pnew->next = ptmp;
}
//定义尾插函数 - 新的结点插入到最后一个有效结点和尾结点之间
void list_add_tail(list_t* list, int data){
    node_t* pnew = create_node(data);
    //head------->10---->20---------->tail
    //                        pnew
    //                  pfirst        pmid
    for(node_t* pnode = list->head; pnode != list->tail; pnode = pnode->next){
        //1.定义三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid == list->tail){//让pmid指向尾结点, 此时pfirst指向原先的最后一个结点
            pfirst->next = pnew;
            pnew->next = pmid;
        }
    } 
}



//删除某个结点的函数
void list_del(list_t* list, int data){
    //head---->10---->20---->30---->tail
    //        pfirst pmid  plast
    //1.遍历要删除的结点, 并且让pmid指向要删除的结点
    for(node_t* pnode = list->head; pnode != list->tail; pnode = pnode->next){
        //1.定义三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid->data == data && pmid != list->tail/*不能将尾结点删除*/){
            pfirst->next = plast;//连接前一个结点和后一个结点
            free(pmid);//释放要删除的结点内存
            //pmid = NULL;
            break;
        }
    } 
}

//定义释放链表所有结点的函数
void list_deinit(list_t* list){
    node_t* pnode = list->head;
    while(pnode){
        node_t* ptmp = pnode->next;//临时分配下一个要删除的结点
        free(pnode);//释放结点内存 
        pnode = ptmp;//准备释放掉下一个结点
    }
}



