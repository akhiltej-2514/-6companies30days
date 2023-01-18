class Solution {
    private :
       vector<int> topo(int numCourses, vector<vector<int>>& prerequisites,vector<int>adj[],int N){
           vector<int>ans;   
           vector<int>indegree(N,0);
          for(auto it : prerequisites){
              indegree[it[1]]++;
          }
           queue<int>q;
           for(int i=0;i<N;i++){
               if(indegree[i]==0){
                   ans.push_back(i);
                   q.push(i);
               }
           }
           while(!q.empty()){
               auto it=q.front();
               q.pop();
               
               for(auto nei:adj[it]){
                   indegree[nei]--;
                   if(indegree[nei]==0){
                       ans.push_back(nei);
                       q.push(nei);
                   }
               }
           }
           return ans;
       }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N=numCourses;
        vector<int>adj[numCourses];
         for(auto it : prerequisites){
             adj[it[0]].push_back(it[1]);
         }
       vector<int>pp= topo(numCourses,prerequisites,adj,N);
    
        return (numCourses==pp.size());
    }
};