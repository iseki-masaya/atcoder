#include <iostream>
 
int main(int argc, const char * argv[])
{
    int num;
    std::cin >> num;
    int list[2][num];
    int sum = 0;
    
    for (int i=0 ; i<num ;i++){
        std::cin >> list[0][i];
        std::cin >> list[1][i];
        sum += list[0][i]*list[1][i];
    }
 
    sum = sum*1.05;
    std::cout << sum << std::endl;
    return 0;
}