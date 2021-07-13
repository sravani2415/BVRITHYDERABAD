#include<stdio.h>
int main()
{
    int i,nop,ms=15,la,pa,ps,p[100],frameno,offset;
    int choice =0;
    printf("\nYour memory size is %d",ms);
    printf("Enter page size\n");
    scanf("%d",&ps);
    nop=ms/ps;
    for(i=0;i<nop;i++)
    {
        printf("enter the frame of page%d\n",i+1);
        scanf("%d",&p[i]);
    }
    do
    {
        printf("\n enter the logical address\n");
        scanf("%d",&la);
        frameno=la/ps;
        offset=la%ps;
        pa=(p[frameno]*ps)+offset;
        printf("pysical address is %d",pa);
        printf("\ndo u want to continue(1/0)");
        scanf("%d",&choice);

    }
    while(choice==1);
    return 0;}

