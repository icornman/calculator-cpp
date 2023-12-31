//
//  main.cpp
//  Calculator
//
//  Created by Vlad Ishchuk on 12.09.2023.
//

#include <cmath>
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

void log_to_file(double result) {
    // Відкриваємо файл для дозапису
    std::ofstream logfile("./log.txt", std::ios_base::app);
    
    // Перевіряємо, чи вдалося відкрити файл
    if (!logfile) {
        std::cout << "File not created!";
        return;
    }
    
    // Отримуємо поточний час (код з Stack Overflow)
    std::time_t curr_time = std::time(nullptr);
    std::tm* curr_tm = std::localtime(&curr_time);
    
    // Форматуємо дату та час
    char date_string[100];
    std::strftime(date_string, sizeof(date_string), "[%d.%m.%Y %T] ", curr_tm);
    
    // Записуємо результат у файл
    logfile << date_string << result << '\n';
    
    // Закриваємо файл
    logfile.close();
}

void clear_log() {
    // Очищаємо файл
    std::ofstream logfile("./log.txt");
    logfile << "";
    // Закриваємо файл
    logfile.close();
}

int main() {
    // Невеличкий туторіал для користувача
    std::cout << "A little information about the available operators and their designations.\n1. (+) - adding.\n2. (-) - subtraction.\n3. (*) - multiplication.\n4. (/) - division.\n5. (r) - get the square root of the number.\n6. (^) - raise a number to a power.\n\n";
    
    clear_log();
    
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
        
        // Виводимо результат і записуємо його до файлу
        cout << "The result is: " << result << std::endl;
        log_to_file(result);
        
        // Питаємо користувача, чи він бажає продовжити
        string continue_answer;
        std::cout << "Want to continue? (y/n): ";
        cin >> continue_answer;
        
        // Перевіряємо відповідь користувача
        if (continue_answer == "y" or continue_answer == "yes") {
            std::cout << std::endl;
        } else if (continue_answer == "n" or continue_answer == "no") {
            clear_log();
            return 0;
        } else {
            std::cout << "The answer is not valid." << std::endl;
            return 0;
        }
    }
}
