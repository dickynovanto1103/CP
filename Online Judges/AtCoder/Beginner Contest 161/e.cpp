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
	int n,k,c;
	string s;
	scanf("%d %d %d",&n,&k,&c);
	cin>>s;
	int last = n;
	int nextWork[200001];
	for(i=n-1;i>=0;i--){
		nextWork[i] = last;
		if(s[i] == 'o'){
			last = i;
		}
	}
	for(i=0;i<n;i++){
		if(s[i] == 'o'){
			//bisa skip ini ga?
		}
	}
	return 0;
};