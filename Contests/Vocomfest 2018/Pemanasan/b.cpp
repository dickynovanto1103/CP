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
	int a[3];
	scanf("%d %d %d",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	printf("%d %d %d\n",a[2], a[1], a[0]);
	return 0;
};