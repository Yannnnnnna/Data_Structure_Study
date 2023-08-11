#include <stdio.h>
#include <stdlib.h>
#define MAXQSIZE 100    //最大队列长度

typedef struct Qnode {
    int data;
    struct Qnode *next;
} Qnode, *QueuePtr;

typedef struct {
    QueuePtr front;     //头指针
    QueuePtr rear;      //尾指针
} LinkQueue;

//【链表初始化】
int InitQueue(LinkQueue *q){
    q->front = q->rear = (QueuePtr) malloc(sizeof (Qnode));
    if(!q->front){
        return -1;
    }
    q->front->next = NULL;
    return 1;
}

//【销毁链队列】
int DestroyQueue(LinkQueue *q){
    QueuePtr p;
    while (q->front){
        p = q->front->next;
        free(q->front);
        q->front = p;
    }
    return 1;
}

//【入队】
int EnQueue(LinkQueue *q, int data){
    QueuePtr p = (QueuePtr) malloc(sizeof (Qnode));
    if(!p){
        return -1;
    }
    q->rear->next = p;
    p->data = data;
    p->next = NULL;
    q->rear = p;
    return 1;

}
//【出队】
int DeQueue(LinkQueue *q, int *data){
    if(q->rear == q->front){
        return -1;
    }
    QueuePtr p = q->front->next;
    *data = q->front->next->data;
    q->front->next = p->next;

    if(q->rear == p){
        q->front = q->rear;
    }
    free(p);
    return 1;
}
int main() {
    LinkQueue q;
    printf("Init:%d\n", InitQueue(&q));
    printf("Des:%d\n", DestroyQueue(&q));
    printf("Init:%d\n", InitQueue(&q));

    printf("Enter:%d\n", EnQueue(&q,2));
    printf("Enter:%d\n", EnQueue(&q,3));

    int data;

    printf("De:%d\n", DeQueue(&q,&data));
    printf("Denum:%d\n", data);
    printf("De:%d %d\n", DeQueue(&q,&data), data);

    return 0;
}
