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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int arr[21];

bool isAllZero(int n) {
	for(int i=0;i<n;i++){
		if(arr[i] != 0){return false;}
	}
	return true;
}

int main(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	int mat[21][21];
	
	memset(arr, 0, sizeof arr);
	memset(mat, 0, sizeof mat);
	bool isAllZeroAndOne = true;
	for(i=0;i<q;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(c != 0 && c != 1){isAllZeroAndOne = false;}
		a--; b--;
		if(a > b){swap(a,b);}
		if(a == b){continue;}
		mat[a][b] ^= c;
		arr[a] ^= c;
		arr[b] ^= c;
	}
	int cnt = 0;
	do{
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(arr[i] == arr[j] && arr[i] != 0){
					cnt++;
					arr[i] = 0; arr[j] = 0;
					// printf("i: %d j: %d\n",i,j);
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(arr[i] != arr[j] && (arr[i] != 0 && arr[j]!=0)){
					// printf("i: %d j: %d => %d %d\n",i,j,arr[i], arr[j]);
					arr[j] ^= arr[i];
					arr[i] = 0;
					
					// printf("jadi arr[%d]: %d arr[%d]: %d\n",i,arr[i], j,arr[j]);
					cnt++;
					goto here1;
				}
			}
		}
		here1:;
	}while(!isAllZero(n));
	printf("%d\n",min(cnt, q));
	return 0;
};