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

struct pasangan{
	int node, id, titikAwal;
};

bool cmp(pasangan a, pasangan b){
	if(a.node == b.node){return a.id > b.id;}
	return a.node < b.node;
}

int main(){
	int n,m,i,j;
	vector<pasangan> a;
	scanf("%d %d",&n,&m);
	pasangan pas1;

	for(i=0;i<n;i++){
		int awal, akhir;

		scanf("%d %d",&awal, &akhir);
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
	int last = 1;
	int ans = 0;
	for(i=0;i<ukuran;i++){
		int node = a[i].node, id = a[i].id, titikAwal = a[i].titikAwal;
		// printf("i: %d node: %d id: %d titikAwal; %d\n",i,node,id, titikAwal);
		if(id == 2){
			it = s.find(titikAwal);
			s.erase(it);
		}else{
			if(s.empty()){
				// printf("m: %d node\ns", );
				int batasBawah = min(m,node);
				int penambahan = batasBawah - last;
				if(penambahan > 0){
					// printf("node: %d last: %d\n",node, last);
					ans+=(penambahan);
					// printf("masuk sini\n");
				}
				
			}

			s.insert(node);
		}
		last = node;
		if(last >= m){break;}
	}

	if(last < m){
		ans+=(m-last);
	}

	printf("%d\n",ans);
	return 0;
};
