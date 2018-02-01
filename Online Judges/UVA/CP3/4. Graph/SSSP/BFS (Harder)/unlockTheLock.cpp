#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 10000;

int main(){
	int lock,unlock,n;
	int a[15],i,j;
	int dist[maxn];
	int test = 1;
	while(scanf("%d %d %d",&lock,&unlock,&n),(lock||unlock||n)){
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		fill(dist,dist+maxn,inf);
		printf("Case %d: ",test++);
		queue<int> q; q.push(lock);
		dist[lock] = 0;
		while(!q.empty()){
			int front = q.front(); q.pop();
			for(i=0;i<n;i++){
				int nilai = (front%maxn + a[i]%maxn)%maxn;
				if(dist[nilai]==inf){
					dist[nilai] = dist[front] + 1; q.push(nilai);
				}
			}
		}
		if(dist[unlock]==inf){printf("Permanently Locked\n");}
		else{printf("%d\n",dist[unlock]);}
	}
	return 0;
};