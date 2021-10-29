#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std; 

int CountTrailingZeros(int n){
    int res = 0;
    for(int i = 5; i <= n; i = i* 5)
        res = res + n/i;
    return res;   
}
 
 int main(){ 

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    cout<<CountTrailingZeros(n)<<endl;
return 0;
}