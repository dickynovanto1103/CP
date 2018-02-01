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

const int maxn = 31700;

bool isprime[maxn+10];
int prime[3410];
bool primaBawah[1000001];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i*2;j<=n;j+=i){
				isprime[j] = false;
			}
		}
	}
}

int main() {
	int a,b,i,j;
	memset(isprime,true,sizeof isprime);
	sieve(maxn);
	int cnt = 0;
	for(i=0;i<=maxn;i++){
		if(isprime[i]){prime[cnt] = i;cnt++;}
	}

	scanf("%d %d",&a,&b);

	for(i=a;i<=b;i++){
		if(i<=maxn){
			if(isprime[i]){primaBawah[i-a] = true;}
			else{primaBawah[i-a] = false;}
		}else{
			primaBawah[i-a] = true;
		}
		//if(primaBawah[i-a]){printf("%d\n",i);}
	}

	for(i=0;prime[i]*prime[i]<=b;i++){
		int awal = (a/prime[i])*prime[i];
		if(awal<a){awal+=prime[i];}
		for(j=awal;j<=b;j+=prime[i]){
			if(j<=maxn){primaBawah[j-a] = isprime[j];}
			else{
				primaBawah[j-a] = false;
			}
		}
	}
	//printf("list prima:\n");
	vi listAns;
	for(i=a;i<=b;i++){
		if(primaBawah[i-a]){
			listAns.pb(i);
		}
	}
	int ukuran = listAns.size();
	int ans = 0;
	for(i=0;i<ukuran-1;i++){
		if(listAns[i+1] - listAns[i]==2){ans++;}
	}
	printf("%d\n",ans);
	
	return 0;
}