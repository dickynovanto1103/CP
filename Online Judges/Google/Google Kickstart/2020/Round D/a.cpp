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
	int tc,n,i,j;
	scanf("%d",&tc);
	int a[200001];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		int maksPrev = -1;
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		int cnt = 0;
		for(i=0;i<n;i++){
			if(a[i] > maksPrev){
				maksPrev = a[i];
				if(i == (n-1)) {
					cnt++;
				}else if(a[i] > a[i+1]){
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	
	return 0;
};