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

ii merge(ii a, ii b){
	ii ans = ii(max(a.first, b.first), min(a.second, b.second));
	return ans;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int maks = 2000000000, minim = -2000000000;
	ii range = ii(minim,maks);

	// printf("%d\n",-2e9);
	for(i=0;i<n;i++){
		string kata;
		char kar;
		int num;
		cin>>kata>>num>>kar;
		ii rangeTebak;
		if(kata == ">"){
			if(kar == 'Y'){
				rangeTebak = ii(num+1, maks);
			}else{
				rangeTebak = ii(minim, num);
			}
		}else if(kata == ">="){
			if(kar == 'Y'){
				rangeTebak = ii(num, maks);
			}else{
				rangeTebak = ii(minim, num-1);
			}
		}else if(kata == "<"){
			if(kar == 'Y'){
				rangeTebak = ii(minim, num-1);
			}else{
				rangeTebak = ii(num, maks);
			}
		}else{
			if(kar == 'Y'){
				rangeTebak = ii(minim, num);
			}else{
				rangeTebak = ii(num+1, maks);
			}
		}
		range = merge(range, rangeTebak);
		if(range.first > range.second){printf("Impossible\n");return 0;}

	}
	printf("%d\n", range.first);
	return 0;
};