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

const int maxn = 2e2 + 2;

string kata[maxn];
int n;
char ans[maxn];

bool check(string word, int cnt) {
	int cntFront = 0, cntBack = 0;
	bool isVisited[maxn];
	memset(isVisited, false, sizeof isVisited);
	for(int i=0;i<cnt;i++){
		int len = kata[i].length();
		if(isVisited[len]){continue;}
		string front = word.substr(0,len);
		string back = word.substr(word.length() - len, len);
		if(front == kata[i]) {
			if(cntFront < n-1){
				cntFront++;
				ans[i] = 'P';
			}
		}
		if(back == kata[i]) {
			if(cntBack < n-1){
				cntBack++;
				ans[i] = 'S';
			}
		}
	}
}

int main(){
	int i,j;
	scanf("%d",&n);
	
	vector<string> listWordLongest;
	for(i=0;i<2*n-2;i++){
		cin>>kata[i];
		if(kata[i].length() == (n-1)){
			listWordLongest.pb(kata[i]);
		}
	}

	string temp1 = listWordLongest[0].substr(0,n-1);
	string temp2 = listWordLongest[1].substr(1,n-1);
	if(temp1 == temp2){
		string temp = "";
		temp += listWordLongest[1][0];
		temp += listWordLongest[0];

	}

	return 0;
};