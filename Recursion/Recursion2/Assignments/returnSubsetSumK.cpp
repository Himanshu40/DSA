#include <iostream>

using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k) {
    if (n == 0) {
        if (k == 0) {
        	output[0][0] = 0;
            return 1;
        }
        else {
        	return 0;    
        }
    }
    
    int o1[100000][50],o2[100000][50];
    int smallOutput1 = subsetSumToK(input + 1, n - 1, o1, k - input[0]);
    int smallOutput2 = subsetSumToK(input + 1, n - 1, o2, k);
    
    for(int i=0;i<smallOutput1;i++)
    {
        output[i][0]=o1[i][0]+1;
        for(int j=1;j<=o1[i][0];j++)
        {
            output[i][j+1]=o1[i][j];
        }
        output[i][1]=input[0];
    }
    for(int i=0;i<smallOutput2;i++)
    {
        for(int j=0;j<=o2[i][0];j++)
            output[smallOutput1+i][j]=o2[i][j];
    }
    
    int smallOutputSize = smallOutput1 + smallOutput2;
    
    return smallOutputSize;
}

int main() {
    int input[20],length, output[10000][50], k;
    
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];

    cin >> k;
    
    int size = subsetSumToK(input, length, output, k);

    for( int i = 0; i < size; i++) { 
        for( int j = 1; j <= output[i][0]; j++) { 
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
