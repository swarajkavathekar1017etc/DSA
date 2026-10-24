#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* Next;
} Node;

Node* top = NULL;
Node* front = NULL;
Node* rear = NULL;

void push(int value)
{
    Node* newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory not available.\n");
        return;
    }

    newNode->data = value;
    newNode->Next = top;
    top = newNode;
}

void pop()
{
    Node* temp = top;

    if (temp == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }

    printf("The popped element is %d.\n", temp->data);
    top = top->Next;
    free(temp);
}

void displayStack()
{
    Node* temp = top;

    printf("Stack: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->Next;
    }

    if (top == NULL)
        printf("Stack Is Empty.");

    printf("\n");
}

void enqueue(int value)
{
    Node* newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory not available.\n");
        return;
    }

    newNode->data = value;
    newNode->Next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->Next = newNode;
        rear = newNode;
    }

    printf("%d enqueued to queue\n", value);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = front;
    printf("%d dequeued from queue\n", front->data);

    front = front->Next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue()
{
    Node* temp = front;

    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->Next;
    }

    if (front == NULL)
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
