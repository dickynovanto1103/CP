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
	scanf("%d",&n);
	int a[1000];
	int ans;
	for(i=1;i<=inf;i++){
		a[i] = (pow(2,i) - 1) * (pow(2,i-1));

		//printf("%d\n",a[i]);
		if(a[i]>100000){break;}
		if(n%a[i]==0){ans=a[i];}
	}
	printf("%d\n",ans);

	return 0;
};