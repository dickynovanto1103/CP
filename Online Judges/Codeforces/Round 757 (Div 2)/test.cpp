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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string printBinary(int a) {
	string s;
	for(int i=0;i<=31;i++){
		if((1LL<<i) & a){
			s += "1";
		}else{
			s+="0";
		}
	}
	reverse(s.begin(), s.end());
	return s;
}

int main(){
	int b;
	scanf("%d",&b);
	cout<<"b: "<<b<<" "<<printBinary(b)<<endl;
	cout<<"~b: "<<~b<<" "<<printBinary(~b)<<endl;
	
	return 0;
};