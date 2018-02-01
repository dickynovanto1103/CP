#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a[110];
bool isVisited[110];

ii findPair(int n, int sum){
	int i;
	bool pertama = false, kedua = false;
	int idx1=-1, idx2=-1;
	int jumlah = 0;
	for(i=0;i<n;i++){
		if(!pertama){
			if(!isVisited[i]){
				jumlah = a[i];
				isVisited[i] = true;
				idx1 = i;
				pertama = true;
				//printf("pertama terpilih idx1: %d jumlah: %d\n",idx1,jumlah);
			}	
		}else{
			if(!isVisited[i] && (jumlah+a[i])==sum){
				jumlah+= a[i];
				isVisited[i] = true;
				idx2 = i;
				kedua = true;
				//printf("kedua terpilih idx2: %d jumlah: %d\n",idx2,jumlah);
			}
		}
		
	}
	if(!(pertama && kedua)){
		if(idx1!=-1){isVisited[idx1] = false;}
		if(idx2!=-1){isVisited[idx2] = false;}
		//printf("masuk sinikah\n");
		return ii(-1,-1);
	}
	/*printf("bla\n");
	printf("idx1: %d idx2: %d\n",idx1,idx2);*/
	return ii(idx1,idx2);
}

int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	
	vii hasil;
	while(true){
		int sum;
		
		bool foundSalah;
		for(i=1;i<n;i++){
			memset(isVisited,false,sizeof isVisited);
			sum = a[0];
			sum+=a[i];
			isVisited[0] = true; isVisited[i] = true;
			hasil.pb(ii(0,i));
			foundSalah = false;
			//printf("milih idx pertama: %d sum jd: %d\n",i,sum);
			while(true){
				if(hasil.size()==n/2){break;}
				ii temp = findPair(n,sum);
				//printf("%d %d\n",temp.first,temp.second);
				if(temp==ii(-1,-1)){foundSalah = true; break;}
				hasil.pb(ii(temp.first,temp.second));
				
			}
			//printf("i: %d masuk sini\n",i);
			if(!foundSalah){break;}
			else{hasil.clear();}
		}
		if(!foundSalah){break;}

	}
	//printf("jawaban:\n");
	for(i=0;i<n/2;i++){
		printf("%d %d\n",hasil[i].first+1,hasil[i].second+1);
	}
	

	return 0;
};