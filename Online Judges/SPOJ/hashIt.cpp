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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,string> ii;
typedef vector<ii> vii;

const int maxn = 105;
const int mod = 101;
string hashed[maxn];
bool isFilled[maxn];

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);

	while(tc--){
		set<string> s;
		for(i=0;i<mod;i++){
			hashed[i] = "";
		}
		memset(isFilled, false, sizeof isFilled);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			string kata;
			cin>>kata;
			string temp = "";
			int pjg = kata.length();
			int nilaiHash = 0;
			// printf("kata: "); cout<<kata<<endl;
			for(j=4;j<pjg;j++){
				nilaiHash += (kata[j]*(j-3));
				nilaiHash %= mod;
				temp += kata[j];
			}

			nilaiHash *= 19;
			nilaiHash%=mod;

			if(kata[0] == 'A'){
				if(s.find(temp) != s.end()){continue;}
				if(!isFilled[nilaiHash]){
					isFilled[nilaiHash] = true;
					hashed[nilaiHash] = temp;
					s.insert(temp);
				}else{
					int next = 0;
					for(j=1;j<=19;j++){
						next = nilaiHash + j*j + 23*j;
						next %= mod;
						if(!isFilled[next]){
							hashed[next] = temp;
							isFilled[next] = true;
							s.insert(temp);
							break;
						}
					}
				}
					
			}else{
				if(s.find(temp) == s.end()){
					continue;
				}else{
					if(hashed[nilaiHash] == temp){
						isFilled[nilaiHash] = false;
						hashed[nilaiHash] = "";
						s.erase(temp);
						continue;
					}else{
						int next = 0;
						for(j=1;j<=19;j++){
							next = nilaiHash + j*j + 23*j;
							next %= mod;
							if(hashed[next] == temp){
								hashed[next] = "";
								isFilled[next] = false;
								s.erase(temp);
								break;
							}
						}	
					}
				}
				
			}
			// printf("temp: "); cout<<temp<<endl;
		}
		vii ans;
		for(i=0;i<mod;i++){
			if(!isFilled[i]){continue;}
			ans.pb(ii(i,hashed[i]));
		}
		int ukuran = ans.size();
		printf("%d\n",ukuran);
		for(i=0;i<ukuran;i++){
			printf("%d:",ans[i].first);
			cout<<ans[i].second<<endl;
		}
	}
	return 0;
};