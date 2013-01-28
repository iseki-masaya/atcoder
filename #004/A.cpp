#include <iostream>
#include <vector>
#include <cmath>
 
struct point {
    int x;
    int y;
};
 
float calcDist(point current,point past)
{
    return sqrtf((current.x-past.x)*(current.x-past.x)+(current.y-past.y)*(current.y-past.y));
}
 
int main(int argc, const char * argv[])
{
    std::cout.precision(8);
    int N;
    float dist;
    float max_dist = 0;
    
    std::cin >> N;
    std::vector <point> v(N);
    
    for (int i=0; i<N; i++) {
        std::cin >> v[i].x;
        std::cin >> v[i].y;
    }
   
    for (int i = 0; i < N-1; i++) {
        for (int j = i; j <N; j++) {
            dist = calcDist(v[i], v[j]);
            if (dist > max_dist) 
                max_dist = dist;
        }
    }
    
    std::cout << max_dist << '\n';
 
    return 0;
}