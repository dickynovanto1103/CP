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
	int n,i,j,k;
	scanf("%d %d",&n,&k);
	string s;

	cin>>s;
	if(k == 0){cout<<s<<endl; return 0;}
	if(n == 1){
		cout<<0<<endl;
		return 0;
	}
	if(s[0] != '1'){
		s[0] = '1';
		k--;
	}
	for(i=1;i<n;i++){
		if(!k){break;}
		if(s[i] != '0'){
			s[i] = '0';
			k--;
		}
	}
	cout<<s<<endl;
	return 0;
};