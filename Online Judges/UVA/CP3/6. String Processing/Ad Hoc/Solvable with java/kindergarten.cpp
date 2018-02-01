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

int main(){
	string kata;
	int i,n,j;
	while(getline(cin,kata)){
		int pjg = kata.length();
		bool sudahSpasi = true;
		int cntKata = 0;
		for(i=0;i<pjg;i++){
			char kar = kata[i];
			if((kar>='a' && kar<='z') || (kar>='A' && kar<='Z')){
				if (sudahSpasi)
				{
					cntKata++;
					sudahSpasi=false;
				}
			}else{
				sudahSpasi = true;
			}
		}
		printf("%d\n",cntKata);
	}
	return 0;
};