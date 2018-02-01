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

string kata;
/*int floydCycleFinding(int x){
	int idx1 = x+1, idx2 = x+2;
	char tortoise = kata[idx1], hare = kata[idx2];
	//printf("tortoise: %c hare: %c\n",tortoise,hare);
	//printf("idx1: %d idx2: %d\n",idx1,idx2);
	while(tortoise!=hare){
		idx1++; idx2+=2;
		tortoise=kata[idx1]; hare = kata[idx2];
		//printf("tortoise: %c hare: %c\n",tortoise,hare);
		//printf("idx1: %d idx2: %d\n",idx1,idx2);
	}
	int mu = 0; hare = x;
	while(tortoise!=hare){
		idx1++; idx2++;
		tortoise=kata[idx1]; hare = kata[idx2]; mu++;
	}
	idx1++;
	int lambda = 1; hare = kata[idx1];
	//printf("idx1: %d\n",idx1);
	//printf("tortoise: %c\n",tortoise);
	while(tortoise!=hare){
		idx1++;
		hare = kata[idx1]; lambda++;
		//printf("hare: %c\n",hare);
	}
	return lambda;

}*/

int main() {
	int tc,i;
	
	scanf("%d",&tc);
	while(tc--){
		cin>>kata;
		int bil;
		if(kata.length()==1){bil = 1; printf("%d\n",bil);}
		else{
			string kata1,kata2;
			int n = kata.length();
			for(i=1;i<=n;i++){
				kata1 = kata.substr(0,i);
				kata2 = kata.substr(i,i);
				//cout<<kata1<<" "<<kata2<<endl;
				if(kata1==kata2){printf("%d\n",i); break;}
			}
		}
		//printf("%d\n",bil);
	}
	return 0;
}