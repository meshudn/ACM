// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> result;
    int counterArray[N] = {0};
    int k = A.size();
    int max_counter = 0;
    bool last_max_counter = false;
    for(int i=0; i<k; i++){
        //for the case: max_counter; change every index;
        if(A[i] == N+1){
            if(last_max_counter)continue;
            else
               last_max_counter = true;

            for(int j = 0; j<N; j++ ){
                counterArray[j] = max_counter;
            }
            continue;
        }
        //for normal cases:
        last_max_counter = false;
        counterArray[A[i]-1] = counterArray[A[i]-1]+1;
        if(counterArray[A[i]-1] >= max_counter){
            max_counter = counterArray[A[i]-1];
        }
    }
    result.assign(counterArray, counterArray+N);
    return result;
}
