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

string getAwal(string s){
	string ans = "";
	for(int i=0;i<s.size();i++){
		if(s[i] == '*'){break;}
		ans += s[i];
	}
	return ans;
}

string getAkhir(string s){
	string ans = "";
	for(int i=s.size()-1;i>=0;i--){
		if(s[i] == '*'){break;}
		ans += s[i];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

bool cmp(string a, string b){
	return a.size() > b.size();
}

vector<string> getTengah(string s) {
	int cnt = 0;
	int cntBin = 0;
	int i,j;
	vector<string> ans;
	for(i=0;i<s.size();i++){
		if(s[i] == '*'){cnt++; continue;}
	}
	string st;
	for(i=0;i<s.size();i++){
		if(s[i] == '*'){
			ans.pb(st);
			cntBin++; st = ""; continue;
		}
		if(cntBin != 0 && cntBin != cnt){
			st += s[i];
		}
	}
	return ans;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	
	string s[51];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		string ans;
		vector<string> awal, akhir;
		for(i=0;i<n;i++){
			cin>>s[i];
			string stAwal = getAwal(s[i]);
			awal.pb(getAwal(s[i]));
			akhir.pb(getAkhir(s[i]));
		}
		sort(awal.begin(), awal.end(), cmp);
		sort(akhir.begin(), akhir.end(), cmp);
		for(i=0;i<awal.size();i++){
			if(awal[i] == ""){continue;}
			// cout<<awal[i]<<" "<<awal[0]<<endl;
			bool bener = true;
			for(j=0;j<awal[i].size();j++){
				if(awal[i][j] != awal[0][j]){
					bener = false;
					break;
				}
			}
			if(!bener){ans = "*"; break;}
			// if(awal[0].find(awal[i]) == -1){ans = "*"; break;}
		}
		if(ans == "*"){printf("*\n"); continue;}
		for(i=0;i<akhir.size();i++){
			if(akhir[i] == ""){continue;}
			// cout<<akhir[i]<<" "<<akhir[0]<<endl;
			bool bener = true;
			int idx = akhir[0].size() - akhir[i].size();
			for(j=0;j<akhir[i].size();j++){
				if(akhir[i][j] != akhir[0][idx]){
					bener = false;
					break;
				}
				idx++;
			}
			if(!bener){ans = "*"; break;}
		}
		if(ans == "*"){printf("*\n"); continue;}
		ans += awal[0];
		for(i=0;i<n;i++){
			vector<string> list = getTengah(s[i]);
			for(j=0;j<list.size();j++){
				ans += list[j];
			}
		}
		ans += akhir[0];
		assert(ans.size() <= 10000);
		cout<<ans<<endl;
	}
	return 0;
};