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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 10;

int main(){
	int a[maxn],i,j,n[3];
	scanf("%d %d %d",&n[0],&n[1],&n[2]);
	stack<int> s[3];
	int sum[3];
	for(i=0;i<3;i++){
		sum[i] = 0;
		for(j=0;j<n[i];j++){
			scanf("%d",&a[j]);
			sum[i]+=a[j];
		}
		for(j=n[i]-1;j>=0;j--){
			s[i].push(a[j]);
		}
	}
	int minim = min(sum[0],min(sum[1],sum[2]));
	while(true){
		bool found = false;
		for(i=0;i<3;i++){
			while(sum[i]>minim){
				int bil = s[i].top();
				sum[i]-=bil;
				s[i].pop();
				minim = min(minim,sum[i]);
				found = true;
			}
		}
		if(!found){break;}
	}
	printf("%d\n",minim);

	return 0;
};