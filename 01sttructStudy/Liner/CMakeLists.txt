#顺序表的测试
add_executable(sqList sqList/main.c sqList/sqList.c sqList/sqList.h)

#链表测试
add_executable(LinkList LinkList/main.c LinkList/LinkList.c LinkList/LinkList.h)

#栈测试
add_executable(stack stack/main.c stack/link_stack.c stack/link_stack.h stack/array_stack.c stack/array_stack.h)

#队列测试
add_executable(queue queue/main.c queue/array_queue.c queue/array_queue.h queue/link_queue.c queue/link_queue.h)