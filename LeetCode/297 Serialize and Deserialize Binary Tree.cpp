class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        TreeNode *tem;
        vector<string> vec;
        tem = root;
        if(root == NULL)
            return "null";
        
        data += to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserializeHelper(queue<string> &nodes)
    {
        if(nodes.size() == 0)
            return NULL;
        string node_begin = nodes.front();
        cout<<node_begin<<" ";
        int x;
        nodes.pop();
        if(node_begin.compare("null") == 0)
            return NULL;
        
        x = stoi(node_begin);
        
        TreeNode *tem = new TreeNode(x);
        tem->left = deserializeHelper(nodes);
        tem->right = deserializeHelper(nodes);
        
        return tem;
    }
    
    vector<string> break_tokens(string data)
    {
        vector<string> vec;
        string tem;
        int i=0;
        while(i < data.length())
        {            
            if(data[i] == ',')
            {
                vec.push_back(tem);
                tem.clear();
            }
            else
                tem += data[i];
            i++;
        }
        return vec;
    }
    
    TreeNode* deserialize(string data) {
        TreeNode *root, *tem;
        queue<string> nodes;
        vector<string> vec = break_tokens(data);
        for(int i=0; i<vec.size(); i++)
            nodes.push(vec[i]);
        return deserializeHelper(nodes);
    }
};
