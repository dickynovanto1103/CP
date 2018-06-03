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
	int i,j,a[10], b[10];
	for(i=0;i<7;i++){scanf("%d",&a[i]);}
	for(i=0;i<7;i++){scanf("%d",&b[i]);}
	int sum = 0;
	for(i=0;i<7;i++){sum+=abs(a[i] - b[i]);}
	printf("%d\n",sum);
	return 0;
};