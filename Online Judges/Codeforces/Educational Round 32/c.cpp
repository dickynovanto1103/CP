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

int counter[256];

int main(){
	int n,i,j;
	//printf("%d %d\n",'a','z');
	string kata;
	cin>>kata;
	n = kata.length();
	int kiri = 1, kanan = n, mid, ans;
	while(kiri<=kanan){
		mid = (kiri+kanan)/2;
		//printf("mid: %d\n",mid);
		
		for(i=97;i<=122;i++){
			counter[i]=0;
		}
		i=0; j=i+mid;
		//printf("j: %d\n",j);
		for(i=0;i<j;i++){
			counter[kata[i]]++;
			//printf("inserted: %c\n",kata[i]);
		}
		//printf("jumlah a: %d\n",(int)s.count('a'));
		bool foundValid = false;
		i=0; j--;
		while((j+1)<n){
			//printf("i: %d j: %d\n",i,j);
			
			j++;
			char kar2 = kata[j];//yang berpotensi diinsert kalo countnya ga nol
			// printf("kar2: %c\n",kar2);
			// printf("jumlah kar2: %d\n",(int)s.count(kar2));

			if(counter[kar2]!=0){
				
				counter[kar2]++;
				
				//printf("kar2: %c counter jd: %d\n",kar2, counter[kar2]);
			}

			char kar1 = kata[i];
			//printf("kar1: %c\n",kar1);
			int jumlahKar1 = counter[kar1];

			if(jumlahKar1!=0){

				counter[kar1]--;
				//printf("kar1: %c counter jd: %d\n",kar1, counter[kar1]);
			}
			// for(int cnt=0;cnt<jumlahKar1-1;cnt++){
			// 	s.insert(kar1);
			// }
			i++;
			
		}
		for(i=97;i<=122;i++){
			if(counter[i]>0){foundValid = true; break;}
		}
		
		if(foundValid){
			//printf("valid\n");
			ans = mid;
			kanan = mid-1;
		}else{
			//printf("ga valid\n");
			kiri = mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
};