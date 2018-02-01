#include <bits/stdc++.h>

using namespace std;
typedef pair<string,int> si; // delete
typedef pair<si,char> sic;
int a[85][85];
int solve(string kata1,string kata2){
	int panjang1 = kata1.length(),panjang2 = kata2.length();
	int i,j;
	//buat base case
	for(i=0;i<=panjang1;i++){a[i][0] = i;}
	for(j=0;j<=panjang2;j++){a[0][j] = j;}
	for(i=1;i<=panjang1;i++){
		for(j=1;j<=panjang2;j++){
			if(kata1[i-1] == kata2[j-1]){a[i][j] = a[i-1][j-1];}
			else{
				a[i][j] = min(a[i-1][j],min(a[i][j-1],a[i-1][j-1])) + 1;
			}
		}
	}
	return a[panjang1][panjang2];
}

int main(){
	int i,j, test=0;
	int panjang1,panjang2;
	map<int,sic> mapper;
	map<int,si> mapper2;
	string kata1,kata2;
	bool isSIC[85], isSI[85];
	while(cin>>kata1){
		if(test==1){printf("\n");}
		cin>>kata2;
		panjang1 = kata1.length(); panjang2 = kata2.length();
		//proses
		printf("%d\n",solve(kata1,kata2));
		//liat table dp
		/*for(i=0;i<=kata1.length();i++){
			for(j=0;j<=kata2.length();j++){
				printf("%3d",a[i][j]);
			}
			printf("\n");
		}*/
		//trace back
		memset(isSI, false, sizeof isSI);
		memset(isSIC, false, sizeof isSIC);
		i = panjang1; j = panjang2;
		int idx, cnt=0;
		
		while((i || j)){
			if(a[i][j] == a[i-1][j-1]){i--; j--;}//sama..cukup mundur idxnya
			else{//ga sama
				cnt++;
				//printf("masuk ga sama\n");
				if(j>0 && a[i][j]==a[i][j-1]+1){
					isSIC[cnt] = true;
					mapper[cnt] = make_pair(si("Insert", i+1), kata2[j-1]);
					j--;
					//printf("masuk insert\n");
				}else if(i>0 && a[i][j] == a[i-1][j]+1){
					isSI[cnt] = true;
					mapper2[cnt] = si("Delete",i+1);
					i--;
					//printf("masuk delete\n");
				}else if(a[i][j] == a[i-1][j-1]+1){
					isSIC[cnt] = true;
					mapper[cnt] = make_pair(si("Replace", i), kata2[j-1]);
					i--;j--;
					//printf("masuk replace\n");
				}
			}
			//printf("i: %d j: %d\n",i);
		}
		int totalOperation = cnt;
		cnt = 0;
		for(i=1;i<=totalOperation;i++){
			string kata; int idx; char kar;
			int cekIdx = totalOperation-i+1;
			if(isSIC[cekIdx]){
				sic pair = mapper[cekIdx];
				kata = pair.first.first;
				idx = pair.first.second;
				kar = pair.second;
				if(kata=="Insert"){cnt++;}
			}else{
				si pair = mapper2[cekIdx];
				kata = pair.first; idx = pair.second;
				cnt--; // karena delete
			}
			string ans = "";
			printf("%d ",i); cout<<kata<<" "; printf("%d",idx+cnt); 
			if(kata!="Delete"){printf(",%c\n",kar);}
			else{printf("\n");}
		}
		mapper.clear(); mapper2.clear();
		test = 1;
	}
	return 0;
}