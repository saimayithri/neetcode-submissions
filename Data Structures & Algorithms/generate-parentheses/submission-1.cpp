class Solution {
public:
    void backtrack(int&n, int opencount, int closedcount,  vector<string>&result, string & current){
        if(opencount+closedcount==2*n)
        {
            result.push_back(current);return;

        }

        if(opencount<n){
            current.push_back('(');
            opencount++;
            backtrack(n,opencount,closedcount,result,current);
            opencount--; current.pop_back();
        }
        if(closedcount<opencount){
            current.push_back(')');
            closedcount++;
            backtrack(n,opencount,closedcount,result,current);
            closedcount--; current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result; string current="";
        backtrack(n,0,0,result,current);
        return result;

        
    }
};
