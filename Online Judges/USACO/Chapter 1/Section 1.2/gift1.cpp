/*
ID: dickyno1
LANG: C++
TASK: gift1
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
	int np,i,j;
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");

	map<string,int> mapper;
	string kata[11];
	int listUang[11];
	memset(listUang,0,sizeof listUang);
	fin>>np;
	for(i=0;i<np;i++){
		string orang;
		fin>>orang;
		kata[i] = orang;
		mapper[orang] = i;
	}
	for(i=0;i<np;i++){
		string pemberi;
		int uang, bagi;
		fin>>pemberi>>uang>>bagi;
		if(bagi==0){continue;}
		int urangRata = uang/bagi, uangSisa = uang%bagi;
		int idxPemberi = mapper[pemberi];
		listUang[idxPemberi]+=uangSisa;
		listUang[idxPemberi]-=(uang);
		for(j=0;j<bagi;j++){
			string diberi;
			fin>>diberi;
			int idxDiberi = mapper[diberi];
			listUang[idxDiberi]+=urangRata;
		}
	}

	for(i=0;i<np;i++){
		fout<<kata[i]<<" "<<listUang[i]<<endl;
	}

	return 0;
};