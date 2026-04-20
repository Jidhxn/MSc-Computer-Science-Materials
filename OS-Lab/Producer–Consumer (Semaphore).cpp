#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 10

int buffer[BUFFERSIZE];
int in = 0, out = 0;
int mutex = 1, empty = BUFFERSIZE, full = 0;
int n, item;

// Wait (P operation)
void wait(int *s)
{
    (*s)--;
}

// Signal (V operation)
void signal(int *s)
{
    (*s)++;
}

// Producer function
void producer()
{
    for (int i = 0; i < n; i++)
    {
        if (empty == 0)
        {
            printf("\nBuffer is full!\n");
            return;
        }

        wait(&empty);
        wait(&mutex);

        printf("\nEnter item: ");
        scanf("%d", &item);

        buffer[in] = item;
        in = (in + 1) % BUFFERSIZE;

        signal(&mutex);
        signal(&full);
    }
}

// Consumer function
void consumer()
{
    for (int i = 0; i < n; i++)
    {
        if (full == 0)
        {
            printf("\nBuffer is empty!\n");
            return;
        }

        wait(&full);
        wait(&mutex);

        item = buffer[out];
        printf("\nConsumed item = %d", item);

        out = (out + 1) % BUFFERSIZE;

        signal(&mutex);
        signal(&empty);
    }
}

int main()
{
    printf("Enter number of items: ");
    scanf("%d", &n);

    producer();
    consumer();

    return 0;
}
