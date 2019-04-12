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
	int a,b;
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int l1,r1,l2,r2;
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		vi list1, list2;
		list1.pb(l1); list1.pb(l1+1);
		list2.pb(l2); list2.pb(l2+1);
		bool found = false;
		for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				int bil1 = list1[i], bil2 = list2[j];
				if(bil1 != bil2){printf("%d %d\n",bil1,bil2); found = true; break;}
			}
			if(found){break;}
		}
	}
	return 0;
};