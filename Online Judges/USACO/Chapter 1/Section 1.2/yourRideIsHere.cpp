/*
ID: dickyno1
LANG: C++
TASK: ride
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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	string comet, group;
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	fin>>comet>>group;
	int jumlahComet = 1, jumlahGroup = 1;
	int i;
	for(i=0;i<comet.length();i++){
		int bil = comet[i] - 'A' + 1;
		jumlahComet*=bil;
		jumlahComet%=47;
	}
	for(i=0;i<group.length();i++){
		int bil = group[i] - 'A' + 1;
		jumlahGroup*=bil;
		jumlahGroup%=47;
	}
	if(jumlahGroup==jumlahComet){fout<<"GO"<<endl;}
	else{fout<<"STAY"<<endl;}
	return 0;
};