class Solution {
    private: 
    void f(int id,vector<vector<int>>&ans,vector<int>&tp,int n,int k){
        //base case 1
       if(n==0 && tp.size()==k){
           ans.push_back(tp);
           return;
       }
       if(id>9)return;
        tp.push_back(id);
       f(id+1,ans,tp,n-id,k);
       tp.pop_back();
       f(id+1,ans,tp,n,k);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
     vector<vector<int>>ans;
     vector<int>tp;
     f(1,ans,tp,n,k);
     return ans;
    }
};

/*
The function has two base cases:

When n becomes 0 and the length of the current combination tp becomes k, this means that a valid combination has been found, so it is added to the ans array and the function returns.
When id becomes larger than 9, this means that all integers from 1 to 9 have been tried and no valid combination has been found, so the function returns.

note :
make sure you write id>9 terminating outerbound case after base case 1

*/