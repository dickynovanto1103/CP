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
	int n,q,i,j;
	string s;
	cin>>s;
	n = s.length();
	int pref[100001];
	for(i=0;i<n-1;i++){
		if(s[i] == s[i+1]){
			pref[i] = 1;
		}else{
			pref[i] = 0;
		}
		if(i){pref[i] += pref[i-1];}
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--; b--;
		printf("%d\n",pref[b-1] - (a == 0 ? 0 : pref[a-1]));
	}
	return 0;
};