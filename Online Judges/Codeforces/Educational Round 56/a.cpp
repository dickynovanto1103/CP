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
	int tc,i,j;
	int n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int cnt = 0;
		while(n>7){
			cnt++;
			n-=7;
		}
		cnt++;
		printf("%d\n",cnt);
	}
	return 0;
};