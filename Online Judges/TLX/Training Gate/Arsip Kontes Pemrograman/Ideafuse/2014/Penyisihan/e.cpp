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
	int tc,batas,i;
	string kata;
	vector<string> listKata;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++) {
		printf("Case #%d:\n",tt);
		scanf("%d",&batas);
		while(cin>>kata && kata!="END") {
			listKata.pb(kata);
		}
		int sisa = batas;
		bool isAwal = true;
		for(i=0;i<listKata.size();i++){
			string a = listKata[i];
			int pjg = a.length();
			int berkurang;
			if(isAwal){berkurang = pjg;}
			else{berkurang = pjg+1;}
			int pjgAkanDatang = sisa - berkurang;
			if(pjgAkanDatang<0){printf("\n"); isAwal = true; sisa = batas; i--; continue;}
			sisa-=pjg;
			if(isAwal){
				cout<<a;	
				isAwal = false;
			}else{
				cout<<" "<<a;
				sisa--;
			}
		}
		printf("\n");
		listKata.clear();
	}
	return 0;
};