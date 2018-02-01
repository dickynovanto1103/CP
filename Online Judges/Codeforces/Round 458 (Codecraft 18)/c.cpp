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
	string kata;
	int i,j,k;
	// int banyak1 = __builtin_popcount(10);
	// printf("%d\n",banyak1);
	int order[1001];
	order[1] = 0;
	for(i=2;i<=1000;i++){
		int banyak1 = __builtin_popcount(i);
		order[i] = 1+order[banyak1];
	}
	for(i=1;i<=1000;i++){
		if(i>1){printf(" ");}
		printf("%d",order[i]);
	}
	printf("\n");
	cin>>kata;
	scanf("%d",&k);
	
	
	int cnt1 = 0, ans=0;
	if(kata.length()<=11){
		int power = 0;
		int sum = 0;
		for(i=kata.length()-1;i>=0;i--){
			char kar = kata[i];
			if(kar=='1'){
				cnt1++;
				sum+=pow(2,power);
			}
			power++;
		}

		if(sum<=1000){
			for(i=sum;i>=0;i--){
				if(order[i]==k){
					ans++;
				}
			}
		}else{
			for(i=1000;i>=0;i--){
				if(order[i]==(k-1)){
					ans++;
				}
			}
		}
	}else{
		for(i=kata.length()-1;i>=0;i--){
			char kar = kata[i];
			if(kar=='1'){
				cnt1++;
			}
		}	
		for(i=1000;i>=0;i--){
			if(order[i]==(k-1)){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
};