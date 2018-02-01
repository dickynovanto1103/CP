#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int id;
	ll n,p;
	while(scanf("%lld",&n)!=EOF){
		p = 1; id = 1; //stan id 1..ollie id 0
		while(p<n){
			if(!id){p*=2;}
			else{p*=9;}
			//printf("id: %d p menjadi: %lld\n",id,p);
			id++; id%=2;
			
			
		}
		if(!id){printf("Stan wins.\n");}
		else{printf("Ollie wins.\n");}
	}
	return 0;
}