/*#include <iostream>
#include <string>
#include <sstream>

int main() {
    int number1, number2;
    std::string input;

    std::cout << "������� ��� ����� ����� ����� ������: ";

    while (true) {
        std::getline(std::cin, input); // ��������� ��� ������

        std::stringstream ss(input);
        if (ss >> number1 >> number2) { // �������� ������� ��� �����
            if (ss.eof()) { // ���������, ��� ����� ����� ��� ������ ��������
                break; // ���� �������, ������� �� �����
            }
        }

        std::cout << "������: ������� ������������ ������. ���������� ��� ���: ";
    }

    std::cout << "�� ����� �����: " << number1 << " � " << number2 << std::endl;
    return 0;
}*/
/*
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

// ��������� ����� ����������
class InputException : public std::runtime_error {
public:
    InputException(const std::string& message) : std::runtime_error(message) {}
};

class InputHandler {
public:
    static void getTwoIntegers(int& num1, int& num2) {
        while (true) {
            try {
                std::string input;
                std::cout << "������� ��� ����� ����� ����� ������: ";
                std::getline(std::cin, input);
                std::stringstream ss(input);

                if (!(ss >> num1 >> num2) || !ss.eof()) {
                    throw InputException("������: ������� ������������ ������. ����������, ���������� �����.");
                }

                // ���� ���� ���������, ������� �� �����
                return;

            }
            catch (const InputException& e) {
                // ��������� ����������
                std::cout << e.what() << std::endl;
            }
        }
    }
};

int main() {
    int number1, number2;

    InputHandler::getTwoIntegers(number1, number2);
    std::cout << "�� ����� �����: " << number1 << " � " << number2 << std::endl;

    return 0;
}

*/
/*#include <stdio.h> 
#include <time.h> 

int main() {
    clock_t start = clock();
    int n = 1;
    for (int i = 0; i < 1000000000; i++) {
        for (int j = 0; j < 2; j++) {
            n = i;
        }
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
}*/
#include <iostream>
#include <chrono>
int main() {
    auto begin = std::chrono::steady_clock::now();
    int n = 1;
    for (int i = 0; i < 2000000000; i++) {
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration<double>(end - begin);
        if (elapsed_ms.count() > 2) {
            std::cout << "The time: " << elapsed_ms.count() << " ms\n";
            begin = std::chrono::steady_clock::now();
        }
    }
}