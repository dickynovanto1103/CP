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
	int tc,s,d;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&s,&d);
		int bil1 = d, bil2 = 0;
		int selisih = (s-d)/2;
		if(selisih<0){printf("impossible\n");}
		else{
			bil1+=selisih; bil2+=selisih;
			if((bil1+bil2)!=s){printf("impossible\n");}
			else{
				printf("%d %d\n",bil1,bil2);	
			}
			
		}
	}
	return 0;
};