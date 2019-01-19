#include <bits/stdc++.h>

using namespace std;

bool pernah[55], prime[55];
int n;

void sieve(int n){
	int i,j;
	prime[1] = false;
	for(i=2;i*i<=n;i++){
		if(prime[i]){
			for(j=i+i;j<=n;j+=i){
				prime[j] = false;
			}	
		}
	}
}

int catat[20];

void solve(int kedalaman){
	int i;
	if(kedalaman==n){
		if(prime[catat[kedalaman-1]+1]){
			for(i=0;i<n;i++){
				if(i>0){printf(" ");}
				printf("%d",catat[i]);
			}
			printf("\n");	
		}
	}else{
		for(i=2;i<=n;i++){
			if(!pernah[i] && prime[i+catat[kedalaman-1]]){
				pernah[i] = true;
				catat[kedalaman] = i;
				solve(kedalaman+1);
				pernah[i] = false;
			}
		}
	}
}

int main(){
	int i;
	memset(prime,true,sizeof prime);
	sieve(50);
	catat[0] = 1;
	int test=1;
	while(scanf("%d",&n)!=EOF){
		if(test>1){printf("\n");}
		printf("Case %d:\n",test++);
		memset(pernah,false,sizeof pernah);
		solve(1);
	}

	return 0;
}