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

double power(double a, int b){
	if(b==0){return 1.0;}
	else{
		if(b%2==0){
			double temp = power(a,b/2);
			return temp*temp;
		}else{
			return a*power(a,b-1);
		}
	}
}

int main(){
	double ans = 0;
	double a,b,c,d;
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	for(int i=1;i<=100000;i++){
		ans += (a/b) * power(1.0-a/b,i-1) * power(1.0-c/d,i-1);
	}
	printf("%.9lf\n",ans);
	return 0;
};