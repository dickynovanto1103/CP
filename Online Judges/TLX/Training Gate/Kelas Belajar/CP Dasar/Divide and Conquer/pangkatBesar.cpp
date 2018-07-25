#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isMore(ll a, ll b){
	ll ans = 1;
	while(b>0){
		ans*=a;
		if(ans>999999){return true;}
		b--;

	}
	return false;
}

ll result(ll a, ll b, ll c){
	if(b==0) return 1;
	if(b%2==1){return (((a%c)*(result(a,b-1,c)))%c);}
	else{
		ll temp = result(a,b/2,c);
		return (((temp%c)*(temp%c))%c);
	}
}

int countDigit(ll a){
	int counter = 0;
	while(a>0){
		a/=10;
		counter++;
	}
	return counter;
}

int main(){
	ll a,b, c = 1000000;
	scanf("%lld %lld",&a,&b);
	if(isMore(a,b)){
		ll bil = result(a,b,c);
		int banyakDigit = countDigit(bil);
		if(bil==0){banyakDigit = 1;}
		for(int i=0;i<6-banyakDigit;i++){printf("0");}
		printf("%lld\n",bil);
	}else{
		printf("%lld\n",result(a,b,c));	
	}
	
	return 0;
}