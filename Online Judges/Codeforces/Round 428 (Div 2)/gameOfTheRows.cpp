#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool mat[10010][9];

bool isSurroundFilled(int n, int i){
	if(i==0 && mat[n][1]){return true;}
	if(i==1 && mat[n][0]){return true;}
	if(i==2 && mat[n][3]){return true;}
	if(i==3 && (mat[n][2] || mat[n][4])){return true;}
	if(i==4 && (mat[n][3] || mat[n][5])){return true;}
	if(i==5 && mat[n][4]){return true;}
	if(i==6 && mat[n][7]){return true;}
	if(i==7 && mat[n][6]){return true;}
	return false;
}

int main() {
	int n,k,a[110],i,j;
	
	scanf("%d %d",&n,&k);
	for(i=0;i<k;i++){scanf("%d",&a[i]);}
	sort(a,a+k);
	memset(mat,false,sizeof mat);
	int idx = 0; j=0;
	for(i=0;i<k && idx<n;i++){
		
		while(a[i]--){
			mat[idx][j++] = true;
			if(j==8){j=0; idx++;}
		}
		if(idx==n){break;}
		if(isSurroundFilled(idx,j)){
			if(j+1==8){j=0;}
			else{j++;}
		}
		
	}
	if(i==k){printf("YES\n");}
	else{printf("NO\n");}
	return 0;
}