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
	bool isVisited[11];
	memset(isVisited, false, sizeof isVisited);
	int kiri = 1, kanan = 10;
	bool isValid = true;
	while(scanf("%d",&n), n) {
		string s1,s2;
		cin>>s1>>s2;

		if(s1 == "too") {
			if(s2 == "high"){
				for(i=n;i<=10;i++){
					isVisited[i]=true;
				}
				kanan = n-1;
			}else{
				for(i=1;i<=n;i++){
					isVisited[i]=true;
				}
				kiri = n+1;
			}
			
		}else{
			
			if(!isVisited[n]){
				printf("Stan may be honest\n");
			}else{
				printf("Stan is dishonest\n");
			}
			memset(isVisited, false, sizeof isVisited);
		}
	}
	return 0;
};