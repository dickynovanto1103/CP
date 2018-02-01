#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	ll x,y,l,r,i,j;
	vector<ll> listbil;
	scanf("%I64d %I64d %I64d %I64d",&x,&y,&l,&r);
	map<ll,int> mapper;
	int cnt=0;
	for(i=0;i<=59;i++){
		ll sum = 1;
		int tempi = i;
		while(sum<=1e18/x && tempi>0){
			tempi--;
			sum*=x;
		}
		//dpt sum
		for(j=0;j<=60;j++){
			int tempj = j;
			ll sumj = 1;
			while(sumj<=(1e18-sum)/y && tempj>0){
				tempj--;
				sumj*=y;
				//if(sumj+sum>1e18){break;}
				//sum+=sumj;
			}
			//if(sumj+sum>1e18){break;}
			ll total = sum+sumj;
			//if(mapper.find(total)==mapper.end()){mapper[total] = cnt++;}
			//else{break;}
			//printf("i: %d j: %d\n",i,j);

			listbil.push_back(total);
		}
	}
	sort(listbil.begin(),listbil.end());
	int ukuran = listbil.size();
	
	//start computing
	cnt=0;
	vector<ll> candidate;
	for(i=0;i<ukuran;i++){
		if(listbil[i]>=l && listbil[i]<=r){candidate.push_back(listbil[i]);
			
		}		
	}

	ukuran = candidate.size();
	ll jarak = 0;
	if(ukuran==0){jarak = r-l+1;}
	else if(ukuran>0){
		jarak = max(jarak,candidate[0]-l); jarak = max(jarak,r - candidate[ukuran-1]);
		for(i=1;i<ukuran-1;i++){
			ll a = candidate[i-1], b = candidate[i], c = candidate[i+1];
			jarak = max(jarak,max(b-a-1,c-b-1));
		}	
	}
	
	
	printf("%I64d\n",jarak);
	return 0;
}