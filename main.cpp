#include <iostream>
#include <cmath>

int encrypt_caesar(std::string text1, int offset1) {
    std::string str;
    for (int i = 0; i < text1.length(); i++) {
        if (offset1 < 0 && text1[i] >= 'a' && text1[i] <= 'z') {
            str = ((text1[i] - 'a') + 26 + offset1) % 26 + 'a';
            std::cout << str;
        } else if (text1[i] >= 'a' && text1[i] <= 'z') {
            str = ((text1[i] - 'a') + offset1) % 26 + 'a';
            std::cout << str;
        } else if (text1[i] >= 'A' && text1[i] <= 'Z') {
            str = ((((text1[i]) - 'A') + offset1) % 26) + 'A';
            std::cout << str;
        } else std::cout << ' ';
    }
    return 0;
}

int decrypt_caesar (std::string text1, int offset1){
    return encrypt_caesar(text1, offset1);
}

int main() {
    std::cout << "Caesar's cipher" << std::endl << std::endl;

    int offset;
    int count = 0;
    std::string text;

    std::cout << "Enter the text you want to encrypt: " << std::endl;
    std::getline(std::cin, text);

    std::cout << "How many characters to shift?";
    std::cin >> offset;

    while (offset == 0) {
        count += 1;
        std::cout << count;
        std::cout << "You entered an invalid value" << std::endl;
        std::cout << "How many characters to shift?" << std::endl;
        std::cin >> offset;

        if (count > 10) break;
    }

    encrypt_caesar(text, offset);
    std::cout << std::endl;
    decrypt_caesar(text, offset);

    return 0;
}