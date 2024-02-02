#include <stdio.h>

#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == SIZE - 1) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("%d has been enqueued.\n", data);
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int data = queue[front];
        front++;
        return data;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int search(int key) {
    if (front == -1) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        for (int i = front; i <= rear; i++) {
            if (queue[i] == key) {
                return i;
            }
        }
        return -1;
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();

    int key = 3;
    int position = search(key);
    if (position == -1) {
        printf("%d is not found in the queue.\n", key);
    } else {
        printf("%d is found at position %d in the queue.\n", key, position);
    }

    return 0;
}
