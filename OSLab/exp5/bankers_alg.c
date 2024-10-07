#include<stdio.h>
int main()
{
	int np,nr;
	
	printf("Enter the number of processes: ");
	scanf("%d",&np);

	printf("Enter the number of resources: ");
	scanf("%d",&nr);

	int erv[nr],max_m[np][nr],cur[np][nr],pv[nr],avail[nr],need[np][nr],csv[np];

	//existing resource vector
	printf("Enter the existing resource vector:\n");
	for(int i=0;i<nr;i++){
		scanf("%d",&erv[i]);
	}
	printf("existing resource vector:\n");
	for(int i=0;i<nr;i++){
		printf("%d ",erv[i]);
	}

	printf("\nEnter the max matrix:\n");
	for(int i=0;i<np;i++){
		printf("process %d\n",i);
		for(int j=0;j<nr;j++){
			scanf("%d",&max_m[i][j]);
		}
	}
	
	printf("\nmax matrix:\n");
	for(int i=0;i<np;i++){
		for(int j=0;j<nr;j++){
			printf("%d ",max_m[i][j]);
		}
		printf("\n");
	}
	//
	for(int i=0;i<nr;i++){
		pv[i]=0;
	}


	//completed status vector
	for(int i=0;i<np;i++){
		csv[i]=0;
	}

	printf("Enter the current allocation matrix:\n");
	for(int i=0;i<np;i++){
		printf("process %d\n",i);
		for(int j=0;j<nr;j++){
			scanf("%d",&cur[i][j]);
			pv[j] += cur[i][j];
		}
	}

	printf("\ncurrent allocation matrix:\n");
	for(int i=0;i<np;i++){
		for(int j=0;j<nr;j++){
			printf("%d ",cur[i][j]);

		}
		printf("\n");
	}

	//printf("available resource vector\n");
	for(int i=0;i<nr;i++){
		avail[i]=erv[i]-pv[i];
	}
	printf("available resource vector\n");
	for(int i=0;i<nr;i++){
		printf("%d ",avail[i]);
	}

	//printf("need matrix\n");
	for(int i=0;i<np;i++){
		for(int j=0;j<nr;j++){
			need[i][j]=max_m[i][j]-cur[i][j];
		}		
	}

	printf("\nneed matrix\n");
	for(int i=0;i<np;i++){
		for(int j=0;j<nr;j++){
			printf("%d ",need[i][j]);
		}printf("\n");			
	}

	
	
	/*for(int i=0;i<np;i++){
		for(int j=0;j<nr;j++){
			if(need[i][j]>avail[i]){
				break;
			}else if(j==nr-1){
				csv[i]=1;
				exec[k]=i;
				k++;
				for(int n=0;n<nr;n++){
					avail[n] += cur[i][j];
					cur[i][j]=0;
				}
				
			}
		}
		if(i==np-1){
			for(int m=0;m<nr;m++){
				if(avail[m]!=erv[m]){
					SAFE=0;
					break;
				}
			}
		}
		
	}

	if(SAFE==1){
		printf("The system is in SAFE state\n");
		printf("Execution sequence is\n");
		for(int i=0;i<np;i++){
			printf("%d ",exec[i]);
		}
		
	}else{
		printf("The system is UNSAFE state\n");
	}*/
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
				}change_comp=1;

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
		printf("The system is in SAFE state\n");
	}else{
		printf("The system is in UNSAFE state\n");

	}
}
