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

const int maxn = 2e5 + 10;
ll a[maxn];
ll cnt[1000010];
int blockSize;
ll ans;
query q[maxn];
ll listAns[maxn];

bool cmp(query a, query b){
	if(a.l/blockSize != b.l/blockSize){return a.l/blockSize < b.l/blockSize;}
	return a.r < b.r;
}

void add(int idx){
	ll v = a[idx];
	ans+=1LL*(2*cnt[v] + 1)*v;
	cnt[a[idx]]++;
}

void remove(int idx){
	ll v = a[idx];
	ans-=1LL*(2*cnt[v] - 1)*v;
	cnt[a[idx]]--;
}

int main(){
	int n,t,i,j;
	scanf("%d %d",&n,&t);
	blockSize = (int) sqrt(n);
	for(i=0;i<n;i++){scanf("%I64d",&a[i]);}
	for(i=0;i<t;i++){
		int kiri,kanan;
		scanf("%d %d",&kiri,&kanan);
		kiri--; kanan--;
		q[i].l = kiri; q[i].r = kanan;
		q[i].idx = i;
	}
	sort(q,q+t,cmp);
	//printf("test\n");
	ans = 0;
	int start = q[0].l, end = start; add(start);
	
	for(i=0;i<t;i++){
		int kiri = q[i].l, kanan = q[i].r;
		while(start>kiri){
			start--;
			add(start);
		}
		while(end<kanan){
			end++;
			add(end);
		}
		while(start<kiri){
			remove(start);
			start++;
		}
		while(end>kanan){
			remove(end);
			end--;
		}
		int indeks = q[i].idx;
		listAns[indeks] = ans;
	}
	for(i=0;i<t;i++){
		printf("%I64d\n",listAns[i]);
	}
	return 0;
};