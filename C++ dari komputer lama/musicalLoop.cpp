#include <cstdio>

using namespace std;

int main(){
	int i,n;
	int a[10004],ans;
	while(scanf("%d",&n),n){
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		ans=0;
		if((a[1]>a[n] && a[1]>a[2])||(a[1]<a[n] && a[1]<a[2])){ans++;}
		for(i=2;i<=n-1;i++){
			if((a[i-1]>a[i] && a[i+1]>a[i])||(a[i-1]<a[i] && a[i+1]<a[i])){ans++;}
		}
		if((a[n]>a[n-1] && a[n]>a[1])||(a[n]<a[n-1] && a[n]<a[1])){ans++;}
		printf("%d\n",ans);
	}
	return 0;
}