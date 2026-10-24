#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop(void) {
    if (top == -1) {
        printf("Invalid postfix expression!\n");
        exit(1);
    }
    return stack[top--];
}

int main(void) {
    char postfix[MAX];
    int i, a, b, result;

    printf("Enter postfix expression: ");
    if (scanf("%99s", postfix) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit((unsigned char)ch)) {
            push(ch - '0');
        } else {
            b = pop();
            a = pop();

            switch (ch) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        printf("Error: Division by zero!\n");
                        return 1;
                    }
                    result = a / b;
                    break;
                case '%':
                    if (b == 0) {
                        printf("Error: Modulo by zero!\n");
                        return 1;
                    }
                    result = a % b;
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return 1;
            }

            push(result);
        }
    }

    if (top != 0) {
        printf("Invalid postfix expression!\n");
        return 1;
    }

    printf("Result = %d\n", pop());

    return 0;
}
