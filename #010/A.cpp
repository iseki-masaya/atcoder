#include <iostream>
 
int main(int argc, const char * argv[])
{
	// insert code here...
	int N,M,A,B;
	std::cin >> N;
	std::cin >> M;
	std::cin >> A;
	std::cin >> B;
	int C[M];
	for (int i=0; i<M; i++) {
		std::cin >> C[i];
	}
	
	for (int i=0; i<M; i++) {
		//Add cards
		if(N<=A){
			N += B;
		}
		
		//use cards
		N -= C[i];
		
		//check the mount of cards
		if(N<0){
			std::cout << i+1 << std::endl;
			return 0;
		}
	}
	
	std::cout << "complete" << std::endl;
//	
//	std::cout << N << " ";
//	std::cout << M << " ";
//	std::cout << A << " ";
//	std::cout << B << std::endl;
//	for (int i=0; i<M; i++) {
//		std::cout << C[i] << std::endl;
//	}
    return 0;
}
