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

bool vis[200001];

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		string s;
		cin>>s;
		int n = s.length();
		for(i=0;i<n;i++){
			vis[i] = false;
		}
		vi list;
		int ans = n;

		for(i=0;i<n;i++){
			if(s[i] == 'A'){
				list.pb(i);
			}else{
				if(list.size()){
					int back = list.back(); list.pop_back();
					vis[i] = true; vis[back] = true;
				}
			}
		}
		string str;
		for(i=0;i<n;i++){
			if(!vis[i]){
				str += s[i];
			}
		}
		s = str;
		n = s.size();
		ans = n;
		for(i=0;i<n-1;i++){
			if(s[i] == 'B' && s[i+1] == 'B'){
				ans-=2;
				i++;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
};