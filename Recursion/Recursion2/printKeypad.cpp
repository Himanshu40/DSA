#include <iostream>
#include <string>

using namespace std;

void helper(int num, string output) {
    if (num == 0) {
        std::cout << output << std::endl;
        return;
    }

    string options[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string store = options[num % 10];

    for (int i = 0; i < store.size(); ++i) {
        helper(num / 10, store[i] + output);
    }
}

void printKeypad(int num){
    helper(num, "");
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}