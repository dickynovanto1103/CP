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
	int n,m,a,b;
	scanf("%d %d %d %d",&n,&m,&a,&b);
	int jawab1, jawab2;
	jawab1 = (n/a) * (m/b);
	swap(a,b);
	jawab2 = (n/a) * (m/b);
	printf("%d\n",max(jawab1, jawab2));
	return 0;
};