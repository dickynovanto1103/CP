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

int main(){
	ll n,m,i,j,a;
	scanf("%lld %lld %lld",&n,&m,&a);
	ll bil = 0;
	ll cnt1 = 0, cnt2 = 0;
	cnt1 = n/a;
	cnt2 = m/a;
	if(n%a!=0){cnt1++;}
	if(m%a!=0){cnt2++;}
	printf("%lld\n",cnt1*cnt2);
	return 0;
};