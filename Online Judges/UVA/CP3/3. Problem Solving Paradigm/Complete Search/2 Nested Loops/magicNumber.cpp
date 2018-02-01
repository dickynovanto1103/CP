#include <bits/stdc++.h>

using namespace std;
#define unvisited -1
#define visited 1
typedef vector<int> vi;
typedef long long ll;
int n, catat[11], cnt;
ll N;
bool pernah[11], found;
vi dfs_num;
bool isAllBeda(ll bil){
	dfs_num.assign(10,unvisited);
	while(bil>0){
		int a = bil%10;
		if(dfs_num[a]==unvisited){dfs_num[a] = visited;}
		else{return false;}
		bil/=10;
	}
	return true;
}
void solve(int kedalaman){
	if(found){return;}
	int i;
	ll bil;
	if(kedalaman==n){
		
		if(catat[0]>0){
			bil = 0;
			for(i=0;i<n;i++){
				int v = catat[i];
				bil*=10; bil+=catat[i];
			}
			//printf("bil: %lld N: %lld\n",bil,N);
			ll total = bil*N;
			if(total>9876543210){found = true;}
			else{
				if(isAllBeda(total)){
					printf("%lld / %lld = %lld\n",total,bil,N);
				}
			}
			
		}
		
		
		//printf("cnt menjadi: %d\n",cnt);
	}else{
		for(i=0;i<=9;i++){
			if(!pernah[i]){
				catat[kedalaman] = i;
				pernah[i] = true;
				solve(kedalaman+1);
				pernah[i] = false;
			}			
		}
	}
}



int main(){
	int tc,i,j, test=1;
	ll bil, total;
	scanf("%d",&tc);
	while(tc--){
		if(test==2){printf("\n");}
		scanf("%lld",&N);
		for(i=1;i<=10;i++){
			memset(pernah,false,sizeof pernah);
			found = false;
			n = i;		
			solve(0);
			if(found) break;
		}
		test=2;
	}

	

	//

	return 0;
}