#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);
 
int n,i,j,k,t;
int a[40002], m;
 
int main(){
	scanf("%d", &t);
	for(int cc=1;cc<=t;++cc){
		scanf("%d", &n);
		m = n*n;
		for(i=0;i<m;++i)
			scanf("%d", a+i);
		vector<int> lis, lds;
		for(i=0;i<m;++i){
			vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), a[i]);
			if(it == lis.end())
				lis.pb(a[i]);
			else
				*it = a[i];
			vector<int>::iterator dt = lower_bound(lds.begin(), lds.end(), a[i], greater<int>());
			if(dt == lds.end())
				lds.pb(a[i]);
			else
				*dt = a[i];
		}
		cout<<"lis : ";
		for(int x : lis)
			cout<<x<<" ";
		cout<<endl;
		cout<<"lds : ";
		for(int x : lds)
			cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}