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

vector<string> listKata;
vector<string> listSentence;

string word;
string text;

int countBanyak(int ukuran){
	int cnt = 0;
	int i,j;
	int pjgWord = word.length();
	for(i=0;i<ukuran;i++){
		text = listSentence[i];
		if(text.find(word) != -1){
			cnt++;
		}
	}
	return cnt;
}

int main(){
	string kata;
	
	string kalimat = "";
	while(cin>>kata){
		if(kata[kata.length()-1] == '.'){
			kalimat+=kata;
			listSentence.pb(kalimat);
			kalimat = "";
		}else{
			kalimat+=kata;
			kalimat += ' ';
		}

	}
	int ukuran = listSentence.size();
	int i,j,k;
	int maks = 0;
	string ans;
	for(i=0;i<ukuran;i++){
		kata = listSentence[i];
		int pjg = kata.length();

		for(j=0;j<pjg;j++){
			word = "";
			for(k=j;k<pjg;k++){
				word += kata[k];
				
				int found = countBanyak(ukuran);
				int pjgWord = word.length();
				if(found == ukuran){
					if(pjgWord > maks){
						maks = pjgWord;
						ans = word;
					}
				}
				

			}

		}
	}
	int pjg=ans.length();
	// printf("pjg: %d\n",pjg);
	cout<<ans<<endl;
	return 0;
};