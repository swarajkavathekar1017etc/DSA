#include <stdio.h>
#define SIZE 100

// Queue for UART data transmission
int queue[SIZE];
int front = -1, rear = -1;

// Insert data into queue (Transmit)
void transmit(int data) {
    if (rear == SIZE - 1) {
        printf("Transmission buffer is full!\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = data;
    printf("Transmitted: %c\n", data);
}

// Remove data from queue (Receive)
void receive() {
    if (front == -1 || front > rear) {
        printf("No data to receive!\n");
        return;
    }

    printf("Received: %c\n", queue[front++]);

    if (front > rear) {
        front = rear = -1;
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("\n--- UART Communication ---\n");
        printf("1. Transmit Data\n");
        printf("2. Receive Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to transmit: ");
                scanf(" %c", (char *)&data);
                transmit(data);
                break;

            case 2:
                receive();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
