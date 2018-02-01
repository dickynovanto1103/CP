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
	int n,i,j;
	int a[4000];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		bool flag[4000];
		memset(flag,false,sizeof flag);
		for(i=0;i<n-1;i++){
			int diff = abs(a[i]-a[i+1]);
			flag[diff] = true;
		}
		bool valid = true;
		for(i=1;i<n;i++){
			if(!flag[i]){valid = false; break;}
		}
		if(valid){printf("Jolly\n");}
		else{printf("Not jolly\n");}

	}
	return 0;
};