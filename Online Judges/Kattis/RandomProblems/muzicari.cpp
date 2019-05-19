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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool cmp(ii a, ii b){
	return a.first > b.first;
}

int main(){
	int t,n,i,j;
	ii pas[550];
	scanf("%d %d",&t,&n);
	for(i=0;i<n;i++){
		scanf("%d",&pas[i].first);
		pas[i].second = i;
	}
	sort(pas, pas+n, cmp);
	int time[550];
	memset(time, -1, sizeof time);
	time[pas[0].second] = 0;
	if(n == 1){printf("0\n"); return 0;}
	else if(n == 2){
		printf("0 0\n");
		return 0;
	}else{
		time[pas[1].second] = 0;
	}
	int waktu = 0;
	priority_queue<int, vi, greater<int> > pq;
	pq.push(pas[0].first);
	pq.push(pas[1].first);
	
	int idx = 2;
	while(waktu <= t) {
		// printf("waktu: %d\n",waktu);
		while(!pq.empty() && pq.top() == waktu){
			pq.pop();
			time[pas[idx].second] = waktu;
			pq.push(waktu + pas[idx].first);
			printf("idx: %d dipush: %d tambah: %d\n",idx,waktu , pas[idx].first);
			assert(waktu + pas[idx].first <= t);
			
			idx++;
			if(idx >= n){break;}
		}
		if(idx >= n){break;}
		waktu++;
	}
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",time[i]);
	}
	printf("\n");
	return 0;
};