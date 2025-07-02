#include <stddef.h>
#include <stdlib.h>

/* to help you solve the kata, a queue implementation has been
preloaded for you */

typedef struct Queue Queue;

// the queue elements are pointers

// creates a new queue
extern Queue *new_queue (void);
// returns the number of elements in the queue
extern size_t queue_size (const Queue *queue);
// adds an element at the back of the queue and returns the queue
extern Queue *queue_enqueue (Queue *queue, const void *data);
// removes the element at the front of the queue and returns it
extern void *queue_dequeue (Queue *queue);
// frees the queue, do not forget to call it !
extern void free_queue (Queue *queue);
/* ==================================================== */

typedef struct Tree {
	struct Tree *left, *right;
	int value;
} Tree;

int count_of_tree(const Tree *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
  
    return count_of_tree(tree->left) + count_of_tree(tree->right) + 1;
}

int *tree_by_levels (const Tree *tree, size_t *tree_size)
{
    
  if (tree == NULL)
  {
      *tree_size = 0;
      
      return NULL; 
  } 
  
  int n = count_of_tree(tree);
  int *result_array = (int *)malloc(n * sizeof(int));
    
  *tree_size = n;
  
  Queue *queue;
  queue = new_queue();
  
  queue_enqueue(queue, tree);
  
  int index = 0;
  Tree *current_node;
    
  while (queue_size(queue) > 0)
  {
      current_node = (Tree*)queue_dequeue(queue);
      result_array[index++] = current_node->value;
    
      if (current_node->left != NULL) 
      {
          queue_enqueue(queue, current_node->left);
      }
    
      if (current_node->right != NULL) 
      { 
          queue_enqueue(queue, current_node->right);
      }       
  }
    
   free_queue(queue);
   return result_array;
}
