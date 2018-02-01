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
	int h1,a1,c1;
	int h2,a2;
	int i,j,n;
	scanf("%d %d %d",&h1,&a1,&c1);
	scanf("%d %d",&h2,&a2);
	vector<string> action;
	while(true){
		if(h1<=a2){
			if(h2<=a1){
				h2-=a1; action.pb("STRIKE");
			}else{
				h1+=c1; action.pb("HEAL");	
			}
			
		}else{
			action.pb("STRIKE");
			h2-=a1;
			
		}
		if(h2<=0){break;}
		h1-=a2;
	}
	int ukuran = action.size();
	printf("%d\n",ukuran);
	for(i=0;i<ukuran;i++){
		cout<<action[i]<<endl;
	}
	return 0;
};