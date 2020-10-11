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
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		bool found = false;
		for(i=0;i<200;i++){
			int sum = 0;
			sum += i * 7;
			if(sum > n){break;}
			for(j=0;j<=200;j++){
				sum += j * 5;
				if(sum > n){
					break;
				}
				int selisih = n - sum;
				if(selisih % 3 == 0){
					int bagi = selisih / 3;
					printf("%d %d %d\n",bagi, j, i);
					found = true;
					break;
				}
			}
			if(found){break;}
		}
		if(!found){printf("-1\n");}
	}
	
	return 0;
};