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


char menang[367];

char getChar(set<char> s) {
	set<char>::iterator it;
	char kar[] = {'P', 'S', 'R'};
	int i;
	for(i=0;i<3;i++){
		char lawan = menang[kar[i]];
		bool valid = true;
		for(it=s.begin();it!=s.end();it++){
			if(lawan == *it){valid = false;break;}
		}	
		if(valid){return kar[i];}
	}
	return 'n';
}

int main(){
	int tc,i,j;
	int n;
	scanf("%d",&tc);
	menang['R'] = 'P';
	menang['P'] = 'S';
	menang['S'] = 'R';
	char kalah[356];
	kalah['P'] = 'R';
	kalah['S'] = 'P';
	kalah['R'] = 'S';
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		string kata[500];
		for(i=0;i<n;i++){
			cin>>kata[i];
		}
		int idx[500];
		memset(idx, 0, sizeof idx);
		bool valid[500];
		memset(valid, true, sizeof valid);
		string ans = "";
		while(true){
			set<char> s;

			for(i=0;i<n;i++){
				if(!valid[i]){continue;}
				s.insert(kata[i][idx[i]]);
				// printf("insert kata[%d][%d]: %c\n",i,idx[i], kata[i][idx[i]]);
			}
			if(s.size() == 1){
				char kar = *s.begin();
				// printf("tambah kar: %c => %c\n",kar, menang[kar]);
				ans += menang[kar];
				break;
			}else if(s.size() == 3){
				ans = "IMPOSSIBLE";
				break;
			}else{
				int kar = getChar(s);
				// printf("kar: %c\n",kar);
				if(kar == 'n'){ans = "IMPOSSIBLE"; break;}
				else{
					ans += kar;
					for(i=0;i<n;i++){
						if(valid[i] && kata[i][idx[i]] == kalah[kar]){
							// printf("idx[%d]: %d\n",i,idx[i]);
							valid[i] = false;
						}
						idx[i]++; idx[i] %= kata[i].length();
						// printf("idx[%d] jd: %d\n", i, idx[i]);
					}
				}
			}
		}
		if(ans.size() > 500){
			cout<<"IMPOSSIBLE"<<endl;
		}else{
			cout<<ans<<endl;	
		}
		
		
	}
	return 0;
};