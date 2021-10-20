#include <string>
#include <iostream>

using namespace std;

int returnPermutations(string input, string output[]){
   	if (input.empty()) {
		output[0] = input[0];
		return 1;
	}

	int index = 0;
	for (int i = 0; i < input.size(); ++i) {
		string smallOutput[1000];
		int count = returnPermutations(input.substr(0, i) + input.substr(i + 1), smallOutput);
		
		for (int j = 0; j < count; ++j) {
			output[index++] = input[i] + smallOutput[j];
		}
	}

	return index;
}

int main(){
    string input;
    cin >> input;
    
	string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    
	return 0;
}
