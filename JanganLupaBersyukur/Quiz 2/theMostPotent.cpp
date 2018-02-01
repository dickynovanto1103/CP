#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,j,k,a[17000];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<(1<<n);i++){
			scanf("%d",&a[i]);
		}
		int ans = -1;
		int sum;
		for(i=0;i<(1<<n);i++){
			int bil = i;
			
			for(j=0;j<n;j++){
				int v = bil^(1<<j);
				//cari tetangga dari bil
				//sum+=a[v];
				sum = 0;
				for(k=0;k<n;k++){
					int u = v^(1<<k);
					//printf("tetangga dari v: %d adalah %d\n",v,u);
					sum+=a[u];
				}
				for(k=0;k<n;k++){
					int u = bil^(1<<k);
					//printf("tetangga dari bil: %d adalah %d\n",bil,u);
					sum+=a[u];
				}
				//printf("sum: %d\n",sum);
				ans = max(ans,sum);
			}
			
		}
		
		printf("%d\n",ans);
	}
	return 0;
}