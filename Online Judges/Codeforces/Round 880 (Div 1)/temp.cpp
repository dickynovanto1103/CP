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

int main(){
	string s = "mrbhia";
	sort(s.begin(), s.end());
	int n, hurufBerapa;
	char c;
	cin>>n>>hurufBerapa>>c;
	do{
		if(s[hurufBerapa - 1] == c) {
			for(int i=0;i<n;i++){
				cout<<s[i];	
			}
			cout<<endl;
			
		}

		// cout<<s<<endl;
		
	}while(next_permutation(s.begin(), s.end()));
	
	return 0;
};