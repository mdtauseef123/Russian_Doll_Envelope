#include<bits/stdc++.h>
using namespace std;


bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first and a.first < b.first){
        return true;
    }
    if(a.first == b.first and a.second > b.second){
        return true;
    }
    return false;
}

int maxEnvelopes(vector<pair<int,int>> &envelopes) {
    int n=envelopes.size();
    sort(envelopes.begin(),envelopes.end(),cmp);
    vector<int> arr;
    for(int i=0;i<n;i++){
        arr.push_back(envelopes[i].second);
    }
    vector<int> dp(n,0);
    int ans=0;
    for(int i=0;i<n;i++){
        int maxi=0;
        for(int j=i-1;j>=0;j--){
            if(arr[i] > arr[j]){
                maxi=max(maxi, dp[j]);
            }
        }
        dp[i]=maxi + 1;
        ans=max(ans, dp[i]);
    }
    cout<<ans<<endl;
}


int main(){
    vector<int> width{4, 4, 6, 2, 1};
    vector<int> height{5, 6, 7, 3, 1};
    vector<pair<int,int>> envelopes;
    for(int i=0;i<width.size();i++){
        envelopes.push_back(make_pair(width[i], height[i]));
    }
    maxEnvelopes(envelopes);
    return 0;
}
