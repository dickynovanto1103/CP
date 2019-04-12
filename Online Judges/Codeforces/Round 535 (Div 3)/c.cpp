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
	scanf("%d",&n);
	string kata;
	cin>>kata;
	if(kata.length() == 1){printf("0\n"); cout<<kata<<endl; return 0;}
	if(kata.length() == 2){
		if(kata[0] != kata[1]){
			printf("0\n"); cout<<kata<<endl;
		}else{
			printf("1\n");
			if(kata[0] == 'R'){
				printf("%c%c",kata[0],'B');
			}else if(kata[0] == 'B'){
				printf("%c%c",kata[0],'R');
			}else if(kata[0] == 'G'){
				printf("%c%c",kata[0],'R');
			}
			printf("\n");

		}
		return 0;
	}
	string temp[] = {"RGB", "RBG", "GRB", "GBR", "BRG", "BGR"};

	for(i=0;i<6;i++){
		for(j=3;j<n;j++){
			temp[i] += temp[i][j-3];
		}
		// printf("temp[%d]: ",i); cout<<temp[i]<<endl;
	}
	int minim = inf;
	string ans;
	for(i=0;i<6;i++){
		int cnt = 0;
		for(j=0;j<n;j++){
			if(temp[i][j] != kata[j]){cnt++;}
		}
		if(cnt < minim){
			minim = cnt;
			ans = temp[i];
		}
	}
	printf("%d\n",minim);
	cout<<ans<<endl;
	return 0;
};