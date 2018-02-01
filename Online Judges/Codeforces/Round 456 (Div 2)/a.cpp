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
	ll a,b,x,y,z;
	scanf("%lld %lld %lld %lld %lld",&a,&b,&x,&y,&z);
	ll yellow = 2LL*x;
	yellow+=y;
	ll blue = 3*z + y;
	//printf("blue: %lld\n",blue);
	ll sisa1 = yellow-a;
	ll sisa2 = blue-b;
	if(sisa1<0){sisa1=0;}
	if(sisa2<0){sisa2=0;}
	printf("%lld\n",sisa1+sisa2);
	return 0;
};