#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int tc,linecounter,a,b,row[9];

bool place(int r,int c){
	int prev;
	for(prev=0;prev<c;prev++){
		if(row[prev]==r || abs(prev-c)==abs(row[prev]-r)){return false;}
	}
	return true;
}

void backtrack(int c){
	int r;
	if(c==8 && row[b]==a){
		printf("%2d      %d",++linecounter, row[0]+1);
		for(r=1;r<8;r++) printf(" %d",row[r]+1);
		printf("\n");
	}
	for(r=0;r<8;r++){
		if(place(r,c)){
			row[c]=r;backtrack(c+1);
		}
	}
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&a,&b); a--;b--;
		memset(row,0,sizeof row);
		linecounter=0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0);
		if(tc) printf("\n");
	}
	return 0;
}