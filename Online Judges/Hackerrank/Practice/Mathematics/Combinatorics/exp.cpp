#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isprime(int bil){
	for(int i=2;i<bil;i++){
		if(bil%i == 0){return false;}
	}
	return true;
}

uint64_t lcm(uint64_t a, uint64_t b){
	ll gcd = __gcd(a,b);
	return a*(b/gcd);
}

int main(){
	ll kali = 1;
	uint64_t lcmVal = 1;
	for(int i=2;i<=51;i++){
		if(isprime(i)){
			printf("%d\n",i);
			kali *= (ll)i;
			printf("kali: %lld\n",kali);
			lcmVal = lcm(lcmVal, i);
			cout<<"lcmVal:"<<lcmVal<<endl;
			// printf("lcmVal: %lld\n",lcmVal);
		}
	}
	for(int i=48;i<=51;i++){
		lcmVal = lcm(lcmVal, i);
		cout<<"lcmVal now:"<<lcmVal<<endl;
	}
	
	return 0;
};