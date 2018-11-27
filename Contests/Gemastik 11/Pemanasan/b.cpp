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
typedef pair<int,double> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	double x,y, a[101], b[101];
	scanf("%d %lf %lf",&n,&x,&y);
	set<ii> s;
	for(i=0;i<n;i++){
		scanf("%lf %lf",&a[i],&b[i]);
		double gradien = (y-b[i])/(x-a[i]);
		if(y == b[i]){
			if(a[i] >= x){
				s.insert(ii(1, gradien));
			}else{
				s.insert(ii(-1,gradien));
			}
		}else if(x == a[i]){
			if(b[i] >= y){
				s.insert(ii(1,gradien));
			}else{
				s.insert(ii(-1,gradien));
			}
		}else{
			if(a[i] >= x){
				s.insert(ii(1, gradien));
			}else{
				s.insert(ii(-1,gradien));
			}
		}

	}
	printf("%d\n",(int)s.size());
	return 0;
};