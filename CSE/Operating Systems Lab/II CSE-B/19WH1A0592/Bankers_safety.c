#include<stdio.h>
int main() {
	int k=0,output[10],d=0,t=0,ins[5],i,available[5],allocated[10][5],need[10][5],max[10][5],pno,P[10],j,resource, count=0;
	printf("Enter the number of resources : ");
	scanf("%d", &resource);
	printf("Enter the max instances of each resources\n");
	for (i=0;i<resource;i++) 
	{
		available[i]=0;
		printf("%c = ",(i+65));
		scanf("%d",&ins[i]);
	}
	printf("Enter the number of processes : ");
	scanf("%d", &pno);
	printf("Enter the allocation matrix \n     ");
	for (i=0;i<resource;i++)
	printf(" %c",(i+65));
	printf("\n");
	for (i=0;i <pno;i++) 
	{
		P[i]=i;
		printf("P[%d]  ",P[i]);
		for (j=0;j<resource;j++) 
		{
			scanf("%d",&allocated[i][j]);
			available[j]+=allocated[i][j];
		}
	}
	printf("\nEnter the max matrix \n     ");
	for (i=0;i<resource;i++) 
	{
		printf(" %c",(i+65));
		available[i]=ins[i]-available[i];
	}
	printf("\n");
	for (i=0;i <pno;i++) 
	{
		printf("P[%d]  ",i);
		for (j=0;j<resource;j++)
		 scanf("%d", &max[i][j]);
	}
	printf("\n");
	A: d=-1;
	for (i=0;i <pno;i++) 
	{
		count=0;
		t=P[i];
		for (j=0;j<resource;j++) 
		{
			need[t][j] = max[t][j]-allocated[t][j];
			if(need[t][j]<=available[j])
			 count++;
		}
		if(count==resource) 
		{
			output[k++]=P[i];
			for (j=0;j<resource;j++)
			available[j]+=allocated[t][j];
		} else
		 P[++d]=P[i];
	}
	if(d!=-1) 
	{
		pno=d+1;
		goto A;
	}
	printf("-----<");
	for (i=0;i<k;i++)
	printf(" P[%d] ",output[i]);
	printf(">-----");
	getch();
}