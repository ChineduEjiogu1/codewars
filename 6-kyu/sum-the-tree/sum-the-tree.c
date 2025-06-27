#include <stddef.h>
​
struct node
{
  int value;
  struct node* left;
  struct node* right;
};
​
​
int sumTheTreeValues(struct node* root)
{
  // place your code here
  
  if (root == NULL) return 0;
  
  return root->value + sumTheTreeValues(root->left) + sumTheTreeValues(root->right);
}