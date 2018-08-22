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

const int maxn = 1e2 + 2;

bool isValid(char kar){
	if(kar >= 'a' && kar<='z'){return true;}
	if(kar >= 'A' && kar <= 'Z'){return true;}
	if(kar == '-'){return true;}
	return false;
}

string getValidString(string kata){
	bool isVisited[maxn];
	memset(isVisited, false, sizeof isVisited);
	string ans = "";
	int i;
	for(i=0;i<kata.length();i++){
		char kar = kata[i];
		if(isValid(kar)){
			isVisited[i] = true;
		}
	}
	for(i=0;i<kata.length();i++){
		if(isVisited[i]){ans += kata[i];}
	}
	return ans;
}

int main(){
	string strMaks = "";
	int maks = 0;
	string kata;
	while(cin>>kata){
		kata = getValidString(kata);
		// cout<<"kata: "<<kata<<endl;
		int pjg = kata.length();
		if(kata == "E-N-D"){break;}

		if(pjg > maks){
			maks = pjg;
			strMaks = kata;
		}
	}
	for(int i=0;i<strMaks.length();i++){
		strMaks[i] = tolower(strMaks[i]);
	}
	cout<<strMaks<<endl;
	return 0;
};