#include <cstdio>

using namespace std;

int a[110];

bool isAllAsc(int idx) {
	return a[idx] < a[idx+1] && a[idx+1] < a[idx+2];
}

bool isAllDesc(int idx) {
	return a[idx] > a[idx+1] && a[idx+1] > a[idx+2];
}


int main(){
	int n,i, ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-2;i++) {
		if(isAllAsc(i) || isAllDesc(i)){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}