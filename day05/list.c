#include "list.h"

//初始化函数
void list_init(list_t* list){
    //初始化头结点
    list->head.next = &list->tail;
    list->head.prev = NULL;
    list->head.data = 0;

    //初始化尾结点
    list->tail.next = NULL;
    list->tail.prev = &list->head;
    list->tail.data = 0;
}
//判断空函数
int list_empty(list_t* list){
   //如果链表中只有头结点和尾结点 
   return list->head.next == &list->tail;//满足, 空; 不满足, 非空
}
//判断结点个数函数
int list_size(list_t* list){
    int count = 0;//记录结点个数
    for(node_t* pnode = &list->head; pnode != &list->tail; pnode = pnode->next){
        //制造三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid != &list->tail)
            count++;
    }
    return count;
}
//定义构造新节点的函数
static node_t* create_node(int data){
    node_t* pnew = malloc(sizeof(node_t));
    pnew->data = data;
    pnew->next = NULL;
    pnew->prev = NULL;
    return pnew;
}
static void insert_node(node_t* pfirst, node_t* pmid, node_t* pnew){
    pfirst->next = pnew;
    pnew->prev = pfirst;

    pnew->next = pmid;
    pmid->prev = pnew;
}
//按照顺序插入函数
void list_add(list_t* list, int data){
    node_t* pnew = create_node(data);
    //head<------>10<---------->20<----->30<---->tail
    //                pnew(15)
    //          pfrist         pmid
    for(node_t* pnode = &list->head; pnode != &list->tail; pnode = pnode->next){
        //制造三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid->data >= pnew->data || pmid == &list->tail){
            insert_node(pfirst, pmid, pnew);
            break;
        }
    }
}

//头插函数
void list_add_head(list_t* list, int data){
    node_t* pnew = create_node(data);
    //head<------------>10<---->20<----->30<---->tail
    //         pnew
    //pfirst          pmid     plast
    //制造游标
    node_t* pfirst = &list->head;
    node_t* pmid = pfirst->next;
    node_t* plast = pmid->next;
    //将pnew结点插入到pfirst和pmid之间
    insert_node(pfirst, pmid, pnew);
}
//尾插函数
void list_add_tail(list_t* list, int data){
    node_t* pnew = create_node(data);
    //head<---->10<---->20<----->30<--------------->tail
    //                                   pnew
    //                         pfirst               pmid   plast
    //制造游标
    node_t* pfirst = list->tail.prev;
    node_t* pmid = pfirst->next;
    node_t* plast = pmid->next;
    //将pnew插入到pfirst和pmid之间
    insert_node(pfirst, pmid, pnew);
}
//定义删除pmid指向的结点
static void del_node(node_t* pfirst, node_t* pmid, node_t* plast){
    pfirst->next = plast;
    plast->prev = pfirst;
    free(pmid);
}
//删除指定的结点
void list_del(list_t* list, int data){
    //head<------>10<---------->20<----->30<---->tail
    for(node_t* pnode = &list->head; pnode != &list->tail; pnode = pnode->next){
        //制造三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid->data == data && pmid != &list->tail){
            del_node(pfirst, pmid, plast);
        }
    } 
}
//删除第一个有效结点
void list_del_head(list_t* list){
    //判断链表是否为空
    if(list_empty(list)){
        printf("链表为空, 无法删除\n");
        return;
    }
    //head<------>10<---------->20<----->30<---->tail
    //pfirst     pmid         plast
    //定义游标
    node_t* pfirst = &list->head;
    node_t* pmid = pfirst->next;
    node_t* plast = pmid->next;
    //删除pmid指向的结点
    del_node(pfirst, pmid, plast);
    
}
//删除最后一个有效结点
//让pmid指向要删除的结点 - 指向最后一个有效结点
void list_del_tail(list_t* list){
    //判断链表是否为空
    if(list_empty(list)){
        printf("链表为空, 无法删除\n");
        return;
    }
    //head<------>10<------>20<----->30<---->tail
    //                     pfirst   pmid     plast
    //定义游标
    node_t* plast = &list->tail;//plast指向了tail结点
    node_t* pmid = plast->prev;//plast的上一个结点 - 最后一个有效结点 - pmid 
    node_t* pfirst = pmid->prev;//指向pmid的上一个结点
    //删除pmid指向的结点 
    del_node(pfirst, pmid, plast);
}

//根据结点编号来获取数据的函数
//数组:
// 10 20 30 40  数据
// 0  1  2  3   数组下标
//双链表:
// 10 20 30 40  双链表数据 
// 0  1  2  3   结点编号 
// 根据结点编号来获取编号对应的数据
int list_get(list_t* list, int index){
    int count = 0;//表示循环的次数
    // head    10     20     30     40   tail 双链表数据 
    //         0      1      2      3         结点编号 
    //              pfirst  pmid   plast
    //tips:根据循环的次数, 判断pmid指向的内容
    for(node_t* pnode = &list->head; pnode != &list->tail; pnode = pnode->next){
        //制造三个游标
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(count == index && pmid != &list->tail)
            return pmid->data;
        count++;
    }
}

//清除链表中的所有内容 
void list_deinit(list_t* list){
   //head----10----20-----30----tail
   //head-----tail
   //head----tail
   //pfirst  pmid  plast
   while(list->head.next != &list->tail){
        node_t* pfirst = &list->head;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        del_node(pfirst, pmid, plast);//删除pmid指向的结点
   }
}





