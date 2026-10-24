#include <stdio.h>
#define Max 5

int Stack[Max], Queue[Max];
int top = -1;
int front = -1, rear = -1;

void push(int value)
{
    if (top == Max - 1)
        printf("Stack Is Full.\n");
    else
        Stack[++top] = value;
}

void pop()
{
    if (top == -1)
        printf("Stack Is Empty.\n");
    else
        printf("%d is popped\n", Stack[top--]);
}

void displayStack()
{
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", Stack[i]);

    if (top == -1)
        printf("Stack Is Empty.");
    printf("\n");
}

void enqueue(int value)
{
    if (rear == Max - 1)
        printf("Queue Is Full.\n");
    else
    {
        if (front == -1)
            front = 0;

        Queue[++rear] = value;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
        printf("Queue Is Empty.\n");
    else
        printf("%d is deleted\n", Queue[front++]);
}

void displayQueue()
{
    printf("Queue: ");
    for (int i = front; i <= rear && front != -1; i++)
        printf("%d ", Queue[i]);

    if (front == -1 || front > rear)
        printf("Queue Is Empty.");
    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display Stack");
        printf("\n4. Enqueue");
        printf("\n5. Dequeue");
        printf("\n6. Display Queue");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            displayStack();
            break;

        case 4:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 5:
            dequeue();
            break;

        case 6:
            displayQueue();
            break;

        case 7:
            printf("Exit\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 7);

    return 0;
}
