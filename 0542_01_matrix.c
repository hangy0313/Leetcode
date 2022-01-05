/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct Queue {
    int queueSize;
    int curSize;
    int front;
    int rear;
    int** que; //store column and row index
};

struct Queue* createQueue(int size) {
    struct Queue* obj;
    
    obj = malloc(sizeof(struct Queue));
    obj->queueSize = size;
    obj->curSize = 0;
    obj->front = 0;
    obj->rear = 0;
    
    obj->que = malloc(sizeof(int*)*size);
    for(int index = 0;index < size;index++)
        obj->que[index] = malloc(sizeof(int)*2);
    
    return obj;
}

bool isFull(struct Queue* obj) {
    return (obj->curSize==obj->queueSize) ? true:false;
}

bool isEmpty(struct Queue* obj) {
    return (obj->curSize==0) ? true:false;
}

void pushQueue(struct Queue* obj, int col, int row) {
    if(isFull(obj)) return;
    
    obj->que[obj->rear][0] = col;
    obj->que[obj->rear][1] = row;
    obj->curSize++;
    obj->rear = (obj->rear+1)%obj->queueSize;
}

int* popQueue(struct Queue* obj) {
    int* value;
    
    value = malloc(2*sizeof(int));
    value[0] = -1;
    value[1] = -1;
    
    if(isEmpty(obj)) return value;
    
    value[0] = obj->que[obj->front][0];
    value[1] = obj->que[obj->front][1];
    obj->curSize--;
    obj->front = (obj->front+1)%obj->queueSize;
    
    return value;
}

void destroyQueue(struct Queue* obj) {
    for(int index = 0;index < obj->queueSize;index++)
        free(obj->que[index]);
    free(obj->que);
    free(obj);
}

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    int** arr;
    int** mark;
    int index, col_index, row_index;
    
    struct Queue* obj = createQueue(matSize*matColSize[0]);
    
    *returnSize = matSize;
    *returnColumnSizes = malloc(sizeof(int)*matSize);
    arr = malloc(sizeof(int*)*matSize);
    mark = malloc(sizeof(int*)*matSize);
    for(index = 0;index < matSize;index++) {
        (*returnColumnSizes)[index] = matColSize[index];
        arr[index] = calloc(matColSize[0], sizeof(int));
        mark[index] = calloc(matColSize[0], sizeof(int));
    }
    
    for(col_index = 0;col_index < matSize;col_index++) {
        for(row_index = 0;row_index < matColSize[0];row_index++) {
            if(!mat[col_index][row_index]) {
                pushQueue(obj, col_index, row_index);
                mark[col_index][row_index] = 1;
            }
        }
    }
    
    int depth = 1;
    int path[4][2] = {{1, 0},{-1, 0},{0, 1},{0, -1}};
    while(obj->curSize) {
        int curSize = obj->curSize;
        while(curSize) {
            int* cur = popQueue(obj);
            for(index = 0;index < 4;index++) {
                col_index = cur[0] + path[index][0];
                row_index = cur[1] + path[index][1];
                
                if(col_index < 0 || col_index >= matSize || row_index < 0 || row_index >=  matColSize[0])
                    continue;
                if(mark[col_index][row_index])
                    continue;
                
                arr[col_index][row_index] = depth;
                mark[col_index][row_index] = 1;
                pushQueue(obj, col_index, row_index);
            }
            curSize--;
        }
        depth++;
    }
    
    destroyQueue(obj);
    free(mark);
    
    return arr;
}

int main()
{
    printf("Hello World");

    return 0;
}
