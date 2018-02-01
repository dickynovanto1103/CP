#include <bits/stdc++.h>

using namespace std;

int main(){
	string kata[1010];
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		cin>>kata[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(kata[i][j]=='X'){printf("%d,%d\n",i,j); break;}
		}
	}
	return 0;
}