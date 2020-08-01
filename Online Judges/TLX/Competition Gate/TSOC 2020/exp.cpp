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

const int mod = 1e9 + 7;

int a(int x) {

	int z = 1000;
	z-=x;
	
	z %= mod;
	
	return z;
}

// int a(int x) {
// 	int z = 100;
// 	while (x --> 0) {
//         z --> 0;
//         printf("z: %d\n",z);
//         z%=mod;
//     }
//     return z;
// }

int main(){
	int ans = a(100);
	printf("%d\n",ans);
	
	return 0;
};