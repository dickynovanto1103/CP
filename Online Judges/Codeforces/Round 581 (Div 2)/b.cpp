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
	int n,l,r,i,j;
	scanf("%d %d %d",&n,&l,&r);
	int cnt = 1;
	ll maks = 0, minim = 0;
	ll bil = 1;
	for(i=0;i<n;i++){
		maks += bil;
		
		cnt++;
		if(cnt >= r+1){

		}else{
			bil*=2;	
		}
	}
	bil = 1;
	int batas = n-l;
	for(i=0;i<n;i++){
		
		if(i > batas) {
			bil*=2;
		}
		minim += bil;
	}
	printf("%lld %lld\n",minim, maks);
	return 0;
};