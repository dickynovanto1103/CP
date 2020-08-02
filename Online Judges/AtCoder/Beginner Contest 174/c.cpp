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
	int k;
	scanf("%d",&k);
	if(k % 2 == 0){printf("-1\n"); return 0;}
	int tot = 0;
	for(int i=0;i<90000000;i++){
		tot *= 10;
		tot %= k;
		tot += 7;
		tot %= k;
		if(tot == 0){printf("%d\n",i+1); return 0;}
	}
	printf("%d\n",-1);
	
	return 0;
};