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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		string s;
		cin>>s;
		int n = s.length();
		string ans = "";

		if(n == 1){
			cout<<s<<endl;
			continue;
		}
		int cntsatu = 0;
		int idx = 0;
		bool berubah = false;
		bool kena1Terus = true;
		for(i=0;i<n;i++){
			if(s[i] == '1'){
				if(!kena1Terus){
					if(s[i] < '9'){berubah = true;}
					ans += '9'; continue;
				}
				cntsatu++;

				if(cntsatu == 2){
					idx = i;
					ans += s[i]-1;
				}else if(cntsatu > 2) {
					if(s[i] < '9'){berubah = true;}
					ans += '9';
				}else{
					ans += s[i];
				}
			}else if(s[i] > '1') {

				if(cntsatu >= 2) {
					if(s[i] < '9'){
						berubah = true;
					}
					ans += '9';
					kena1Terus = false;
					continue;
				}
				if(kena1Terus){
					// printf("i: %d\n", i);
					idx = i;
					ans += s[i] - 1;
					kena1Terus = false;
				}else{

					if(s[i] < '9'){
						berubah = true;
					}
					ans += '9';
				}
			}else{ // s[i] == 0
				if(!kena1Terus){
					if(s[i] < '9'){berubah = true;}
					ans += '9'; continue;
				}

				if(cntsatu >= 2) {
					if(s[i] < '9'){berubah = true;}
					ans += '9';
				}else{
					ans += s[i];
				}
			}
		}
		if(idx == n-1){
			ans[idx]++;
			cout<<ans<<endl;
			continue;
		}

		if(cntsatu==1){
			bool valid = true;
			for(i=1;i<n;i++){
				if(s[i] != '0'){valid = false; break;}
			}
			if(!valid){goto here;}
			ans = "";
			for(i=0;i<n-1;i++){
				ans+='9';
			}
			cout<<ans<<endl;
			continue;
		}
		here:;

		if(!berubah){
			ans[idx]++;
		}
		cout<<ans<<endl;

	}
	return 0;
};