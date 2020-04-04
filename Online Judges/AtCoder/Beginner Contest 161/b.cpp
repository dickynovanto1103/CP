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
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int tot = 0;
	int a[101];

	for(i=0;i<n;i++){scanf("%d",&a[i]); tot += a[i];}
	int minim = tot / (4*m);
	if(tot % (4*m) == 0){
		minim--;
	}
	int ans = 0;
	for(i=0;i<n;i++){
		if(a[i] > minim){
			ans++;
		}
	}
	if(ans >= m){printf("Yes\n");}
	else{
		printf("No\n");
	}
	return 0;
};