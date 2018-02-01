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
	int n,i,j, a1=1,a2=2;
	scanf("%d",&n);
	int a[3] = {1,2,3};
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		if(bil==a1 || bil==a2){
			//deciding who are playing next
			int yangBelum;
			for(j=0;j<3;j++){
				if(a[j]!=a1 && a[j]!=a2){
					yangBelum = a[j];
					break;
				}
			}
			if(bil==a1){
				a2 = yangBelum;
			}else{
				a1 = yangBelum;
			}
		}else{
			printf("NO\n");
			return 0;
		}
		
	}
	printf("YES\n");
	return 0;
};