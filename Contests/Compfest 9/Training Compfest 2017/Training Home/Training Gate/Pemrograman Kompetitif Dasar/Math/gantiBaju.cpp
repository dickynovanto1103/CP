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
	int n;
	double ans = 0;
	scanf("%d",&n);
	double percentage = (double)n / 100.0;
	for(int i=1;i<1000;i+=2){
		ans+=((percentage) * pow((1.0-percentage), i-1));
	}
	printf("%.9lf\n",ans);
	return 0;
}