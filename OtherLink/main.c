#include <stdio.h>
#include <stdlib.h>
//双向链表
typedef struct DulNode{
    int data;
    struct DulNode *prior,*next;
}DulNode, *DuLinkList;

//【双向链表的插入】
int LinkInsert_DuL(DuLinkList *list, int i, int data){
    //找到第i个节点
    int j = 1;
    DuLinkList p = (*list)->next;
    while (p&&j < i){
        j++;
        p = p->next;
    }
    if(!p){
        return 0;
    }
    //插入节点
    DuLinkList s = (DulNode*) malloc(sizeof (DulNode));
    //核心四步
    s->data = data;
    s->prior = p;
    p->next = s;
    s->next = p->next;
    p->next->prior = s;
    return 1;
}
//【双向链表删除】
int ListDelete_Dul(DuLinkList *list, int i,int *data){
    //找到第i个节点
    int j = 1;
    DuLinkList p = (*list)->next;
    while (p&&j < i){
        j++;
        p = p->next;
    }
    if(!p){
        return 0;
    }
    //删除节点
    *data = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return 1;
}
int main() {
    printf("Hello, World!\n");
    return 0;
}
