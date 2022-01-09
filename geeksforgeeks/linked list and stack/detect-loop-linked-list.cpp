
        struct Node *temp = head;
        
        map<Node*, int> visitedList;
        
        while(temp != NULL){
              if(visitedList[temp] == 1){
                  return true;
              }
              visitedList[temp] = 1;
              temp = temp->next;
        }
        return false;
    }
