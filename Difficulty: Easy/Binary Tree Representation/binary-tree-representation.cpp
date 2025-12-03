// User function Template for C++

/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution {
  public:
    void build_tree(int i, int n, node *root, vector <int> &v)
    {
        if(2*i+1 < n)
        {
            root->left = newNode(v[2*i+1]);;
            build_tree(2*i+1, n, root->left, v);
        }
        if(2*i+2 < n)
        {
            root->right = newNode(v[2*i+2]);;
            build_tree(2*i+2, n, root->right, v);
        }
    }
    
    void create_tree(node* root0, vector<int>& vec) {
        // Your code goes here
        int n = vec.size();
        build_tree(0, n, root0, vec);
    }
};