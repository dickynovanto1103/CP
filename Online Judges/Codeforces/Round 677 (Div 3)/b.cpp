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
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int a[51];
		int first = -1, last = -1;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] == 1){
				if(first == -1){
					first = i;
				}else{
					last = i;
				}
			}
		}
		int cnt = 0;
		for(i=first;i<=last;i++){
			if(a[i] == 0){cnt++;}
		}
		printf("%d\n",cnt);
	}
	
	return 0;
};