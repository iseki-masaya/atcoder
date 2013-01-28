#include <iostream>
#include <string>
#include <vector>
 
int main(int argc, const char * argv[])
{
    int N;
    int count=0;
    std::cin >> N;
    std::vector <std::string> str;
    str.resize(N);
    
    for (int i=0; i<N; i++) {
        std::cin >> str[i];
        if (i == N-1) {
            str[i].erase(str[i].length()-1);
        }
        
        if (!(str[i].compare("TAKAHASHIKUN")))
            count++;
        if (!(str[i].compare("Takahashikun")))
            count++;
        if (!(str[i].compare("takahashikun")))
            count++;
    }
    
    std::cout << count << '\n';
    
    return 0;
}