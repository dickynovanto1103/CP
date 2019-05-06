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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[200];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);

	}
	int ans = 0;
	for(i=0;i<n;i++){
		bool valid = true;
		for(j=0;j<i;j++){
			if(a[i] < a[j]){valid = false; break;}
		}
		if(valid){ans++;}
	}
	printf("%d\n",ans);
	return 0;
};