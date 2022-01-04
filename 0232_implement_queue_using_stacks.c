/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int size;
    int top;
    int* queue;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj;
    obj = malloc(sizeof(MyQueue));
    obj->size = 10;
    obj->top = 0;
    obj->queue = malloc(sizeof(int)*10);
    
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    if(obj->top == obj->size) return;
    obj->queue[obj->top++] = x;
}

int myQueuePop(MyQueue* obj) {
    int value =   obj->queue[0];
    int index;
    for(index = 1;index < obj->top;index++) {
        obj->queue[index-1] = obj->queue[index];
    }
    obj->top--;
    return value;
}

int myQueuePeek(MyQueue* obj) {
    return obj->queue[0];
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->top == 0) return true;
    return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj->queue);
    free(obj);
}

void myQueueDump(MyQueue* obj) {
    int index;
    printf("myQueue : ");
    for(index = 0;index < obj->top;index++)
        printf(" %d", obj->queue[index]);
    printf("\n");
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/

int main()
{
    int index;
    MyQueue* queue = myQueueCreate();
    myQueuePush(queue, 1);
    myQueueDump(queue);
    myQueuePush(queue, 2);
    myQueueDump(queue);
    myQueuePop(queue);
    myQueueDump(queue);
    
    return 0;
}


