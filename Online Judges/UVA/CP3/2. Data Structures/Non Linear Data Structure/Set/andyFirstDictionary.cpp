#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	string kata, total="";
	while(getline(cin,kata)){
		if(kata==""){continue;}
		total+=kata; total+=" ";
	}
	int ukuran = total.length();
	
	for(int i=0;i<ukuran;i++){total[i] = tolower(total[i]);}
	//cout<<total<<endl;
	kata = "";
	set<string> himp;
	set<string>::iterator it;
	bool terisi = false;
	for(int i=0;i<ukuran;i++){
		if(total[i]>=97 && total[i]<=122){terisi = true; kata+=total[i];}
		else{
			if(terisi){himp.insert(kata); kata=""; terisi = false;}
		}
	}
	for(it=himp.begin();it!=himp.end();it++){
		cout<<*it<<endl;
	}

	return 0;
}