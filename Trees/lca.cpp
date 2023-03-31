/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL){
        return NULL;
    }
    if(root->val==p->val || root->val==q->val){
        return root;
    }
    TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
    TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

    if(leftAns!=NULL and rightAns!=NULL){
        return root;
    }
    if(leftAns!=NULL and rightAns==NULL){
        return leftAns;
    }
    if(leftAns==NULL and rightAns!=NULL){
        return rightAns;
    }

    return NULL;
}