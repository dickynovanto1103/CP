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
	int n;
	string s;
	cin>>n>>s;
	if(n % 2 == 1){printf("No\n");}
	else{
		string satu = s.substr(0,n/2);
		string dua = s.substr(n/2, n/2);
		if(satu == dua){printf("Yes\n");}
		else{printf("No\n");}
	}
	return 0;
};