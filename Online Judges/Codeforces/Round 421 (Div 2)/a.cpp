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
	int c,v0,v1,a,l,i;
	scanf("%d %d %d %d %d",&c,&v0,&v1,&a,&l);
	int cnt=1;
	i = v0;
	if(i==c){printf("%d\n",cnt );}
	else{
		while(i<=c){
			//if(i==c){break;}
			if(v0+a<=v1){v0+=a;}
			i+=v0;
			//printf("i jd: %d\n",i);
			cnt++;
			//if(i==c){i--;}
		}	
		printf("%d\n",cnt);
	}
	
	
	return 0;
}