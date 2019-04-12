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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;
int main(){
	int n,i,j;
	scanf("%d",&n);

	char a[maxn], b[maxn];

	scanf("%s",a);
	int ca = 0, cb=0, cc = 0;
	int cnt[3];
	memset(cnt, 0, sizeof cnt);
	for(i=0;i<n;i++){
		if(a[i] == 'A'){cnt[0]++; ca++;}
		else if(a[i] == 'B'){cnt[1]++; cb++;}
		else{cnt[2]++; cc++;}
	}
	int maks;

	if(ca >= cb && ca >= cc){maks=0;}
	else if(cb >= ca && cb >= cc){maks = 1;}
	else{maks = 2;}

	int kiri = 0, kanan = cnt[maks] - 1;
	int minim = inf;
	int ans = 0;

	for(i=0;i<cnt[maks];i++){
		b[i] = maks + 'A';
		if(a[i] != b[i]){ans++;}
	}
	int idxKiri = 0;
	minim = ans;
	do{
		if(a[kiri] != maks + 'A'){ans--;}
		kiri++; kiri %= n;
		kanan++; kanan %= n;
		if(a[kanan] != maks + 'A'){ans++;}	
		if(minim > ans){
			minim = ans;
			idxKiri = kiri;
		}
		// printf("kiri: %d kanan: %d ans: %d char: %c\n",kiri, kanan, ans, maks + 'A');
	}while(kiri !=0 && kanan != cnt[maks] - 1);
	// printf("idxKiri: %d\n",idxKiri);
	//place maks + 1 then maks + 2
	int idx = idxKiri;
	int cnt1 = cnt[maks], cnt2 = cnt[(maks+1) % 3], cnt3 = cnt[(maks+2) % 3];
	for(i=idxKiri;;i = (i+1) % n){
		if(!cnt1 && !cnt2 && !cnt3){break;}
		if(cnt1){b[i] = maks + 'A'; cnt1--; continue;}
		if(cnt2){b[i] = ((maks+1) % 3) + 'A'; cnt2--; continue;}
		if(cnt3){b[i] = ((maks+2) % 3) + 'A'; cnt3--;}

	}
	printf("b: %s\n",b);
	int ans1 = 0;
	for(i=0;i<n;i++){
		if(a[i] != b[i]){ans1++;}
	}

	cnt1 = cnt[maks], cnt2 = cnt[(maks+2)%3], cnt3 = cnt[(maks+1)%3];
	for(i=idxKiri;;i = (i+1) % n){
		if(!cnt1 && !cnt2 && !cnt3){break;}
		if(cnt1){b[i] = maks + 'A'; cnt1--; continue;}
		if(cnt2){b[i] = ((maks+2) % 3) + 'A'; cnt2--; continue;}
		if(cnt3){b[i] = ((maks+1) % 3) + 'A'; cnt3--;}

	}
	printf("b: %s\n",b);
	int ans2 = 0;
	for(i=0;i<n;i++){
		if(a[i] != b[i]){ans2++;}
	}
	printf("%d\n",min(ans1,ans2));

	return 0;
};