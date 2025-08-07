int area_or_perimeter(int l , int w) 
{
  // code away..
  if (l != w)
  {
      return l + w + l + w;
  }
  else
  {
      return l * w;
  }
}