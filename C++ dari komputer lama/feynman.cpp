#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n,i;
	int ans;
	while(scanf("%d",&n),n){
		ans=0;
		for(i=1;i<=n;i++){
			ans+=i*i;
		}
		printf("%d\n",ans);
	}
	return 0;
}