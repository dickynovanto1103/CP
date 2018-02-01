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

const int kiri = 1;
const int kanan = 0;

int main() {
	int n,i,m;
	scanf("%d %d",&n,&m);
	stack<int> s;
	
	vector<ii> P;
	for(i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		P.pb(ii(a,kiri)); P.pb(ii(b,kanan));
	}
	sort(P.begin(), P.end());
	int ans = 0;
	int batas = 1;
	for(i=0;i<P.size();i++){
		ii front = P[i];
		int waktu = front.first;
		
		//if(waktu>m){batas = waktu; break;}//sudah melewati batas waktu nonton
		if(s.empty()){//dijamin kiri klo misal lg kosong
			ans+=(min(waktu,m)-batas);
			//printf("waktu: %d-batas: %d ans jd: %d\n",waktu,batas,ans);
		}
		if(front.second==kiri){
			s.push(waktu); 
			//printf("pushed: waktu: %d id: %d\n",waktu,front.second); printf("ukuran stack: %d\n",s.size());
		}
		else{
			s.pop();
			/*printf("waktu %d terpop\n",waktu);
			printf("ukuran stack jd: %d\n",s.size());*/
			if(s.empty()){
				batas = min(waktu,m);
				//printf("jadi kosong\n");
			}
		}
		//batas = waktu;
		//printf("batas jd: %d\n\n",batas);
	}
	//printf("batas: %lld\n",batas);
	if(P[P.size()-1].first<=m){ans+=(m-batas);}
	printf("%lld\n",ans);
	return 0;
}

