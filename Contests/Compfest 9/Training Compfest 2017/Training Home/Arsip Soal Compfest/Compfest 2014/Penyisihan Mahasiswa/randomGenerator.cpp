#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,n;
	double percentage;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %lf",&n,&percentage);
		double sum = 0;
		for(int i=0;i<n;i++){
			sum+=(pow(2,i)*(percentage/100.0));
		}
		printf("%.9lf\n",sum);
	}
	return 0;
}