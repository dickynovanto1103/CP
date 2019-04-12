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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 22;

int n;

bool isValid(int x){
	return x>=0 && x<n;
}

int d[] = {-1,1};

void selfMin(int &a, int b){
	a = min(a, b);
}

void selfMax(int &a, int b){
	a = max(a, b);
}

int main(){
	int p,i,j;
	scanf("%d %d",&n,&p);
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int minim[maxn], maks[maxn];
	fill(minim, minim+maxn, inf);
	fill(maks, maks+maxn, -inf);

	for(i=0;i<(1<<n);i++){
		int dist[n];
		// printf("i: %d\n",i);
		queue<int> q;
		for(j=0;j<n;j++){
			if(i & (1<<j)){
				dist[j] = 0;
				q.push(j);
			}else{
				dist[j] = inf;	
			}
		}
		// printf("sebelum bfs\n");
		while(!q.empty()){
			int front = q.front(); q.pop();
			for(j=0;j<2;j++){
				int baru = front + d[j];
				if(dist[baru] == inf){
					dist[baru] = dist[front] + 1;
					q.push(baru);
				}
			}
		}
		// printf("bisa bfs\n");
		vii listPas;
		for(j=0;j<n;j++){
			int waktu = dist[j] + a[j];
			listPas.pb(ii(waktu, j));
			// printf("dipush %d %d\n",waktu, j);
		}
		sort(listPas.begin(), listPas.end());
		int rank = 0;
		int curTime = 0;
		for(j=0;j<n;j++){
			if(listPas[j].first != curTime){
				rank = j + 1;
				curTime = listPas[j].first;
			}
			int idx = listPas[j].second;
			selfMax(maks[idx], rank);
			selfMin(minim[idx], rank);
		}

	}
	if(p == 1){
		for(i=0;i<n;i++){
			printf("%d\n",minim[i]);
		}
	}else{
		for(i=0;i<n;i++){
			printf("%d\n",maks[i]);
		}
	}

	return 0;
};