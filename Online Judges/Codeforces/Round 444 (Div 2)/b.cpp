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

int a[4][7];

bool isFound(int bil, int row){
	int j;
	for(j=0;j<6;j++){
		if(a[row][j]==bil){return true;}
	}
	return false;
}

int main(){
	int n,i,j;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<6;j++){
			int bil;
			scanf("%d",&a[i][j]);	
		}
	}
	int batas;
	if(n==1){batas = 9;}
	else if(n==2){batas = 99;}
	else{batas = 999;}
	for(i=1;i<=batas;i++){
		bool ans;
		if(i<10){
			if(n==3){
				ans = (isFound(i,0) || isFound(i,1) || isFound(i,2));	
			}else if(n==2){
				ans = (isFound(i,0) || isFound(i,1));	
			}else{
				ans = (isFound(i,0));
			}
			
			if(!ans){break;}
		}else if(i<100){
			int bil1 = i%10;
			int bil2 = (i/10)%10;
			ans = false;
			if(n==3){
				ans = ans || (isFound(bil1,0) && isFound(bil2,1));
				ans = ans || (isFound(bil1,1) && isFound(bil2,0));
				ans = ans || (isFound(bil1,0) && isFound(bil2,2));
				ans = ans || (isFound(bil1,2) && isFound(bil2,0));
				ans = ans || (isFound(bil1,1) && isFound(bil2,2));
				ans = ans || (isFound(bil1,2) && isFound(bil2,1));	
			}else{
				ans = ans || (isFound(bil1,0) && isFound(bil2,1));
				ans = ans || (isFound(bil1,1) && isFound(bil2,0));
			}
			
			if(!ans){break;}
		}else{
			int bil1 = i%10;
			int bil2 = (i/10)%10;
			int bil3 = (i/100)%10;
			ans = false;
			ans |= isFound(bil1,0) && isFound(bil2,1) && isFound(bil3,2);
			ans |= isFound(bil1,0) && isFound(bil2,2) && isFound(bil3,1);
			ans |= isFound(bil1,1) && isFound(bil2,0) && isFound(bil3,2);
			ans |= isFound(bil1,1) && isFound(bil2,2) && isFound(bil3,0);
			ans |= isFound(bil1,2) && isFound(bil2,0) && isFound(bil3,1);
			ans |= isFound(bil1,2) && isFound(bil2,1) && isFound(bil3,0);
			if(!ans){break;}
		}
	}
	printf("%d\n",i-1);
	return 0;
};