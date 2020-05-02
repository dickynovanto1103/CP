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
	int tc,i,j,n,k;
	string s;
	scanf("%d",&tc);
	string ans[100001];
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<k;i++){
			ans[i] = "";
		}

		cin>>s;
		sort(s.begin(), s.end());
		char last = s[n-1];
		// printf("last: %c\n",last);
		for(i=0;i<k;i++){
			ans[i] += s[i];
		}
		if(ans[0] != ans[k-1]){printf("%c\n",ans[k-1][0]); continue;}
		string jawab = "";
		int idx = 0;
		int lastIdx = 0;
		if(k == n){printf("%c\n",ans[k-1][0]); continue;}
		bool isRata = (s[k] == last) ? true : false;
		// printf("isRata: %d\n",isRata);
		if(!isRata){jawab = ans[0];}
		for(i=k;i<n;i++){
			if(isRata){
				//bagi rata
				ans[idx] += s[i];
				lastIdx = idx;
				isRata = true;
				idx++;
				idx %= k;
			}else{
				jawab += s[i];
			}
		}
		if(isRata){
			jawab = ans[lastIdx];
		}
		cout<<jawab<<endl;
	}
	
	return 0;
};