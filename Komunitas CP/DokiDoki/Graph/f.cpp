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

const int mod = 10000;

int main(){
	int awal, akhir, n,i,j;
	int tc = 1;
	int dist[10000];
	while(scanf("%d %d %d",&awal,&akhir,&n), (awal || akhir || n)) {
		printf("Case %d: ",tc++);
		for(i=0;i<mod;i++){dist[i] = inf;}
		int a[13];
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		queue<int> q;
		q.push(awal);
		
		dist[awal] = 0;
		while(!q.empty()){
			int front = q.front(); q.pop();
			for(i=0;i<n;i++){
				int angkaBaru = front + a[i];
				angkaBaru%=mod;
				if(dist[angkaBaru]==inf){
					dist[angkaBaru] = dist[front] + 1;
					q.push(angkaBaru);
				}
			}
		}
		if(dist[akhir]==inf){printf("Permanently Locked\n");}
		else{printf("%d\n",dist[akhir]);}
	}
	return 0;
};