/*
ID: dickyno1
LANG: C++14
TASK: namenum
*/

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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);

	string in;
	cin>>in;
	// cout<<"in: "<<in<<endl;

	fstream dictFile;
	dictFile.open("dict.txt", ios::in);

	map<char, int> charToNum;
	int cnt = 0;
	int num = 2;
	for(int i=0;i<26;i++) {
		char c = i + 'A';
		if(c == 'Q' || c == 'Z') {continue;}
		if(cnt == 3){cnt = 0; num++;}
		charToNum[c] = num;
		cnt++;
	}

	if(dictFile.is_open()) {
		string s;
		bool found = false;
		while(getline(dictFile, s)) {
			int n = s.size();
			string angka;
			for(int i=0;i<n;i++){
				char c = s[i];
				angka += charToNum[c] + '0';
			}
			if(angka == in) {
				cout<<s<<endl;
				found = true;
			}
		}
		if(!found){
			cout<<"NONE"<<endl;
		}
		dictFile.close();
	}

	

	
	return 0;
};