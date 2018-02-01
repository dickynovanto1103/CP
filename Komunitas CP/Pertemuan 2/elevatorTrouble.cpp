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

int dist[1000010];
queue<int> q;

int main(){
	int i,f,start,end,u,d;
	scanf("%d %d %d %d %d",&f,&start,&end,&u,&d);
	for(i=1;i<=f;i++){dist[i] = inf;}
	dist[start] = 0; q.push(start);
	while(!q.empty()){
		int front = q.front(); q.pop();
		int hasilNaik = front + u, hasilTurun = front - d;
		if(hasilNaik<=f && dist[hasilNaik]==inf){
			dist[hasilNaik] = dist[front] + 1;
			q.push(hasilNaik);
		}
		if(hasilTurun>=1 && dist[hasilTurun]==inf){
			dist[hasilTurun] = dist[front] + 1;
			q.push(hasilTurun);
		}
	}
	if(dist[end]==inf){printf("use the stairs\n");}
	else{printf("%d\n",dist[end]);}
	return 0;
};