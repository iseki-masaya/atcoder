#include <iostream>
 
int main(int argc, const char * argv[])
{
    int num_of_box;
    int count = 0;
    int weight_of_box;
    int stack[50];
    
    std::cin >> num_of_box;
    
    for (int i = 0; i < num_of_box; i++)
    {
        std::cin >> weight_of_box;
        if (!count) {
            stack[count] = weight_of_box;
            count++;
        }
        else 
        {
            if (weight_of_box > stack[count - 1]) 
            {
                stack[count] = weight_of_box;
                count++;
            }
            else
            {
                for (int j = 0; j < count ; j++) 
                {
                    if (weight_of_box <= stack[j]) 
                    {
                        stack[j] = weight_of_box;
                        break;
                    } 
                }
            }
        }
    }
    
    std::cout << count << '\n';
    return 0;
}