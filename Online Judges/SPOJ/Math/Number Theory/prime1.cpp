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

bool isprime[50010];
int prime[5200];

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
	int tc,i,j,a,b;
	memset(isprime,true,sizeof isprime);
	sieve(50000);
	int cnt = 0;
	for(i=0;i<=50000;i++){
		if(isprime[i]){prime[cnt] = i; cnt++;}
	}
	int n = cnt;
	scanf("%d",&tc);
	bool ans[100010];
	int test = 1;
	while(tc--){
		if(test==2){printf("\n");}
		scanf("%d %d",&a,&b);
		for(i=a;i<=b;i++){
			if(i<=50000){
				if(isprime[i]){ans[i-a] = true;}
				else{ans[i-a] = false;}
			}else{ans[i-a] = true;}
			
		}//set to true
		//cari prime number dari prime[0] sampe akar b...
		
		cnt = 0;
		for(i=0;prime[i]*prime[i]<=b;i++){
			int bilawal = (a/prime[i])*prime[i];
			if(bilawal<a){bilawal+=prime[i];}
			for(j=bilawal;j<=b;j+=prime[i]){
				if(j<=50000 && isprime[j]){continue;}
				ans[j-a] = false;
			}
		}
		for(i=a;i<=b;i++){

			if(ans[i-a]){printf("%d\n",i);}
		}
		test=2;
	}
	return 0;
}