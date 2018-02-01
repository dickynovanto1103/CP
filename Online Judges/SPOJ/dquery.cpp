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

struct query{
	int idx,l,r;
};

const int maxn = 3e4 + 10;
int blockSize;
query q[200010];
int cnt[1000010];
int ans;
int listans[200010];
int a[maxn];

bool cmp(query a, query b){
	if(a.l/blockSize != b.l/blockSize){return a.l/blockSize < b.l/blockSize;}
	return a.r < b.r;
}

void add(int idx){
	cnt[a[idx]]++;
	if(cnt[a[idx]]==1){ans++;}
}

void remove(int idx){
	cnt[a[idx]]--;
	if(cnt[a[idx]]==0){ans--;}
}

int main(){
	int i,j,nquery,n;
	
	scanf("%d",&n);
	blockSize = (int)sqrt(n);
	//printf("blockSize: %d\n",blockSize);

	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	scanf("%d",&nquery);
	
	for(i=0;i<nquery;i++){
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].l--; q[i].r--;
		q[i].idx = i;
	}
	sort(q,q+nquery,cmp);
	ans = 0;
	int start = q[0].l, end = start; add(start);
	for(i=0;i<nquery;i++){
		int kiri = q[i].l, kanan = q[i].r;
		while(end<kanan){
			end++;
			add(end);
		}
		while(start>kiri){
			start--;
			add(start);
		}
		while(end>kanan){
			
			remove(end);
			end--;
		}
		while(start<kiri){
			
			remove(start);
			start++;
		}
		
		
		int indeks = q[i].idx;
		//printf("untuk indeks: %d ans jd: %d\n",indeks,ans);
		listans[indeks] = ans;
	}
	for(i=0;i<nquery;i++){
		printf("%d\n",listans[i]);
	}
	return 0;
};