#include <bits/stdc++.h>

using namespace std;

vector <int> a;

int main(){
	int n,i,temp;
	double ans;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&temp); a.push_back(temp);
	}
	sort(a.begin(),a.end());
	if(n%2==1){
		ans=(double)a[n/2];
	}else{
		ans=(double)(a[n/2-1]+a[n/2])/2.0;
	}
	printf("%.2lf\n",ans);
	return 0;
}