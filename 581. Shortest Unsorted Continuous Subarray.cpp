class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=-1;
        int maxi=nums[0],mini=nums[n-1];
        for(int i=1;i<n;i++){
            if(maxi>nums[i]){
                end=i;
            }
            else{
                maxi=nums[i];
            }
        }    

          for(int i=n-2;i>=0;i--){
            if(mini<nums[i]){
                start=i;
            }
            else{
                mini=nums[i];
            }
        }    
        return end-start+1;
    }
};