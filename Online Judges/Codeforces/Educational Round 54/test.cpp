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
	int n=69;
	double a = 0.0001;
	for(double i=0;i<=69;i+=(0.01)){
		double bil1 = i;
		double sisa = (double)n-bil1;
		printf("%lf\n",bil1*sisa);
	}
	return 0;
};