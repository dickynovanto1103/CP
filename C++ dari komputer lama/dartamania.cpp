#include <bits/stdc++.h>

using namespace std;
typedef pair <int,int> ii;
typedef pair <ii,int> iii;


int main(){
	int n,i,j,k,combination,permutation,bilangan;
	bool isallowed[62],found;
	iii temp;
	vector <int> arr,bil;
	set <iii> usedvalues;
	memset(isallowed,false,sizeof isallowed);
	for(i=1;i<=20;i++){
		isallowed[i]=true; isallowed[i*2]=true; isallowed[i*3]=true;
	}
	isallowed[50]=true; isallowed[0]=true;
	int cnt=0;
	for(i=0;i<=60;i++){
		if(isallowed[i]){
			//printf("yang boleh: %d\n",i); 
			arr.push_back(i); cnt++;
		}
	}
	//for(i=0;i<cnt;i++){printf("%d\n",arr[i]);}
	//printf("total yang boleh: %d\n",cnt);
	while(scanf("%d",&n),(n>0)){
		found=false; permutation=0;
		for(i=0;i<cnt;i++){
			if(n-arr[i]>=0){
				for(j=0;j<cnt;j++){
					int sisa = n-arr[i];
					if(sisa - arr[j]>=0){
						for(k=0;k<cnt;k++){
							bilangan = sisa - arr[j];
							bil.clear();
							if((bilangan-arr[k])==0){found=true; 
								permutation++; bil.push_back(i); bil.push_back(j); bil.push_back(k); sort(bil.begin(),bil.end());
								temp=make_pair(ii(bil[0],bil[1]),bil[2]);
								usedvalues.insert(temp);
							}
						}	
					}
					
				}	
			}
			
		}
		if(!found){printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);}
		else{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n,usedvalues.size());
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",n,permutation);
		}
		for(i=1;i<=70;i++){printf("*");}
		printf("\n");
		usedvalues.clear();
	}
	printf("END OF OUTPUT\n");
	return 0;
}