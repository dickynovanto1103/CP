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

const int maxn = 1e5 + 5;

int main(){
	string dummy;
	int n,i,j;
	cin>>dummy;
	scanf("%d",&n);
	int counter[maxn];
	memset(counter, 0, sizeof counter);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		counter[bil]++;
		// printf("counter[%d] jd: %d\n",bil,counter[bil]);
	}

	int next[maxn];
	memset(next, -1, sizeof next);
	int selanjutnya = -1;
	for(i=100000;i>=1;i--){
		if(counter[i] > 0){
			next[i] = selanjutnya;
			selanjutnya = i;
			// printf("next[%d]: %d\n",i,next[i]);
		}
	}

	int pref[maxn];
	for(i=1;i<=100000;i++){
		if(i==1){pref[i] = counter[i];}
		else{pref[i] = pref[i-1] + counter[i];}
	}	
	// printf("pref 100 rb: %d\n",pref[100000]);

	ll jumlah[maxn];
	memset(jumlah, 0, sizeof jumlah);
	for(i=1;i<=100000;i++){
		if(next[i] == -1){continue;}
		int selanjutnya = next[i];
		ll banyakSetelahnya = pref[100000] - pref[selanjutnya];

		// printf("i: %d banyakSetelahnya: %lld pref selanjutnya: %d selanjutnya: %d\n",i,banyakSetelahnya,pref[selanjutnya],selanjutnya);
		ll bil = counter[i];
		jumlah[i] = banyakSetelahnya*bil;
	}
	ll sum[maxn];
	sum[0] = 0;
	for(i=1;i<=100000;i++){
		if(i==1){sum[i] = jumlah[i];}
		else{sum[i] = sum[i-1] + jumlah[i];}
	}

	ll total = 0;
	for(i=1;i<=100000;i++){
		// printf("i: %d\n",i);
		if(next[i] == -1){continue;}
		// printf("jumlah[%d]: %lld counter: %d\n",i,jumlah[i], counter[i]);
		total+=(sum[100000] - sum[i-1]);
	}
	printf("%lld\n",total);

	return 0;
};