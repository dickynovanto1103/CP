#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<string> arr[110][110];

void lcs(string kata1[], string kata2[], int m, int n){
	int i,j,k;
	int maks = max(m,n);
	int a[110][110];
	string ans[110];
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0 || j==0){a[i][j]=0;}
			else if(kata1[i-1]==kata2[j-1]){
				a[i][j] = a[i-1][j-1] + 1;
			}
			else {
				a[i][j] = max(a[i-1][j], a[i][j-1]);
			}
		}
	}
	int idx = a[m][n];
	i=m; j=n;
	while(i>0 && j>0){
		if(kata1[i-1]==kata2[j-1]){
			ans[idx-1] = kata1[i-1];
			idx--; i--; j--;
		}else{
			if(a[i-1][j] > a[i][j-1]){i--;}
			else{j--;}

		}
	}
	for(i=0;i<a[m][n];i++){
		if(i==0){cout<<ans[i];}
		else{printf(" ");cout<<ans[i];}
	}
	printf("\n");
}

int main(){
	//ios_base::sync_with_stdio(false);
	string kata1[110],kata2[110], temp;
	int cnt2;
	int m,n,tc,i, cnt1=cnt2=0;
	int countpagar = 0;
	while(cin>>temp){
		//printf("yang dibaca: "); cout<<temp<<endl;
		if(temp=="#"){

			countpagar++;
			//printf("countpagar sekarang: %d\n",countpagar);
			if(countpagar==2){
				countpagar=0; 
				//process lcs
				lcs(kata1,kata2,cnt1,cnt2);
				//printf("banyak: %d\n",banyak);
				cnt1 = cnt2 = 0;
			}
		}else{
			if(countpagar%2==0){kata1[cnt1] = temp; cnt1++;}
			else{kata2[cnt2] = temp; cnt2++;}	
		}
		
	}
	
	return 0;
}