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

int main(){
	int pembilang, penyebut;
	int halo[] = {1,2,2,3,2,5,2,4,3,5,2,8,2,5,5,5,2,8,2,8,5,5,2,11,3,5,4,8,2,14,2,6,5,5,5,13,2,5,5,11,2,14,2,8,8,5,2,14,3,8,5,8,2,11,5,11,5,5,2,23,2,5,8,7,5,14,2,8,5,14,2,18,2,5,8,8,5,14,2,14,5,5,2,23,5,5,5,11,2,23,5,8,5,5,5,17,2,8,8,13,2,14,2,11,14,5,2,18,2,14,5,14,2,14,5,8,8,5,5,32,3,5,5,8,4,23,2,8,5,14,2,23,5,5,11,11,2,14,2,23,5,5,5,23,5,5,8,8,2,23,2,11,8,14,5,23,2,5,5,17,5,14,2,8,14,5,2,32,3,14,8,8,2,14,8,14,5,5,2,38,2,14,5,11,5,14,5,8,11,14,2,20,2,5,14,13,2,23,2,18,5,5,5,23,5,5,8,14,5,41,2,8,5,5,5,25,5,5,5,23,5,14,2,17,13,5,2,23,2,14,14,11,2,23,5,8,5,14,2,41,2,8,6,8,8,14,5,11,5,11,2,38,5,5,14,9,2,14,5,23,8,5,2,32,5,14,5,8,2,32,2,14,14,5,8,23,2,5,8,32,2,14,2,8,14,14,5,28,3,14,5,8,2,23,5,11,11,5,5,38,5,5,5,14,5,23,2,23,5,14,2,32,2,5,23,8,2,14,5,20,5,14,5,23,8,5,5,11,5,41,2,8,8,5,5,41,2,8,5,23,5,23,4,11,14,5,2,23,2,23,11,17,2,14,5,8,14,5,2,53,3,5,8,23,5,14,2,14,8,14,5,23,2,14,11,11,5,32,2,23,5,5,2,23,14,5,8,8,2,41,5,18,5,5,5,38,2,5,14,23,2,14,5,8,14,14,5,32,2,14,5,8,5,23,5,17,5,14,2,68,2,5,8,11,8,14,5,8,14,14,2,32,2,14,14,8,5,14,2,32,13,14,2,23,5,5,5,20,2,38,5,8,5,5,14,32,2,5,11,23,2,41,2,14,14,5,2,38,5,14,5,11,5,14,8,23,8,5,2,50,5,5,14,13,5,17,2,11,5,23,2,23,5,14,23,14,5,14,2,18,5,5,2,53,5,14,8,8,2,41,5,10,11,5,5,23,5,14,5,32,2,23,2,8,23,5,5,41,3,14,8,23,5,14,5,11,5,5,8,53,2,5,5,17,5,41,2,8,8,23,5,32,5,5,14,8,2,23,5,41,14,5,2,23,5,5,14,11,2,41,2,23,5,14,8,33,2,8,5,23,5,14,5,11,23,5,2,38,5,14,5,14,2,32,14,8,5,14,2,53,2,14,8,8,8,14,2,17,14,14,5,38,2,5,14,32,2,14,2,23,11,5,5,41,5,5,14,8,5,68,2,11,5,5,5,23,8,14,8,23,2,14,2,23,14,14,2,32,5,23,14,8,2,14,5,14,8,14,2,68,2,5,14,11,14,23,5,8,5,14,5,50,2,5,18,13,2,14,5,32,5,14,2,38,5,11,5,14,5,41,2,8,23,5,5,32,5,5,5,38,2,32,5,20,14,5,5,23,2,14,8,11,5,41,14,8,5,5,2,68,5,8,5,8,8,23,2,32,7,14,5,23,2,5,23,17,5,23,2,23,14,14,2,32,5,5,8,23,5,32,2,14,5,14,5,53,2,5,14,32,2,14,5,8,23,5,5,26,2,41,5,8,2,23,8,11,14,5,5,68,5,14,11,23,5,14,2,8,5,14,5,53,5,5,14,8,2,41,5,28,8,5,5,23,14,14,5,11,2,41,2,23,5,14,5,41,5,5,23,23,2,14,2,11,23,14,2,38,2,14,5,20,8,14,5,23,11,5,2,95,3,5,5,8,8,23,8,14,5,23,5,23,2,14,23,11,2,41,2,23,14,5,2,39,5,5,8,23,5,41,5,11,8,14,11,23,2,5,5,41,2,38,2,23,14,5,2,32,5,14,14,8,5,14,5,23,14,5,5,63,5,14,14,11,5,14,2,8,8,41,2,41,5,5,14,8,5,32,2,32,5,5,5,68,8,5,8,17,2,41,8,8,5,5,14,53,2,14,5,23,2,14,5,14,32,14,2,23,5,23,5,32,2,23,5,8,14,5,5,59,3,14,8,8,5,41,2,18,14,14,2,28,5,5,23,14,2,14,5,38,8,5,2,32,5,14,14,23,5,68,2,17,5,14,5,23,2,5,11,25,14,14,5,8,14,5,5,68,2,14,5,23,2,23,14,11,8,5,2,68,2,14,14,11,8,32,5,8,11,14,2,32,2,14,23,23,5,14,2,41,5,5,5,38,14,5,5,11,2,68,2,8,14,14,5,50,5,8,5,23,2,23,2,32,14,14,5,23,2,14,23,14,5,14,8,8,5,23,5,74,5,5,8,8,14,14,2,20,13,14,2,68,2,5,14,11,2,23,5,38,5,14,2,41,14,14,11,8,2,41,5,11,14,5,5,38,2,14,5,50,5,41,2,8,18,5,8,32,2,14,14,8,5,41,5,14,5,5,5,68,5,5,8,32,5,14,5,23,5,23,2,38,2,5,41,13,5,14,5,32,11,14,2,23,5,14,5,14,5,68,2,8,14,5,8,53,5,14,8,23,2,14,8,17,14,5,2,53,5,41,5,11,2,14,5,23,23,5,5,68,2,5,5,23,5,23,5,11,14,23,5,23,2,5,17,20,2,41,5,23,14,14,2,53,13,5,5,8,2,41,2,41,8,5,14,23,2,5,14,32,5,32,5,8,14,14,5,50,2,14,8,8,5,41,5,11,5,14,2,113,5,5,5,14,14,14,5,8,11,14,5,32,5,23,23,23,2,23,2,26,14,5,2,23,5,5,23,32,2,41,2,23,5,5,14,41,2,14,5,38,2,41,2,11,23,5,2,23,14,14,14,17,5,23,5,23,5,5,2,95,2,5,18,8,8,41,2,14,5,41,4,38,5,14,14,11,5,14,5,23,8,14,5,59,5,5,5,8,5,53,5,18,14,5,5,23,5,14,8,41,2,14,5,23,41,5,2,53,3,14,5,18,2,14,11,17,14,14,5,68,2,5,5,11,5,68,5,8,5,14,5,41,5,14,23,8,5,14,2,53,5,5,5,53,5,14,14,23,2,41,5,8,8,14,5,32,5,5,14,23,8,23,2,14,23,14,2,68,2,41,11,11,2,14,14,8,5,5,2,83,5,14,14,13,8,14,2,11,23,23,2,38,2,5,14,41,5,20,2,23,5,14,14,32,5,5,8,8,5,68,2,20,5,14,8,38,5,5,14,32,2,41,2,23,32,5,2,41,2,14,14,8,2,23,14,32,5,14,2,53,5,5,8,17,14,14,5,23,5,14,2,74,5,5,14,8,5,41,8,41,13,5,2,23,8,14,5,11,5,68,2,8,14,14,5,29,5,5,14,68,5,14,2,11,14,5,14,38,2,23,14,14,2,41,5,8,8,14,2,95,5,14,5,23,5,32,2,28,5,14,2,23,8,5,38,11,5,14,2,23,14,14,2,68,5,14,8,8,5,41,5,11,11,5,14,68,2,14,14,33,2,23,5,8,14,14,2,32,2,41,8,23,2,14,14,14,23,5,2,68,2,5,5,32,11,14,2,23,8,14,5,50,5,14,14,8,2,68,5,32,5,5,5,23,14,5,11,14,5,68,5,23,14,5,5,53,2,5,14,23,5,14,2,23,23,23,2,23,2,14,5,32,5,32,8,8,14,5,5,122,3,8,23,8,5,14,5,11,5,23,5,38,2,23,14,17,2,14,2,38,17,14,5,32,14,5,5,23,2,68,5,14,5,5,11,68,5,5,8,32,2,41,2,8,23,5,5,46,14,14,5,8,2,23,5,32,8,14,5,68,2,14,14,14,5,23,2,23,14,32,5,32,2,5,32,8,5,14,2,50,5,5,5,63,5,5,14,32,5,41,14,8,8,5,8,41,2,14,5,23,5,41,2,11,41,14,2,23,2,14,8,26,5,41,5,8,5,14,5,88,2,14,5,23,8,41,5,14,11,14,2,23,8,5,23,11,5,23,5,68,5,5,2,50,8,14,23,8,5,41,2,11,14,14,5,53,5,5,5,41,5,14,5,8,23,14,2,95,3,23,5,8,5,23,14,20,5,5,8,68,2,23,14,11,5,14,2,8,14,41,2,68,2,5,14,23,2,14,2,32,23,5,5,23,14,14,14,17,2,95,5,23,5,5,5,32,5,14,8,38,2,14,5,41,14,5,2,38,5,14,23,11,2,41,5,8,11,14,5,68,5,8,5,23,23,23,5,11,5,14,2,68,2,5,23,23,5,41,5,23,5,5,5,39,5,14,14,8,2,68,2,17,23,5,14,23,5,14,5,53,5,23,5,8,14,5,5,41,5,14,11,23,2,41,8,32,5,14,2,113,5,5,5,20,5,14,2,23,23,14,5,32,2,5,41,8,2,32,2,32,14,41,2,23,5,14,8,11,8,41,2,8,14,14,14,83,2,5,5,23,5,14,8,32,23,5,2,38,2,41,5,14,5,23,14,8,14,5,2,95,5,5,8,23,5,41,5,12,5,23,5,53,2,14,14,11,8,32,5,23,8,5,2,41,14,5,14,23,2,68,5,32,5,14,8,23,5,5,32,50,2,14,2,8,14,14,2,53,2,41,14,8,14,14,5,14,8,5,2,113,5,5,5,11,5,41,8,23,14,14,2,59,2,14,23,13,5,14,5,32,14,5,5,38,11,5,5,41,2,41,2,23,11,14,14,32,2,5,14,23,2,68,2,17,41,14,5,23,5,23,8,11,2,14,5,38,5,14,5,95,2,14,14,8,5,23,5,11,8,41,5,23,5,5,23,23,5,38,2,23,5,5,5,95,14,5,8,8,5,41,5,14,14,5,5,38,4,14,5,53,5,14,2,23,38,5,2,50,3,41,14,23,2,32,5,11,5,5,5,68,2,14,23,14,8,41,5,8,5,14,5,53,14,5,14,23,2,14,2,59,11,14,2,68,5,5,14,11,5,53,2,8,5,23,14,41,5,5,8,23,14,41,5,11,14,14,2,68,2,14,5,17,2,14,23,8,23,14,5,95,2,14,5,8,5,23,2,41,14,14,5,23,2,14,32,32,2,14,8,38,14,5,8,43,5,5,5,8,2,122,2,18,8,14,5,23,5,14,5,41,5,32,5,23,23,5,5,32,5,14,23,23,2,14,5,17,14,14,2,113,2,5,14,11,14,41,2,8,14,23,2,68,5,14,14,23,2,23,5,32,5,5,5,23,14,23,8,20,5,41,2,8,14,5,11,74,2,14,14,68,2,14,2,14,23,5,14,23,2,14,5,32,2,68,5,8,14,14,2,83,5,5,11,8,14,14,5,32,14,14,2,38,5,14,41,14,2,41,5,38,8,14,2,32,8,5,5,8,5,50,14,23,5,5,5,68,2,14,8,32,2,41,5,23,14,5,2,68,5,38,14,8,5,14,5,11,32,5,2,68,5,5,5,50,14,23,2,8,5,41,5,32,2,5,38,8,2,41,5,41,5,14,5,53,14,14,5,11,5,41,5,23,8,14,5,59,5,5,23,23,5,23,2,11,14,14,5,68,5,14,14,14,5,14,5,23,5,5,5,158,2,14,8,8,8,14,8,17,8,41,2,23,5,14,23,11,5,32,2,23,23,14,2,41,5,14,8,38,2,68,2,32,14,5,14,38,2,5,5,29,5,41,5,8,32,5,5,32,5,14,5,8,5,68,8,41,5,5,2,68,5,5,23,32,14,14,5,8,5,41,2,50,2,5,14,23,8,14,5,53,13,5,5,68,5,5,14,14,2,68,5,8,14,5,5,32,2,41,11,23,2,41,5,20,32,14,5,38,5,14,5,32,2,14,14,8,8,5,14,122,5,5,5,8,8,53,2,11,5,23,5,68,5,5,23,17,2,14,2,68,5,11,2,53,14,14,14,23,5,41,2,14,17,14,8,23,2,14,14,32,5,23,2,23,14,14,2,68,2,14,23,8,2,14,23,11,14,14,2,88,5,14,14,23,5,41,2,8,23,14,2,32,2,14,14,23,14,23,2,50,5,5,5,23,8,14,11,32,2,122,2,8,5,5,5,68,14,8,14,23,2,14,5,25,23,5,5,23,2,32,14,20,2,41,14,23,5,14,5,95,5,5,8,8,14,14,2,14,14,14,5,113,5,14,23,11,2,14,5,23,11,14,8,50,5,14,5,23,2,68,2,11,23,14,14,23,2,5,8,68,2,14,2,8,41,14,5,74,3,14,5,23,5,41,5,26,8,5,2,68,14,14,5,11,8,23,5,23,14,14,5,41,2,14,41,8,2,41,5,32,5,23,2,38,5,5,14,17,14,68,2,23,8,5,5,95,2,5,5,68,2,32,5,14,14,5,5,23,5,41,23,11,8,14,11,8,14,5,2,98,5,14,8,23,5,41,2,18,11,23,8,23,5,5,14,14,2,68,5,38,5,5,2,53,14,5,23,8,2,41,5,50,5,14,14,33,2,5,14,32,5,14,5,23,38,41,2,41,5,14,5,8,5,23,5,11,14,14,2,113,5,5,11,23,14,14,5,23,5,23,5,53,2,14,14,8,2,41,5,41,23,5,2,68,5,5,14,32,2,95,2,8,5,5,23,50,5,5,8,23,5,41,5,11,14,5,5,38,8,41,5,41,5,14,5,23,14,5,2,74,2,14,41,8,5,23,5,20,14,41,2,23,5,14,23,32,5,14,2,23,14,5,2,95,13,14,5,8,5,41,5,11,8,14,5,68,2,23,5,50,2,38,5,8,41,5,5,32,2,23,11,23,5,14,14,14,5,14,14,113,2,5,5,11,5,41,2,23,23,14,5,32,5,14,23,8,5,41,2,95,14,14,2,23,5,5,18,14,2,41,5,8,5,41,5,53,5,5,5,38,5,41,5,17,32,5,5,68,2,14,14,11,5,23,14,23,5,5,2,122,2,14,8,23,6,14,5,32,14,14,5,53,5,5,41,33,2,14,5,23,8,5,5,32,14,23,5,8,5,113,5,14,5,14,5,23,14,5,17,32,5,41,2,23,14,5,2,83,2,14,14,23,5,23,8,11,8,14,8,68,2,14,5,14,23,32,2,8,5,41,2,95,5,5,23,23,5,41,5,38,14,5,2,38,5,14,5,11,2,41,8,23,32,5,5,41,2,5,14,68,2,23,5,32,23,5,5,23,2,41,8,17,5,68,5,8,14,5,5,95,5,5,14,8,14,14,5,41,13,32,2,23,2,5,41,32,2,23,2,23,5,14,5,59,5,14,18,23,5,41,2,11,5,5,8,113,5,14,5,41,5,14,8,8,23,14,5,32,14,41,5,8,5,32,5,17,14,14,2,113,2,14,8,32,5,41,2,8,5,14,14,68,2,5,41,8,5,41,2,32,14,14,2,23,23,5,5,26,2,68,2,38,14,5,14,32,5,5,23,23,5,14,2,41,14,14,2,53,5,23,5,11,5,41,14,8,8,14,2,149,2,8,14,13,5,68,14,11,5,14,2,23,2,14,25,14,5,14,5,38,23,14,5,53,5,5,5,38,2,41,2,20,23,5,14,23,5,5,14,53,5,50,5,23,14,14,2,41,5,41,8,8,2,14,5,32,14,5,5,113,5,14,14,17,8,14,5,8,11,32,5,95,2,14,14,8,5,23,5,41,14,5,5,68,14,5,8,11,2,68,14,8,5,14,5,53,2,41,5,23,2,14,2,11,68,5,2,38,2,14,14,41,5,23,8,23,14,14,8,95,3,5,14,23,14,41,5,17,5,14,2,38,5,5,14,32,5,41,2,53,8,14,5,41,5,5,14,8,8,95,2,11,5,14,14,23,2,5,23,59,5,14,5,8,23,14,2,88,2,14,14,8,2,41,14,41,11,14,2,68,2,41,5,11,5,23,2,8,23,23,5,50,14,5,23,23,2,14,2,32,5,14,5,68,14,5,14,14,5,122,2,23,8,5,23,32,8,5,5,23,2,23,2,29,14,14,5,68,5,14,32,11,2,14,5,23,14,14,5,113,5,5,5,23,14,14,2,32,8,23,5,68,2,14,14,17,2,32,14,23,14,5,2,32,11,23,23,8,5,68,2,14,14,14,5,38,2,14,5,95,5,14,2,8,20,5,5,59,5,23,5,23,5,68,14,11,14,14,2,68,5,5,23,14,5,41,5,23,5,14,2,74,2,14,38,8,2,14,5,50,8,14,5,23,14,14,5,11,14,68,2,23,5,5,5,122,2,8,11,38,2,14,8,11,41,14,5,38,2,41,5,23,5,14,5,8,23,23,2,95,3,5,14,38,8,41,2,14,14,14,14,23,2,5,23,11,5,41,2,68,14,5,5,83,14,5,5,8,5,41,8,32,11,5,5,23,8,5,14,41,2,68,5,8,14,14,2,32,2,41,8,23,11,41,8,20,5,5,2,158,5,14,14,32,5,14,5,8,8,14,5,41,2,14,41,23,2,23,5,53,14,5,2,23,5,14,14,50,5,41,5,8,14,5,14,53,5,14,14,23,2,68,2,14,38,5,5,68,5,14,5,11,2,32,14,23,5,14,5,77,5,14,23,13,5,14,2,32,5,68,2,38,2,14,14,14,14,14,5,23,32,5,2,95,5,5,5,8,5,68,8,28,5,14,11,68,2,14,8,32,2,14,5,8,41,14,8,50,2,14,5,23,5,41,14,11,8,5,5,113,5,5,5,20,14,68,2,8,5,41,2,32,14,14,32,23,2,14,2,68,5,14,2,38,8,14,41,11,2,41,2,8,23,14,5,50,5,14,14,23,5,32,2,32,14,5,2,68,5,23,8,41,5,14,14,23,5,5,5,158,5,14,5,8,14,14,2,23,23,14,8,23,5,5,23,32,5,68,5,23,5,14,5,41,5,5,8,8,2,122,5,11,11,5,14,53,5,5,14,39,2,41,2,68,23,5,2,32,5,14,14,23,2,23,14,14,14,23,2,68,2,5,11,11,23,41,2,23,14,41,5,98,5,5,14,8,5,14,5,32,8,14,5,23,5,23,14,41,2,68,2,8,14,5,5,53,2,5,23,68,5,14,5,17,14,14,8,38,5,41,14,11,2,41,8,8,11,5,2,122,14,14,5,8,14,23,5,32,14,14,2,68,2,14,68,13,5,14,2,38,5,14,5,74,5,5,8,23,5,41,2,14,8,23,5,53,5,14,5,32,5,23,14,8,32,5,2,50,2,41,17,8,2,41,5,32,14,5,2,113,5,14,5,41,5,14,14,23,8,23,5,32,2,14,14,8,2,95,2,59,14,5,5,23,23,5,8,11,5,41,5,23,14,5,8,68,2,5,14,68,5,41,5,11,32,41,5,23,5,14,14,17,5,23,5,8,5,5,14,158,2,14,8,8,8,14,5,14,14,14,2,68,5,23,14,32,2,41,2,23,23,5,5,68,13,5,5,23,2,68,2,18,14,14,23,23,5,14,11,41,2,41,2,8,14,14,5,53,5,32,14,8,2,14,14,50,23,5,2,68,2,5,23,32,5,32,5,23,5,41,2,41,2,5,38,8,14,41,5,32,5,5,2,113,5,5,5,20,2,122,5,23,14,14,5,32,2,14,5,38,14,23,5,14,41,5,5,23,5,14,8,53,5,14,5,23,5,14,5,116,5,5,14,23,8,41,2,11,23,14,5,38,5,14,23,14,2,23,2,68,5,14,5,32,14,14,32,8,2,68,5,26,5,14,14,63,2,5,5,32,8,14,2,8,23,14,5,122,5,41,14,8,2,23,14,11,5,14,5,68,5,14,8,17,5,41,5,8,41,14,2,53,5,11,14,23,2,14,5,68,11,14,14,23,5,5,14,32,2,113,5,8,5,5,5,59,5,8,8,68,2,41,2,32,23,5,5,53,5,14,14,14,14,14,5,8,23,14,5,95,2,5,5,23,14,68,2,17,5,23,2,68,5,14,41,11,2,14,11,23,5,14,2,68,14,41,5,8,5,41,5,32,23,5,8,23,8,5,5,68,2,32,2,23,41,5,5,95,3,14,8,8,2,41,14,14,5,14,5,88,5,5,14,11,14,14,2,38,11,41,5,50,2,14,41,8,2,23,2,32,14,41,2,68,8,14,8,14,5,41,5,23,5,5,5,95,5,5,14,23,5,14,14,20,23,5,2,23,2,68,14,11,5,68,5,23,23,14,5,122,2,5,18,23,14,14,2,11,5,14,5,38,5,5,23,50,5,41,5,23,8,14,2,32,14,5,14,23,5,95,2,41,5,5,5,23,2,23,23,53,5,41,2,8,14,23,5,48,5,14,14,8,5,14,14,11,17,5,5,203,2,5,14,23,11,23,5,23,5,14,5,32,5,14,23,23,2,14,2,50,41,14,2,53,5,14,5,32,2,68,2,8,23,14,23,41,2,14,5,23,5,68,2,32,14,5,5,23,14,14,11,20,2,41,23,23,5,5,2,158,5,5,14,8,5,41,5,14,8,41,2,68,8,5,14,11,14,41,5,38,5,5,2,83,5,14,8,23,5,41,5,32,5,5,14,38,5,14,23,41,2,14,2,8,53,14,5,32,2,41,14,38,2,23,5,23,5,14,5,68,5,5,23,11,14,41,5,8,5,32,2,95,8,5,14,23,5,41,2,95,13,5,5,23,5,5,14,17,5,68,5,8,14,41,8,32,5,5,14,23,5,14,2,41,41,5,2,113,2,14,5,11,2,41,14,23,23,5,2,98,2,14,5,8,8,32,14,11,14,41,5,23,2,14,23,41,2,41,5,23,5,5,14,53,8,14,5,23,5,122,2,17,11,5,5,68,5,14,5,53,5,23,5,23,41,5,5,41,5,23,38,8,5,14,5,11,5,14,5,83,2,41,5,26,14,14,5,8,8,14,2,95,5,5,32,23,2,23,14,41,5,5,5,68,5,14,11,32,2,41,5,8,14,5,14,83,5,14,14,63,8,41,2,11,23,14,5,23,2,14,5,14,4,95,5,8,14,5,2,95,14,14,8,8,8,14,5,59,14,41,2,38,2,5,41,11,2,14,5,68,14,14,2,41,14,5,14,8,8,113,2,11,14,5,5,68,2,14,23,50,8,14,5,23,14,14,2,74,2,41,5,23,2,14,8,14,23,14,5,68,5,14,14,32,5,23,2,23,5,14,14,68,2,14,32,8,5,68,2,32,5,14,2,38,41,5,5,14,2,41,2,23,8,14,14,95,5,14,14,23,2,41,2,17,23,14,5,23,5,14,23,32,5,14,14,8,14,14,2,203,3,5,8,23,5,23,8,11,32,23,2,23,5,23,14,20,5,23,2,68,14,5,5,32,5,14,8,23,5,68,5,14,14,14,23,53,2,5,5,32,2,68,14,23,23,5,2,50,5,14,5,23,5,23,5,53,5,5,2,113,2,5,20,41,5,41,2,8,14,41,5,53,2,5,41,8,14,14,2,32,8,14,5,68,11,14,5,11,5,95,5,8,14,14,14,41,5,14,8,23,5,14,5,11,32,14,2,113,5,23,14,50,2,14,5,8,11,5,14,95,5,14,5,8,5,68,2,41,5,41,2,23,5,14,38,11,5,14,2,68,14,5,5,59,14,5,41,8,2,41,5,32,8,23,5,23,2,14,5,68,5,38,8,8,14,14,5,95,2,14,11,8,5,41,14,17,14,5,5,113,5,14,5,11,23,41,2,8,23,14,2,41,2,5,14,68,2,32,8,32,5,5,8,68,5,14,23,23,5,95,5,23,14,14,5,53,5,14,5,23,2,14,5,41,41,5,5,23,5,41,14,11,2,23,8,8,5,41,2,149,2,14,8,8,14,14,5,11,14,23,14,88,5,5,14,14,2,14,5,38,23,14,2,95,5,14,14,8,2,68,5,20,41,5,5,23,5,5,11,95,5,14,2,18,23,5,5,68,3,41,5,23,2,41,14,32,8,14,5,68,8,5,14,17,5,50,2,23,5,23,2,32,5,5,68,23,5,41,5,41,5,14,5,38,14,5,5,32,14,41,5,23,11,5,11,77,5,5,14,23,2,68,5,11,14,5,2,23,5,68,8,14,2,41,14,23,14,5,2,123,5,14,5,23,14,41,2,28,8,14,5,68,2,5,23,11,2,68,2,23,14,5,14,41,23,5,14,23,5,41,2,32,5,41,5,38,2,5,23,59,2,14,2,8,38,14,5,32,2,23,14,23,14,32,5,41,14,5,5,203,5,5,8,11,5,14,14,8,5,14,2,83,5,41,23,13,2,41,2,32,32,5,2,23,5,14,14,32,5,68,8,8,5,14,14,32,5,5,23,53,2,41,2,23,14,5,2,68,5,41,14,32,5,14,5,23,8,14,2,122,2,14,14,8,23,23,2,11,14,41,2,23,5,5,32,17,8,41,5,23,5,14,5,158,5,14,8,23,5,68,14,14,8,5,14,23,2,14,14,32,5,32,2,23,41,23,5,59,2,14,8,23,2,14,8,32,23,5,5,113,2,5,5,14,5,68,5,23,17,41,2,32,14,5,14,8,5,23,5,83,5,5,5,23,14,5,23,11,5,122,5,23,5,14,5,95,5,8,5,23,14,14,2,32,23,14,5,68,5,14,5,29,5,23,23,8,5,5,2,95,2,41,32,23,5,14,2,14,14,23,2,38,2,14,41,32,2,41,2,23,23,14,5,50,14,5,5,23,2,122,5,11,14,5,8,68,5,14,8,41,14,14,2,38,14,5,8,53,2,14,14,8,2,41,14,20,11,41,5,113,2,5,5,32,14,23,5,8,14,14,2,122,5,5,23,8,2,14,14,95,5,5,5,53,8,14,14,17,5,41,5,8,38,14,14,32,2,14,5,68,2,68,2,14,14,23,5,23,2,32,14,11,5,41,5,8,14,5,5,113,5,14,14,23,5,23,5,32,8,14,5,68,5,5,68,23,5,32,2,38,14,23,2,32,14,14,8,8,5,41,2,17,5,5,14,113,14,14,5,53,2,14,5,8,32,5,2,68,5,41,14,8,2,68,5,11,14,5,8,68,2,14,8,59,8,14,2,23,14,41,11,46,5,5,14,8,5,41,2,41,23,14,2,23,14,14,5,32,2,113,2,68,5,5,5,50,2,14,32,23,2,14,14,11,41,14,2,38,2,14,14,14,5,41,11,23,8,5,2,158,2,14,14,8,14,32,8,26,14,41,5,23,5,14,23,32,2,14,5,38,14,14,2,68,5,5,14,23,5,41,5,11,14,5,23,68,5,14,5,50,5,68,2,8,23,5,2,95,13,14,8,8,5,41,5,41,5,5,2,158,5,5,14,11,14,14,5,8,8,68,5,59,2,14,14,8,14,23,5,32,5,14,5,68,5,14,32,14,5,41,5,8,14,14,8,53,5,23,5,68,2,14,5,50,68,14,2,23,5,14,5,32,5,41,14,8,5,5,5,95,5,5,23,23,5,122,2,11,5,14,2,38,5,14,14,23,5,41,5,68,11,5,5,32,8,14,23,23,2,68,5,41,5,14,14,23,2,5,23,32,5,41,2,8,41,5,2,116,5,38,5,23,2,14,14,11,8,14,5,68,14,14,14,14,5,23,2,23,23,14,5,95,2,5,28,38,5,14,2,59,5,5,14,63,5,14,5,11,2,122,2,8,8,14,14,41,14,5,14,38,2,32,5,32,41,14,5,23,5,41,23,17,2,14,5,23,5,41,5,158,2,5,14,8,18,14,5,14,11,14,2,68,2,5,14,32,8,68,5,23,14,14,2,35,5,14,8,23,14,68,2,11,14,14,5,68,5,5,5,122,5,41,2,23,23,5,5,32,5,14,23,8,2,53,23,17,14,5,5,68,5,14,11,11,5,14,5,68,5,14,5,68,5,14,41,8,2,14,2,53,23,14,2,68,14,14,5,20,5,95,2,8,14,14,14,95,2,5,8,23,2,41,8,14,23,14,5,38,2,41,14,32,5,14,14,8,41,5,5,149,3,5,5,23,5,23,2,32,5,17,14,23,8,14,23,41,2,41,5,23,5,14,2,74,14,14,5,8,2,122,2,38,23,5,8,23,2,14,41,32,5,23,5,8,14,14,2,41,5,41,11,38,14,14,5,11,5,14,2,188,2,14,14,17,14,14,14,23,8,14,2,32,5,41,14,8,2,50,5,41,23,14,2,68,23,5,23,32,2,41,5,8,5,5,14,98,2,5,5,23,5,41,2,32,32,14,5,38,5,23,14,14,2,23,14,23,14,23,2,95,2,5,23,23,14,14,2,17,14,68,5,53,2,5,32,11,5,14,2,68,8,5,5,122,5,14,5,8,2,68,14,32,5,14,5,68,2,14,14,43,5,41,5,8,41,5,5,53,14,14,5,23,8,14,5,14,23,5,8,68,2,23,5,32,8,95,2,8,5,14,5,50,5,5,68,8,5,41,5,95,14,5,5,38,5,14,14,41,2,68,2,8,11,14,5,32,5,5,5,68,14,23,5,20,14,14,5,113,2,14,8,11,2,41,23,8,14,14,14,122,2,14,5,8,5,41,5,11,23,41,2,23,5,14,14,50,5,38,5,53,14,5,5,32,5,5,11,8,5,122,5,41,14,5,5,38,11,5,14,32,2,14,5,23,38,14,5,68,2,14,14,23,5,53,5,32,5,14,5,68,5,5,8,14,41,14,2,8,14,23,2,158,2,14,41,23,5,14,5,50,9,14,2,23,14,23,14,11,2,68,2,23,14,14,8,41,2,41,23,68,2,14,5,11,14,14,5,53,5,14,11,20,5,41,5,23,8,5,2,158,14,5,14,23,5,23,2,41,5,14,5,68,5,5,53,11,5,14,2,23,5,41,5,83,11,5,8,8,5,122,5,11,23,14,5,68,2,5,5,41,5,41,14,23,14,5,8,32,5,68,8,8,2,14,11,29,14,5,2,113,2,5,5,53,14,41,5,8,32,41,5,41,2,14,23,8,5,68,2,32,14,14,5,23,14,5,8,50,2,41,2,23,14,5,14,74,5,14,41,38,2,14,2,14,23,14,5,68,2,41,5,11,8,23,14,23,5,5,2,176,14,5,14,13,8,41,8,18,5,14,5,113,2,41,14,14,2,14,5,23,23,5,5,32,14,5,14,23,5,74,5,17,5,14,14,23,5,14,8,53,2,68,2,23,41,14,5,68,5,14,14,8,5,14,8,53,11,5,2,68,2,5,41,23,14,68,5,8,14,41,2,32,2,14,23,8,5,41,5,68,5,14,2,83,5,14,5,32,5,41,8,23,8,5,14,50,5,14,5,68,5,23,2,11,68,5,2,23,2,14,32,41,2,41,5,8,14,14,5,158,2,14,5,23,8,41,5,20,8,23,14,23,14,14,14,11,2,32,4,53,5,14,2,122,5,5,23,23,2,41,2,11,14,14,14,38,8,14,5,50,5,41,2,8,41,14,5,95,3,41,5,8,5,23,14,14,23,5,2,113,5,41,23,11,5,14,2,23,23,14,2,60,5,5,14,68,2,14,14,32,8,5,14,23,8,5,5,14,8,203,5,8,5,5,14,53,5,5,11,23,5,41,5,50,14,14,2,38,2,23,14,32,5,41,14,23,8,23,2,122,2,8,14,8,14,41,2,32,14,41,2,68,5,14,38,20,2,14,5,23,14,5,2,53,14,14,14,8,5,41,2,41,32,14,5,68,2,5,5,74,2,23,5,23,14,14,23,50,5,14,23,8,2,41,14,11,5,23,2,158,14,5,5,14,8,14,2,23,23,41,5,32,5,5,41,8,5,68,2,68,5,14,2,23,5,14,17,11,14,68,5,23,5,5,14,113,2,5,14,23,5,41,5,11,23,5,5,68,2,41,5,50,5,32,8,23,14,5,2,95,5,5,8,68,14,14,5,14,14,14,5,38,5,5,41,11,5,68,5,38,11,14,2,59,23,41,14,8,2,68,5,32,5,5,5,23,5,5,23,41,2,14,5,23,32,14,2,95,2,41,5,8,5,41,5,17,23,14,8,203,5,5,5,32,5,23,5,8,5,68,2,41,5,23,32,8,5,14,2,32,41,5,14,38,5,5,5,32,5,41,5,23,8,14,23,95,2,14,5,23,5,95,5,14,14,5,2,23,14,14,23,32,2,41,5,23,5,14,5,138,5,14,14,8,14,14,2,32,14,41,2,23,2,5,41,41,5,23,2,38,14,14,5,95,13,5,23,23,2,41,5,20,5,5,5,53,2,41,14,32,5,41,2,8,68,5,2,41,5,32,5,38,2,68,5,11,14,14,14,113,5,5,11,17,5,41,8,23,5,14,5,53,5,5,23,23,5,14,5,122,8,14,2,23,14,5,14,11,5,59,5,8,41,14,5,68,2,14,8,38,8,14,5,32,14,14,2,113,2,41,5,14,5,41,41,23,11,5,5,95,2,14,5,8,8,68,5,17,14,14,2,68,2,14,23,32,14,14,5,23,5,5,5,95,14,5,14,23,2,113,2,11,23,5,5,23,5,14,14,59,5,23,5,23,14,14,5,32,2,41,41,23,5,14,11,14,5,41,5,113,8,5,14,32,14,14,5,8,8,14,5,149,2,5,41,13,5,32,8,53,5,5,5,23,5,23,8,14,5,122,2,23,14,14,5,53,2,5,5,68,5,14,5,26,53,14,5,23,14,14,5,11,2,68,5,38,14,5,5,122,5,8,8,8,5,41,5,53,14,23,2,68,5,5,41,17,2,41,2,23,8,41,5,32,5,5,14,8,14,68,5,14,14,14,23,68,2,5,11,95,2,41,5,8,14,14,2,98,2,41,14,8,5,14,5,11,38,14,2,68,5,23,14,41,14,32,2,8,5,14,14,32,5,23,23,8,2,41,5,50,14,5,2,113,23,14,14,11,2,41,5,23,17,5,14,41,2,5,14,68,2,23,5,32,14,32,2,68,2,23,8,23,14,14,5,8,14,5,2,221,2,14,5,23,14,41,14,41,13,14,5,23,2,14,23,11,2,23,14,23,23,14,2,50,14,5,11,23,2,122,2,32,5,5,23,38,5,14,14,68,5,41,2,8,38,5,2,32,5,14,14,23,5,41,5,59,5,14,5,68,2,14,38,11,11,41,5,8,5,41,5,68,5,14,14,23,5,41,2,32,11,5,2,113,14,5,5,17,2,113,5,8,5,14,5,95,14,14,23,23,5,14,5,14,41,5,14,53,2,41,5,32,2,14,8,23,8,14,5,86,2,14,14,23,14,68,2,18,14,14,2,23,8,5,41,41,5,14,2,113,14,5,2,53,14,5,14,23,5,41,5,17,8,41,5,23,2,14,14,32,5,95,2,8,23,5,2,122,5,14,8,8,14,14,41,11,5,14,5,113,2,23,14,33,5,14,5,23,32,32,5,95,2,5,41,23,2,23,2,41,14,5,5,23,5,14,8,11,5,122,5,23,5,23,8,61,14,5,5,23,5,14,5,32,23,14,5,68,2,41,23,14,2,23,5,8,14,14,5,158,5,14,18,8,14,14,5,23,14,41,5,113,5,5,14,11,2,14,5,68,23,5,2,41,8,41,5,23,2,95,5,32,14,5,5,23,5,5,23,83,2,14,14,23,14,5,14,53,5,23,5,23,2,122,5,14,14,5,5,68,5,5,5,11,23,68,2,23,14,14,5,59,2,14,53,23,2,41,2,32,14,14,2,53,14,5,14,41,11,41,5,8,8,5,5,95,5,14,5,38,2,23,5,50,41,14,2,23,5,41,11,32,5,14,5,8,41,14,2,203,3,14,14,23,8,14,2,11,8,41,14,23,2,5,23,26,2,68,5,23,5,23,8,32,14,14,8,8,2,68,2,41,14,14,14,113,5,14,14,32,5,14,2,23,32,14,5,50,5,14,5,8,14,23,23,11,5,5,5,203,5,14,8,14,5,32,8,8,5,41,5,74,2,14,41,8,5,41,5,46,23,5,5,68,5,5,14,95,2,68,2,8,5,5,14,41,2,14,20,23,5,41,5,32,23,5,5,38,14,41,5,17,5,41,5,38,23,5,2,95,14,5,14,8,5,32,5,14,5,68,5,68,2,5,23,32,5,41,2,68,5,14,5,113,5,14,5,8,2,41,5,11,32,14,23,23,5,14,5,41,2,23,5,23,68,14,2,32,2,14,23,38,2,41,5,50,5,5,14,113,2,5,14,11,5,41,8,8,23,14,2,68,14,5,14,8,2,68,5,95,5,14,2,23,14,14,32,20,5,41,5,23,5,23,5,53,5,14,5,68,5,41,5,14,23,5,2,68,5,23,41,11,5,32,14,8,5,5,5,149,2,41,8,23,14,14,2,11,14,41,2,38,5,14,23,41,14,41,2,23,14,5,8,95,5,5,5,23,5,203,2,14,5,14,14,23,5,5,8,53,5,14,5,23,14,14,5,95,2,14,41,8,5,23,14,32,23,14,2,68,2,5,5,17,23,23,5,38,14,14,2,74,2,14,32,23,2,14,14,41,14,14,2,38,14,41,5,11,5,95,5,8,23,5,14,59,5,5,5,68,5,50,2,11,41,5,5,68,2,14,8,41,2,41,8,8,14,5,5,158,13,14,14,23,5,14,2,50,11,14,2,23,2,41,41,32,2,23,5,38,5,14,8,41,14,5,23,23,5,41,2,11,14,5,5,158,2,5,14,68,5,41,14,8,38,14,5,32,2,68,5,8,5,23,5,14,14,14,5,68,5,14,14,32,5,41,5,8,23,23,5,83,2,5,14,8,5,41,5,95,8,14,2,68,14,14,5,14,2,95,5,68,5,14,11,32,2,14,38,23,8,41,5,20,41,14,2,38,2,14,5,11,14,14,14,8,11,41,5,203,5,5,5,23,8,23,5,11,5,23,5,23,5,14,68,17,5,41,2,23,14,5,2,95,8,14,8,38,2,41,2,41,8,5,14,68,14,5,14,32,5,68,2,8,14,14,2,77,14,38,11,8,5,14,14,32,5,5,5,113,2,5,41,23,5,41,2,23,8,68,5,32,5,14,23,23,8,32,5,50,14,5,5,68,5,5,23,11,5,41,5,23,14,14,5,68,5,14,5,53,2,41,5,11,50,5,5,23,5,41,5,59,2,68,14,8,14,5,5,95,2,5,8,8,23,68,2,41,5,14,5,53,14,14,14,32,2,14,2,68,23,5,2,50,5,5,41,8,5,113,5,11,5,41,14,68,5,14,11,41,5,14,2,8,14,5,5,158,14,14,5,8,2,14,18,23,8,5,5,203,2,14,5,32,14,41,5,23,14,14,8,41,5,5,23,23,2,14,2,53,14,41,5,38,5,14,14,17,2,122,5,8,32,14,5,32,5,14,23,23,5,23,2,68,32,14,2,23,2,14,23,32,5,14,14,23,5,14,5,137,2,14,14,8,41,41,2,32,13,23,5,68,5,5,14,14,5,68,5,23,5,14,2,53,5,14,14,23,2,68,14,17,23,5,8,38,2,5,14,95,2,14,5,23,23,14,14,41,2,41,5,23,2,95,14,11,14,5,2,113,14,14,8,29,5,14,2,23,5,41,5,88,2,5,41,8,5,14,2,41,32,23,14,23,8,5,5,11,14,68,2,23,14,14,5,149,2,14,8,68,2,41,5,11,41,5,2,38,5,41,5,14,2,14,14,23,23,14,5,95,2,14,14,23,5,23,5,20,14,14,8,68,5,14,53,11,5,122,2,23,5,5,2,68,14,14,14,18,14,41,5,32,8,5,5,23,5,14,14,83,5,32,2,23,14,41,2,32,5,14,23,8,5,41,14,41,5,5,2,188,2,14,14,11,8,14,14,8,14,14,2,68,8,14,41,13,2,23,2,95,14,5,5,68,14,5,8,41,2,68,5,8,14,14,41,74,5,14,5,23,2,41,2,17,23,41,2,23,8,14,5,11,5,68,11,23,14,14,5,122,5,5,32,8,5,14,2,32,5,41,5,113,2,5,14,20,14,14,5,38,23,5,5,95,14,14,5,23,5,122,14,14,5,5,5,23,5,32,8,32,5,14,2,23,68,5,5,83,2,41,14,68,2,14,5,11,11,14,5,68,2,14,14,41,5,68,5,8,14,23,2,32,5,23,23,8,8,14,8,77,14,5,2,53,14,5,23,32,2,122,2,8,8,14,8,122,5,8,14,23,5,23,5,11,14,5,14,68,5,41,17,17,8,14,14,23,5,14,2,123,2,14,5,8,5,41,2,14,68,41,2,23,2,5,14,53,5,32,5,68,14,14,5,59,13,5,23,23,2,122,5,11,5,5,14,38,5,5,14,41,2,41,2,68,32,5,5,95,2,23,14,23,5,23,5,17,5,14,2,68,14,14,23,32,23,14,2,8,5,14,5,122,5,14,38,8,5,41,5,32,8,14,5,23,14,41,14,23,5,68,2,8,14,5,14,32,5,5,11,113,5,41,2,14,14,14,5,113,2,14,5,32,5,68,5,23,8,14,5,149,5,5,5,8,11,53,2,32,14,41,5,23,2,5,68,14,2,14,14,23,14,14,5,53,14,14,5,8,5,68,2,59,14,14,5,68,2,14,14,32,2,23,23,23,41,5,5,41,5,41,8,8,2,41,8,32,41,14,5,158,2,5,5,50,14,14,2,8,8,14,14,32,5,5,14,38,5,68,2,68,5,14,2,68,14,5,32,11,2,41,5,38,14,14,14,53,5,14,14,23,2,41,5,11,38,14,2,23,5,41,14,14,5,50,5,8,5,14,2,284,2,5,23,8,8,41,5,28,5,32,8,38,5,14,14,32,2,14,5,23,25,14,5,41,14,14,5,23,14,68,5,32,14,5,23,23,2,5,8,59,2,122,2,23,14,5,5,74,5,14,14,23,2,14,23,41,8,5,5,113,5,5,14,11,5,68,5,23,14,68,2,50,5,5,41,23,11,14,2,32,14,14,2,113,8,5,5,41,5,41,14,8,23,14,5,32,2,41,14,23,2,32,2,23,41,5,5,68,2,68,8,32,5,14,5,8,5,5,8,203,14,14,5,8,5,41,14,11,11,14,2,68,14,14,17,17,2,23,5,68,14,5,5,95,5,23,23,8,5,41,2,14,14,41,5,68,2,14,14,53,14,14,2,8,68,5,5,98,3,14,5,23,2,23,14,32,14,14,2,68,2,14,11,41,23,14,5,8,14,41,2,53,2,14,41,23,2,68,2,50,8,5,14,23,5,5,14,11,5,158,5,23,14,14,14,41,8,5,8,68,2,41,2,53,14,5,2,38,5,14,41,26,2,14,8,23,20,14,2,95,5,14,14,8,14,68,5,14,5,41,2,68,5,14,23,11,2,14,14,53,5,5,14,116,5,23,5,8,5,41,2,32,23,14,14,68,5,5,14,122,2,38,5,8,23,14,5,32,5,14,11,8,2,41,5,20,23,14,2,113,14,14,5,11,14,41,2,68,8,23,2,41,5,14,68,8,5,41,8,32,5,14,5,23,5,5,8,50,5,122,5,8,5,5,8,158,5,5,14,23,14,14,8,14,32,5,2,68,5,41,14,32,5,68,14,8,14,5,5,113,2,5,23,23,14,14,5,11,5,23,5,53,2,41,14,14,5,41,2,68,8,14,2,32,32,5,5,23,2,68,2,50,23,5,14,68,5,14,41,32,5,14,2,8,14,41,5,68,2,23,5,23,8,14,5,32,23,14,5,203,2,5,5,20,5,32,5,8,14,14,5,95,5,14,38,23,2,14,2,68,14,14,5,38,14,14,5,32,2,122,5,8,11,14,14,50,2,14,14,38,5,113,5,11,14,14,5,23,14,14,23,14,5,14,14,23,14,14,2,116,2,5,14,68,8,14,5,29,23,41,5,23,2,14,41,11,14,23,2,23,14,5,2,122,5,14,18,8,2,95,8,32,5,5,5,38,5,41,5,50,5,14,5,8,68,14,2,95,2,14,5,23,5,32,23,41,5,5,14,68,2,14,8,11,14,41,2,8,14,41,2,98,5,14,14,23,5,41,5,88,23,23,2,68,14,5,14,14,5,68,2,23,5,14,14,32,2,5,8,23,14,14,14,17,23,11,5,158,2,14,14,11,2,41,14,8,8,5,2,122,5,41,14,23,14,23,5,11,23,23,2,23,5,14,32,68,2,41,2,68,14,5,5,53,5,5,41,8,5,122,2,14,8,5,11,23,14,14,14,95,5,41,2,23,14,5,2,50,14,41,23,8,5,41,5,11,5,23,5,188,2,5,5,14,14,41,2,8,11,14,14,95,5,5,14,23,5,68,14,59,5,23,2,23,8,14,8,32,2,41,2,23,41,5,5,95,5,5,5,68,2,14,5,32,68,5,11,23,2,23,14,17,5,68,14,23,5,14,5,95,5,14,17,23,5,41,2,41,5,14,8,38,2,5,68,32,5,14,5,23,8,41,5,77,5,5,5,23,5,95,5,11,5,14,5,113,5,5,23,41};
	while(scanf("%d/%d",&pembilang, &penyebut) !=EOF){
		penyebut--;
		printf("%d\n",halo[penyebut]);
		// printf("%d -> %d\n",penyebut, cnt);
	}
	return 0;
};