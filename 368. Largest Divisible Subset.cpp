class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;
        int lasti=-1;
        if(n==1){return arr;}
         sort(arr.begin(),arr.end());
        vector<int>dp(n,1),hash(n,1);
        int maxi=-1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[i]%arr[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
                if(dp[i]>maxi){
                    maxi=dp[i];
                    lasti=i;
                }
            }
        }
        ans.push_back(arr[lasti]);
        while(hash[lasti]!=lasti){
            lasti=hash[lasti];
             ans.push_back(arr[lasti]);
        }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};