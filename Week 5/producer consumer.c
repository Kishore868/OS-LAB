
#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int full=0;
int empty=5;
int x=0;

void wait(int *S)
{
    (*S)--;
}

void signal(int *S)
{
    (*S)++;
}

void producer()
{

    if(mutex==1 && empty>0)
    {
        wait(&mutex);
         signal(&full);
        x++;

        wait(&empty);
        signal(&mutex);

        printf("Producer has produced : %d\n",x);

    }
    else{
        printf("Production limit exceeded\n");
    }
}
void consumer()
{

    if(mutex==1 && full>0)
    {
        wait(&mutex);
        signal(&empty);

        wait(&full);
        signal(&mutex);

        printf("Consumer has consumed : %d\n",x);
        x--;

    }
    else
    {
        printf("Nothing there to consume\n");
    }
}

int main()
{
    int ch;

    while(1)
    {
        printf("1.Producer\n2.Consumer\n3.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {

        case 1:
                producer();
                break;

        case 2: consumer();
                break;
        case 3 : exit(0);
                  break;

        default : printf("Wrong choice");
                    break;
        }
    }

return 0;
}
