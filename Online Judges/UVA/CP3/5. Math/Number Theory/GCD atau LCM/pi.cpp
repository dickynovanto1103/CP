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

int main(){
	int n,a[55],i,j;
	while(scanf("%d",&n),n){

		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		int cnt = 0, ans=0;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				//if(a[i]==1 || a[j]==1){continue;}
				cnt++;
				if(__gcd(a[i],a[j])==1){ans++;}
			}
		}
		//printf("cnt: %d ans: %d\n",cnt,ans);
		if(ans==0){printf("No estimate for this data set.\n");}
		else{
			double jawab = 6.0*(double)cnt/(double)ans;
			printf("%.6lf\n", sqrt(jawab));
		}
	}
	return 0;
};