#include<stdio.h>

struct process{
	int at;
	int bt;
	int wt;
	int st;
	int ft;
	int ta;
	float pr;
}p[10];
int n;
void arsort(){
	struct process temp;
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(p[i].at>p[j].at){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}
void prsort(){
	struct process temp;
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(p[i].pr<p[j].pr){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}

void display(){
	int i;
	printf("Process\tArrival time\tBurst time\n");
	for(i=0;i<n;i++){
		
		printf("   P%d\t%d\t\t%d  \n",i+1,p[i].at,p[i].bt);
	}
}





int main(){
	printf("Enter number of processes : ");
	scanf("%d",&n);
	printf("Enter the arrival and burst time of each process: ");
	for(int i=0;i<n;i++){
		printf("\n P%d Arrival:",i+1);
		scanf("%d",&p[i].at);
		printf("\n P%d Burst:",i+1);
		scanf("%d",&p[i].bt);	
	}
	printf("\n Entered Data: \n");
	display();
	printf("\n\n");
	printf("\n Sorted According to Arrival Time: \n");
	printf("\n\n");
	arsort();
	display();
	printf("\n\n");
	int i=0;
	for(int j=i+1;j<n;j++){
		p[i].pr=100;
		if(p[j].at<p[i].bt){
			p[j].wt=p[i].bt-p[j].at;
			p[j].pr=1+((float)p[j].wt/(float)p[j].bt);
		}
	}
	printf("\n Sorted According to Priority: \n");
	prsort();
	printf("\n\n");
	display();
	printf("\n\n");
	int totwt,totta;
	for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            p[i].st=p[i].at;
            p[i].wt=p[i].st-p[i].at;
            p[i].ft=p[i].st+p[i].bt;
            p[i].ta=p[i].ft-p[i].at;
        }
        else
        {
            p[i].st=p[i-1].ft;
            p[i].wt=p[i].st-p[i].at;
            p[i].ft=p[i].st+p[i].bt;
            p[i].ta=p[i].ft-p[i].at;
        }
        totwt+=p[i].wt;
        totta+=p[i].ta;
    }
    float awt=(float)totwt/n;
    float ata=(float)totta/n;
    printf("\nProcess  arrivaltime  executiontime  priority  waitingtime  TAtime");
    for(i=0; i<n; i++)
        printf("\nP%d          %d          %d           %.3f         %d        %d",i+1,p[i].at,p[i].bt,p[i].pr,p[i].wt,p[i].ta);
    printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaroundtime is:%f",ata);

	return 0;
		
	
}
