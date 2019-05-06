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

char getMissing(string s){
	int i,j;
	for(i=0;i<5;i++){
		bool valid = true;
		for(j=0;j<s.length();j++){
			if(s[j] == (i + 'A')){valid = false;break;}
		}
		if(valid){return i + 'A';}
	}
	return 'G';
}

int main(){
	int tc,i,j;
	int f;
	cin>>tc>>f;
	
	while(tc--){
		// if(tt == 2){cout<<"asuga"<<flush;}
		int cnt[256];
		memset(cnt, 0, sizeof cnt);
		
		set<ii> listSegment;
		set<ii>::iterator it;
		for(i=1;i<=595;i+=5){
			listSegment.insert(ii(i, i+4));
		}
		string ans = "";

		int minim[] = {24, 6,2,1};
		for(i=0;i<4;i++){
			memset(cnt, 0, sizeof cnt);
			vi listKar;
			// cerr<<"ukuran: "<<listSegment.size()<<endl<<flush;
			// assert(listSegment.size() == minim[i-1]);
			for(it=listSegment.begin(); it!=listSegment.end();it++){
				ii pas = *it;
				// cerr<<"sekarang: "<<pas.first<<" "<<pas.second<<endl<<flush;
				// cerr<<"yang diprint: "<<pas.first + i<<endl<<flush;
				printf("%d\n",pas.first + i);
				fflush(stdout);
				char kar;
				cin>>kar;

				if(kar == 'N'){return 0;}
				else{
					cnt[kar]++;
					listKar.pb(kar);
					// cerr<<"dipush kar:"<<kar<<endl<<flush;
				}
			}
			for(j='A';j<='E';j++){
				int k;
				for(k=0;k<ans.size();k++){
					if(ans[k] == j){break;}
				}
				if(k < ans.size()){continue;}
				if(cnt[j] == (minim[i]-1)){
					ans += j;
					char kar = j;
					break;
				}
			}

			char add = ans[ans.length() - 1];
			// cerr<<"add: "<<add<<endl<<flush;
			int idx = 0;
			set<ii> temp;
			temp = listSegment;

			for(it=temp.begin();it!=temp.end();it++){
				if(listKar[idx++] != add){
					ii pas = *it;
					listSegment.erase(pas);
					// cerr<<"yang dihapus:"<<pas.first<<" "<<pas.second<<endl<<flush;
				}
			}
		}
		ans += getMissing(ans);
		cout<<ans<<endl<<flush;
		// cerr<<"ans: "<<ans<<endl<<flush;
		char jawab;
		cin>>jawab;

		if(jawab == 'N'){return 0;}
	}

	return 0;
};