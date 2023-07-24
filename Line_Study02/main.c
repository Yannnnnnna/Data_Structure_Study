#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
} ElemType;
//单链表的存储结构
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;   //LinkList为指向结构体Node的指针类型

//【单链表初始化】
int InitList(LinkList *list) {
    *list = (LinkList) malloc(sizeof(Node));
    (*list)->next = NULL;
    return 1;
}

//【判断链表是否为空】
int IsEmpty(LinkList list) {
    if (list->next) {
        return 0;
    } else {
        return 1;
    }
}

//【链表销毁】
int DestroyList(LinkList *list) {
    LinkList p;
    while (*list) {
        p = *list;
        *list = (*list)->next;
        free(p);
    }
    free(*list);
    return 1;
}

//【清空链表】
int ClearList(LinkList *list) {
    LinkList p, q;
    p = (*list)->next;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    (*list)->next = NULL;
    return 1;
}

//【求链表表长】
int ListLength(LinkList list) {
    LinkList p;
    p = list->next;
    int length = 0;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

//【查找链表中第i个元素】
int getElem(LinkList list, int i, ElemType *e) {
    LinkList p = list->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p) {
        return 0;
    }
    *e = p->data;
    return 1;
}

//【查找指定元素】
Node *LocateElem(LinkList list, ElemType e) {
    LinkList p = list->next;
    while (p && p->data.data != e.data) {
        p = p->next;
    }
    return p;
}

//【再第i个位置插入数据元素】
int ListInsert(LinkList *list, int i, ElemType e) {
    LinkList p = *list;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p) {
        return 0;
    }
    Node *s = (LinkList) malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

//【删除第i个节点】
int ListDelete(LinkList *list, int i) {
    LinkList p = *list;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p) {
        return 0;
    }
    LinkList s = p->next;
    p->next = s->next;
    free(s);
    return 1;
}

//【头插法创建链表】
void HeadCreate(LinkList *list, int n) {
    *list = (Node*) malloc(sizeof(Node));
    (*list)->next = NULL;

    for (int i = 0; i < n; ++i) {
        LinkList p = (LinkList) malloc(sizeof(Node));
        scanf("%d",&p->data.data);
        p->next = (*list)->next;
        (*list)->next = p;
    }
}

//【尾插法创建链表】
void LastCreate(LinkList *list, int n) {
    *list = (Node*) malloc(sizeof(Node));
    (*list)->next = NULL;
    LinkList r = *list;
    for (int i = 0; i < n; ++i) {
        LinkList p = (LinkList) malloc(sizeof(Node));
        scanf("%d",&p->data.data);
        p->next = NULL;
        r->next = p;
        r = p;

    }
}

void MergeList_L(LinkList *list1, LinkList *list2, LinkList *list3){
    LinkList p1 = (*list1)->next;
    LinkList p2 = (*list2)->next;
    LinkList p3 = *list3 = *list1;
    while (p1&&p2){
        if(p1->data.data <= p2->data.data){
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        } else{
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }

    }
    p3->next = p1 ? p1 :p2;
    free(p2);
}

int main() {
    LinkList list = NULL;
    InitList(&list);
    printf("Is the list empty? %d\n", IsEmpty(list));

    // 插入元素
    ElemType e1 = {10};
    ElemType e2 = {20};
    ElemType e3 = {30};
    ListInsert(&list, 1, e1);
    ListInsert(&list, 2, e2);
    ListInsert(&list, 3, e3);
    printf("Length of the list: %d\n", ListLength(list));

    // 删除元素
    ListDelete(&list, 2);
    printf("Length of the list after deletion: %d\n", ListLength(list));

    ClearList(&list);
    printf("Is the list empty after clearing? %d\n", IsEmpty(list));

    // 查找元素
    ElemType target;
    int found = getElem(list, 2, &target);
    if (found) {
        printf("Element at position 2: %d\n", target.data);
    } else {
        printf("Element not found at position 2\n");
    }

    Node* result = LocateElem(list, e3);
    if (result) {
        printf("Element 30 found in the list\n");
    } else {
        printf("Element 30 not found in the list\n");
    }

    DestroyList(&list);

    LinkList list1 = NULL;
    LinkList list2 = NULL;

    // 头插法创建链表
    HeadCreate(&list1, 3);
    printf("Length of list1: %d\n", ListLength(list1));

    // 尾插法创建链表
    LastCreate(&list2, 3);
    printf("Length of list2: %d\n", ListLength(list2));

    DestroyList(&list1);
    DestroyList(&list2);

    return 0;
}
