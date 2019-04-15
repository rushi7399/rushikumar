#include<stdio.h>
#include<conio.h>
void project();
class A
{
      int i,j,k,n,po,minimum,btime,temp,sum,ta; 
	  float wavg,tavg,tsum,wsum;   
	 public:	
	 void project(int n)
	 {
	    int process[n],burst[n],arrival[n],waiting[n],turn[n],start[n],finish[n],pri[n];	
	 	
	 	
	 	for(i=0;i<n;i++)
	 	{
	 		process[i]=i+1;
	 		printf("enter burst time  =  \t");
	 		scanf("%d",&burst[i]);
	 		printf("enter arrival time  =  \t");
	 		scanf("%d",&arrival[i]);
		 }
		 
		 for(i=0;i<n;i++)
		 {
		 for(j=0;j<n;j++)
		 {
		 	if(arrival[i]<arrival[j])
		 	{
		 		temp=process[j];
		 		process[j]=process[i];
		 		process[i]=temp;
		 		temp=arrival[j];
		 		arrival[j]=arrival[i];
		 		arrival[i]=temp;
		 		temp=burst[j];
		 		burst[j]=burst[i];
		 		burst[i]=temp;
			 }
		 	
		 }
	     }
	     k=1;
	 for(j=0;j<n;j++)
	 {
	 	btime=btime+burst[j];
	 	minimum=burst[k];
	 	for(i=k;i<n;i++)
	 	{
	 		if(btime>=arrival[i]&&burst[i]<=minimum)
	 		{
	 			temp=process[k];
	 			process[k]=process[i];
	 			process[i]=temp;
	 			temp=arrival[k];
	 			arrival[k]=arrival[i];
	 			arrival[i]=temp;
	 			temp=burst[k];
	 			burst[k]=burst[i];
	 			burst[i]=temp;
			 }
		 }
		  k++; }

waiting[0] = arrival[0];
     for(i=0; i<n; i++)
       {   
        if(i==0)
            start[i]=arrival[i];
        else
        start[i]=finish[i-1]; 
  if(start[i] < arrival[i]){ 
            start[i]=arrival[i];
          } 
        waiting[i]=start[i]-arrival[i];
        finish[i]=start[i]+burst[i];
        turn[i]=finish[i]-arrival[i];
        pri[i] = 1 + (waiting[i]/burst[i]);
         }
printf("\nProcess\t Burst\t Arrival\t Waiting Time\t Turn-around\tpriority" );
for(i=0;i<n;i++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d\t\t%d",process[i],burst[i],arrival[i],waiting[i],turn[i],pri[i]);
}
        for(i=0;i<n;i++){
             wsum=wsum+waiting[i];
             tsum=tsum+turn[i];
        }
        tavg=tsum/n;
        wavg=wsum/n;
    printf("\n Average turn around tim is %f",tavg);
    printf("\t Average waiting time is %f",wavg);
    }

}ob;	
main()
{
	 int n;
    printf("enter number of process  =  ");
	scanf("%d",&n);
	ob.project(n);
	
}


