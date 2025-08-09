 #include <stddef.h>
​
enum membership {OPEN = 1, SENIOR = 2};
​
void open_or_senior (size_t n, const int members[n][2], enum membership memberships[n])
{
// write to the memberships[] array
  
  int senior = 55;
  int handicap = 7;
  
  for (size_t i = 0; i < n; i++)
  {
      if (members[i][0] >= senior && members[i][1] > handicap)
      {
          memberships[i] = SENIOR;
      }
      else if (members[i][0] < senior)
      {
          memberships[i] = OPEN;
      }
      else
      {
          memberships[i] = OPEN;
      }
  }
}