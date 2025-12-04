/*prints the post order traversal of the
tree */
void postOrder(int inL, int inR, int preL, int preR, vector <int> &pre, vector <int> &in)
{
    if(inL > inR || preL > preR) // Empty Subtree
        return;
    int k = inL; // keep k at the left extreme of inorder range to find root location
    while(k <= inR && in[k] != pre[preL])
        k++; // increment k till root is found
    int left = k - inL; // SIze of the left subtree
    // Now in the inorder : inL to k-1 is left subtree, k+1 to inR is right subtree
    // In the preorder : preL+1 to preL+left is left subtree, preL+left+1 to preR is the right subtree
    // Make the function calls according to the left and right subtree indices
    postOrder(inL, k-1, preL+1, preL+left, pre, in); // Call on the left subtree
    postOrder(k+1, inR, preL+left+1, preR, pre, in); // Call on the right subtree
    cout << pre[preL] << ' ';
}

void printPostOrder(vector<int>& in, vector<int>& pre) {
    // Your code here
    int n = in.size();
    postOrder(0, n-1, 0, n-1, pre, in);
    // return order;
}