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

bool isValid(string s) {
	char cur = 'z';
	bool vis[256];
	memset(vis, false, sizeof vis);
	for(int i=0;i<s.size();i++){
		char c = s[i];
		if(vis[c]){
			if(cur == c) {
				continue;
			}

			return false;
		}

		vis[c] = true;
		cur = c;
	}
	return true;
}

bool isAllCharSame(string s) {
	char c = s[0];
	for(int i=0;i<s.size();i++){
		if(c != s[i]) return false;
	}

	return true;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		int n;
		scanf("%d",&n);
		string s[101];
		bool valid = true;
		for(int i=0;i<n;i++){
			cin>>s[i];
			if(!isValid(s[i])){
				valid = false;
			}
		}

		if(!valid){
			printf("IMPOSSIBLE\n");
			continue;
		}

		//coba match
		string final = s[0];
		
		int cntGabung = 1;
		
		bool idxProcessed[101];
		memset(idxProcessed, false, sizeof idxProcessed);
		idxProcessed[0] = true;
		
		while(cntGabung < n) {
			char beginChar = final[0], endChar = final[final.size() - 1];
			//find string that ends with begin char;
			string candidate = "";
			int idxCdd = -1;
			for(int i=0;i<n;i++){
				if(idxProcessed[i]) continue;
				
				string st = s[i];
				if(st[st.size() - 1] == beginChar) {
					if(isAllCharSame(st)){
						idxProcessed[i] = true;
						final = st + final;
						cntGabung++;
						break;
					}

					candidate = st;
					idxCdd = i;
				}
			}

			if(idxCdd != -1) {
				idxProcessed[idxCdd] = true;
				cntGabung++;
				final = candidate + final;
				continue;
			}

			candidate = "";
			idxCdd = -1;
			for(int i=0;i<n;i++){
				if(idxProcessed[i]) continue;
				string st = s[i];
				if(st[0] == endChar) {
					if(isAllCharSame(st)) {
						idxProcessed[i] = true;
						cntGabung++;
						final = final + st;
						break;
					}

					candidate = st;
					idxCdd = i;
				}
			}

			if(idxCdd != -1) {
				idxProcessed[idxCdd] = true;
				cntGabung++;
				final = final + candidate;
				continue;
			}

			//klo ga ada yang cocok, sambungin random
			for(int i=0;i<n;i++){
				if(idxProcessed[i]) continue;
				idxProcessed[i] = true;
				cntGabung++;
				final = final + s[i];
				break;
			}
			//if cannot gabung anymore, then valid = false;
		}

		if(!valid){
			puts("IMPOSSIBLE");
			continue;
		}

		// if(!isValid(final)){
		// 	puts("IMPOSSIBLE");
		// 	continue;
		// }



		cout<<final<<endl;
	}
	
	return 0;
};

Set up Netlify DNS for your domain
Automatically provision DNS records and wildcard certificates for all subdomains.

Add domain
Add DNS records
Activate Netlify DNS
Update your domain’s name servers
Last step! Log in to your domain provider and change your name servers to the following:

ns2.domain.com
ns1.domain.com

dns1.p01.nsone.net
dns2.p01.nsone.net
dns3.p01.nsone.net
dns4.p01.nsone.net