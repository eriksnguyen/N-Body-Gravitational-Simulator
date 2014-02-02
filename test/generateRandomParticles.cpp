#include <sstream>
#include <fstream>
#include <cstdlib>

int main(){
	std::ostream output{"large-number-of-particles.txt"};
	output << 1024 << "\n";
	for(int i = 0; i < 1024; ++i){
		for(int j = 0; j < 3; j++){
			output << static_cast <float> (rand())/ static_cast<float>(RAND_MAX) * 20 - 10 << " ";
		}
		for(int j = 0; j < 3; j++){
			output << static_cast <float> (rand())/ static_cast<float>(RAND_MAX) * 2 - 1 << " ";
		}
		for(int j = 0; j < 3; ++j){
			output << 0.0 << " ";
		}
		output << 1.0 << "\n";
	}

	return 0;
}
