#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,a,bil;
	scanf("%d %d",&n,&a);
	bool found = false;
	for(i=1;i<=n;i++){scanf("%d",&bil); if(bil>a){printf("%d\n",i); found = true; break;}}
	if(!found){printf("%d",i);}
	return 0;
}