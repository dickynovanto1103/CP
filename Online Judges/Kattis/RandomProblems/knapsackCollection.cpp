#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000000000000LL
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

ll waktu[10000010];
multiset<int> mul, temp;
multiset<int>::iterator it;
ll t,pjg;

void copy(){
	temp = mul;
}

ll simulate(int next) {
	it = temp.find(next);
	// if(it == temp.end()){printf("halo gan next: %d\n",next);}
	temp.erase(it);

	if(temp.empty()){return 0;}

	ll waktu = 0;
	
	next = (next + t) % pjg;
	// printf("next: %d\n",next);
	ll sementara = next;
	it = temp.lower_bound(next);
	if(it == temp.end()){
		it = temp.begin();
	}
	ll valSekarang = *it;
	// printf("valSekarang: %lld\n",valSekarang);
	if(sementara > valSekarang){
		valSekarang += pjg;

	}
	
	waktu += t;
	waktu += valSekarang - sementara;
	// printf("waktu jd: %lld\n",waktu);

	waktu += simulate(valSekarang%pjg);
	return waktu;
}

int arr[2010];

int main(){
	int n,i,j;
	scanf("%d %lld %lld",&n,&pjg,&t);
	set<int> s;
	set<int>::iterator it2;
	
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		s.insert(bil);
		mul.insert(bil);
	}
	memset(waktu, -1, sizeof waktu);
	int cnt = 0;
	for(it2 = s.begin();it2!=s.end();it2++){
		arr[cnt++] = *it2;
	}
	for(i=0;i<cnt;i++){
		int bil = arr[i];
		// printf("bil: %d\n",bil);
		copy();
		ll tot = simulate(bil);
		waktu[bil] = tot + t;
		// printf("waktu[%d]: %lld\n",bil,waktu[bil]);
	}

	for(i=0;i<cnt;i++) {
		int bil = arr[i];
		ll awal = waktu[bil];
		bil--;
		if(bil < 0){bil += pjg;}
		ll tambahan = 1;
		while(waktu[bil] == -1){
			waktu[bil] = awal + tambahan;
			bil--;
			tambahan++;
			if(bil < 0){bil += pjg;}
		}
	}

	ll minim = inf, maks = -inf, tot = 0;

	for(i=0;i<pjg;i++){
		
		minim = min(minim, waktu[i]);
		maks = max(maks, waktu[i]);
		tot += waktu[i];
	}
	
	ll gcd = __gcd(tot, pjg);
	tot /= gcd; pjg /= gcd;
	printf("%lld\n",minim);
	printf("%lld\n",maks);
	printf("%lld/%lld\n",tot,pjg);

	return 0;
};