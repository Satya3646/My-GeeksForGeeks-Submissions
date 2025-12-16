/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class BSTiterator 
{
public :
    stack <Node*> stk;
    bool reverse;
    BSTiterator(Node* root, bool reverse)
    {
        this->reverse =reverse;
        pushAll(root);
    }

    int next()
    {
        Node* node = stk.top();
        stk.pop();
        if(reverse)
            pushAll(node->left);
        else
            pushAll(node->right);
        return node->data;
    }

    bool hasNext()
    {
        return !stk.empty();
    }

private :
    void pushAll(Node* root)
    {
        if(!root)
            return;
        while(root)
        {
            stk.push(root);
            if(reverse)
                root = root->right;
            else
                root = root->left;
        }
    }
};

class Solution {
  public:
    bool findTarget(Node *root, int k)
    {
        // your code here.
        BSTiterator l = BSTiterator(root, false); // left pointer of inorder(sorted).
        BSTiterator r = BSTiterator(root, true); // right pointer of inorder(sorted).
        int i = l.next(), j = r.next();
        while(i < j)
        {
            if(i + j == k)
                return true;
            if(i + j < k) // sum is too small so increment i.
                i = l.next();
            else // sum is too large so decrement j.
                j = r.next();
        }
        return false;
    }
};