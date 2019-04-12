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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	while(scanf("%d",&n), n){
		int a[35];
		memset(a, -1, sizeof a);
		for(i=0;i<n;i++){
			string s;
			int bil;
			cin>>s;
			if(s == "SET"){
				scanf("%d",&bil);
				a[bil] = 1;
			}else if(s == "CLEAR"){
				scanf("%d",&bil);
				a[bil] = 0;
			}else if(s == "OR") {
				int idx1, idx2;
				scanf("%d %d",&idx1,&idx2);
				if(a[idx1] == 1 || a[idx2] == 1){
					a[idx1] = 1;
				}else{
					if(a[idx1] == 0 && a[idx2] == -1){
						a[idx1] = -1;
					}
				}
			}else{
				int idx1, idx2;
				scanf("%d %d",&idx1,&idx2);
				if(a[idx1] == 0 || a[idx2] == 0){
					a[idx1] = 0;
				}else{
					if(a[idx1] == 1 && a[idx2] == -1){
						a[idx1] = -1;
					}
				}
			}
		}
		string ans = "";
		// printf("n: %d\n",n);
		reverse(a,a+32);
		for(i=0;i<32;i++){
			if(a[i] == -1){printf("?");}
			else{printf("%d",a[i]);}
		}
		printf("\n");
	}
	return 0;
};