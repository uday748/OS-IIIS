#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    try {
        if (op != '+' && op != '-' && op != '*' && op != '/')
            throw string("Invalid operator! Please use +, -, *, or /");

        if (op == '/' && num2 == 0)
            throw string("Division by zero is not allowed!");

        double result;
        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
        }

        cout << "Result: " << result << endl;
    }
    catch (string &err) {
        cout << "Error: " << err << endl;
    }

    cout << "Program ended successfully." << endl;
    return 0;
}

