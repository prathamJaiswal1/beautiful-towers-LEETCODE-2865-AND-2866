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
    
    int n=h.size();
           stack<int>st;  // index of prev smallest element
    vector<ll>leftsum(n,0);
    for(int i=0; i<n; i++){
        while(st.size() && h[st.top()] > h[i]){
            st.pop();
        }
        if(st.empty()){
            leftsum[i]=1LL*(i+1)*h[i];
        }else{
            leftsum[i]=leftsum[st.top()]+1LL*(i-st.top())*h[i];
        }
        st.push(i);
    }

    while(st.size()){
        st.pop();
    } 

    // now stack will store index of next smaller element from currenct element
    vector<ll>rightsum(n,0);
    for(int i=n-1; i>=0; i--){
        while(st.size() && h[st.top()] > h[i]){
            st.pop();
        }
        if(st.empty()){
            rightsum[i]=1LL*(n-i)*h[i];
        }else{
            rightsum[i]=rightsum[st.top()]+1LL*(st.top()-i)*h[i];
        }
        st.push(i);
    }

    ll ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,leftsum[i]+rightsum[i]-h[i]);
    }
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}