static void search(int t, int k, const int ls[], int length,
                   int start, int sum_so_far, int *best)
{
    // BASE CASE: we've chosen k towns
    if (k == 0) 
    {
        if (sum_so_far <= t && sum_so_far > *best)
            *best = sum_so_far;
        return;
    }
​
    // RECURSIVE CASE: try each remaining town as the next pick
    for (int i = start; i < length; i++) \
    {
        search(t, k - 1, ls, length, i + 1, sum_so_far + ls[i], best);
    }
}
​
int chooseBestSum(int t, int k, const int ls[], int length)
{
    int best = -1;
  
    search(t, k, ls, length, 0, 0, &best);
  
    return best;
}