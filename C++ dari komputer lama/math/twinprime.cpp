#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
vector <int> primes;
vector <iii> jawaban;
bool a[20000010];
void sieve(int n){
	int i,j;
	a[1]=false;
	for(i=2;i*i<=n;i++){
		if(a[i]){
			for(j=i+i;j<=n;j+=i){a[j]=false;}
			//primes.push_back(i);
		}
	}
}

int main(){
	int n,i,j;
	memset(a,true,sizeof a);
	sieve(20000000);
	for(i=2;i<=20000000;i++){
		if(a[i]){primes.push_back(i);}
	}
	i=0;
	for(j=0;j<primes.size();j++){
		//printf("%d\n",primes[j]);
		if(primes[j+1]==primes[j]+2){i++;jawaban.push_back(make_pair(i,ii(primes[j],primes[j+1])));}
	}
	while(scanf("%d",&n)!=EOF){
		i=0;
		iii jaw = jawaban[n-1];
		//printf("bilangan prima:\n");
		
		printf("(%d, %d)\n",jaw.second.first,jaw.second.second);
	}
	return 0;
}