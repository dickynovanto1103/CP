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

const int maxn = 1e5 + 5;
int n;
int a[maxn], b[maxn];
double val[maxn];
double dp[maxn];
map<string,int> mapper;

int main(){
	int i,j;
	scanf("%d",&n);
	
	int cnt = 2;
	
	mapper["pink"] = 0;
	mapper["blue"] = 1;



	for(i=0;i<n;i++){
		dp[i] = -1;
		string kata1, kata2;
		cin>>kata1>>kata2;
		int idx1, idx2;
		if(mapper.find(kata1) == mapper.end()){
			mapper[kata1] = cnt;
			idx1 = cnt;
			cnt++;
		}else{
			idx1 = mapper[kata1];
		}
		if(mapper.find(kata2) == mapper.end()){
			mapper[kata2] = cnt;
			idx2 = cnt;
			cnt++;
		}else{
			idx2 = mapper[kata2];
		}
		// cout<<kata1<<" dimap jd: "<<idx1<<" "<<kata2<<" dimap jadi:"<<idx2<<endl;
		a[i] = idx1; b[i] = idx2;
		scanf("%lf",&val[i]);
	}

	for(i=0;i<cnt;i++){
		dp[i] = (double)-inf;
	}

	dp[0] = 0;

	for(i=0;i<n;i++){
		int akhir = a[i];
		int awal = b[i];
		double rasio = val[i];
		if(fabs(dp[awal] + (double)inf) < eps){
			continue;
		}else{
			double nilaiAkhir = dp[awal];
			nilaiAkhir+= log10(rasio);
			dp[akhir] = max(dp[akhir], nilaiAkhir);
		}
	}

	double ans = 0;
	if(dp[1] > 1){
		ans = 10.0;
	}else{
		if(fabs(dp[1] + (double)inf) < eps){
			ans = 0;
		}else{
			ans = pow(10,dp[1]);	
		}
	}

	printf("%.9lf\n",ans);

	return 0;
};