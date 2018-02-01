#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isprime[46511];
ll prime[4810];
bool primeans[2000010];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i+i;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

int main() {
	ll a,b,i,j;
	int cnt=0;
	memset(isprime,true,sizeof isprime);
	sieve(46500);
	for(i=0;i<=46500;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}
	//printf("cnt: %d\n",cnt);

	while(scanf("%lld %lld",&a,&b)!=EOF){
		for(i=a;i<=b;i++){
			//printf("i: %d\n", i);
			if(i<=46500){primeans[i-a] = isprime[i];}
			else{
				//printf("ngetrue in %d\n",i-a);
				primeans[i-a] = true;
			}
			
		}
		//memset(primeans,true,sizeof primeans);
		for(i=0;prime[i]*prime[i]<=b;i++){
			ll bil = prime[i];
			ll temp = bil*bil;
			//printf("bil*bil = %lld\n",temp);

			//if(temp>b){printf("kelewat\n");}
			ll low = (a/bil)*bil;

			if(low<a){low+=bil;}
			//printf("low: %lld saat prime[%d] = %d\n",low,i,prime[i]);
			for(j=low;j<=b;j+=bil){
				if(j<=46500 && isprime[j]){continue;}
				else{
					//printf("ngefalse in %d\n",j-a);
					primeans[j-a] = false;
				}
			}
		}
		//printf("prima antara %d dan %d\n",a,b);
		vi ans;
		for(i=a;i<=b;i++){
			if(primeans[i-a]){ans.pb(i); }
		}
		int ukuran = ans.size();
		int minim = inf, maks = -inf;
		if(ukuran<2){
			printf("There are no adjacent primes.\n");
		}else{
			//printf("ukuran: %d\n",ukuran);
			int x1,y1,x2,y2;
			for(i=0;i<ukuran-1;i++){
				int jarak = ans[i+1] - ans[i];
				if(jarak < minim){minim = jarak; x1 = ans[i]; y1 = ans[i+1];}
				if(jarak > maks){maks = jarak; x2 = ans[i]; y2 = ans[i+1];}
			}
			printf("%d,%d are closest, %d,%d are most distant.\n",x1,y1,x2,y2);
		}
		

	}
	return 0;
}