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

string inverseString(string s) {
	string newStr;
	for(char c: s) {
		char newChar;
		if(c == 'T') {
			newChar = 'F';
		} else {
			newChar = 'T';
		}
		newStr += newChar;
	}
	return newStr;
}

int main(){
	int tc,i,j,n,q;
	scanf("%d",&tc);
	string answers[5];
	int score[5];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);

		scanf("%d %d",&n,&q);
		string trueAnswer = "z";
		int maksScore = 0;
		string ansWithMaxScore = "";
		for(i=0;i<n;i++){
			cin>>answers[i]>>score[i];
			if(maksScore < score[i]){
				maksScore = max(maksScore, score[i]);
				ansWithMaxScore = answers[i];
			}
			
			if(score[i] == q) {
				trueAnswer = answers[i];
			} else if(score[i] == 0) {
				trueAnswer = inverseString(answers[i]);
			}
		}
		if(trueAnswer == "z") {
			cout<<ansWithMaxScore<<" "<<maksScore<<"/1"<<endl;
		}else{
			cout<<trueAnswer<<" "<<q<<"/1"<<endl;
		}

	}
	
	return 0;
};