#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,a[10010],listIdx[10010],i,j;
	while(scanf("%d",&n),n){
		char kar;
		scanf("%c ",&kar);
		for(i=0;i<n;i++){scanf("%d",&a[i]); listIdx[a[i]] = i;}
		bool found = false;
		for(i=1;i<n-1;i++){
			int bil = a[i];
			for(j=i-1;j>=0;j--){
				int diff = a[i] - a[j];
				int bilbaru = a[i] + diff;
				if(bilbaru>=n || bilbaru<0){continue;}
				if(listIdx[bilbaru]>i){found = true; break;}
			}
			if(found){break;}
		}
		if(found){printf("no\n");}
		else{printf("yes\n");}
	}
	return 0;
}