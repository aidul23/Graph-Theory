#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,total = 0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int d;
        cin>>d;
        total += d;
    }
    if(total == 2*(n-1)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
