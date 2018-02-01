#include <bits/stdc++.h>

using namespace std;

int main(){
	int temp,i;
	vector <int> a;
	while(scanf("%d",&temp)!=EOF){
		a.push_back(temp);
	}
	for(i=a.size()-1;i>=0;i--){printf("%d\n",a[i]);}
	return 0;
}