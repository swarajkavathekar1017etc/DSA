#include <stdio.h>
#include <stdlib.h>
void reverse(char input[]);
int palindrome(char input[]);
void copy(char input[], char output[]);
void substring(char input[]);
int stringlength(char input[]);

int pallindrome(char name[])
{
    int i = 0, j = 0;
    while (name[j] != '\0')
    {
        j++;
    }
    j--;
    while (i < j)
    {
        if (name[i] != name[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
void copy(char input[], char output[])
{
    int i;
    for (i = 0; input[i] != '\0'; i++)
    {
        output[i] = input[i];
    }
    output[i] = '\0';
    printf("the output (copied) string is:");
    printf("%s", output);
}
void substring(char input[])
{
    int i, n, position;
    char output[20];
    printf("Enter the position:");
    scanf("%d", &position);
    n = stringlength(input);
    if (position < n)
    {
        for (i = 0; i < n - position; i++)
        {
            output[i] = input[position + i];
        }
        output[i] = '\0';
        printf("\nthe input string %s \noutput substring %s", input, output);
    }
    else
    {
        printf("the position is out of range");
    }
}
int stringlength(char input[])
{
    int i = 0;
    while (input[i] != '\0')
    {
        i++;
    }
    return i;
}
void reverse(char input[])
{
    int i, n;
    char output[20];
    n = stringlength(input);
    for (i = 0; i < n; i++)
        output[n - 1 - i] = input[i];
    output[i] = '\0';
    printf("\ninput:%s\noutput(reversed):=%s", input, output);
}
int main()
{
    char name[50], output[20];
    printf("Enter the string:");
    scanf("%s", name);
    int ch, c;

    do
    {
        printf("\n1)palindrome\n2)copy\n3)reverse\n4)substring\n5)Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            c = pallindrome(name);

            if (c == 1)
                printf("the string is pallindrome string");
            else
                printf("The string is not pallindrome");

            break;

        case 2:
            copy(name, output);
            break;

        case 3:
            reverse(name);
            break;

        case 4:
            substring(name);
            break;

        case 5:
            printf("Exiting...");
            break;

        default:
            printf("something went wrong");
            break;
        }

    } while (ch != 5);

    return 0;
}