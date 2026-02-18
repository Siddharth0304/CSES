#include <bits/stdc++.h>
using namespace std;
 
int findLargestDigit(int n){
    int x=0;
    while(n>0){
        int rem=n%10;
        x=max(x,rem);
        n/=10;
    }
    return x;
}
 
int main() {
    int n;
    cin>>n;
    int ans=0;
    while(n>0){
        int x=findLargestDigit(n);
        n-=x;
        ans++;
    }
    cout<<ans;
 
    return 0;
}
