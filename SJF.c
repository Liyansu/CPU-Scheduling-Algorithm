#include<stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int bt[],int p[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (bt[j] < bt[min_idx])
            min_idx = j;
           swap(&bt[min_idx], &bt[i]);           
           swap(&p[min_idx], &p[i]);
           
        
    }
}

void findWaitingTime(int processes[], int n,int bt[], int wt[])
{
	wt[0] = 0;
	for (int i = 1; i < n ; i++ )wt[i] = bt[i-1] + wt[i-1] ;
}
void findTurnAroundTime( int processes[], int n,int bt[], int wt[] ,int tat[])
{
 	for (int i = 0; i < n ; i++)
	tat[i] = bt[i] + wt[i];
}
void findavgTime( int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
  
	findWaitingTime(processes, n, bt, wt);
	findTurnAroundTime(processes, n, bt, wt, tat);
	printf("P\tBT\tWT\tTAT\n");
	
  for (int i=0; i<n; i++)
	{

		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf("P%d ",processes[i]);
		printf("\t%d ", bt[i] );
		printf("\t%d",wt[i] );
		printf("\t%d\n",tat[i] );
	}
	int s=(float)total_wt / (float)n;
	int t=(float)total_tat / (float)n;
	printf("Average waiting time = %d",s);
	printf("\n");
	printf("Average turn around time = %d ",t);
}

int main()
{
  int n;
  int processes[20];
  int burst_time[20];
  
  printf("How Many Processes ?\n");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    processes[i]=i+1;
    printf("\nEnter Brust Time of Process P%d ?\n",i+1);
    scanf("%d",&burst_time[i]);
   
  }	
 
  selectionSort(burst_time,processes,n);
	findavgTime(processes, n, burst_time);
	return 0;
}
