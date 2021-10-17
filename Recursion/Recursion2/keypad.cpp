#include <iostream>
#include <string>

using namespace std;

string helper(int num) {
    string store;
    
    switch (num) {
        case 2: store = "abc";
            	break;
        case 3: store = "def";
            	break;
        case 4: store = "ghi";
            	break;
        case 5: store = "jkl";
            	break;
        case 6: store = "mno";
            	break;
        case 7: store = "pqrs";
            	break;
        case 8: store = "tuv";
            	break;
        case 9: store = "wxyz";
            	break;
        default: store = " ";
    }
    
    return store;
}

int keypad(int num, string output[]){
    if (num == 0) {
        output[0] = "";
        return 1;
    }
    
    int remainder = num % 10;
    num = num / 10;
    
    int smallNumStringSize = keypad(num, output);
    string smallNumString = helper(remainder);

    for (int i = 0; i < smallNumString.size() - 1; ++i) {
        for (int j = 0; j < smallNumStringSize; ++j) {
            output[j + (i + 1) * smallNumStringSize] = output[j];
        }
    }

    int k = 0;
    for (int i = 0; i < smallNumString.size(); ++i) {
        for (int j = 0; j < smallNumStringSize; ++j) {
            output[k++] += smallNumString[i];
        }
    }

    return smallNumStringSize * smallNumString.size();
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    
    return 0;
}
