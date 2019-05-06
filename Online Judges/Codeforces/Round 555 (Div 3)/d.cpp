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
	int n,k;
	scanf("%d %d",&n,&k);
	ll minim = ((ll)k*(ll)(k-1))/2LL;
	ll tambah = k;
	if(n < (minim + tambah)){
		printf("NO\n");
	}else{
		if(k <= 30){
			if(n > (1<<k) - 1){

			}
		}
	}
	return 0;
};