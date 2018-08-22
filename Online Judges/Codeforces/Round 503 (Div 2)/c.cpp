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

const int maxn = 3e3 + 3;

int cnt[maxn], id[maxn],cost[maxn];

struct pasangan{
	int id, cnt, cost;
};

bool cmp(pasangan a, pasangan b){
	return a.cost < b.cost;
}

bool isWin(int m){
	int cnt1 = cnt[1];
	for(int i=2;i<=m;i++){
		if(cnt1 <= cnt[i]){return false;}
	}
	return true;
}

struct compare{
	bool operator() (const pasangan &a, const pasangan &b) const{
		if(a.cnt == b.cnt){
			return a.cost > b.cost;
		}
		return a.cnt < b.cnt;
	}
};

priority_queue<pasangan,vector<pasangan>,compare> pq;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int temp[maxn];

	for(i=0;i<n;i++){
		scanf("%d %d",&id[i],&cost[i]);
		cnt[id[i]]++;
		temp[id[i]] = cnt[id[i]];
	}
	pasangan pas[maxn];
	int counter = 0;
	for(i=0;i<n;i++){
		if(id[i] == 1){continue;}
		pas[counter].id = id[i]; pas[counter].cnt = cnt[id[i]]; pas[counter].cost = cost[i];
		counter++;
	}
	sort(pas, pas+counter, cmp);
	ll sum1 = 0;
	for(i=0;i<counter;i++){
		pq.push(pas[i]);
		if(isWin(m)){break;}
		sum1 += pas[i].cost;
		cnt[pas[i].id]--;
		cnt[1]++;
	}
	// printf("sum1: %lld\n",sum1);

	//reset cnt
	for(i=0;i<=m;i++){
		cnt[i] = temp[i];
	}
	ll sum2 = 0;
	while(!pq.empty()){
		pasangan front = pq.top(); pq.pop();
		int id = front.id, banyak = front.cnt, cost = front.cost;
		// printf("id: %d banyak; %d cost: %d\n",id,banyak,cost);
		if(banyak != cnt[id]){
			pasangan added;
			added.id = id; added.cnt = cnt[id]; added.cost = cost;
			pq.push(added);
		}else{
			if(isWin(m)){break;}
			cnt[id]--;
			cnt[1]++;
			sum2+=cost;
			// printf("ditambah: %d jd %lld\n",cost,sum2);
		}
	}

	printf("%lld\n",min(sum1,sum2));
	return 0;
};