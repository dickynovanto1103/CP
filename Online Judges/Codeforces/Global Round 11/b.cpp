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
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

int compute(string s){
	int i,j;
	int n = s.length();
	int ans = 0;
	for(i=0;i<n;i++){
		if(s[i] == 'W'){
			if(i > 0 && s[i-1] == 'W') {
				ans+=2;
			}else{
				ans++;
			}
		}
	}
	return ans;
}

bool cmp(iii a, iii b){
	if(a.first.second == b.first.second){
		return a.first.first < b.first.first;
	}
	return a.first.second > b.first.second;
}

int main(){
	int tc,i,j,n,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		string s;
		cin>>s;
		if(k == 0){
			printf("%d\n",compute(s));
			continue;
		}
		int cntw = 0;
		vi idx;
		for(i=0;i<n;i++){
			if(s[i] == 'W'){
				cntw++;
				idx.pb(i);
			}
		}
		if(cntw == 0){
			for(i=0;i<k;i++){
				s[i] = 'W';
			}
			printf("%d\n",compute(s));
			continue;
		}
		viii listPas;
		if(cntw == 1){
			int pos = idx[0];
			listPas.pb(iii(ii(idx[0], -1), idx[0]));
			listPas.pb(iii(ii(n-1-idx[0], 1), idx[0]));
		}else{
			listPas.pb(iii(ii(idx[0], -1), idx[0]));
			for(i=0;i<cntw - 1;i++){
				listPas.pb(iii(ii(idx[i+1] - idx[i] - 1, 1), idx[i]));
			}	
			listPas.pb(iii(ii(n - 1 - idx[cntw-1], 0), idx[cntw-1]));
		}

		sort(listPas.begin(), listPas.end(), cmp);
		for(i=0;i<listPas.size();i++){
			int start = listPas[i].second;
			int selisih = listPas[i].first.first;
			int order = listPas[i].first.second;
			// printf("start %d selisih: %d order: %d\n",start, selisih, order);
			if(order < 0){
				for(j=start-1;j>=0 && k > 0;j--){
					assert(s[j] == 'L');
					s[j] = 'W';
					// printf("balik j: %d\n",j);
					k--;
				}
			}else{
				for(j=start+1;j<(start+1+selisih) && k > 0;j++){
					// printf("maju j: %d\n",j);
					assert(s[j] == 'L');
					s[j] = 'W';
					k--;
				}	
			}
			
		}

		printf("%d\n",compute(s));
	}
	
	return 0;
};