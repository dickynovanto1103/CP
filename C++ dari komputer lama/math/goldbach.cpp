#include <bits/stdc++.h>

using namespace std;

bool a[1000010];
void sieve(int n){
	int i,j;
	a[1]=false;
	for(i=2;i*i<=n;i++){
		if(a[i]){
			for(j=i+i;j<=n;j+=i){a[j]=false;}
		}
	}
}

int main(){
	int n,i,bil1,bil2;
	bool found;

	memset(a,true,sizeof a);
	sieve(1000000);
	/*printf("primes:\n");
	for(i=1;i<=100;i++){
		if(a[i]){printf("%d\n",i);}
	}*/
	while(scanf("%d",&n),n){
		found=false;
		for(i=2;i<=1000000 && !found;i++){
			if(a[i]){
				if(a[n-i]){found=true;}
				bil1=i;bil2=n-i;
			}
		}
		if(found){
			printf("%d = %d + %d\n",n,bil1,bil2);
		}else{printf("Goldbach's conjecture is wrong.\n");}
		
	}
	return 0;
}