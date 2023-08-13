#include <stdio.h>
#define MAXLEN 255 //最大长度时255
#define CHUNKSIZE 80    //定义块的大小
//顺序串
typedef struct {
    char ch[MAXLEN + 1];
    int len;       //串当前的长度
}SString;

//链串
typedef struct Chunk{
    char ch[CHUNKSIZE];
    struct Chunk *next;
}Chunk;

typedef struct {
    Chunk *head,*tail;  //头指针和尾指针
    int curlen;     //当前串的长度
}LString;   //字符串的块结构

int main() {
    printf("Hello, World!\n");
    return 0;
}
