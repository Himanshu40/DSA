#include <iostream>

int indicesNum(int *input, int size, int x, int *output) {
    if (size == 0) {
        return 0;
    }

    // output array size
    int ans = indicesNum(input + 1, size - 1, x, output);

    if (input[0] == x) {
        for (int i = ans - 1; i >= 0; --i) {
            output[i + 1] = output[i] + 1;
        }

        output[0] = 0;
        ans++;
    }
    else {
        for (int i = ans - 1; i >= 0; --i) {
            output[i] += 1;
        }
    }
    
    return ans;
}

int main() {
    int n;
    std::cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        std::cin >> input[i];
    }
    
    int x;
    
    std::cin >> x;
    
    int *output = new int[n];
    
    int size = indicesNum(input, n, x, output);
    for(int i = 0; i < size; i++) {
        std::cout << output[i] << " ";
    }
    
    delete [] input;
    delete [] output;

    return 0;
}
