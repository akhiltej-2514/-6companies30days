class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int ans;
        int sum=0;
        int f0=0;
        for(int i=0;i<n;i++){
            f0+=nums[i]*i;
            sum+=nums[i];
        }
        ans=f0;
        for(int i=0;i<n;i++){
           int f1=f0+sum-(n*nums[n-i-1]);
           ans=max(ans,f1);
           f0=f1;
        }
      return ans;
    }
};