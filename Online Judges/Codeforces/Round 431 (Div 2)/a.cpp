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

int main() {
	int n,a[101],i,j;
	scanf("%d",&n);
	vi ganjil;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]%2==1){ganjil.pb(i);}
	}
	
	int ukuran = ganjil.size();
	if(ganjil[0]!=0){printf("No\n"); return 0;}
	if(ganjil[ukuran-1]!=n-1){printf("No\n"); return 0;}
	int awal, akhir;
	bool found = true;
	for(i=0;i<ukuran;i++){
		found = false;
		awal = 1; akhir = ganjil[i];
		int idx = i;
		while(true){
			if((akhir-awal+1)%2==0){break;}
			awal = (akhir+1==n)?n-1 : akhir+1;
			idx++;
			
		}
		if(found){break;}//sudah ketemu klo bisa
	}
	if(found){printf("Yes\n");}
	else{printf("No\n");}
	return 0;
}