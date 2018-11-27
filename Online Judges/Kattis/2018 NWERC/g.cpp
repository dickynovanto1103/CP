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

int par[35];
int sebelum[35];


bool isCyclic(string kata) {
	int i,j;
	int pjg = kata.length();
	int node = 1;
	int maks = 1;
	char curChar = kata[0];
	char pref = kata[0];
	sebelum[1] = 'z';
	bool isBalik = false;
	for(i=1;i<pjg;i++){
		char kar = kata[i];
		printf("kar sekarang: %c\n",kar);
		if(kar == 'L' && pref == 'R'){
			node = par[node];
			pref = sebelum[node];
			isBalik = true;
		}else if(kar == 'R' && pref == 'L'){
			node = par[node];
			pref = sebelum[node];
			isBalik = true;
		}else if(kar == 'U' && pref == 'D'){
			node = par[node];
			pref = sebelum[node];
			isBalik = true;
		}else if(kar == 'D' && pref == 'U'){
			node = par[node];
			pref = sebelum[node];
			isBalik = true;
		}else{
			printf("baru nih kar: %c pref: %c\n",kar, pref);
			int temp = node;

			node = maks + 1;
			maks = node;
			par[node] = temp;
			sebelum[node] = curChar;
			pref = curChar;
			isBalik = false;
		}
		printf("node: %d maks: %d pref: %c\n",node, maks, pref);
		curChar = kar;
	}

	return isBalik;
}

int main(){
	string kata;
	cin>>kata;
	memset(par, -1, sizeof par);
	memset(sebelum, -1, sizeof sebelum);
	if(isCyclic(kata)){
		printf("impossible\n");
	}else{
		printf("ga siklik\n");
	}
	return 0;
};