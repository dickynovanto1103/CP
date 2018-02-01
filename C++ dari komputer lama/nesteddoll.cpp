#include <bits/stdc++.h>

using namespace std;

struct b{
	int w;
	int h;
}

bool acompare(b lhs, b rhs){return lhs.w < rhs.w;}

int main(){
	b a[20010];
	int i,tc,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d %d",a[i].w,a[i].h);
		}
		sort(a,a+n,acompare);
		
	}
	return 0;
}