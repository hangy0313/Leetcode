/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int path[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

struct Queue {
    int size;
    int curSize;
    int front;
    int rear;
    int** que;
};

struct Queue* createQueue(int size) {
    struct Queue* obj;
    
    obj = malloc(sizeof(struct Queue));
    obj->size = size;
    obj->curSize = 0;
    obj->front = 0;
    obj->rear = 0;
    obj->que = malloc(sizeof(int*)*size);
    for(int index = 0;index < size;index++)
        obj->que[index] = malloc(sizeof(int)*2);
    
    return obj;
}

bool isFull(struct Queue* obj) {
    return obj->curSize==obj->size ? true:false;
}

bool isEmpty(struct Queue* obj) {
    return obj->curSize==0 ? true:false;
}

void pushQueue(struct Queue* obj, int col, int row) {
    if(isFull(obj)) return;
    
    obj->que[obj->rear][0] = col;
    obj->que[obj->rear][1] = row;
    obj->rear = (obj->rear+1)%obj->size;
    obj->curSize++;
}

int* popQueue(struct Queue* obj) {
    int* value;
    value = malloc(sizeof(int)*2);
    value[0] = -1;
    value[1] = -1;
    if(isEmpty(obj)) return value;
    
    value[0] = obj->que[obj->front][0];
    value[1] = obj->que[obj->front][1];
    obj->front = (obj->front+1)%obj->size;
    obj->curSize--;
    
    return value;
}

void destoryQueue(struct Queue* obj) {
    for(int index = 0;index < obj->size;index++)
        free(obj->que[index]);
    free(obj->que);
    free(obj);
}

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int** mark;
    struct Queue* obj = createQueue(gridSize*gridColSize[0]);
    int min = -1;
    int total = 0;
    int rotten = 0;
    
    mark = malloc(sizeof(int*)*gridSize);
    for(int index = 0;index < gridSize;index++) {
        mark[index] = calloc(gridColSize[index], sizeof(int));
    }
    
    for(int col = 0;col < gridSize;col++) {
        for(int row = 0;row < gridColSize[0];row++) {
            if(grid[col][row] == 2) {
                mark[col][row] = 1;
                pushQueue(obj, col, row);
                total++;
                rotten++;
            } else if(grid[col][row] == 1) {
                total++;
            }
        }
    }
    
    if(rotten == total) return 0;
    
    while(obj->curSize) {
        int curSize = obj->curSize;
        while(curSize) {
            int* cur = popQueue(obj);
            for(int index = 0;index < 4;index++) {
                int col_index = path[index][0] + cur[0];
                int row_index = path[index][1] + cur[1];
                
                if(col_index < 0 || col_index >= gridSize || row_index < 0 || row_index >=gridColSize[0])
                    continue;
                if(mark[col_index][row_index]) continue;
                
                if(grid[col_index][row_index] == 1) {
                    grid[col_index][row_index] == 2;
                    pushQueue(obj, col_index, row_index);
                    mark[col_index][row_index] = 1;
                    rotten++;
                }
            }
            curSize--;
        }
        min++;
    }
    
    if(rotten != total) return -1;
    
    return min;
}

int main()
{
    printf("Hello World");

    return 0;
}
