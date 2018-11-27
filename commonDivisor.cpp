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

string a,b;
int pjgA, pjgB;
bool isDivisor(int pjg){
	string cocok = a.substr(0,pjg);
	int i;
	// printf("cocok A: "); cout<<cocok<<endl;
	for(i=pjg;i<pjgA;i+=pjg){
		string jawab = a.substr(i,pjg);
		// printf("jawab A: "); cout<<jawab<<endl;
		if(cocok != jawab){return false;}
	}
	// printf("cocok B: "); cout<<cocok<<endl;
	for(i=0;i<pjgB;i+=pjg){
		string jawab = b.substr(i,pjg);
		// printf("jawab B: "); cout<<jawab<<endl;
		if(cocok != jawab){return false;}
	}

	return true;
}

int main(){
	int i,j;
	cin>>a>>b;
	pjgA = a.length(), pjgB = b.length();

	int maks = max(pjgA, pjgB);
	vi listDiv;
	for(i=1;i*i<=maks;i++){
		if(maks%i == 0){
			int hasilBagi = maks / i;
			listDiv.pb(i);
			if(i != hasilBagi){
				listDiv.pb(hasilBagi);
			}
			
		}
	}
	int ukuran = listDiv.size();
	int cnt = 0;
	for(i=0;i<ukuran;i++){
		int pembagi = listDiv[i];

		if(pjgA % pembagi == 0 && pjgB % pembagi == 0){
			// printf("cek pembagi: %d\n",pembagi);
			if(isDivisor(pembagi)){
				// printf("pembagi: %d\n",pembagi);
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
};