#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;cin>>n;
    vector<int>h;
    for(int i=0;i<n;i++){
        int ele;cin>>ele;
        h.push_back(ele);
    }
    
    ll ans=0;
    for(int i=0; i<n; i++){
        ll leftsum=0;
        int left=i-1;
        int maxi=h[i];
        while(left >= 0){
            if(h[left] >= maxi){
               
            }else{
                maxi=h[left];
            }
            leftsum+=maxi;
            left--;
        }

        ll rightsum=0;
        int right=i+1;
        maxi=h[i];
        while(right<n){
            if(h[right] >= maxi){

            }else{
                maxi=h[right];
            }
            rightsum+=maxi;
            right++;
        }
        
        ans=max(ans,leftsum+rightsum+h[i]);
    }
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}