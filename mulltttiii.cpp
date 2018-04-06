#include<stdio.h>
#include<unistd.h>
int count(int a,int b,int *p,int n){
	int c=0;
	for(int i=0;i<n;i++){
		if((p[i]>a)&&(p[i]<=b)){
			c=c+1;
		}
	}
	return c; 
}
 
int rr(int limit,int arrival_time[],int burst_time[],int p[])
{ 
      int i, total = 0, x, counter = 0, time_quantum=4; 
      int wait_time = 0, turnaround_time = 0, temp[10]; 
      float average_wait_time, average_turnaround_time;
     
      
     
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d",p[i], burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
                  turnaround_time = turnaround_time + total - arrival_time[i]; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(arrival_time[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
}
int fcfs(int p3[],int bt3[],int n){
	int wt3[20],tat3[20],avwt=0,avtat=0,i,j;
   
 
    wt3[0]=0;    
 
    
    for(i=1;i<n;i++)
    {
        wt3[i]=0;
        for(j=0;j<i;j++)
            wt3[i]+=bt3[j];
    }
 
    
 
    
    for(i=0;i<n;i++)
    {
        tat3[i]=bt3[i]+wt3[i];
        avwt+=wt3[i];
        avtat+=tat3[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",p3[i],bt3[i],wt3[i],tat3[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);
 
   
	
}
int priority(int p2[],int bt2[],int pr2[],int n){
	int wt2[20],tat2[20],i,j,total=0,pos,temp,avg_wt,avg_tat;
    
 
    
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr2[j]<pr2[pos])
                pos=j;
        }
 
        temp=pr2[i];
        pr2[i]=pr2[pos];
        pr2[pos]=temp;
 
        temp=bt2[i];
        bt2[i]=bt2[pos];
        bt2[pos]=temp;
 
        temp=p2[i];
        p2[i]=p2[pos];
        p2[pos]=temp;
    }
 
    wt2[0]=0;    
 
    
    for(i=1;i<n;i++)
    {
        wt2[i]=0;
        for(j=0;j<i;j++)
            wt2[i]+=bt2[j];
 
        total+=wt2[i];
    }
 
    avg_wt=total/n;      
    total=0;
 
   
    for(i=0;i<n;i++)
    {
        tat2[i]=bt2[i]+wt2[i];     
        total+=tat2[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p2[i],bt2[i],wt2[i],tat2[i]);
    }
 
    avg_tat=total/n;     
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
    
}
int main(){
	int n;
	printf("\n enter total number of processes : ");
	scanf("%d",&n);
	int pro[n],bt[n],pr[n],arr[n];
	for(int i=0;i<n;i++){
		printf("\n enter process id : ");
		scanf("%d",&pro[i]);
		printf("\n enter burst time : ");
		scanf("%d",&bt[i]);
		printf("\n enter priority : ");
		scanf("%d",&pr[i]);
		printf("\n enter arrival time : ");
		scanf("%d",&arr[i]);
	}
	int c=count(0,2,pr,n);
	int d=count(2,6,pr,n);
	int e=count(6,20,pr,n);
	int p1[c],bt1[c],at[c],p2[d],bt2[d],pr2[d],p3[e],bt3[e];
	int k=0;
	for(int i=0;i<n;i++){
		if((pr[i]>0)&&(pr[i]<=2)){
			p1[k]=pro[i];
			bt1[k]=bt[i];
			at[k]=arr[i];
			k=k+1;
		}
	}
	k=0;
	for(int i=0;i<n;i++){
		if((pr[i]>2)&&(pr[i]<=6)){
			p2[k]=pro[i];
			bt2[k]=bt[i];
			pr2[k]=pr[i];
			k=k+1;
		}
	}
	k=0;
	for(int i=0;i<n;i++){
		if((pr[i]>6)&&(pr[i]<=20)){
			p3[k]=pro[i];
			bt3[k]=bt[i];
			k=k+1;
		}
	}

	for(int i=0;i<c;i++){
		printf("p[%d] : %d",p1[i],bt1[i]);
	}
	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
	rr(c,at,bt1,p1);
	priority(p2,bt2,pr2,d);
	fcfs(p3,bt3,e);
	
	
}
