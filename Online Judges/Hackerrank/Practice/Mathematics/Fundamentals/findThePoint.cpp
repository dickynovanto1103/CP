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
	int p1,p2,q1,q2;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&p1,&p2,&q1,&q2);
		int selisih1 = q1-p1, selisih2 = q2-p2;
		printf("%d %d\n",q1+selisih1,q2+selisih2);
	}
	return 0;
};