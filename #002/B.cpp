#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
 
int year,month,day;
 
void JudgeMonth()
{
  if(month == 12)
  {
    year++;month = 1;day = 1;
  }
  else
  {
    month++;day = 1;
  }
}
void JudgeDay(int LimitDay)
{
  if(day==LimitDay)
  {
    JudgeMonth();
  }
  else
  {
    day++;
  }
}
int main(int argc, const char * argv[])
{
  std::string Calender;std::cin >> Calender;
  year = atoi(Calender.substr(0,4).c_str());
  month = atoi(Calender.substr(5,7).c_str());
  day = atoi(Calender.substr(8,10).c_str());
  bool check = true ;
  while(check)
  {
    if(year%month)
      JudgeMonth();
    else if (year%(day*month))
    {
      switch (month)
      {
        case 4:case 6:case 9:case 11:
          JudgeDay(30);
          break;
        case 2:
          if(!(year%4))
          {
            if(!(year%100))
            {
              if(!(year%400))
                JudgeDay(29);
              else JudgeDay(28);
            }
            else 
              JudgeDay(29);
          }
          else
          {
            JudgeDay(28);
          }
          break;
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
          JudgeDay(31);
        break;
      }
    }
    else
    {
      break;
    }
  }
  if(day<10 && month<10)std::cout << year << "/0" << month << "/0" << day << '\n';
  else if (day<10)std::cout << year << "/" << month << "/0" << day << '\n';
  else if (month<10)std::cout << year << "/0" << month << "/" << day << '\n';
  else std::cout << year << "/" << month << "/" << day << '\n';std::cin >> year;return 0;
}