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
	int node, id, titikAwal;
};

bool cmp(pasangan a, pasangan b){
	if(a.node == b.node){return a.id > b.id;}
	return a.node < b.node;
}

vector<pasangan> a;

int main(){
	int n,i,j;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		int awal, akhir;
		scanf("%d %d",&awal,&akhir);
		pasangan pas;
		pas.node = awal; pas.id = 1; pas.titikAwal = -1;
		a.pb(pas);
		pas.node = akhir; pas.id = 2; pas.titikAwal = awal;
		a.pb(pas);
	}
	sort(a.begin(), a.end(), cmp);
	int ukuran = a.size();
	multiset<int> s;
	multiset<int>::iterator it;
	ll ans = 0;
	for(i=0;i<ukuran;i++){
		pasangan pas = a[i];
		int node = pas.node, id = pas.id, titikAwal = pas.titikAwal;
		if(id == 2){
			it = s.find(titikAwal);
			s.erase(it);
		}else{
			ans+=((ll)s.size());
			// printf("ans jd: %lld\n",ans);
			s.insert(node);
		}
	}
	printf("%lld\n",ans);
	return 0;
};
