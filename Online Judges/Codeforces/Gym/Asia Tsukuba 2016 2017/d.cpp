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

int freq1[26], freq2[26];
bool isSamaFreq() {
	int i;
	for(i=0;i<26;i++) {
		if(freq1[i] != freq2[i]){return false;}
	}
	return true;
}

int main(){
	string kata1,kata2;
	
	cin>>kata1>>kata2;
	cout << kata1<<" "<<kata2<<endl;
	int pjg1 = kata1.length(), pjg2 = kata2.length();
	int minim = min(pjg1,pjg2);
	int kiri = 0, kanan = minim, mid, ans = 0;
	int i,j;

	
	bool isSama;
	for(mid = 1; mid <= minim; mid++) {
		
		//ambil substring di string 1
		// printf("mid: %d\n",mid);
		string temp1 = "", temp2="";
		temp1 = kata1.substr(0,mid);
		temp2 = kata2.substr(0,mid);
		
		for(i=0;i<pjg1; i++) {
			memset(freq1, 0, sizeof freq1); memset(freq2, 0, sizeof freq2);
			for(j=0;j<mid;j++) {
				char kar1 = temp1[j]-'a';
				char kar2 = temp2[j]-'a';
				freq1[kar1]++; freq2[kar2]++;
			}
			//catet semua frequensi kata2 dengan panjang mid
			
			isSama = isSamaFreq();
			if(isSama) {
				ans = mid; kiri = mid+1;
				// printf("ketemu sama pertama yaitu ans: %d kiri jadi: %d kanan: %d\n",ans,kiri,kanan);
				break;
			}
			else{
				int idxAwal = 0;
				for(j=mid;j<pjg2;j++) {
					int idxAkhir = j;
					char karAwal = kata2[idxAwal]-'a', karAkhir = kata2[idxAkhir]-'a';
					freq2[karAwal]--; 
					freq2[karAkhir]++;
					isSama = isSamaFreq();
					idxAwal++;
					if(isSama) {
						break;
					}
				}
				if(isSama){break;}
			}	
		}
		if(isSama) {
			kiri = mid+1; ans = mid;
			// printf("ketemu sama pertama yaitu ans: %d kiri jadi: %d kanan: %d\n",ans,kiri,kanan);
		}
		else{

			kanan = mid-1;
			// printf("ga ketemu kanan jadi: %d\n",kanan);
		}

	}
	printf("%d\n",ans);
	return 0;
};