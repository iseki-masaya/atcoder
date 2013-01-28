#include<iostream>
#include<vector>
 
int main(){
	int N,max_correct,min_correct;
    std::vector <int> count(4);
    std::cin >> N;
	char c[100];
	for(int i = 0; i < N ;++i){
        std::cin >> c[i];
		switch(c[i]){
            case '1':
                ++count[0];
                break;
            case '2':
                ++count[1];
                break;
            case '3':
                ++count[2];
                break;
            case '4':
                ++count[3];
                break;
		}
	}
    
    max_correct = min_correct = count[0];
    for (int i=0; i<4; i++) {
        if (max_correct<count[i]) 
            max_correct = count[i];
        if (min_correct>count[i]) 
            min_correct = count[i];
    }
 
    std::cout << max_correct << ' ' << min_correct << '\n';
    
return 0;
}