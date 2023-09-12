//
//  main.cpp
//  Calculator
//
//  Created by Vlad Ishchuk on 12.09.2023.
//

#include <iostream>

using namespace std;

int main() {
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
        default:
            // Невідома операція: виводимо повідомлення про помилку
            std::cout << "The specified operator is not valid" << std::endl;
            break;
    }

    // Виводимо результат
    cout << "The result is: " << result << std::endl;
    return 0;
}
