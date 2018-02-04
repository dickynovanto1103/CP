#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isWatered[4000];
bool isAllWatered(int n){
	int i;
	for(i=1;i<=n;i++){
		if(!isWatered[i]){return false;}
	}
	return true;
}

int main(){
	int tc,n,k,i,j;
	scanf("%d",&tc);
	
	while(tc--){
		memset(isWatered,false, sizeof isWatered);
		queue<int> q;
		scanf("%d %d",&n,&k);
		while(k--){
			int idx;
			scanf("%d",&idx);
			q.push(idx);
		}
		//mulai hari pertama

		//bfs
		int day = 1;
		vi listIdxTemp;
		while(true){
			while(!q.empty()){	
				int idx = q.front(); q.pop();
				isWatered[idx] = true;
				if((idx-1)>=1 && !isWatered[idx-1]){
					listIdxTemp.pb(idx-1);
				}
				if((idx+1)<=n && !isWatered[idx+1]){
					listIdxTemp.pb(idx+1);
				}
				
			}
			for(i=0;i<listIdxTemp.size();i++){
				q.push(listIdxTemp[i]);
			}
			if(isAllWatered(n)){printf("%d\n",day); break;}
			else{
				day++;
				listIdxTemp.clear();
			}
		}
		
	}
	
	return 0;
};