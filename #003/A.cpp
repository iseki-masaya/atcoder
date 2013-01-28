#include <iostream>
 
int main(int argc, const char * argv[])
{
    double num_of_unit;
    char evaluation_of_unit[100];
    double sum_of_evaluation = 0;
    double GPA = 0;
    
    std::cin >> num_of_unit;
    for (int i=0; i<num_of_unit; i++) {
        std::cin >> evaluation_of_unit[i];
        switch (evaluation_of_unit[i]) {
            case 'A' : 
                sum_of_evaluation += 4.0;
                break;
            case 'B':
                sum_of_evaluation += 3.0;
                break;
            case 'C':
                sum_of_evaluation += 2.0;
                break;
            case 'D':
                sum_of_evaluation += 1.0;
                break;
            case 'F':
                sum_of_evaluation += 0;
                break;
        }
    }
    
    GPA =  sum_of_evaluation/num_of_unit;
    
    std::cout.precision(10);
    std::cout << GPA << '\n';
    return 0;
}