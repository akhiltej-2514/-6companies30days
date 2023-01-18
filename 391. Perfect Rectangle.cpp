class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& r) {
        int n=r.size();
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++){
         mp[{r[i][0],r[i][1]}]++;
         mp[{r[i][0],r[i][3]}]--;
         mp[{r[i][2],r[i][3]}]++;
         mp[{r[i][2],r[i][1]}]--;
        }
        int mark=0;
        for(auto it:mp){
            if(it.second!=0){
                if(abs(it.second)!=1)return false;
                mark++;
            }
        }
        return mark==4;
    }
};