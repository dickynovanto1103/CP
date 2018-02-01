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

const int maxn = 1000;
int a,b,c;

void compute(int i, int j){
	a = j*j - i*i;
	b = 2*j*i;
	c = j*j + i*i;
}

bool isVisited[1000001];

int main(){
	int n,m,i,j;
	int batas;
	
	
	while(scanf("%d",&batas)!=EOF){
		
		memset(isVisited,false,sizeof isVisited);
		int cnt = 0;
		for(i=1;i<=maxn;i++){
			for(j=i+1;j<=maxn;j+=2){
				compute(i,j);
				if(a>batas || b>batas || c>batas){
					break;
				}
				if(__gcd(i,j)==1){
					cnt++;
					isVisited[a] = isVisited[b] = isVisited[c] = true;
					int bil1 = a, bil2 = b, bil3 = c;
					while(true){
						a+=bil1; b+=bil2; c+=bil3;
						if(a>batas || b>batas || c>batas){
							break;
						}
						isVisited[a] = true; isVisited[b] = true; isVisited[c] = true;
					}
				}
			}
		}

		int ans = 0;
		for(i=1;i<=batas;i++){
			if(!isVisited[i]){ans++;}
		}
		
		printf("%d %d\n",cnt,ans);
	}
	return 0;
};