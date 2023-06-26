#include<stdio.h>
void main(){
int a[25],p[25],j,t,n,i,wt=0,swt=0,tt=0,stt=0;
printf("Shortest time");
printf("enter the number of jobs");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("\n Service time or Burst Time of %d",i);
scanf("%d",&a[i]);
p[i]=i;
}
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(a[i]>a[j]){
t=a[i];
a[i]=a[j];
a[j]=t;
t=p[i];
}
}
}
printf("\n Process\t\tBurstTime\t\tWaiting Time\t\tTurnAroundTime");
for(i=0;i<n;i++){
swt=swt+wt;
tt=tt+a[i];
stt=stt+tt;
printf("\nP%d\t\t%d\t\t\t%d\t\t\t%d",i,a[i],wt,tt);
wt=wt+a[i];
}
printf("Avg Waiting Time = %d",swt/n);
printf("Avg Turn Around Time =%d",stt/n);
}
