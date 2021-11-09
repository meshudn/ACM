#include <iterator>
#include <map>
 
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    map <int,int> hash;
    map<int,int>::iterator itr;
    int n = A.size();
    
    //making the hash table.
    for(int i=0; i<n; i++){
        hash.insert(pair<int, int>(A[i], 0));    
    }
    for(int i=0; i<n; i++){
            hash[A[i]] = hash[A[i]] + 1;    
    }

    for (itr = hash.begin(); itr != hash.end(); itr++) {
        if(itr->second == 1){
            return itr->first;
        }
    }
    return 0;

}
