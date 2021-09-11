// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        vector<int> position;
        bool found = false;
        long long sum = 0;
        int start = 0;
        int end = n-1;
        
        for(int i=0; i<n; i++){
            sum = 0;
            start = i;
            
            for(int j=i; j<n; j++){
                sum = sum + arr[j];
                if(sum == s){
                    end = j;
                    found = true;
                    position.push_back(start+1);
                    position.push_back(end+1);
                    break;
                }
                if(sum > s){
                    break;
                }
            }
            if(found == true)
               break;
        }
    
       if(found == false){
           position.clear();
           position.push_back(-1);
       }
        return position;
        
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
