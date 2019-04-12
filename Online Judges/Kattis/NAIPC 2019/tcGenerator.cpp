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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,k,i,j;
	do{
		k = rand()%2495 + 3;
		n = k + rand()%(2500-k);	
	}while(n > 2500 || k > 2500);
	printf("%d %d\n",n,k);
	for(i=0;i<n;i++){
		double x, y;
		int bil = rand()%10;
		do{
			x = (double)(bil+10) / (double)bil;
			bil = rand()%10;
			y = (double)(bil+10) / (double)bil;	
		}while(x > 10 || y > 10);
		printf("%lf %lf\n",x,y);
	}

	return 0;
};