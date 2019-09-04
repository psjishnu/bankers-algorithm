#include<stdio.h>
int i,j,m,n;
int safety(int need1[20][20],int finish1[20],int work1[20],int alloc1[20][20]);
int kl=1;
int main()
{
	int avail[20],max[20][20],alloc[20][20],alloc2[20][20],need[20][20],work[20],work3[20],finish[20],flag,K,rq[20];
	printf("enter no.of resources and no.of processes: ");
	scanf("%d %d",&m,&n);
	printf("\nenter available resourses if each type");
	for(i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
	}
	printf("\nenter max matrix");
	for(i=0;i<n;i++)
	{	printf("P%d: ",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}	
	}
	printf("\nenter allocation matrix\n");
	for(i=0;i<n;i++)
	{	printf("P%d: ",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	for(i=0;i<m;i++)
	{
		work[i]=avail[i];
		work3[i]=avail[i];
	}
		for(i=0;i<m;i++)
		printf("  w1  %d",work[i]);

	printf("\nthe need matrix\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<m;j++)
		{
			printf("%d\t",need[i][j]);
		}
	}
	
	printf("\n");

	if(safety(need,finish,work3,alloc)==0)
		printf("\nThe system is not is safe state\n");
	else
		printf("\nThe system is in safe state\n");	
int cg;
printf("\npress 1 to continue to resourse-rqst algorithm\n");
scanf("%d",&cg);
if(cg==1)		
{	printf("enter row ro change alocation : ");
	int r;
	scanf("%d",&r);
	printf("\nenter request ");
	for(int y=0;y<m;y++)
	{
		scanf("%d",&rq[y]);
	}
	int p=1,q=1;
	for(i=0;i<m;i++)
	{
		if(rq[i]>need[r-1][i])
			p=0;
	}
	if(p==1)
	{//	printf("\ncompleted stage 1\n");
		if(rq[i]>avail[i])
		q=0;
	}
	if(p==1 && q==1)
	{//	printf("\ncompleted stage 2\n");
		for(int y=0;y<m;y++)
		{
			work3[y]=work3[y]-rq[y];
			alloc[r-1][y]=alloc[r-1][y]+rq[y];
			need[r-1][y]=need[r-1][y]-rq[m];
		}
			printf("\nthe need matrix2\n");
		for(i=0;i<n;i++)
		{
			printf("\n");
			for(j=0;j<m;j++)
			{
				printf("%d\t",need[i][j]);
			}
		}
		if(safety(need,finish,work,alloc)==0)
			printf("\nThe system is not is safe state in case 2\n");
		else
			printf("\nThe system is in safe state in case 2\n");
	}
	else
		printf("\nIt is not possible\n");
	
}	
	return 0;
	
}

int safety(int need1[20][20],int finish1[20],int work1[20],int alloc1[20][20])
{	

	printf("\nentered %d\n",kl);kl++;
	for(i=0;i<n;i++)
	{	
		finish1[i]=0;
	}
	int count=0,safe1=1,flag=1,k;
	while(count<n)
	{//	printf("\n%d1 %d1\n",m,n);
		for(i=0;i<n;i++)
		{   	if(finish1[i]==0)
					{
						flag=1;
						for(k=0;k<m;k++) 
						{
							if(need1[i][k]>work1[k])
								{
									flag= 0;
									break;
								
								}
						}
						if(flag==1 )
						{	for(j=0;j<m;j++)
							{
								work1[j]= work1[j]+alloc1[i][j]; 
								
							} 
							finish1[i]=1; 
							printf("\ncompleted P%d  ",i); 
						}
					
					}
			
		}count ++;
	}
	for(i=0;i<n;i++)
	{	
		if(finish1[i]==0)
			safe1=0;
			
	}
	return safe1;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
