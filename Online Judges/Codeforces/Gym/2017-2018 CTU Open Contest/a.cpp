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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	int a[1010];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int ans = 0;
		set<int> s;
		for(i=n-2;i>=0;i--){
			int selisih = a[i+1] - a[i];
			s.insert(selisih);
			if(s.size() == 1){
				ans = i;
			}else{
				break;
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
};