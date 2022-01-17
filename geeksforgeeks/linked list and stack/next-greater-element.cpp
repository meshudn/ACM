 vector< long long > result;
        stack< long long > list;
        bool isFound = false;
        int j;
        long long high_number = -2;
        
        for(int i=0; i<n-1; i++){
            if(!list.empty()){
                high_number = (long long) list.top();
            }
            if(arr[i] < arr[i+1]){
                result.push_back(arr[i+1]);
            }
            else if(arr[i] < high_number){
                result.push_back(high_number);
            }
            else{
                isFound = false;
                j = i+2;
                while(j < n){
                     if(arr[i] < arr[j]){
                        result.push_back(arr[j]);
                        list.push(arr[j]);
                        isFound = true;
                        break;
                    }
                    j++;
                }
                if(!isFound){
                      result.push_back(-1);
                }
            }
        } //outer loop
        
        result.push_back(-1);
        return result;