// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        vector<string> temp;
        string str = "";
        
        for(int i=0; i<S.length(); i++){
            
            if(S[i] == '.'){
                if(!temp.empty())
                    str += S[i];
                temp.push_back(str);
                str = "";
            }
            else{
                str += S[i];
            }
        }
        if(!temp.empty())
           str += '.';
        temp.push_back(str);
    
        reverse(temp.begin(), temp.end());
        
        string result;
        for(int i=0;i<temp.size();i++){
            result += temp[i];
        }
        return result;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends
