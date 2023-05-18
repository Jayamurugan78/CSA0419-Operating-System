#include<stdio.h>
int main()
{
int a[2][2],i,j,n,m;
printf("Enter the row:");
scanf("%d",&n);
printf("Enter the column:");
scanf("%d",&m);
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("\n enter %d %d value",i,j);
scanf("%d",&a[i][j]);
}

}
for (i=0;i<n;i++)
{
    printf("\n");
    for(j=0;j<n;j++)
    {
        printf("\t %d",a[i][j]);
    }
}
}
