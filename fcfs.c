#include <stdio.h>
int main(){
int a[25],i,n,wt=0,swt=0,tt=0,stt=0;
printf("Enter the number of jobs");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("Enter the Service time/Burst time");
scanf("%d",&a[i]);
}
printf("Process \t Burst Time \t\t Waiting Time \t\t Turn Around Time");
for(i=0;i<n;i++){

swt+=wt;
tt+=a[i];
stt+=tt;
printf("P%d \t\t %d \t\t\t%d\t\t\t%d\t\t\t%d",i,a[i],wt,tt);
wt+=a[i];
}
printf("Avg Waiting Time : %d",swt/n);
printf("Avg Turn Around Time : %d",stt/n);


}
