#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
//【顺序表】
typedef struct SqStack {
    int *data;  //可以时任何类型的数据
    int *base, *top;    //栈底和栈顶指针
    int stackSize;  //栈的大小

} SqStack;

//【栈】
//  1.初始化
int InitStack(SqStack *stack) {
    //分配空间
    stack->data = (int *) malloc(MAXSIZE * sizeof(int));
    //判断空间分配是否成功
    if (!stack->data) return 0;
    //分配头指针和尾指针
    stack->top = stack->base;
    stack->stackSize = MAXSIZE;
    //返回
    return 1;
}

//  2.进栈
int Push(SqStack *stack, int data) {
    //判断栈是否满
    if (stack->top - stack->base == stack->stackSize) {
        return 0;
    }
    //移动栈顶指针，存入数据
    *stack->top++ = data;
    return 1;
}

//  3.出栈
int Pop(SqStack *stack, int *data) {
    //判断栈是否为空
    if (stack->top == stack->base) {
        return 0;
    }
    //元素出栈并保存,移动栈顶指针
    *data = *stack->top--;
    return 1;
}

//  4.取栈顶元素
int GetTop(SqStack stack, int *data) {
    if (stack.top == stack.base) {
        return 0;
    }
    *data = *(stack.top - 1);
    return 1;
}

//  5.销毁栈
int DestroyStack(SqStack *stack){
    if(stack->data){
        free(stack->data);
        stack->stackSize = 0;
        stack->top = stack->base = NULL;
    }
    return 1;
}

//  6.判断栈是否为空
int StackEmpty(SqStack stack){
    if(stack.top == stack.base){
        return 1;
    }
    return 0;
}

//  7.栈置空
int ClearStack(SqStack stack){
    if(stack.base){
        stack.top = stack.base;
    }
    return 1;
}
int main() {

    return 0;
}
