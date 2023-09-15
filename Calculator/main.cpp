//
//  main.cpp
//  Calculator
//
//  Created by Vlad Ishchuk on 12.09.2023.
//

#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ofstream logfile;
    
    while (true) {
        // Оголошуємо зміні
        double first_number, second_number;
        char operation;
        double result = 0;
        
        // Запитуємо дані користувача
        cout << "Enter first number: ";
        cin >> first_number;
        cout << "Choose operation: ";
        cin >> operation;
        
        // Перевіряємо тип операції
        if (operation == '+' or operation == '-' or operation == '*' or
            operation == '/') {
            // Запитуємо друге число
            cout << "Enter second number: ";
            cin >> second_number;
            
            // Перебираємо тип операції
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
            }
        } else {
            // Перебираємо інші нетипові операції з числами
            switch (operation) {
                case 'r':
                    // Знаходження квадратних коренів
                    result = (first_number > 0) ? sqrt(first_number) : sqrt(-first_number);
                    break;
                case '^':
                    // Піднесення до степеня
                    int exponent;
                    cout << "Raise to: ";
                    cin >> exponent;
                    result = std::pow(first_number, exponent);
                    break;
                default:
                    // Невідома операція: виводимо повідомлення про помилку
                    std::cout << "The specified operator is not valid." << std::endl;
                    return 0;
                    break;
            }
        }
        
        // Виводимо результат
        cout << "The result is: " << result << std::endl;
        
        // Питаємо користувача, чи він бажає продовжити
        string continue_answer;
        std::cout << "Want to continue? (y/n): ";
        cin >> continue_answer;
        
        // Перевіряємо відповідь користувача
        if (continue_answer == "y" or continue_answer == "yes") {
            // Записуємо результати до файлу (оптимізація вийшла з чату)
            logfile.open(
                         "./log.txt",
                         std::ios_base::app); // Додаємо інфу в файл, замість перезапису
            if (!logfile) {
                cout << "File not created!";
            }
            
            logfile << result << "\n";
            logfile.close();
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
