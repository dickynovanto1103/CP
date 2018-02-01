#include <bits/stdc++.h>

using namespace std;

int row[8],a[10][10],ans;

bool place(int r, int c){
	int prev;
	for(prev=0;prev<c;prev++){
		if(row[prev]==r || abs(row[prev]-r)==abs(prev-c)){return false;}
	}
	return true;
}

void backtrack(int c){
	int sum,r,j;
	if(c==8){
		sum=0;
		for(j=0;j<8;j++){sum+=a[row[j]][j];}
		ans=max(ans,sum);
	}else{
		
		for(r=0;r<8;r++){
			if(place(r,c)){
				row[c]=r;
				backtrack(c+1);
			}
		}
	}
}

int jumlahdigit(int n){
	int cnt=0;
	while(n>0){
		n/=10; cnt++;
	}
	return cnt;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	while(n--){
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				scanf("%d",&a[i][j]);
			}
		}
		ans=-1;
		backtrack(0);
		for(i=1;i<=5-jumlahdigit(ans);i++){printf(" ");}
		printf("%d\n",ans);
	}
	return 0;
}