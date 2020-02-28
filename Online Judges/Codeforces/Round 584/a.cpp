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
	int n,i,j;
	scanf("%d",&n);
	int a[101];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	bool vis[101];
	memset(vis, false, sizeof vis);
	int cnt = 0;
	for(i=0;i<n;i++){
		if(vis[i]){continue;}
		vis[i] = true;
		for(j=i+1;j<n;j++){
			if(!vis[j]){
				if(a[j]%a[i] == 0){
					vis[j] = true;
				}
			}
		}
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
};