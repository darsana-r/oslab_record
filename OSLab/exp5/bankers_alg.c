#include<stdio.h>
int main()
{
	int np,nr;
	printf("Enter the number of processes: ");
	scanf("%d",&np);
	printf("Enter the number of  types of resources: ");
	scanf("%d",&nr);
	
	int erv[nr],max_m[np][nr],cur[np][nr],pv[nr],avail[nr],need[np][nr],csv[np];

	//existing resource vector
	printf("Enter the total number of instances of each type of resources\n");
	for(int i=0;i<nr;i++){
		printf("number of instances of resource %d: ",i);
		scanf("%d",&erv[i]);
	}
	
	printf("\nEnter the maximum number of resources required by each process\n");
	for(int i=0;i<np;i++){
		for(int j=0;j<nr;j++){
			printf("enter max. no: of R%d resources required by P%d : ",j,i);
			scanf("%d",&max_m[i][j]);
		}
	}
	
	//possessed vector
	for(int i=0;i<nr;i++){
		pv[i]=0;
	}
	//completed status vector
	for(int i=0;i<np;i++){
		csv[i]=0;
	}

	printf("Enter the current allocation of each resourses required by each process\n");
	for(int i=0;i<np;i++){
		for(int j=0;j<nr;j++){
			printf("enter current allocation of R%d resoursesto P%d : ",j,i);
			scanf("%d",&cur[i][j]);
			pv[j] += cur[i][j];
		}
	}
	
	//available resource vector
	for(int i=0;i<nr;i++){
		avail[i]=erv[i]-pv[i];
	}
	
	//need matrix
	for(int i=0;i<np;i++){
		for(int j=0;j<nr;j++){
			need[i][j]=max_m[i][j]-cur[i][j];
		}		
	}
	
	printf("\nMax matrix:\n");
	for(int i=0;i<np;i++){
		for(int j=0;j<nr;j++){
			printf("%d  ",max_m[i][j]);
		}
		printf("\n");
	}

	printf("\nCurrent allocation matrix:\n");
	for(int i=0;i<np;i++){
		for(int j=0;j<nr;j++){
			printf("%d  ",cur[i][j]);
		}
		printf("\n");
	}

	printf("\nNeed matrix\n");
	for(int i=0;i<np;i++){
		for(int j=0;j<nr;j++){
			printf("%d  ",need[i][j]);
		}printf("\n");			
	}
	printf("existing resource vector:\n");
	for(int i=0;i<nr;i++){
		printf("%d ",erv[i]);
	}
	printf("\n");
	printf("Possess vector\n");
	for(int i=0;i<nr;i++){
		printf("%d ",pv[i]);
	}
	printf("\n");
	printf("available resource vector\n");
	for(int i=0;i<nr;i++){
		printf("%d ",avail[i]);
	}

	int change_comp,safe,flag,ans[np];
	for(int i=0;i<np;i++){
		change_comp=0;
		for(int j=0;j<np;j++){
			if(csv[j]==0){
				flag=1;
				for(int k=0;k<nr;k++){
					if(avail[j]<need[k][k]){
					flag=0;
					break;
					}	
				}
			}
			if(flag==1){
				csv[j]=1;
				for(int k=0;k<nr;k++){
					avail[k] += need[j][k];
				}
				change_comp=1;
			}
		}
		if(change_comp==0){
			safe=0;
			break;
		}else{ safe=1;
			for(int j=0;j<np;j++){
				if(csv[j]==0){safe=0;break;}
			}
		}
	}
	if(safe==1){
		printf("The state is SAFE\n");
		
	}else{
		printf("The state is UNSAFE\n");
	}
}
