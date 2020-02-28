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

bool isDelimiter(char kar) {
	return kar == '.' || kar == ',' || kar == ';' || kar == '\'';
}

string parse(string kata) {
	stack<char> s;
	string ans = "";
	bool containCapital = false;
	for(int i=0;i<kata.length();i++){
		if(isDelimiter(kata[i])){
			int cnt = 0;
			while(!s.empty()){
				char tambah = s.top(); s.pop();
				if(containCapital && !cnt){
					tambah -= 'a'; tambah += 'A';
					ans += tambah;
					cnt++;
				}else{
					ans += tambah;
				}
			}
			if(containCapital){
				containCapital = false;
				int pjgTemp = ans.length();
				ans[pjgTemp - 1] -= 'A'; ans[pjgTemp -1] += 'a';
			}
			ans += kata[i];
		}else{
			if(kata[i] >= 'A' && kata[i] <= 'Z'){containCapital = true;}
			s.push(kata[i]);
		}
	}
	int cnt = 0;
	while(!s.empty()){
		char tambah = s.top(); s.pop();
		if(containCapital && !cnt){
			tambah -= 'a'; tambah += 'A';
			ans += tambah;
			cnt++;
		}else{
			ans += tambah;
		}
	}
	if(containCapital){
		containCapital = false;
		int pjgTemp = ans.length();
		ans[pjgTemp - 1] -= 'A'; ans[pjgTemp -1] += 'a';
	}
	
	
	return ans;
}

int main(){
	int tc,i,j;
	scanf("%d\n",&tc);
	for(int tt=1;tt<=tc;tt++){
		if(tt>1){printf("\n");}
		string kata;
		while(getline(cin, kata), kata != "*"){
			stringstream s(kata);
			string word;
			vector<string> listWord;
			while(s >> word) {
				// cout<<word<<endl;
				listWord.pb(parse(word));
			}
			for(i=0;i<listWord.size();i++){
				if(i){printf(" ");}
				// else{listWord[0][0] -= 'a'; listWord[0][0] += 'A';}
				cout<<listWord[i];
			}
			cout<<endl;
			// cout<<kata<<endl;
		}
		
	}
	return 0;
};