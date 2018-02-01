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

int main() {
	int k,i,j,n;
	string kata;
	scanf("%d",&k);
	getline(cin>>ws,kata);
	//cout<<kata<<endl;
	n = kata.length();
	vi ans;
	int pjg = 0;
	for(i=0;i<n;i++){
		pjg++;
		if(kata[i]==' ' || kata[i]=='-'){ans.pb(pjg); pjg = 0;}
	}
	ans.pb(pjg);
	/*for(i=0;i<ans.size();i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");*/
	int ukuran = ans.size();
	
	//if(ukuran==1 && ans[0]==0){printf("0\n"); return 0;}
	int minim = inf, maks = -inf;
	for(i=0;i<ukuran;i++){minim = min(minim,ans[i]); maks = max(maks,ans[i]);}

	int jawab;
	int kiri = maks, kanan = n, mid;
	while(kiri<=kanan){
		mid = (kiri+kanan)/2;
		//printf("kiri: %d kanan: %d mid: %d\n",kiri,kanan,mid);
		//simulasi
		int cntBaris = 1;
		pjg = 0;
		for(i=0;i<ukuran;i++){
			if(pjg+ans[i]>mid){
				cntBaris++; pjg = ans[i];
			 //printf("cntBaris jd: %d pjg skrg: %d\n",cntBaris,pjg);
			}else{
				pjg+=ans[i];
				//printf("pjg jd: %d\n",pjg);
			}
		}
		if(cntBaris<=k){jawab = mid; kanan = mid-1;}
		else{kiri = mid+1;}
	}
	printf("%d\n",jawab);
	return 0;
}