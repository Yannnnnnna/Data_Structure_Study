#include <stdio.h>
#include <stdlib.h>
//【栈的链表实现】
//[链栈]
typedef struct StackNode{
    int data;
    struct StackNode *next;
}StackNode, *LinkStack;
//【初始化】
void InitStack(LinkStack *stack){
    *stack = NULL;
}
//【判断栈是否为空】
int StackEmpty(LinkStack *stack){
    if(*stack == NULL){
        return 1;
    } else{
        return 0;
    }
}
//【入栈】
int Push(LinkStack *stack, int data){
    LinkStack p = (LinkStack)malloc(sizeof (StackNode));
    p->data = data;
    p->next = *stack;
    *stack = p;
    return 1;
}
//【出栈】
int Pop(LinkStack *stack, int *data){
    if(*stack == NULL){
        return 0;
    }
    *data = (*stack)->data;
    *stack = (*stack)->next;
}
//【取出栈顶元素】
int GetTop(LinkStack stack){
    if(stack!= NULL){
        return stack->data;
    } else{
        return 0;
    }
}

int main() {
    return 0;
}
