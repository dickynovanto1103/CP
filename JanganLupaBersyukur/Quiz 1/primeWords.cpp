#include <bits/stdc++.h>

using namespace std;

bool prime[1050];

void sieve(int n){
	int i,j;
	prime[1] = true;
	for(i=2;i*i<=n;i++){
		if(prime[i]){
			for(j=i*2;j<=n;j+=i){
				prime[j] = false;
			}
		}
	}
}

int main(){
	int i;
	memset(prime,true,sizeof prime);
	sieve(1050);
	/*for(i=0;i<=100;i++){
		if(prime[i]){printf("%d\n",i);}
	}*/
	string kata;
	while(cin>>kata){
		int sum = 0;
		int pjg = kata.length();

		for(i=0;i<pjg;i++){
			char kar = kata[i];
			int bil = kar;
			if(bil>=97){bil-=96;}
			else{bil-=38;}
			//printf("bil: %d\n",bil);
			sum+=bil;
			//printf("sum sekarang: %d\n",sum);
			//printf("kar: %c\n",kar);
		}
		if(prime[sum]){printf("It is a prime word.\n");}
		else{printf("It is not a prime word.\n");}
	}
	return 0;
}