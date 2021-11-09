#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    sort(A.begin(), A.end());
    bool all_negative = false;
    int all_sorted = 0;

    if(n == 1){
        if(A[0] <= 0)return 1;
        else{
            return (A[0]+1);
        }
    }
    for(int i =0 ; i<n-1; i++){
        if(A[i] < 0 || A[i+1] < 0){
            all_negative = true;
            continue;
        }
        else if(A[i+1] - A[i] == 1 || A[i+1] - A[i] == 0 ){
            all_negative = false;
            ++all_sorted;
            continue;

        }else if(A[i+1] - A[i] > 1){
           return (++A[i]);
        }
    }
    if(all_sorted > 1){
        return A[n-1]+1;
    }
    else if(all_negative && A[n-1] <= 0)
       return 1;
    else{
       return 1;  
    }

   
}
