// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		   vector<string> temp;
		   int n = S.length();
		   permute(S, 0, n-1, temp);
		   sort(temp.begin(), temp.end());
		   return temp;
		}
	public:
	     void permute(string S, int l, int r, vector<string>& temp){
	         
	         // Base case
            if (l == r)
                temp.push_back(S);
            else
            {
                // Permutations made
                for (int i = l; i <= r; i++)
                {
         
                    // Swapping done
                    swap(S[l], S[i]);
         
                    // Recursion called
                    permute(S, l+1, r, temp);
         
                    //backtrack
                    swap(S[l], S[i]);
                }
            }
	     }
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
