#include<stdio.h>
void main()
{

    int rows,cols,rowsum=0,colsum=0;
    int k=0,l=0;
    printf("Enter order of  matrix(rows and columns)\n");
    scanf("%d%d",&rows,&cols);
    int m[rows][cols];
    printf("\nEnter the elements");
    for(int i=0;i<rows;i++)
    {

    for(int j=0;j<cols;j++)
    {
        scanf("%d",&m[i][j]);
    }
    }

       for(int i=0;i<rows;i++)
    {

    for(int j=0;j<cols;j++)
    {
        rowsum+=m[i][j];
    }
    printf("\nSum of %d row= %d",(k+1),rowsum);
    k++;
    rowsum-=rowsum;
    }
      for(int j=0;j<cols;j++)
    {

    for(int i=0;i<rows;i++)
    {
        colsum+=m[j][i];
    }
    printf("\nSum of %d column= %d",(l+1),colsum);
    l++;
    colsum-=colsum;
    }
}

