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
	int tc,n,i;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		double sum = 0;
		for(i=0;i<n;i++){
			double bil1,bil2;
			scanf("%lf %lf",&bil1,&bil2);
			double tengah = (bil1 + bil2)/2.0;
			double waktu = tengah-bil1;
			sum+=waktu;
		}
		printf("%.1lf\n",sum);
	}
	return 0;
};