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

int cariBanyakDigit(int n){
	int cnt = 0;
	while(n>0){
		cnt++;
		n/=10;
	}
	return cnt;
}

vector<multiset<int> > AdjList;

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	int a[maxn];
	AdjList.assign(11,multiset<int>());
	int digit[maxn];
	int maksDigit = 0;
	set<int> sDigit;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		int banyakDigit = cariBanyakDigit(a[i]);
		digit[i] = banyakDigit;
		sDigit.insert(banyakDigit);
		// printf("banyakDigit: %d dipush: %d\n",banyakDigit,a[i]);
		AdjList[banyakDigit].insert(a[i]%k);
		
	}
	vi listDigit;
	for(set<int>::iterator it = sDigit.begin();it!=sDigit.end();it++){
		listDigit.pb(*it);
	}

	ll hasilPower[] = {1LL,10LL,100LL,1000LL,10000LL,100000LL,1000000LL,10000000LL,100000000LL,1000000000LL,10000000000LL};
	ll ans = 0;
	// printf("k: %d\n",k);
	int ukuran = listDigit.size();
	for(i=0;i<n;i++){
		ll bil = a[i];
		// printf("i: %d\n",i);
		for(int d=0;d<ukuran;d++){
			// printf("j: %d\n",j);
			j = listDigit[d];
			ll cnt = 0;
			ll penambahan = hasilPower[j];
			ll mod1 = ((bil%k)*(penambahan%k))%k;
			bool termasuk = false;
			// printf("penambahan: %lld\n",penambahan);
			ll harapan;
			if(mod1 == 0){harapan = mod1;}
			else{harapan = k-mod1;}
			cnt += AdjList[j].count(harapan);
			if(digit[i] == j){
				ll mod2 = bil%k;
				if((mod1 + mod2) == k || (mod1 + mod2) == 0){
					cnt--;
				}
			}
			
			ans += cnt;
			// printf("cnt total: %lld\n",cnt);
			// printf("ans jd: %lld\n",ans);
		}
	}
	printf("%lld\n",ans);
	return 0;
};