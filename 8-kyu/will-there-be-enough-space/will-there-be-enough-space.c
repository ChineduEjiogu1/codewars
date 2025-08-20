int enough(int cap, int on, int wait)
{
//Your code goes here
  
    // int cant_fit = 0;
    
    if (wait + on > cap)
    {
        return ((wait + on) - cap);
    }
    else
    {
        return 0;
    } 
}