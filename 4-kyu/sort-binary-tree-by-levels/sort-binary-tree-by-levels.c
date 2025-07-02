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