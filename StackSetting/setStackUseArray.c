#include<stdio.h>
#include<stdlib.h>

#define Max 100

//Initialize a struct to store data and node top
typedef struct{
    int data[Max];
    int top;
}Stack;

//prototpye
void IniStack(Stack* stack); // Initialize stack empty
int IsEmpty(Stack* stack); // Check stack empty 
int IsFull(Stack* stack); // Check stack full
void Push(Stack* Stack, int x); // Push x into top of stack
int Pop(Stack* stack); //Remove element top of stack
int Peek(Stack* stack); //Watch top withou delete

int main(){
    //Call Stack stack;
    Stack stack;

    IniStack(&stack);
    Push(&stack, 10);
    Push(&stack, 20);
    Push(&stack, 30);
    printf("Value of top: %d\n", Peek(&stack));

    printf("Check stack full(1/0): %d\n", IsFull(&stack));

    Pop(&stack);
    Pop(&stack);
    printf("Value of top: %d\n", Peek(&stack));
    printf("Check Empty(1/-1): %d", IsEmpty(&stack));

    return 0;
}

void IniStack(Stack* stack){
    stack->top = -1; //Init stack empty
}

int IsEmpty(Stack* stack){
    // if(stack->top == -1){
    //     printf("Stack is empty!\n");
    // }
    return stack->top == -1;
}

int IsFull(Stack* stack){
    // if(stack->top == Max - 1){
    //     printf("Stack is full!\n");
    // }
    return stack->top == Max - 1;
}

void Push(Stack* stack, int x){
    if(IsFull(stack)){
        printf("Stack overflow! Impossible push %d.", x);
        return;
    }

    stack->data[++(stack->top)] = x;
    printf("Push successfully %d.\n", x);
}

int Pop(Stack* stack){
    if(IsEmpty(stack)){
        printf("Stack is empty!\n");
        return -1;
    }

    return stack->data[(stack->top)--];
    printf("Remove top successfully!\n");
}

int Peek(Stack* stack){
    if(IsEmpty(stack)){
        printf("Stack is empty! Not found.\n");
        return -1;
    }

    return stack->data[stack->top];
}