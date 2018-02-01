#include <bits/stdc++.h>
//#include <unordered_map>

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
	int idx, l, r;
};
const int maxn = 1e5 + 10;
int a[maxn];
int blockSize;
int ans;
int cnt[maxn];
int listans[maxn];
query q[maxn];
unordered_map<int,int> mapper;


bool cmp(query a, query b){
	if(a.l/blockSize != b.l/blockSize){return a.l/blockSize < b.l/blockSize;}
	return a.r < b.r;
}

void add(int indeks){
	int v = a[indeks];
	int idx = mapper[v];

	cnt[idx]++;
	if(cnt[idx]==v){ans++;}
	else{
		if((cnt[idx]-1)==v){ans--;}//sebelumnya udah sama..terus ketambahan jadi ga sama..jawaban berkurang
	}
}

void remove(int indeks){
	int v = a[indeks];
	int idx = mapper[v];
	cnt[idx]--;
	if(cnt[idx]==v){ans++;}
	else{
		if((cnt[idx]+1)==v){ans--;}//sebelum dikurangin udah sama kyk v..begitu dikurangin nilai cnt nya..jd ga sama v lagi..nilai ans dikurangin 1
	}
}


int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	

	blockSize = (int)sqrt(n);
	set<int> s;
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		s.insert(a[i]);
	}
	int counter = 0;
	for(set<int>::iterator it=s.begin();it != s.end(); it++){
		int bil = *it;
		mapper[bil] = counter++;
	}
	//printf("ans\n");
	for(i=0;i<m;i++){
		int kiri, kanan;
		scanf("%d %d",&kiri,&kanan);
		kiri--; kanan--;
		q[i].l = kiri; q[i].r = kanan;
		q[i].idx = i;
	}
	sort(q,q+m,cmp);
	ans = 0;
	int start = q[0].l, end = start; add(start);
	for(i=0;i<m;i++){
		int kiri = q[i].l, kanan = q[i].r;
		while(start > kiri){//ditambahin
			add(--start);
		}
		while(end < kanan){
			add(++end);
		}
		while(start < kiri){
			remove(start++);
		}
		while(end > kanan){
			remove(end--);
		}
		int indeks = q[i].idx;
		listans[indeks] = ans;
	}
	for(i=0;i<m;i++){
		printf("%d\n",listans[i]);
	}

	return 0;
};