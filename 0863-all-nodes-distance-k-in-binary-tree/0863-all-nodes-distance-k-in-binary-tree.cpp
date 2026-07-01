/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }

            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);
        unordered_map<TreeNode*, int> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=1;
        int dist=0;
        while(!q.empty()){
            if(dist==k) break;
            int size=q.size();
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left]=1;
                    q.push(node->left);
                }

                if(node->right && !vis[node->right]){
                    vis[node->right]=1;
                    q.push(node->right);
                }

                if(parent[node]&&!vis[parent[node]]){
                    vis[parent[node]]=1;
                    q.push(parent[node]);
                }
            }
            dist++;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};