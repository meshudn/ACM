        struct Node *temp = head; 
        struct Node *trash, *last_head, *last_temp;
        
        int total = 0, length = k;
        vector<int> list;
        
        if(head != NULL){ 
            while(temp != NULL){
                if(k > 0){
                    list.push_back(temp->data);
                    trash = temp;
                    temp = temp->next;
                    last_head = temp;
                    delete trash;
                    k--;
                    total++;
                    continue;
                }
                total++;
                if(temp->next == NULL) last_temp = temp;
                temp = temp->next;
            }
            if(total == length){
                return head;
            }
            for(int i=0; i<list.size(); i++){
                last_temp->next = new Node(list[i]);
                last_temp = last_temp->next;
            }
            return last_head;
        }else{
            return head;
        }