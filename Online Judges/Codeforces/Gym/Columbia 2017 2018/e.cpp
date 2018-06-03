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

const int maxn = 1e5 + 5;
string text, pattern, kata;
int b[maxn], n,m;

void kmpPreprocess() {
	int i = 0, j = -1; b[0] = -1;
	while(i<m) {
		while(j >= 0 && pattern[i]!=pattern[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

int kmpSearch() {
	int i = 0, j = 0;
	int cnt = 0;
	while(i<n) {
		while(j >= 0 && text[i]!=pattern[j]) j = b[j];
		i++; j++;
		if(j == m) {
			// printf("pattern found in index %d\n",i-j);
			cnt++;
			j = b[j];
		}
	}
	return cnt;
}

int main(){
	
	getline(cin, text);
	getline(cin, kata);
	int minOccurence;
	scanf("%d",&minOccurence);
	n = text.length();
	m = kata.length();
	int kiri = 1, kanan = kata.length(), mid;
	int ans = -1;
	// pattern = kata;

	// printf("text: "); cout<<text<<endl;
	// printf("pattern: "); cout<<pattern<<endl;
	// kmpPreprocess();
	// kmpSearch();
	// printf("halo\n");
	// printf("jawab: %d\n",jawab);
	while(kiri<=kanan) {
		mid = (kiri+kanan) / 2;
		//ambil sebanyak mid
		pattern = kata.substr(0,mid);
		m = mid;
		//kmp
		kmpPreprocess();
		int hasil = kmpSearch();
		
		// printf("mid: %d hasil: %d\n",mid, hasil);
		// printf("pattern: "); cout<<pattern<<endl;
		if(hasil>=minOccurence){
			ans = mid;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}

	}
	if(ans == -1){printf("IMPOSSIBLE\n");}
	else{cout<<kata.substr(0,ans)<<endl;}
	return 0;
}; 