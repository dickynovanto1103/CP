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
	int n,i,k;
	int tc,grundy[110];
	
	int d[3] = {2,3,5};
	grundy[0] = 0;
	grundy[1] = 0;
	for(i=2;i<=100;i++){
		set<int> s;
		for(int j=0;j<3;j++){
			int bil = i-d[j];
			if(bil<0){s.insert(0);}
			else{s.insert(grundy[bil]);}
		}
		for(k=0; ;k++){
			if(!s.count(k)){
				grundy[i] = k;
				break;
			}
		}
	}
	
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		if(grundy[n]==0){printf("Second\n");}
		else{printf("First\n");}
	}
	return 0;
};