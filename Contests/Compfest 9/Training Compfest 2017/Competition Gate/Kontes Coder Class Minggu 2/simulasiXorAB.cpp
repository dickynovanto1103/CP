#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string toBinary(ll a){
	if(a==0){return "0";}
	string kata = "";
	while(a>0){
		int bil = a%2;
		kata+=(bil+48);
		a/=2;
	}
	string ans = "";
	int n = kata.length();
	for(int i=n-1;i>=0;i--){
		ans+=kata[i];
	}
	return ans;
}

int main() {
	ll a,b;
	scanf("%lld %lld",&a,&b);
	ll ans = a;
	for(ll i=a+1;i<=b;i++){
		ans^=i;
		printf("ans: %d\n",ans);
	}
	cout<<toBinary(ans)<<endl;
	return 0;
}