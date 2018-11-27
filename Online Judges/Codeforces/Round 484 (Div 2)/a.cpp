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
	int n,i,j;
	string kata;
	scanf("%d",&n);
	cin>>kata;
	for(i=0;i<(n-1);i++){
		char kar1 = kata[i], kar2 = kata[i+1];
		if(kar1 == kar2 && kar1 == '1'){
			printf("No\n"); return 0;
		}
		if(i>0 && i<(n-1)){
			if(kata[i] == '0'){
				if(kata[i-1] == '0' && kata[i+1] == '0'){
					printf("No\n"); return 0;
				}else if(kata[i+1] == '0' && (i+1) == (n-1)){
					printf("No\n"); return 0;
				}
			}
		}
		if(i==0 && kata[i]=='0' && kata[i+1] == '0'){
			printf("No\n");
			return 0;
		}
	}

	if(n==1){
		if(kata[0]=='0'){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
		return 0;
	}else if(n==2){
		if(kata == "00" || kata=="11"){printf("No\n");}
		else{
			printf("Yes\n");
		}
		return 0;
	}
	printf("Yes\n");
	return 0;
};