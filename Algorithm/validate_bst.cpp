    stack<TreeNode*> stk, lower_limit, upper_limit;
    
    void update(TreeNode* root, TreeNode* low, TreeNode* high){
        stk.push(root);
        lower_limit.push(low);
        upper_limit.push(high);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* low = nullptr;
        TreeNode* high = nullptr;
        update(root, low, high);
        
        while(!stk.empty()){
            root = stk.top();
            stk.pop();
           
            low = lower_limit.top();
            lower_limit.pop();
            
            high = upper_limit.top();
            upper_limit.pop();
            
            if(root == nullptr){
                continue;
            }
            
            TreeNode* val_node = root;
            if(low != nullptr and val_node->val <= low->val){
                return false;
            }
            if(high != nullptr and val_node->val >= high->val){
                return false;
            }
            update(root->right, val_node, high);
            update(root->left, low, val_node);
        }
        return true;
    }
