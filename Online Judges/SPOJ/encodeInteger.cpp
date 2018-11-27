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
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		if(n==0){printf("10\n");}
		else if(n==1){printf("1\n");}
		else{
			string ans = "";
			for(i=9;i>=2;i--){
				while(n%i==0){
					n/=i;
					ans += (i + '0');
				}
			}
			if(n!=1){printf("-1\n"); continue;}
			reverse(ans.begin(), ans.end());
			cout<<ans<<endl;
		}
	}
	return 0;
};