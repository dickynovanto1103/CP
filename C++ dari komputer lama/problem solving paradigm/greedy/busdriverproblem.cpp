#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	int n,d,r,i,bil,a[110],b[110];
	int total,minim,ans,selisih;
	while(scanf("%d %d %d",&n,&d,&r),(n||d||r)){
		minim = n*d;
		total=0; ans=0;
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		for(i=0;i<n;i++){scanf("%d",&b[i]);}
		sort(a,a+n); sort(b,b+n); reverse(b,b+n);
		for(i=0;i<n;i++){
			int bil = a[i]+b[i]-d;
			if(bil > 0){total+=bil;}
		}
		total*=r;
		printf("%d\n",total);
	}
	return 0;
}