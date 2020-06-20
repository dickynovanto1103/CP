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
	int i,j;
	ll k;
	scanf("%lld",&k);
	string s = "codeforces";
	int a[11];
	ll banyak = 1;
	int len = s.size();
	for(i=0;i<len;i++){a[i] = 1;}
	int idx = 0;
	while(banyak < k){
		banyak /= a[idx];
		a[idx]++;
		banyak *= a[idx];
		idx++;
		idx %= len;
	}
	
	for(i=0;i<len;i++){
		for(j=0;j<a[i];j++){
			printf("%c",s[i]);
		}
	}
	printf("\n");
	return 0;
};