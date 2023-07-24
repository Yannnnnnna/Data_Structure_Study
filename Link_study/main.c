#include <stdio.h>
#include <stdlib.h>

#define LIST_INT_SIZE 100
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#define FALSE 0
#define TRUE 1

typedef struct {    //创建一个数据类型
    int a;
    double b;
    char c;
    //若干个数据域
} ElemType;

typedef struct {    //【顺序表】
    //ElemType elem[LIST_INT_SIZE];   //顺序表数据内容
    ElemType *elem;
    int length; //储存顺序表长度
} SqList;


int InitList(SqList *list) {   //【创建一个空的线性表】
    list->elem = (ElemType *) malloc(sizeof(ElemType) * LIST_INT_SIZE);
    //出现分配空间失败的问题
    if (!list->elem) {
        printf("空间不足\n");
        return OVERFLOW;
    }
    list->length = 0;
    return OK;

}

void DestroyList(SqList *list) {     //【销毁线性表】
    if (list->elem) {
        free(list->elem);
    }
}

void ClearList(SqList *list) {      //【清空线性表】
    list->length = 0;

}

int GetLength(SqList list) {     //【求线性表的长度】
    return list.length;
}

int IsEmpty(SqList list) {   //【判断表是否为空】
    if (list.length) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int GetElem(SqList list, int i, ElemType *e) {   //【顺序表取值】
    if (i < 1 || i > list.length) {
        printf("查找的位置不和法，请重新输入\n");
        return OVERFLOW;
    }
    *e = list.elem[i - 1];
    return OK;
}

int LocateElem(SqList list, ElemType e) {    //【顺序表查找】
    for (int i = 0; i < list.length; ++i) {
        if (list.elem[i].a == e.a) {  //可以将ElemType里的元素一个一个对比
            return i + 1;
        }
    }
    return FALSE;
}

int ListInsert(SqList *list, int i, ElemType e) {       //【插入线性表元素】
    //判断i值是否合法
    if (i < 1 || i > list->length + 1) {
        return ERROR;
    }
    //储存空间已经满了的情况
    if (i == LIST_INT_SIZE) {
        printf("储存空间已满，存储失败\n");
        return ERROR;
    }
    //进行元素的插入
    for (int j = list->length - 1; j >= i; j--) {
        list->elem[j + 1] = list->elem[j];
    }
    list->elem[i - 1] = e;
    list->length++;
    return OK;
}

int ListDelete(SqList *list, int i) {       //【删除顺序表的元素】
    //判断i值是否合法
    if (i < 1 || i > list->length) {
        return OVERFLOW;
    }
    //进行删除
    for (int j = i - 1; j < list->length - 1; ++j) {
        list->elem[j] = list->elem[j + 1];
    }
    list->length--;
    return OK;
}


int main() {
    SqList sqList;
    InitList(&sqList);
    ElemType e = {1,2.2,'a'};
    int i = ListInsert(&sqList,1,e);
    printf("%d\n", i);


    return 0;
}
