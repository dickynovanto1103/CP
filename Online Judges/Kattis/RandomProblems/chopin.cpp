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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	map<string, string> mapper;
	mapper["A"] = "A";
	mapper["A#"] = "Bb"; mapper["Bb"] = "A#";
	mapper["B"] = "B";
	mapper["C"] = "C";
	mapper["C#"] = "Db"; mapper["Db"] = "C#";
	mapper["D"] = "D";
	mapper["D#"] = "Eb"; mapper["Eb"] = "D#";
	mapper["E"] = "E";
	mapper["F"] = "F";
	mapper["F#"] = "Gb"; mapper["Gb"] = "F#";
	mapper["G"] = "G";
	mapper["G#"] = "Ab"; mapper["Ab"] = "G#";
	string s, tone;
	int tc = 1;
	while(cin>>s>>tone) {
		printf("Case %d: ",tc++);
		if(mapper[s] == s){
			printf("UNIQUE\n");
		}else{
			cout<<mapper[s]<<" "<<tone<<endl;
		}
	}
	return 0;
};