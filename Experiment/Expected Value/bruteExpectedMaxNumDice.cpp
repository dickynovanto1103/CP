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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	double sum = 0;
	int i,j;
	srand(time(NULL));
	for(i=0;i<10000;i++){
		int maks = 0;
		for(j=0;j<100;j++){
			int num = rand() % 6 + 1;
			maks = max(maks, num);	
		}
		sum += maks;
	}
	printf("expected: %.9lf\n",sum/10000);
	
	return 0;
};