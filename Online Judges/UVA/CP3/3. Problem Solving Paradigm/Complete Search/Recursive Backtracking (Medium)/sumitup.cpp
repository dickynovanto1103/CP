#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
bool found;
int counter;
vector<vi> AdjList;
void solve(int a[], int i, int tot, vi ans, int n){
	int j,k;
	if(tot==0){
		found = true;
		/*for(j=0;j<AdjList.size();j++){
			printf("node %d:", j);
			for(k=0;k<AdjList[j].size();k++){
				printf(" %d",AdjList[j][k]);
			}
			printf("\n");
		}*/
		//pengecekan ada ga di list
		vi temp;
		for( j=0;j<ans.size();j++){
			temp.push_back(ans[j]);
		}
		//cek temp ada di adjlist atau gga
		bool isSama = false;
		for( j=0;j<AdjList.size();j++){
			if(AdjList[j].size()==temp.size()){
				
				//printf("masuk sini\n");
				for(k=0;k<AdjList[j].size();k++){
					if(AdjList[j][k]!=temp[k]){
						//printf("%d %d\n",AdjList[j][k],temp[k]);
						break;
					}
				}
				if(k==AdjList[j].size()){isSama = true; break;}
			}
			
		}
		if(!isSama){
			for(j=0;j<ans.size();j++){
				if(j>0){printf("+");}
				printf("%d",ans[j]);
				AdjList[counter].push_back(ans[j]);

			}
			counter++;
			printf("\n");	
		}
		
	}else{
		for(int j=i+1;j<n;j++){
			if(tot-a[j]>=0){
				ans.push_back(a[j]);
				solve(a,j,tot-a[j],ans,n);
				ans.pop_back();
				solve(a,j,tot,ans,n);
			}
		}
	}
}

int main(){
	int t,n,a[12],i,j;
	while(scanf("%d %d",&t,&n),(t||n)){
		AdjList.assign(t,vi());
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		vi ans;
		found = false;
		printf("Sums of %d:\n",t);
		counter = 0;
		solve(a,-1,t,ans,n);
		if(!found){printf("NONE\n");}
		AdjList.clear();
	}
	return 0;
}