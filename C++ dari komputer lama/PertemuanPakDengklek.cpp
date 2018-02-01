#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

vector <int> panjang;


int main()
{
    int N,i,j,k;
    string nama[510];
    string namaAkhir[510];
    cin>>N;
    for(i=0;i<N;i++){
        cin>>nama[i];
        panjang.push_back(nama[i].length());
    }
    
    sort(panjang.begin(),panjang.end());
    vector<int>::iterator it;
    it=unique(panjang.begin(),panjang.end());
    panjang.resize(distance(panjang.begin(),it));
    //cari panjang masing"dan ditaruh di atas
    k=1;
    for(i=0;i<panjang.size();i++){
        for(j=0;j<N;j++){
            if(nama[j].length()==panjang[i]){
                namaAkhir[k]=nama[j];
                k++;
            }
        }
    }
    k--;
    printf("awal:\n");
    for(i=1;i<=k;i++)
        cout<<namaAkhir[i]<<endl;
    //proses leksikografis

    sort(namaAkhir+2,namaAkhir+6);
    printf("akhir:\n");
    for(i=1;i<=k;i++)
        cout<<namaAkhir[i]<<endl;
    int curPanjang;
    curPanjang=namaAkhir[1].length();
    int curIdx=1;
    /*for(i=1;i<=k;i++){
        while(curPanjang==namaAkhir[i].length()){i++;}
        i--;
        //printf("curIdx: %d i: %d\n",curIdx,i);
        //printf("i adalah : %d\n",i);
        sort(namaAkhir+curIdx,namaAkhir+i+1);
        //printf("setelah diurutkan parsial:\n");
        
        curIdx=i+1;
        if(curIdx<=k)
            curPanjang=namaAkhir[curIdx].length();

    }
    //printf("akhir:\n");
    for(i=1;i<=k;i++){
        //printf("ke %d\n",i);
        cout<<namaAkhir[i]<<endl;

    }*/
    return 0;
}
