#include <stdio.h>
#include <string.h>

#define SIZE 10

struct process
{
    char a[10];
} buffer[10];

int mutex = 1, full = 0, empty = SIZE, flag = 0;

int wait(int);
int signal(int);

int main()
{
    int ch, i;
    printf("\nPRODUCER - CONSUMER PROBLEM\n");

    while (1)
    {
        printf("\nChoices are:\n");
        printf("1. Producer Routine\n");
        printf("2. Consumer Routine\n");
        printf("3. Display the contents of the buffer\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            empty = wait(empty);
            mutex = wait(mutex);

            if (flag == 0)
            {
                printf("\nEnter the item to be added: ");
                scanf("%s", &buffer[full].a);
                printf("Item inserted successfully\n\n");
                full = signal(full);
            }
            else
            {
                printf("Buffer Full\n");
                flag = 0;
            }

            mutex = signal(mutex);
            break;

        case 2:
            full = wait(full);
            mutex = wait(mutex);

            if (flag == 0)
            {
                printf("\n\nItem %s is successfully consumed\n", buffer[0].a);

                for (i = 0; i < SIZE; i++)
                {
                    strcpy(buffer[i].a, buffer[i + 1].a);
                }

                empty = signal(empty);
            }
            else
            {
                printf("No item is in buffer\n\n");
                flag = 0;
            }

            mutex = signal(mutex);
            break;

        case 3:
            if (full != 0)
            {
                for (i = 0; i < full; i++)
                {
                    printf("%s\n", buffer[i].a);
                }
            }
            else
            {
                printf("Buffer is empty\n\n");
            }
            break;

        case 4:
            return 0;

        default:
            printf("Please enter a valid option\n");
        }
    }
}

int wait(int s)
{
    if (s == 0)
    {
        flag = 1;
    }
    else
    {
        s--;
    }

    return s;
}

int signal(int s)
{
    s++;
    return s;
}
