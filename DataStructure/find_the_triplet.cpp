// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    sort(arr, arr+n);
	    int count = 0;
	    
	    for(int i= n-1; i >=0; i--){
          int j=0;
          int k = i-1;
          
          while(j < k){
              if( j == k){
                  break;
              }
              
              if(arr[i] == arr[j]+arr[k]){
                  count++;
                  j = j + 1;
                  k = k - 1;
              }
              else if(arr[i] > arr[j] + arr[k]){
                  j = j + 1;
              }
              else{
                  k = k - 1;
              }
              
          }
        }
        
        return count;
	}
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends
