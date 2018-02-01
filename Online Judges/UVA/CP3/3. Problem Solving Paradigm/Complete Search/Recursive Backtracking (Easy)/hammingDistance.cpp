#include <bits/stdc++.h>

using namespace std;
int n,h;
int catat[17];
bool pernah[17];
vector<string> listkata;
void solve(int kedalaman, int lastdigit){
	int i;
	if(kedalaman==h){
		string kata="";
		for(i=0;i<n;i++){kata+='0';}
		for(i=0;i<kedalaman;i++){
			//if(i>0){printf(" ");}

			int idx = catat[i];
			//printf("%d",idx);
			kata[idx] = '1';
		}
		//printf("\n");
		//cout<<kata<<endl;
		listkata.push_back(kata);
	}else{
		for(i=lastdigit+1;i<n;i++){
			if(!pernah[i]){
				pernah[i] = true;
				catat[kedalaman] = i;
				solve(kedalaman+1,i);
				pernah[i] = false;
			}
		}
	}
}

int main(){
	int tc,i,test=1;
	scanf("%d",&tc);
	while(tc--){
		if(test==2){printf("\n");}
		scanf("%d %d",&n,&h);
		memset(pernah,false,sizeof pernah);
		solve(0,-1);
		int ukuran = listkata.size();
		for(i=ukuran-1;i>=0;i--){
			cout<<listkata[i]<<endl;
		}
		test=2;
		listkata.clear();
	}
	return 0;
}