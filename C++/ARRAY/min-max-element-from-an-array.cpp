//Program to find minimum and maximum element in an array
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {3, 2, 1, 56, 10000, 167};
    int n = sizeof(a)/sizeof(a[0]);
    int mn = INT_MAX;
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    cout<<mn<<endl<<mx<<endl;
    return 0;
}
