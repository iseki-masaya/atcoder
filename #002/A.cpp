#include <iostream>
#include <vector>
 
int main(int argc, const char * argv[])
{
    int year;
    bool leapYear = false;
    std::cin >> year; 
    
    if (!(year%4))
        leapYear = true;
    if (!(year%100))
        leapYear = false;
    if (!(year%400))
        leapYear = true;
        
    if (leapYear){
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
    }
    return 0;
}