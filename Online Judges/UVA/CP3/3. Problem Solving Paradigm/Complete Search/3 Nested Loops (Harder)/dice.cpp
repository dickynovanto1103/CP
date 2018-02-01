#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,i,j,k;
	string a,b;
	scanf("%d",&tc);
	//cin>>ws;
	int awal[6][6] = {{1,2,3,4,5,6},{2,1,6,5,4,3},{3,5,1,6,2,4}, {4,6,1,3,2,5}, {5,3,1,4,2,6}, {6,4,1,5,2,3}};
	/*awal[0]=std::initializer_list<int>();
	awal[1]=;
	awal[2]=;
	awal[3]=;
	awal[4]=;
	awal[5]=;*/
	int idx[4][4] = {{2,3,4,5},{3,4,5,2},{4,5,2,3},{5,2,3,4}};
	/*idx[0] = ;
	idx[1] = ;
	idx[2] = ;
	idx[3] = ;*/

	/*for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			if(j>0){printf(" ");}
			printf("%d",awal[i][j]);
		}
		printf("\n");
	}*/
	cin>>ws;
	while(tc--){
		bool found = false;
		cin>>a>>b;
		for(i=0;i<6;i++){
			string kata = "";
			kata+=a[awal[i][0]-1]; kata+=a[awal[i][1]-1];
			for(j=0;j<4;j++){
				string temp = kata;
				for(k=0;k<4;k++){
					int index = idx[j][k];
					//char kar = a[awal[i][index]-1];
					//printf("ditambah kar: %c\n",kar);
					temp+=a[awal[i][index]-1];
				}
				//printf("temp: "); cout<<temp<<endl;
				if(temp==b){printf("Equal\n"); found=true; break;}
			}
			if(found){break;}
		}
		if(!found){printf("Not Equal\n");}
	}
	return 0;
}