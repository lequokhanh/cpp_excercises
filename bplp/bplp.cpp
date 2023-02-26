#include <iostream>

using namespace std;
long long i,s,t,a,b,c;
int main()
{
    cin>>a>>b>>c;
    if(a>=0)
        s=s+a*a;
    else
        t=t+a*a*a;
    if(b>=0)
        s=s+b*b;
    else
        t=t+b*b*b;
    if(c>=0)
        s=s+c*c;
    else
        t=t+c*c*c;
    cout<<"tbp="<<s<<endl<<"tlp="<<t;
}
