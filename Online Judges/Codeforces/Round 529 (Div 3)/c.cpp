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

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int i,j;
	int banyak = __builtin_popcount(n);
	if(banyak > k){printf("NO\n"); return 0;}
	if(n < k){printf("NO\n"); return 0;}
	vi listBil;
	printf("YES\n");
	priority_queue<int> pq;
	for(i=0;i<31;i++){
		if((1<<i) & n){
			// listBil.pb(1<<i);
			pq.push(1<<i);
			// printf("dipush: %d\n",1<<i);
		}
	}
	
	while(pq.size() < k){
		int front = pq.top(); pq.pop();
		pq.push(front/2); pq.push(front/2);
	}
	while(!pq.empty()){
		printf("%d ",pq.top());
		pq.pop();
	}
	printf("\n");
	return 0;
};