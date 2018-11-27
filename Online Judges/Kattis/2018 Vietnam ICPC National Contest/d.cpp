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

bool isLeapYear(int y){
	if(y%400 == 0){return true;}
	else{
		if(y%100 == 0){return false;}
		else{
			if(y%4==0){return true;}
			else{return false;}
		}
	}
}

int maksDay(int m, int y){
	if(m == 1){return 31;}
	else if(m == 2){
		if(isLeapYear(y)){
			return 29;	
		}else{
			return 28;
		}
		
	}
	else if(m == 3){return 31;}
	else if(m == 4){return 30;}
	else if(m == 5){return 31;}
	else if(m == 6){return 30;}
	else if(m == 7){return 31;}
	else if(m == 8){return 31;}
	else if(m == 9){return 30;}
	else if(m == 10){return 31;}
	else if(m == 11){return 30;}
	else {return 31;}
}

bool isValidDate(int d, int m, int y){
	if(y<2000){return false;}
	if(m <= 0 || m > 12){return false;}
	int maks = maksDay(m, y);
	if(d <=0 || d > maks){return false;}
	else{return true;}
	
	
}

int getDay(string tanggal){
	int a = 0;
	int i;
	for(i=0;i<2;i++){
		a *= 10;
		a += tanggal[i] - '0';
	}
	return a;
}

int getMonth(string tanggal){
	int a = 0;
	int i;
	for(i=2;i<4;i++){
		a*=10;
		a += tanggal[i] - '0';
	}
	return a;
}
int getYear(string tanggal){
	int a = 0;
	int i;
	for(i=4;i<8;i++){
		a*=10;
		a += tanggal[i] - '0';
	}
	return a;
}

bool isSmaller(string tanggal1, string tanggal2){
	int d1 = getDay(tanggal1);
	int d2 = getDay(tanggal2);
	int m1 = getMonth(tanggal1);
	int m2 = getMonth(tanggal2);
	int y1 = getYear(tanggal1);
	int y2 = getYear(tanggal2);

	if(y1 > y2){return false;}
	else if(y1 < y2){return true;}
	else{
		if(m1 > m2){return false;}
		else if(m1 < m2){return true;}
		else{
			if(d1 > d2){return false;}
			else if(d1 < d2){return true;}
			else{return false;}
		}
	}
}

int main(){
	int tc,i,j;
	string d, m,y;
	scanf("%d",&tc);
	
	while(tc--){
		string minTanggal = "99999999";
		int cnt = 0;
		cin>>d>>m>>y;
		string tanggal = d + m + y;
		sort(tanggal.begin(), tanggal.end());
		do{
			// cout<<tanggal<<endl;
			int dd = getDay(tanggal);
			int mm = getMonth(tanggal);
			int yy = getYear(tanggal);
			// printf("dd: %d mm: %d yy: %d\n",dd, mm, yy);
			if(isValidDate(dd, mm, yy)){
				
				if(isSmaller(tanggal, minTanggal)){
					// printf("halo tanggal: "); cout<<tanggal<<endl;
					minTanggal = tanggal;	
				}
				cnt++;
			}
		}while(next_permutation(tanggal.begin(), tanggal.end()));
		if(cnt == 0){printf("%d\n",cnt); continue;}
		printf("%d %c%c %c%c %c%c%c%c\n",cnt, minTanggal[0], minTanggal[1], minTanggal[2], minTanggal[3], minTanggal[4], minTanggal[5], minTanggal[6], minTanggal[7]);
	}
	return 0;
};