#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10
//【队列的顺序表示】
//【队列】
typedef struct {
    int *base;
    int front;
    int rear;
} SqQueue;

//【初始化】
int InitQueue(SqQueue *queue) {
    queue->base = (int *) malloc(MAXSIZE * sizeof(int));
    if (!queue->base) {
        return 0;
    }
    queue->front = queue->rear = 0;
    return 1;
}

//【销毁队列】
void DestroyQueue(SqQueue *queue) {
    queue->base = NULL;
    queue->front = queue->rear = 0;
}

//【清空队列】
int clearQueue(SqQueue *queue) {
    queue->front = queue->rear = 0;
    return 1;
}

//【返回队列的头元素】
int getHead(SqQueue *queue) {
    if (queue->front != queue->rear) {
        return queue->base[queue->front];   //返回数据
    }
    return 0;//返回错误
}

//【插入队尾元素】
int enterQueue(SqQueue *queue, int num) {
    if ((queue->rear + 1) % MAXSIZE == queue->front) {
        return 0;
    }
    queue->base[queue->rear] = num;
    queue->rear = (queue->rear + 1) % MAXSIZE;
    return 1;
}

//【删除对头元素】
int DelQueue(SqQueue *queue, int *num){
    if(queue->rear == queue->front){
        return 0;
    }
    *num = queue->base[queue->front];
    queue->front = (queue->front + 1) %MAXSIZE;
    return 1;
}
//【求队列长度】
int getLength(SqQueue *queue) {
    return (queue->rear - queue->front + MAXSIZE) % MAXSIZE;
}


int main() {
    SqQueue queue;
    printf("init:%d\n", InitQueue(&queue));
    printf("enter:%d\n", enterQueue(&queue, 1));
    printf("enter:%d\n", enterQueue(&queue, 2));
    printf("enter:%d\n", enterQueue(&queue, 3));
    printf("enter:%d\n", enterQueue(&queue, 4));
    printf("enter:%d\n", enterQueue(&queue, 5));

    printf("getHead:%d\n", getHead(&queue));
    int num = 0;
    printf("DelQueue:%d %d\n", DelQueue(&queue, &num), num);
    printf("DelQueue:%d %d\n", DelQueue(&queue, &num), num);
    printf("DelQueue:%d %d\n", DelQueue(&queue, &num), num);
    return 0;
}
