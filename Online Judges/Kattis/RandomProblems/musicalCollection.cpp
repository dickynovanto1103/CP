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
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool cmp(pair<string, int> a, pair<string, int> b) {
	if(a.first.length() == b.first.length()) {
		return a.first < b.first;
	}else if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first.length() < b.first.length();
}

vector<pair<string, int> > listPas;
vector<pair<string, int> >::iterator it;

void generateSubstring(const string& kata, int idx) {
	int pjg = kata.length();
	int i,j;
	for(i=0;i<pjg;i++){
		string temp = "";
		for(j=i;j<pjg;j++){
			temp += kata[j];
			listPas.pb(pair<string,int>(temp, idx));
		}
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:\n",tt);
		int n;
		scanf("%d\n",&n);

		string kata;
		string ans[105];
		for(i=0;i<105;i++){ans[i] = ":(";}
		for(i=0;i<n;i++){
			getline(cin, kata);
			int pjg = kata.length();
			for(j=0;j<pjg;j++){
				if(kata[j] >= 'a' && kata[j] <= 'z'){kata[j] -= 'a'; kata[j] += 'A';}
			}
			generateSubstring(kata, i);

		}

		if(n == 1){printf("\"\"\n"); listPas.clear();continue;}
		sort(listPas.begin(), listPas.end(), cmp);

		it = unique(listPas.begin(), listPas.end());
		listPas.resize(distance(listPas.begin(), it));

		int ukuran = listPas.size();
		// if(tt == 6){
		// 	for(i=0;i<ukuran;i++){
		// 		printf("i: %d ",i);
		// 		cout<<listPas[i].first<<" "<<listPas[i].second<<endl;
		// 	}	
		// }
		

		for(i=0;i<ukuran-1;i++){
			if(listPas[i].first == listPas[i+1].first){
				
				for(j=i+1;j<ukuran;j++){
					if(listPas[j].first == listPas[i].first){i = j;}
					else{break;}
				}
			}else{
				if(ans[listPas[i].second] != ":("){continue;}
				ans[listPas[i].second] = listPas[i].first;
				// printf("diassign a[%d]: ",listPas[i].second); cout<<listPas[i].first<<endl;
			}
		}
		// printf("i: %d\n",i);
		i = ukuran-1;
		if(ukuran > 1 && listPas[i].first != listPas[i-1].first) {
			if(ans[listPas[i].second] == ":("){
				ans[listPas[i].second] = listPas[i].first;
				// printf("diassign a[%d]: ",listPas[i].second); cout<<listPas[i].first<<endl;
			}
			
		}
		for(i=0;i<n;i++){
			if(ans[i] == ":("){printf(":(\n"); continue;}
			// printf("i: %d\n",i);
			printf("\"");
			cout<<ans[i];
			printf("\"\n");
		}
		
		listPas.clear();
	}
	return 0;
};