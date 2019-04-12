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

const int maxn = 2010;

int main(){
	int tc,i,j,n;
	bool isVisited[maxn];
	string kata;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		cin>>kata;
		int pjgSekarang = kata.length();
		bool isDepan = true;
		memset(isVisited, false, sizeof isVisited);
		int depan = 0, belakang = kata.length()-1;
		for(i=0;i<n;i++){
			// printf("i: %d n: %d pjgSekarang: %d\n",i,n,pjgSekarang);
			int bagi4 = pjgSekarang / 4;
			if(bagi4 == 0){break;}
			else{
				if(isDepan){
					for(j=depan;j<depan + bagi4;j++){
						isVisited[j] = true;
					}
					depan = j;
					isDepan = false;
				}else{
					for(j=belakang;j>belakang - bagi4;j--){
						isVisited[j] = true;
					}
					belakang = j;
					isDepan = true;
				}
			}
			pjgSekarang -= bagi4;
			// printf("pjgSekarang jd: %d\n",pjgSekarang);
		}
		for(i=0;i<kata.length();i++){
			if(!isVisited[i]){printf("%c",kata[i]);}
		}
		printf("\n");
	}

	return 0;
};