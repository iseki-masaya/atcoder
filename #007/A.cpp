#include <iostream>
#include <string>
#include <vector>
 
int main(int argc, const char * argv[])
{
    char breakKey;
    std::string inputWord;
    std::cin >> breakKey;
    std::cin >> inputWord;
    
    for(int i=0;i<inputWord.length();i++){
        if (inputWord[i] != breakKey)
            std::cout << inputWord[i];
    }
    std::cout << "\n";
    return 0;
}