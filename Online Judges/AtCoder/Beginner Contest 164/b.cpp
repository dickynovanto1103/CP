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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int val = 0;
	while(true){
		if(!val){
			c -= b;
		}else{
			a -= d;
		}
		val = 1 - val;
		if(c <= 0){printf("Yes\n"); return 0;}
		else if(a <= 0){printf("No\n"); return 0;}
	}
	
	return 0;
};