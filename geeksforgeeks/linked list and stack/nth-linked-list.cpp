struct Node* temp = head; 
    int count = 0;
    
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    temp = head;
    if(count < n){
        return -1;
    }
    for(int i=1; i<=count-n; i++){
        temp = temp->next;
    }
    return temp->data;