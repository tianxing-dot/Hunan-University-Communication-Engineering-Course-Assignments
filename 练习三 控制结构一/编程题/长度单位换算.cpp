// 长度单位换算
#include <iostream>
using namespace std;

int main()
{
    int mi,yd,ft,in;
    cin>>in;
    ft=in/12;
    yd=ft/3;
    mi=yd/1760;
    in=in%12;
    ft=ft%3;
    yd=yd%1760;
    if (mi&&yd&&ft&&in)
        cout<<mi<<" mi "<<yd<<" yd "<<ft<<" ft "<<in<<" in";
    else if (mi&&yd&&ft)
        cout<<mi<<" mi "<<yd<<" yd "<<ft<<" ft";
    else if (mi&&yd&&in)
        cout<<mi<<" mi "<<yd<<" yd "<<in<<" in";
    else if (mi&&ft&&in)
        cout<<mi<<" mi "<<ft<<" ft "<<in<<" in";
    else if (yd&&ft&&in)
        cout<<yd<<" yd "<<ft<<" ft "<<in<<" in";
    else if (mi&&yd)
        cout<<mi<<" mi "<<yd<<" yd";
    else if (mi&&ft)
        cout<<mi<<" mi "<<ft<<" ft";
    else if (mi&&in)
        cout<<mi<<" mi "<<in<<" in";
    else if (yd&&ft)
        cout<<yd<<" yd "<<ft<<" ft";
    else if (yd&&in)
        cout<<yd<<" yd "<<in<<" in";
     else if (ft&&in)
        cout<<ft<<" ft "<<in<<" in";
    else if (mi)
        cout<<mi<<" mi";
    else if (yd)
        cout<<yd<<" yd";
    else if (ft)
        cout<<ft<<" ft";
    else if (in)
        cout<<in<<" in";
}
