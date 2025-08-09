int basic_op(char op, int value1, int value2) 
{
  if (op == '+')
  {
      return value1 + value2;
  }
  else if (op == '-')
  {
      return value1 - value2;
  }
  else if (op == '*')
  {
      return value1 * value2;
  }
  else if (op == '/' && value2 != 0)
  {
      return value1 / value2;
  }
  
  return 0;
}