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

const int maxn = 2e5 + 5;

struct pasangan{
	int banyak, idxAwal;
};
struct cmp{
	bool operator() (const pasangan& a, const pasangan& b) const{
		if(a.banyak==b.banyak){return a.idxAwal < b.idxAwal;}
		return a.banyak > b.banyak;	
	}
};

// bool cmp(pasangan a, pasangan b){
// 	if(a.banyak==b.banyak){return a.idxAwal < b.idxAwal;}
// 	return a.banyak > b.banyak;
// }

int main(){
	int n,i,j;
	// scanf("%d",&n);
	// for(i=0;i<n;i++){scanf("%d",&a[i]);}
	
	set<pasangan,cmp> s;
	set<pasangan,cmp>::iterator it;
	scanf("%d",&n);
	// for(i=0;i<n;i++){
	// 	int banyak, idxAwal;
	// 	scanf("%d %d",&banyak,&idxAwal);
	// 	a.banyak = banyak;
	// 	a.idxAwal = idxAwal;
	// 	s.insert(a);
	// }
	// for(it=s.begin();it!=s.end();it++){
	// 	a = *it;
	// 	printf("%d %d\n",a.banyak, a.idxAwal);
	// }
	// s.erase({1,2});
	// s.erase({1,1});
	// printf("setelah dihapus\n");
	// for(it=s.begin();it!=s.end();it++){
	// 	a = *it;
	// 	printf("%d %d\n",a.banyak, a.idxAwal);
	// }

	pasangan b;
	int lastIdx[maxn];
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int curBil = 0;
	int banyak = 0, idxAwal = -1;
	for(i=0;i<n;i++){
		if(a[i]!=curBil){
			banyak = 0;
			b.banyak = banyak; b.idxAwal = idxAwal;
			lastIdx[idxAwal] = i-1;
			s.insert(b);
			curBil = a[i];
		}
		banyak++;
	}
	return 0;
};