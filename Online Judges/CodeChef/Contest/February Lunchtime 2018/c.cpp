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
	int tc,i,j,n,q;
	string kata;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&q);
		cin>>kata;
		while(q--){
			int p,k;
			scanf("%d %d",&p,&k);
			string subKata = kata.substr(0,p);
			int pjg = subKata.length();
			string kata1="", kata2;
			for(i=0;i<pjg;i++){
				kata1+=subKata[i];
				int idxAkhir = pjg-1-i;
				kata2 = subKata.substr(idxAkhir,i+1);
				// printf("kata1: "); cout<<kata1<<" "; printf("kata2: "); cout<<kata2<<endl;
				if(kata1==kata2){k--; if(k==0){break;}}
			}
			if(k==0){printf("%d\n",i+1);}
			else{printf("-1\n");}
		}
	}
	return 0;
};