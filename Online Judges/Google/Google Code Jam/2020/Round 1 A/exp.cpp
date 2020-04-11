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
	int sum = 0;
	for(int i=0;i<200;i++){
		int bil = (1<<i);
		if(sum + bil > inf){
			break;
		}else{
			sum += bil;
			printf("i: %d sum: %d\n",i, sum);
		}
	}
	return 0;
};