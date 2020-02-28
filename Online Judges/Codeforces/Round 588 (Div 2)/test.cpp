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
	map<int,int> m;
	m[1] = 1;
	int& j = m[1];
	vi a;
	a.pb(j);
	printf("j:%d\n",j);
	j = -1;
	printf("%d\n",m[1]);
	printf("vector:\n");
	for(int i=0;i<a.size();i++){
		printf("%d\n",a[i]);
	}
	printf("\n");
	return 0;
};