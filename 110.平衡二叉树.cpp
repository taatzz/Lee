#include <iostream>

using namespace std;

typedef struct node
{
    int val;

    node* left;
    node* right;
}node;

int height(node* root)
{
    if(!root)
        return 0;

    int left = height(root->left) + 1;
    int right = height(root->right) + 1;

    return max(left, right);
}

bool if_binary_tree(node* root)
{
    int left = height(root->left);
    int right = height(root->right);
    if(left - right  > 1 || right - left > 1)
        return false;
    
    return if_binary_tree(root->left) && if_binary_tree(root->right);
}

int main()
{


    return 0;
}