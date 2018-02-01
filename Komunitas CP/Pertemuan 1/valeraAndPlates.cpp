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

int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int cnt = 0;
	for(int i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		if(bil==1){
			if(m==0){cnt++;}
			else{m--;}
		}else{
			if(k==0){//plate kosong..cek bowl kosong apa ngga
				if(m==0){cnt++;}
				else{m--;}
			}else{
				//printf("bil: %d i: %d masuk sini\n",bil,i);
				k--;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
};