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
	int tc,i,j,a[4];
	scanf("%d",&tc);
	while(tc--){
		for(i=0;i<4;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+4);
		printf("%d\n",a[0]*a[2]);
	}
	
	return 0;
};