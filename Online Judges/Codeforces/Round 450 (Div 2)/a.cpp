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
	int x,y;
	int n,i,j;
	scanf("%d",&n);
	int cnt1 = 0, cnt2 = 0;
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		if(x<0){cnt1++;}
		else if(x>0){cnt2++;}
	}
	//printf("cnt1: %d cnt2: %d\n",cnt1,cnt2);
	if(cnt1==1 || cnt2==1){printf("Yes\n");}
	else if(cnt1==0 || cnt2==0){printf("Yes\n");}
	else{printf("No\n");}
	return 0;
};