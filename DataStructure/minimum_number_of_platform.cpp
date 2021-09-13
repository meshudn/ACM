// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	multiset<pair<int, char>> train;
    	 for (int i = 0; i < n; i++) {
            train.insert(make_pair(arr[i], 'a'));
            train.insert(make_pair(dep[i], 'd'));
        }
        
        int result = 0;
        int plat_needed = 0;
        
        for(auto it : train){
            if(it.second == 'a'){
                plat_needed++;
            }else{
                plat_needed--;
            }
            
            if(plat_needed > result){
                result = plat_needed;
            }
        }
        return result;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
