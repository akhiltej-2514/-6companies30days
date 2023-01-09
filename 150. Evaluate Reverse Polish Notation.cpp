
class Solution {
private:
  bool isop(string c){
      return (c=="+"||c=="-"||c=="*"||c=="/");
  }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(isop(tokens[i])){
               int a=s.top();
               s.pop();
               int b=s.top();
               s.pop();
               if(tokens[i]=="+"){
                  a=a+b;
               }
               else if(tokens[i]=="-"){
                    a=b-a;
               }
               else if(tokens[i]=="*"){
                   a=a*b;
               }
               else if(tokens[i]=="/"){
                   a=b/a;
               }
               s.push(a);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};

// Path: 151. Reverse Words in a String.cpp
/*
The function first checks if the current element in the input vector is an operator or not. If it is an operator, it takes the two top elements from the stack, applies the operator on them, and pushes the result back onto the stack. If it is not an operator, it converts the element to an integer and pushes it onto the stack. At the end, it returns the top element of the stack, which should be the result of the RPN expression.

*** PLS pay attention at SUBTRACTION AND DIVISION, the order of operands is important. ***

Time Complexity: O(n), where n is the number of elements in the input vector. We iterate over the vector once.

Space Complexity: O(n), where n is the number of elements in the input vector. We use a stack to store the intermediate results.

-- Akhil Tej 
*/

