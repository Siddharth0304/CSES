#include <bits/stdc++.h>
using namespace std;

long long helper(long long a,long long b,int i){
    if(i==18)
        return 0;
    int cost=0;
}

long long countingNumbers(long long a,long long b){
    return helper(a,b,0);
}
 
int main() {
    long long a,b;
    cin>>a>>b;
    cout<<countingNumbers(a,b); 
    return 0;
}