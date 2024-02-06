#include <iostream>

struct fibvec {
    int zeros;
    int ones;
};

int main(void) {
    // >>> input
    int inputBuf[1024];
    int length = 0;

    int largestInput = -1;

    std::cin >> length;
    for (int i = 0; i < length; i++) {
        std::cin >> inputBuf[i];
        if (inputBuf[i] > largestInput) {
            largestInput = inputBuf[i];
        }
    }

    // >>> output
    struct fibvec fibonacci[1024];
    for (int i = 0; i <= largestInput; i++) {
        if (i == 0) {
            fibonacci[i].zeros = 1;
            fibonacci[i].ones = 0;
        }
        else if (i == 1) {
            fibonacci[i].zeros = 0;
            fibonacci[i].ones = 1;
        }
        else {
            fibonacci[i].zeros = fibonacci[i - 1].zeros + fibonacci[i - 2].zeros;
            fibonacci[i].ones  = fibonacci[i - 1].ones  + fibonacci[i - 2].ones;
        }
    }

    for (int i = 0; i < length; i++) {
        std::cout << fibonacci[inputBuf[i]].zeros << ' '
                  << fibonacci[inputBuf[i]].ones << std::endl;
    }
    return 0;
}

