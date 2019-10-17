
#include<iostream>
using namespace std;
int main()
{
    int t,n,p,m;
    cin >> t;
    while(t--)
    {
        cin >> n >> p >> m;       // 废话
        cout<<max(2 * n - 3, 0) << endl;    // 2n-3即可
    } 
    return 0;
}