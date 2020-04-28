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
	string s;
	cin>>s;
	int i,j,n;
	n = s.size();
	int mod = 2019;
	for(i=1;i<100;i++){
		printf("%d\n",mod*i);
	}
	
	// for(i=0;i<n;i++){
	// 	int val = 0;
	// 	for(j=i;j<n;j++){
	// 		val *= 10;
	// 		val += s[j] - '0';
	// 		val %= mod;
	// 		printf("i: %d j: %d val: %d\n",i+1, j+1, val);
	// 	}
		
	// }
	
	return 0;
};