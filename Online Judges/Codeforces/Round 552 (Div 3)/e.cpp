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

const int maxn = 2e5 + 4;

int pref[maxn], nex[maxn];
int a[maxn];
int n,k;
set<int> s;
int ans[maxn];

int toRight(int idx, int id) {
	int cnt = 0;
	if(idx == -1){return -1;}
	while(cnt<k && idx != -1){
		ans[idx] = id;
		s.erase(a[idx]);
		cnt++;
		idx = nex[idx];
	}
	return idx;
}

int toLeft(int idx, int id) {
	int cnt = 0;
	if(idx == -1){return -1;}
	// printf("left\n");
	while(cnt < k && idx != -1){
		// printf("idx: %d cnt: %d\n",idx,cnt);
		ans[idx] = id;
		s.erase(a[idx]);
		cnt++;
		idx = pref[idx];
		// printf("ke idx: %d\n",idx);
	}
	return idx;
}

int main(){
	int i,j;
	scanf("%d %d",&n,&k);
	int idx[maxn];
	
	
	
	memset(pref, -1, sizeof pref); memset(nex, -1, sizeof nex);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		s.insert(a[i]);
		idx[a[i]] = i;
		if(i){pref[i] = i-1;}
		if(i < n-1){nex[i] = i+1;}
	}
	int id = 0;
	
	while(!s.empty()) {
		int maks = *--s.end();
		int indeks = idx[maks];
		// printf("maks: %d indeks: %d\n",maks, indeks);
		s.erase(maks);
		ans[indeks] = id;
		int ne = toRight(nex[indeks], id);
		int pre = toLeft(pref[indeks], id);
		// printf("ne: %d pre: %d\n",ne, pre);
		nex[pre] = ne;
		pref[ne] = pre;
		id = 1 - id;
	}
	for(i=0;i<n;i++){
		printf("%d",ans[i]+1);
	}
	printf("\n");
	return 0;
};