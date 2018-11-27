#include <bits/stdc++.h>

using namespace std;

#define pb push_back



int n,i,j,k,t;
const int maxn = 1000002;
int a[maxn];
int id[maxn];


int main(){
	scanf("%d", &n);
	for(i=0;i<n;++i){
		scanf("%d", a+i);
		a[i] -= i;
	}
	std::vector<int> v;
	for(i=0;i<n;++i){
		if(a[i] <= 0) continue;
		vector<int>::iterator it = upper_bound(v.begin(), v.end(), a[i]);
		if(it == v.end())
			v.pb(a[i]);
		else
			*it = a[i];
	}
	printf("%d\n", n - (int)v.size());
	return 0;
}