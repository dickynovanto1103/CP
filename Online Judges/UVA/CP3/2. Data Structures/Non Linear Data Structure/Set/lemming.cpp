#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,battlefield,sg,sb,i,j;
	multiset<int> g,b;
	multiset<int>::iterator it,it1,it2;
	scanf("%d",&tc);
	int test=1;
	while(tc--){
		if(test==2){printf("\n");}
		scanf("%d %d %d",&battlefield,&sg,&sb);
		int bil;
		for(i=0;i<sg;i++){scanf("%d",&bil); g.insert(bil);}
		for(i=0;i<sb;i++){scanf("%d",&bil); b.insert(bil);}
		/*printf("awal:\n");
		printf("g:");
		for(it=g.begin();it!=g.end();it++){printf(" %d",*it);}
		printf("\n");
		printf("b:");
		for(it=b.begin();it!=b.end();it++){printf(" %d",*it);}
		printf("\n");*/
		while(g.size()>0 && b.size()>0){
			int ukuranG = g.size(), ukuranB = b.size();
			int minim = min(ukuranG,min(ukuranB,battlefield));
			vi antrianG, antrianB;
			for(i=0;i<minim;i++){
				it1 = --g.end();
				it2 = --b.end();
				int bil1 = *it1, bil2 = *it2;
				//printf("bil1: %d bil2: %d\n",bil1,bil2);
				//klo rte..inget coba simpen nilainya di var dulu
				g.erase(it1); b.erase(it2);
				if(*it1>*it2){//g menang
					bil = *it1-*it2;
					antrianG.pb(bil);
					//g.insert(bil);
					//printf("g sementara menang, yang diinsert bil: %d\n",bil);
				}else if(*it1 < *it2){
					bil = *it2-*it1;
					antrianB.pb(bil);
					//b.insert(bil);
					//printf("b sementara menang, yang diinsert bil: %d\n",bil);
				}
				/*printf("g:");
				for(it=g.begin();it!=g.end();it++){printf(" %d",*it);}
				printf("\n");
				printf("b:");
				for(it=b.begin();it!=b.end();it++){printf(" %d",*it);}
				printf("\n");*/
			}
			for(i=0;i<antrianG.size();i++){g.insert(antrianG[i]);}
			for(i=0;i<antrianB.size();i++){b.insert(antrianB[i]);}
		}
		if(g.size()==0 && b.size()==0){printf("green and blue died\n");}
		else if(g.size() >  b.size()){
			printf("green wins\n");
			vi ans;
			for(it1 = g.begin();it1!=g.end();it1++){
				//printf("%d\n",*it1);
				ans.pb(*it1);
			}
			int ukuran = ans.size();
			for(i=ukuran-1;i>=0;i--){printf("%d\n",ans[i]);}
		}else{
			printf("blue wins\n");
			vi ans;
			for(it1 = b.begin();it1!=b.end();it1++){
				//printf("%d\n",*it1);
				ans.pb(*it1);
				//printf("yang dipush: %d\n",*it1);
			}
			int ukuran = ans.size();
			//printf("ukuran: %d\n",ukuran);
			for(i=ukuran-1;i>=0;i--){printf("%d\n",ans[i]);}
		}
		g.clear(); b.clear();
		test = 2;
	}
	return 0;
}