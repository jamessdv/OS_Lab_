#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	int n;
	printf("Enter the no. of processes: ");
	scanf("%d", &n );
	int bt[n], wt[n], tat[n];
	int var;

	printf("\nEnter the burst times for all processes:\n");
	for(int i=0; i<n; i++){
		scanf("%d", &var);
		bt[i]=var;	
	}

	printf("Given input is:");
	printf("\nProcess \tBT\n");
	for(int i=0; i<n; i++){
                printf("P%d \t\t%d\n", i+1, bt[i]);
        }

	wt[0]=0; 
	for(int i=1; i<n; i++){
        	wt[i]=bt[i-1]+wt[i-1];
        }

	for(int i=0; i<n; i++){
                tat[i]=bt[i]+wt[i];
        }

	int avg_wt=0, avg_tat=0;
	for(int i=0;i<n;i++){
		avg_wt += wt[i];
		avg_tat += tat[i];
	}
	avg_wt /= n;
	avg_tat /= n;

	printf("Required Output;");
        printf("\nProcess \tBT \t\tWT \t\tTAT\n");
        for(int i=0; i<n; i++){
                printf("P%d \t\t%d \t\t%d \t\t%d\n", i+1, bt[i], wt[i], tat[i]);
        }

	printf("The average Waiting time is: %d\n", avg_wt);
	printf("The average Turnaround time is: %d\n", avg_tat);


}
