#include<stdlib.h>
void main()
{

    int rows,sum=0;
    printf("Enter order of square matrix");
    scanf("%d",&rows);
    int m[rows][rows];
    printf("\nEnter the elements");
    for(int i=0;i<rows;i++)
    {

    for(int j=0;j<rows;j++)
    {
        scanf("%d",&m[i][j]);
        if(i==j)
        {

            sum+=m[i][j];
        }
    }
    }
    printf("Sum of left diagonal= %d",sum);


}
