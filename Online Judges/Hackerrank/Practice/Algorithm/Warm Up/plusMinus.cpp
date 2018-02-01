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
	int n,i;
	scanf("%d",&n);
	int bil;
	int cntPos = 0, cntNeg = 0, cntNol = 0;
	for(i=0;i<n;i++){
		scanf("%d",&bil);
		if(bil>0){cntPos++;}
		else if(bil<0){cntNeg++;}
		else{cntNol++;}
	}
	double ans1 = (double)cntPos/n;
	double ans2 = (double)cntNeg/n;
	double ans3 = (double)cntNol/n;
	printf("%.6lf\n%.6lf\n%.6lf\n",ans1,ans2,ans3);
	return 0;
};