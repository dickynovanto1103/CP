#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j,m;
	scanf("%d",&n);
	bool ada[220];
	memset(ada, false, sizeof ada);
	int a[101], b[101];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		ada[a[i]] = true;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
		ada[b[i]] = true;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if((a[i] + b[j]) > 200){
				printf("%d %d\n",a[i], b[j]);
				return 0;
			}else{
				int tot = a[i] + b[j];
				if(!ada[tot]){
					printf("%d %d\n",a[i],b[j]);
					return 0;
				}
			}
		}
	}
	return 0;
};