//
//  main.cpp
//  Calculator
//
//  Created by Vlad Ishchuk on 12.09.2023.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        // Оголошуємо зміні
        double first_number, second_number;
        char operation;
        double result = 0;

        // Запитуємо дані користувача
        cout << "Enter first number: ";
        cin >> first_number;
        cout << "Enter second number: ";
        cin >> second_number;
        cout << "Choose operation: ";
        cin >> operation;
        
        switch (operation) {
            case 43:
                // Додавання: виконуємо операцію додавання між першим і другим числами
                result = first_number + second_number;
                break;
            case 45:
                // Віднімання: виконуємо операцію віднімання першого числа від другого
                result = first_number - second_number;
                break;
            case 42:
                // Множення: виконуємо операцію множення першого і другого чисел
                result = first_number * second_number;
                break;
            case 47:
                // Ділення: виконуємо операцію ділення першого числа на друге
                result = first_number / second_number;
                break;
            case 'r':
                // Знаходження квадратних коренів
                if (first_number > 0) {
                    first_number = sqrt(first_number);
                } else {
                    first_number = sqrt(-first_number);
                }
                
                if (second_number > 0) {
                    second_number = sqrt(second_number);
                } else {
                    second_number = sqrt(-second_number);
                }
                
                std::cout << "\nThe root of first number is: " << first_number << std::endl << "The root of second number is: " << second_number << std::endl;
                
                return 0;
                break;
            case '^':
                // Знаходження чисел піднесених до степеня
                int exponent;
                cout << "\nRaise to: ";
                cin >> exponent;
                
                if (exponent < 0) {
                    first_number = std::pow(first_number, -exponent);
                    second_number = std::pow(second_number, -exponent);
                    
                    std::cout << "\nThe first result is: 1/" << first_number << std::endl << "The second number is: 1/" << second_number << std::endl;
                } else {
                    first_number = std::pow(first_number, exponent);
                    second_number = std::pow(second_number, exponent);
                    
                    std::cout << "\nThe first result is: " << first_number << std::endl << "The second number is: " << second_number << std::endl;
                }
                return 0;
                break;
            default:
                // Невідома операція: виводимо повідомлення про помилку
                std::cout << "The specified operator is not valid." << std::endl;
                return 0;
                break;
        }

        // Виводимо результат
        cout << "The result is: " << result << std::endl;
        
        // Питаємо користувача, чи він бажає продовжити
        string continue_answer;
        std::cout << "Want to continue? (y/n): ";
        cin >> continue_answer;
        
        // Перевіряємо відповідь користувача
        if (continue_answer == "y" or continue_answer == "yes") {
            std::cout << std::endl;
        } else if (continue_answer == "n" or continue_answer == "no") {
            return 0;
        } else {
            std::cout << "The answer is not valid." << std::endl;
            return 0;
        }
    }
    
    return 0;
}
