#include "tasks.h"

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    do {
        ShowMenu();
        std::cin >> choice;
        switch (choice) {
        case 1: Task1(); break;
        case 2: Task2(); break;
        case 3: Task3(); break;
        case 4: Task4(); break;
        case 5: Task5(); break;
        case 6: Task6(); break;
        case 7: Task7(); break;
        case 8: Task8(); break;
        case 0: std::cout << "Выход из программы.\n"; break;
        default: std::cout << "Неверный выбор, попробуйте снова.\n"; break;
        }
    } while (choice != 0);

    return 0;
}
