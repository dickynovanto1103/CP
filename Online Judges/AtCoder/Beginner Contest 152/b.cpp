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
	int a,b,i;
	cin>>a>>b;
	string satu, dua;
	char a1 = a+'0', a2 = b+'0';
	// cout<<a1<<" "<<a2<<endl;
	for(i=0;i<a;i++){
		dua.pb(a2);
	}
	for(i=0;i<b;i++){
		satu.pb(a1);
	}
	if(satu < dua){
		cout<<satu<<endl;
	}else{
		cout<<dua<<endl;
	}
	return 0;
};