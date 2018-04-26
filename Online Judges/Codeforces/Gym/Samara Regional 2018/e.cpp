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
	string kata1,kata2;
	cin>>kata1>>kata2;
	int pjg = kata1.length();
	int sudahBeda = false;
	int idxAwal =-1 , idxAkhir = -1;
	int cntBeda = 0;
	if(kata1 == kata2){printf("YES\n"); return 0;}
	for(int i=0;i<pjg;i++){
		char kar1 = kata1[i], kar2 = kata2[i];
		if(kar1!=kar2){
			if(sudahBeda){
				idxAkhir = i;
			}else{
				idxAwal = i;
				idxAkhir = i;
				sudahBeda = true;
			}
		}
		
	}
	int banyak = idxAkhir - idxAwal + 1;
	// printf("idxAwal: %d idxAKhir: %d\n",idxAwal, idxAkhir);
	string sub = kata1.substr(idxAwal, banyak);
	string sub2 = kata2.substr(idxAwal, banyak);
	// cout << "sub: "<<sub<< " sub2: "<<sub2<<endl;
	reverse(sub.begin(), sub.end());

	if(sub==sub2){printf("YES\n");}
	else{printf("NO\n");}
	return 0;
};