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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string s;
bool prime[100002];

int main(){
	memset(prime, true, sizeof prime);
	prime[0]=prime[1] = false;
	for(ll i=2;i<100000;++i){
		if(prime[i])
			for(ll j=i*i;j<=100000;j+=i)
				prime[j] = false;
	}
	cin>>s;
	int ans = -1;
	for(int i=0;i<s.size();++i){
		int num = 0;
		for(int j=i;j<s.size();++j){
			num *=10;
			num += s[j] -'0';
			if(num > 100000)
				break;
			if(prime[num])
				ans = max(ans, num);
		}
	}
	printf("%d\n", ans);
	return 0;
};