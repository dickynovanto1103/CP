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

int cnt[30];

bool isOnly1Char(){
	int i;
	int counter = 0;
	for(i=0;i<26;i++){
		if(cnt[i] > 0){counter++;}
	}
	if(counter == 1){return true;}
	else{return false;}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	// printf("n: %d\n",n);
	string kata;
	for(i=0;i<n;i++){
		// printf("i: %d\n",i);
		cin>>kata;
		int pjg = kata.length();
		
		memset(cnt, 0, sizeof cnt);
		for(j=0;j<pjg;j++){
			char kar = kata[j];
			cnt[kar - 'a']++;
		}
		if(isOnly1Char()){
			printf("-1\n");
		}else{
			for(j=0;j<26;j++){
				for(int k=0;k<cnt[j];k++){
					printf("%c",j+'a');
				}
			}
			printf("\n");
		}

	}
	return 0;
};