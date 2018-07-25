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

int main(){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		set<int> s;
		multiset<int> mul;
		for(i=0;i<n;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			int selisih = a - b;
			int jumlah = a+b;
			s.insert(selisih); s.insert(jumlah);
			mul.insert(selisih); mul.insert(jumlah);
		}
		set<int>::iterator it;
		ll banyakKombinasi = 0;
		for(it=s.begin();it!=s.end();it++){
			int bil = *it;
			ll jumlah = mul.count(bil);
			banyakKombinasi += (jumlah*(jumlah-1LL));
		}
		ll total = (ll)n*(ll)n;
		double peluang = (double)banyakKombinasi/(double)total;
		printf("%.8lf\n",peluang);
	}
	
	
	return 0;
};