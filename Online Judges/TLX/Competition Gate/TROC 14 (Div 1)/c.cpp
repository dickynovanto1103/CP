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

int main(){
	int n,i,j;
	int a[10001], b[10001];
	scanf("%d",&n);
	vi list;
	for(i=0;i<n;i++){scanf("%d",&a[i]); list.pb(a[i]);}
	for(i=0;i<n;i++){scanf("%d",&b[i]); list.pb(b[i]);}
	sort(list.begin(), list.end());
	reverse(list.begin(), list.end());
	ll sum = 0;
	for(i=0;i<n;i++){
		sum += list[i];
	}
	printf("%lld\n",sum);
	
	return 0;
};