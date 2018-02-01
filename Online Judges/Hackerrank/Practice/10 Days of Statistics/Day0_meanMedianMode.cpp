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

int counter[100010];

int main(){
	int n,i,j,a[2510];
	
	scanf("%d",&n);
	int sum = 0;
	for(i=0;i<n;i++){scanf("%d",&a[i]); sum+=a[i]; counter[a[i]]++;}
	sort(a,a+n);
	double mean = (double)sum / (double)n;
	double median;
	int mode;
	// for(i=0;i<n;i++){
	// 	if(i){printf(" ");}
	// 	printf("%d",a[i]);
	// }
	// printf("\n");
	if(n%2==1){
		median = a[n/2]*1.0;
	}else{
		//printf("masuk sini %d %d\n",a[n/2 - 1],a[n/2]);
		median = (a[n/2 - 1] + a[n/2])/2.0;
	}
	int cnt = 0;
	for(i=1;i<=100000;i++){
		if(cnt < counter[i]){
			mode = i;
			cnt = counter[i];
		}
	}
	printf("%.1lf\n%.1lf\n%d\n",mean,median,mode);
	return 0;
};