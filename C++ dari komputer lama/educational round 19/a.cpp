#include <bits/stdc++.h>

using namespace std;
bool prime[100010];
vector<int> list1;
void sieve(int n){
	int i,j;
	prime[2]=true;
	for(i=2;i*i<=n;i++){
		if(prime[i]==true){
			for(j=i+i;j<=n;j+=i){
				prime[j] = false;
			}
			list1.push_back(i);	
		}	
	}
}

int main(){
	int n,k,i;
	vector<int> listans;
	memset(prime,true,sizeof prime);
	sieve(100000);
	scanf("%d %d",&n,&k);

	while(k>1 && n>1){
		for(i=0;i<list1.size();i++){
			if(n%list1[i]==0){
				listans.push_back(list1[i]);
				n/=list1[i];
				k--;
				i=-1;
				//printf("n: %d k: %d\n",n,k);
			}
			if(n==1 || k==1){break;}
		}
	}
	bool found = true;
	if(k==1){
		if(n==1){printf("-1\n");found = false;}
		else{listans.push_back(n); k--;}
	}
	if(found){
		if(k>0){printf("-1\n");}
		else{
			
			
				for(i=0;i<listans.size();i++){
					if(i==0){printf("%d",listans[i]);}
					else{printf(" %d",listans[i]);}
				}	
			
			
			printf("\n");
		}	
	}
	
	return 0;
}