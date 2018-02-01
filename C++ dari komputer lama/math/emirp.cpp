#include <bits/stdc++.h>

using namespace std;

bool isprime[1000011];

void sieve(int n){
	int i,j;
	isprime[1]=false;
	for(i=2;i*i<=n;i++){
		if(isprime[i]){
			for(j=i+i;j<=n;j+=i){isprime[j]=false;}
		}
	}
}

int reverse(int n){
	int bil=0;
	while(n>0){
		bil=bil*10 + n%10;
		n/=10;
	}
	return bil;
}

int main(){
	int n,bil,i;
	memset(isprime,true,sizeof isprime);
	sieve(1000010);
	/*for(i=1;i<100;i++){
		if(isprime[i]){printf("%d\n",i);}
	}*/
	while(scanf("%d",&n)!=EOF){
		if(!isprime[n]){printf("%d is not prime.\n",n);}
		else{
			if(isprime[reverse(n)] && reverse(n)!=n){
				printf("%d is emirp.\n",n);
			}else{printf("%d is prime.\n",n);}
		}
	}
	return 0;
}