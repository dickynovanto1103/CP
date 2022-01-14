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
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	vi v;
	priority_queue<ii> pq;
	while(n--){
		string s;
		int x,y;
		cin>>s;
		if(s == "add") {
			scanf("%d %d",&x,&y);
			while(y--){
				v.pb(x);
			}
			printf("%d\n", (int)v.size());
		}else if(s == "del") {
			int banyak;
			scanf("%d",&banyak);
			int angka = -1;
			int penambahan = 0;
			while(banyak--){
				//pop jg dari priority queue
				while(pq.size() > 0 && pq.top().first == (v.size() - 1)) {
					penambahan += pq.top().second;
					// printf("penambahan: %d idx: %d\n", penambahan, (int)v.size() - 1);
					pq.pop();
					
				}
				int num = v.back() + penambahan;
				if(angka == -1){angka = num;}
				v.pop_back();
			}
			if(v.size() > 0) {
				pq.push(ii(v.size() - 1, penambahan));
			}
			printf("%d\n", angka);
		}else if(s == "adx") {
			int tambah;
			scanf("%d",&tambah);
			pq.push(ii(v.size() - 1, tambah));
		}else if(s == "dex") {
			int kurang;
			scanf("%d",&kurang);
			pq.push(ii(v.size() - 1, -kurang));
		}
	}
	
	return 0;
};