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

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	priority_queue<ii, vii, greater<ii> > pq;
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		pq.push(ii(bil, i+1));
	}
	ii a[200010];
	for(i=0;i<m;i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort(a, a+m);
	int ans[200010];
	for(i=0;i<m;i++){
		int butuh = a[i].first;
		int idx = a[i].second;
		bool assigned = false;
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int sisa = front.first, idxHotel = front.second;
			if(sisa >= butuh){
				ans[idx] = idxHotel;
				assigned = true;
				if(sisa > 0){pq.push(ii(sisa - butuh, idxHotel));}
				break;
			}
		}
		if(!assigned){ans[idx] = 0;}
	}

	for(i=0;i<m;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");

	return 0;
};