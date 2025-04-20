#include<stdio.h>
#include<stdlib.h>

//Declare maximum element of queue
#define Max 100

// Initialize struct to store data for queue
typedef struct{
    int data[Max];
    int front, rear;
}Queue;

//prototype
void init(Queue* q); //Initialize queue
int isEmpty(Queue* q); //check queue Empty?
int isFull(Queue* q); //check queue full?
void enqueue(Queue* q, int x); //Add element at front queue
int dequeue(Queue* q); //Remove rear element
int peek(Queue* q); //Show front element

int main(){
    //when declare a pointer array, queue, stack,v.v, certainly 
    //need allocation memory for them to use. 
    // Queue *q = (Queue*)malloc(sizeof(Queue));
    Queue q;

    init(&q);
    printf("Check queue(1/0): %d\n", isEmpty(&q));

    enqueue(&q,10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    printf("Front element: %d\n", peek(&q));
    printf("List queue: ");
    for(int i = q.front; i <= q.rear; i++){
        printf("%d ", q.data[i]);
    }
    printf("\n");

    dequeue(&q);
    printf("Front element: %d\n", peek(&q));
    
    // free(q);
    return 0;
}

void init(Queue* q){
    q->front = 0;
    q->rear = -1;
    //Init queue empty
}

int isEmpty(Queue* q){
    return q->front > q->rear;
}

int isFull(Queue* q){
    return q->rear == Max - 1;
}

void enqueue(Queue* q, int x){
    if(isFull(q)){
        printf("Queue overflow! Impossile add element.\n");
        return;
    }

    q->data[++(q->rear)] = x;
    printf("Add element at rear of queue!\n"); 
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return 1;
    }

    int value = q->data[q->front++];
    printf("Remove front element succesfully!\n");
    return value;
}

int peek(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return 1;
    }

    return q->data[q->front];
}