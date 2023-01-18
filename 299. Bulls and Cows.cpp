class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0;
        int cows=0;
        int n=guess.size();
        int bar[n];
        int car[n];
        for(int i=0;i<n;i++){
            bar[i]=0;
            car[i]=0;
        }
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bull++;
            }
            else{
                bar[secret[i]-'0']++;
                car[guess[i]-'0']++;
            }
        }
        for(int i=0;i<n;i++){
            cows+=min(car[i],bar[i]);
        }
        string ans="";
        ans.push_back(char(bull));
        ans.push_back('A');
        ans.push_back(char(cows));
        ans.push_back('B');
        return ans;
    }
};