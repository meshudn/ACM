class Solution {

public:
    vector<int> sortArray(vector<int> array) {
        vector<int> tempLeft, tempRight, leftList, rightList;
        
        if(array.size() <= 1){
            return array;
        }
        
        int mid = array.size() / 2;
        
        //copying 0-mid element
        tempLeft.assign(array.begin(), array.end()-mid);
        //copying mid-end element
        tempRight.assign(array.begin() + mid, array.end());
        
        leftList = sortArray(tempLeft);
        rightList = sortArray(tempRight);
        return merge(leftList, rightList);
    }
    
public:
    vector<int> merge(vector<int> leftList, vector<int> rightList){
        vector<int> jointList(leftList.size() + rightList.size());
        int leftCursor=0, rightCursor=0, jointListCursor=0;
        
        while(leftCursor < leftList.size() && rightCursor < rightList.size()){
            if(leftList[leftCursor] < rightList[rightCursor]){
                jointList[jointListCursor++] = leftList[leftCursor++];
            }
            else{
                jointList[jointListCursor++] = rightList[rightCursor++];
            }
        }
        while(leftCursor < leftList.size()){
            jointList[jointListCursor++] = leftList[leftCursor++];
        }
        while(rightCursor < rightList.size()){
           jointList[jointListCursor++] = rightList[rightCursor++];
        }
        return jointList;
    }
};
