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
	int a[8];
	int i,j;
	int sum = 0;
	for(i=0;i<5;i++){scanf("%d",&a[i]); sum+=a[i];}
	if(sum==0){printf("-1\n"); return 0;}
	if(sum%5==0){printf("%d\n",sum/5);}
	else{printf("-1\n");}
	return 0;
};