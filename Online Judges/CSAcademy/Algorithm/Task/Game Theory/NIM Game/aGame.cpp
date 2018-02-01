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
	string kata;
	scanf("%d",&n);
	cin>>kata;
	int cntA = 0, cntB = 0, sum = 0;
	for(i=0;i<n;i++){
		if(kata[i]=='A'){
			sum^=cntB; cntB=0;
			cntA++;
		}
		else{
			cntB++;
		}
	}
	sum^=cntB;
	if(cntA%2==0){printf("-1\n");}
	else{
		if(sum==0){printf("B\n");}
		else{printf("A\n");}
	}
	return 0;
};