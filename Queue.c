#include<stdio.h>
#include<stdlib.h>
#define max 5
int front = -1;
int rear = -1;
int Queue[max];

int Isfull(){
    return (rear+1) % max == front;
}

int Isempty(){
    return (front == -1);
}

void Enqueue(int value){
    if(Isfull()){
        printf("\nQueue is full..!");
    } else if(Isempty()){
        front = rear = 0;
        Queue[rear] = value;
        printf("\n%d is inserted to the Queue",value);
    } else {
        rear = (rear + 1) % max;
        Queue[rear] = value;
        printf("\n%d is inserted into the Queue",value);
    }
}

void Dequeue(){
    if(Isempty()){
        printf("Queue is Empty..!");
        return;
    } else {
        printf("\n%d is deleted from the Queue",Queue[front]);
        if(rear == front){
           rear = front = -1; 
        } else {
            front = (front + 1) % max ;
        }
    }
}

void Display(){
    if(Isempty()){
        printf("Queue is Empty");
    } else {
        printf("\n----Queue data-----\n");
       int i = front;
        while(1){
            printf("%d\n",Queue[i]);
            if(i == rear){
                break;
            } 
            i = (i + 1) % max;
        }
    }
}

int main() {
    int value, choice;
    while (1) {
        printf("\n-----Queue menu------\n");
        printf("1. Enqueue (add)\n2. Dequeue (delete)\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                Enqueue(value);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid choice...!");
        }
    }
    return 0;
}