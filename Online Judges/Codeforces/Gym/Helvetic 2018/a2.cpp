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

const int maxN = 2e3 + 1;
const int maxM = 200 + 1;

int baris, kolom;
bool isValid;

char text[maxM][maxN], pattern[maxN][maxM];
int b[maxN][maxM], n,m;

void kmpPreprocess() {
	for(int k=0;k<n;k++){
		int i = 0, j = -1; b[k][0] = -1;
		while(i<m) {
			while(j >= 0 && pattern[k][i]!=pattern[k][j]) j = b[k][j];
			i++; j++;
			b[k][i] = j;
		}	
	}
}

void kmpSearch(int idx) {
	set<int> s, temp;

	for(int k=0;k<m;k++){
		int i = 0, j = 0;

		while(i<n) {
			while(j >= 0 && text[k][i]!=pattern[idx+k][j]) j = b[idx+k][j];
			i++; j++;
			if(j == m) {
				// printf("pattern found in index %d\n",i-j);
				int bil = i-j + 1;
				if(k>0){
					if(s.count(bil)){temp.insert(bil);}
				}else{
					s.insert(bil);
				}
				j = b[idx+k][j];
			}
		}
		if(k>0){
			s = temp;
			if(s.empty()){
				isValid = false;
				return;
			}
		}
		
	}
	if(!s.empty()){
		baris = idx+1;
		kolom = *(s.begin());
	}
	
}

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",pattern[i]);
		// cin>>pattern[i];
		// printf("P[%d]: %s\n",i,P[i]);
	}
	for(i=0;i<m;i++){
		scanf("%s",text[i]);
		// cin>>text[i];
		// printf("T[%d]: %s\n",i,T[i]);
	}

	kmpPreprocess();
	for(i=0;i<=(n-m);i++){
		isValid = true;
		kmpSearch(i);
	}

	printf("%d %d\n",baris,kolom);
	return 0;
};