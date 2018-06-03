#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int mod = 1e9 + 7;

int main(){
	int n,m;
	string kata;
	scanf("%d %d",&n,&m);
	cin>>kata;
	int sum = 0, ans = 1;
	for(int i=0;i<n;i++){
		sum*=10; sum+=kata[i]-'0';

		sum%=m;
		//printf("sum jd: %d\n",sum);
		if(sum==0 && i<n-1){ans = (ans*2)%mod;}
	}
	if(sum!=0){ans = 0;}
	printf("%d\n",ans);
	return 0;
};