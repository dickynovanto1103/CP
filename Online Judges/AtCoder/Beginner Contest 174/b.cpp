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
	int a,b,d;
	scanf("%d %d",&n,&d);
	int cnt=0;
	while(n--){
		scanf("%d %d",&a,&b);
		ll tot = (ll)a*(ll)a + (ll)b*(ll)b;
		ll comp = (ll)d*(ll)d;
		if(tot <= comp){cnt++;}
	}
	printf("%d\n",cnt);
	
	return 0;
};