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
	int n,i,j;
	int a[110];
	double mean;
	scanf("%d",&n);
	int sum = 0;
	for(i=0;i<n;i++){scanf("%d",&a[i]); sum+=a[i];}
	double avg = (double)sum/(double)n;
	double sumSelisih = 0;
	for(i=0;i<n;i++){
		sumSelisih+=(((double)a[i]-avg)*((double)a[i]-avg));
	}
	sumSelisih/=(double)n;
	double ans = sqrt(sumSelisih);
	printf("%.1lf\n",ans);
	return 0;
};