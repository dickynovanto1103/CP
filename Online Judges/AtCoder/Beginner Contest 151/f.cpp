#include<bits/stdc++.h>
#define nn 520
#define ff first
#define se second
#define mp make_pair
#define inf 1e100
#define cmp 1e-7
using namespace std;

pair<double,double>pts[nn],c;
int n,m;
double ans;
bool flag;

bool pos(pair<double,double>c,pair<double,double>p,double r2)
{
    return ((p.ff-c.ff)*(p.ff-c.ff) + (p.se-c.se)*(p.se-c.se))<=r2+cmp;
}

double slope(pair<double,double>p1,pair<double,double>p2)
{
    return abs(p1.se-p2.se)>cmp?(p2.ff-p1.ff)/(p1.se-p2.se):inf+100000000;
}

double euclid_dist(pair<double,double>p1,pair<double,double>p2)
{
    return (p1.ff-p2.ff)*(p1.ff-p2.ff)+(p1.se-p2.se)*(p1.se-p2.se);
}

double solve(pair<double,double>p1,pair<double,double>p2,pair<double,double>p3)
{
    double x1,x2,y1,y2,m1,m2,r,r2,c1,c2;
    m1=slope(p1,p2);
    m2=slope(p2,p3);
    x1=(p1.ff+p2.ff)/2;
    x2=(p2.ff+p3.ff)/2;
    y1=(p1.se+p2.se)/2;
    y2=(p2.se+p3.se)/2;
    c1=y1-m1*x1;
    c2=y2-m2*x2;
    flag=false;
    if(abs(m1-m2)<cmp)
    {
        return inf;
    }
    else if(m1>=inf)
    {
        c=mp(x1,m2*x1+c2);
    }
    else if(m2>=inf)
    {
        c=mp(x2,m1*x2+c1);
    }
    else
    {
        c=mp((c2-c1)/(m1-m2),(c2-c1)/(m1-m2)*m1 + c1);
    }
    r2=euclid_dist(mp(p1.ff,p1.se),c);
    r=sqrt(r2);
    if(r>ans)
        return inf;
    int p=0;
    for(int i=0;i<n;i++)
    {
        if(p>n-m)
            return inf;
        if(!pos(c,pts[i],r2))
            p++;
    }
    if(p>n-m)
        return inf;
    flag=true;
    return r;
}

double solve(pair<double,double>p1,pair<double,double>p2)
{
    double r,r2;
    c=mp((p1.ff+p2.ff)/2.000,(p1.se+p2.se)/2.000);
    r2=euclid_dist(mp(p1.ff,p1.se),c);
    r=sqrt(r2);
    flag=false;
    if(r>ans)
        return r;
    int p=0;
    for(int i=0;i<n;i++)
    {
        if(p>n-m)
            return r;
        if(!pos(c,pts[i],r2))
            p++;
    }
    if(p>n-m)
        return r;
    flag=true;
    return r;
}

bool func(pair<double,double>p1,pair<double,double>p2)
{
    pair<double,double>p3=mp((p1.ff+p2.ff)/2,(p1.se+p2.se)/2);
    pair<double,double>c1,c2;
    double q=sqrt(euclid_dist(p1,p2));
    flag=false;
    c1.ff=p3.ff + sqrt(ans*ans-(q/2)*(q/2))*(p1.se-p2.se)/q;
    c1.se=p3.se + sqrt(ans*ans-(q/2)*(q/2))*(p2.ff-p1.ff)/q;
    c2.ff=p3.ff - sqrt(ans*ans-(q/2)*(q/2))*(p1.se-p2.se)/q;
    c2.se=p3.se - sqrt(ans*ans-(q/2)*(q/2))*(p2.ff-p1.ff)/q;
    int p=0;
    for(int i=0;i<n;i++)
    {
        if(p>n-m)
            break;
        if(!pos(c1,pts[i],ans*ans))
            p++;
    }
    if(p<=n-m)
        flag=true;
    p=0;
    for(int i=0;i<n;i++)
    {
        if(p>n-m)
            break;
        if(!pos(c2,pts[i],ans*ans))
            p++;
    }
    if(p<=n-m)
        flag=true;
    return flag;

}

int main()
{
    int i,j,k;
    cin>>n;
    m=n;
    ans=2000;
    for(i=0;i<n;i++){
        cin>>pts[i].ff>>pts[i].se;
    }
    sort(pts,pts+n);
    if(m==1)
    {
        cout<<"0.0000000"<<endl;
        return 0;
    }
    double tmp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            tmp=solve(pts[i],pts[j]);
            if(tmp>=ans)
                continue;
            else if(flag)
            {
                ans=tmp;
                continue;
            }
            else if(!func(pts[i],pts[j]))
                continue;
            for(k=j+1;k<n;k++)
            {
                ans=min(ans,solve(pts[i],pts[j],pts[k]));
            }
        }
    }
    printf("%.7lf\n",ans);
    return 0;
}
