#include <iostream>
 
int main(int argc, const char * argv[])
{
    int E[6];
    int B;
    int L[6];
    bool bonus = false;
    int count = 0;
    
    for (int i=0; i<6; i++) {
        std::cin >> E[i];
    }
    std::cin >> B;
    for (int i=0; i<6; i++) {
        std::cin >> L[i];
    }
 
    for (int i=0; i<6; i++) {
        if (L[i] == B) 
            bonus = true;
        for (int j=0; j<6; j++) {
            if (E[i]<L[j]) 
                break;
            if (E[i] == L[j]) 
                count++;
        }
    }
    
    switch (count) {
        case 6:
            std::cout << "1\n";
            break;
            
        case 5:
            if (bonus) {
                std::cout << "2\n";
            } else {
                std::cout << "3\n";
            }
            break;
            
        case 4:
            std::cout << "4\n";
            break;
            
        case 3:
            std::cout << "5\n";
            break;
            
        default:
            std::cout << "0\n";
            break;
    }
 
    return 0;
}