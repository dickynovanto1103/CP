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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,n,k;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Kasus #%d: ",tt);
		scanf("%d %d",&n,&k);
		if(n%(k+1) == 0){printf("ya\n");}
		else{printf("tidak\n");}
	}
	return 0;
};