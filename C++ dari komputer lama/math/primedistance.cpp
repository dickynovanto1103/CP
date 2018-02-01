#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef long long ll;
bool isprime1[10000010];
vector <int> primes,uji;
ll ukuran;

void sieve(int n){
	int i,j;
	isprime1[1]=false;
	for(i=2;i*i<=n;i++){
		if(isprime1[i]){
			for(j=i+i;j<=n;j+=i){
				isprime1[j]=0;
			}
		}
	}
}

bool isprime(ll N){
	int i;
	if(N<=ukuran){return isprime1[N];}
	else{
		for(i=0;i<primes.size();i++){if(N%primes[i]==0){return false;}}
		return true;
	}
}

int main(){
	int i,j,n,awalpendek,akhirpendek,awalpanjang,akhirpanjang;

	int maks,minim,last;
	ll cnt,awal,akhir;
	memset(isprime1,true,sizeof isprime1);
	sieve(10000000);
	
	while(scanf("%d %d",&awal,&akhir)!=EOF){
		//printf("awal: %d akhir: %d\n",awal,akhir);
		cnt=0;
		for(i=awal;i<=akhir;i++){
			if(isprime(i)){cnt++;}
		}

		maks=-1; minim=inf;
		if(cnt<=1){printf("There are no adjacent primes.\n");}
		else{
			last=-1;
			for(i=awal;i<=akhir;i++){
				if(isprime(i)){
					if(last==-1){last=i;}
					else{
						if(maks < i-last){maks = i-last; awalpanjang = last; akhirpanjang= i;}
						if(minim > i-last){minim = i-last; awalpendek = last; akhirpendek = i;}
						last=i;
					}
				}
			}
			printf("%d,%d are closest, %d,%d are most distant.\n",awalpendek,akhirpendek,awalpanjang,akhirpanjang);
		}
	}
	
	return 0;
}