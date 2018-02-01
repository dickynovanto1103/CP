#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int listSum[1000010];

int main() {
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		string kata;
		cin>>kata;
		//catat semua indeks kurung buka
		int n = kata.length();
		vi listIdx;
		int sum = 0;
		for(i=0;i<n;i++){
			if(kata[i]=='('){listIdx.pb(i); sum+=1;}
			else{sum-=1;}
			listSum[i] = sum;
		}
		int ukuran = listIdx.size();
		bool found = false;
		int start;
		for(i=ukuran-1;i>=0;i--){
			int idx = listIdx[i];
			if(listSum[idx]>=2){found = true; start = idx; break;}//start here
		}
		if(!found){printf("TIDAK ADA\n");}
		else{
			sum = listSum[start];
			kata[start] = ')';
			sum-=1;
			for(i=start+1;i<n;i++){
				if(sum+1<=n-i){kata[i] = '('; sum++;}//bisa ditutup nanti
				else{kata[i] = ')'; sum--;}
			}
			cout<<kata<<endl;
		}

	}
	return 0;
}