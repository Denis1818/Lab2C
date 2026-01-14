#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
#include <vector>
#include <locale>

// ---------- Задание 1 ----------
void Task1() {
    int n;
    do {
        std::cout << "Задание 1: Введите количество элементов, кратное 3: ";
        std::cin >> n;
    } while (n <= 0 || n % 3 != 0);

    std::list<int> L;
    std::cout << "Введите элементы списка: ";
    for (int i = 0; i < n; ++i) {
        int x; std::cin >> x;
        L.push_back(x);
    }

    int third = n / 3;
    auto it = L.begin();
    std::cout << "Первая треть: ";
    for (int i = 0; i < third; ++i, ++it) std::cout << *it << " ";

    std::cout << "\nВторая треть в обратном порядке: ";
    auto rit = std::next(L.rbegin(), third);
    for (int i = 0; i < third; ++i, ++rit) std::cout << *rit << " ";

    std::cout << "\nПоследняя треть в обратном порядке: ";
    rit = L.rbegin();
    for (int i = 0; i < third; ++i, ++rit) std::cout << *rit << " ";
    std::cout << "\n\n";
}

// ---------- Задание 2 ----------
void Task2() {
    int n;
    do {
        std::cout << "Задание 2: Введите четное количество элементов дека: ";
        std::cin >> n;
    } while (n <= 0 || n % 2 != 0);

    std::deque<int> D(n);
    std::cout << "Введите элементы дека: ";
    for (int i = 0; i < n; ++i) std::cin >> D[i];

    auto it = D.begin() + n / 2;
    for (int i = 0; i < n / 2; ++i) it = D.insert(--it, -1);

    std::cout << "Результирующий дек: ";
    for (int x : D) std::cout << x << " ";
    std::cout << "\n\n";
}

// ---------- Задание 3 ----------
void Task3() {
    int m;
    std::cout << "Задание 3: Введите количество элементов списка L: ";
    std::cin >> m;
    std::list<int> L;
    std::cout << "Введите элементы списка: ";
    for (int i = 0; i < m; ++i) { int x; std::cin >> x; L.push_back(x); }

    int n;
    do {
        std::cout << "Введите четное количество элементов дека D: ";
        std::cin >> n;
    } while (n <= 0 || n % 2 != 0);

    std::deque<int> D(n);
    std::cout << "Введите элементы дека: ";
    for (int i = 0; i < n; ++i) std::cin >> D[i];

    L.insert(L.begin(), D.begin(), D.begin() + n / 2);
    D.erase(D.begin(), D.begin() + n / 2);

    std::cout << "Список L после вставки: ";
    for (int x : L) std::cout << x << " ";
    std::cout << "\n\n";
}

// ---------- Задание 4 ----------
void Task4() {
    std::string filename;
    std::cout << "Задание 4: Введите имя файла: ";
    std::cin >> filename;

    std::string s;
    std::cout << "Введите строку символов: ";
    std::cin >> s;

    std::ofstream out(filename);
    for (char c : s) out << int(c) * 2 << " ";
    out.close();

    std::cout << "Данные записаны в файл " << filename << "\n\n";
}

// ---------- Задание 5 (исправленное) ----------
void Task5() {
    int n;
    do {
        std::cout << "Задание 5: Введите четное количество элементов вектора V: ";
        std::cin >> n;
    } while (n <= 0 || n % 2 != 0);

    std::vector<int> V(n);
    std::cout << "Введите элементы вектора: ";
    for (int i = 0; i < n; ++i) std::cin >> V[i];

    std::cin.ignore(); // Очистка буфера
    std::list<int> L;
    std::cout << "Введите элементы списка L через пробел (Enter для окончания): ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int x;
    while (iss >> x) L.push_back(x);

    // Находим последний элемент списка, который есть в первой половине вектора
    auto it_last = L.end();
    for (auto it = L.begin(); it != L.end(); ++it) {
        if (std::find(V.begin(), V.begin() + n / 2, *it) != V.begin() + n / 2) {
            it_last = it;
        }
    }

    if (it_last != L.end()) {
        L.insert(std::next(it_last), *it_last); // Дублируем после него
    }

    std::cout << "Список L после дублирования: ";
    for (int val : L) std::cout << val << " ";
    std::cout << "\n\n";
}

// ---------- Задание 6 ----------
void Task6() {
    int n;
    do {
        std::cout << "Задание 6: Введите четное количество элементов вектора V: ";
        std::cin >> n;
    } while (n <= 0 || n % 2 != 0);

    std::vector<int> V(n);
    std::cout << "Введите элементы вектора: ";
    for (int i = 0; i < n; ++i) std::cin >> V[i];

    auto it = std::remove(V.begin() + n / 2, V.end(), 0);
    V.erase(it, V.end());

    std::cout << "Вектор после удаления нулей во второй половине: ";
    for (int x : V) std::cout << x << " ";
    std::cout << "\n\n";
}

// ---------- Задание 7 ----------
void Task7() {
    int n;
    do {
        std::cout << "Задание 7: Введите четное количество элементов вектора V: ";
        std::cin >> n;
    } while (n <= 0 || n % 2 != 0);

    std::vector<int> V(n);
    std::cout << "Введите элементы вектора (первая половина уже отсортирована): ";
    for (int i = 0; i < n; ++i) std::cin >> V[i];

    std::sort(V.begin() + n / 2, V.end());
    std::inplace_merge(V.begin(), V.begin() + n / 2, V.end());

    std::cout << "Вектор после сортировки и слияния: ";
    for (int x : V) std::cout << x << " ";
    std::cout << "\n\n";
}

// ---------- Задание 8 ----------
void Task8() {
    int n;
    std::cout << "Задание 8: Введите количество слов в списке L: ";
    std::cin >> n;
    std::list<std::string> L;
    std::cout << "Введите слова: ";
    for (int i = 0; i < n; ++i) { std::string s; std::cin >> s; L.push_back(s); }

    std::deque<std::string> D;
    auto it1 = L.begin();
    auto it2 = std::next(it1);
    for (; it2 != L.end(); ++it1, ++it2) {
        D.push_back(std::string() + (*it1)[0] + (*it2).back());
    }

    std::cout << "Дек D: ";
    for (auto& s : D) std::cout << s << " ";
    std::cout << "\n\n";
}

// ---------- Меню ----------
void ShowMenu() {
    std::cout << "Выберите задание (1-8) или 0 для выхода:\n";
    std::cout << "Задание 1\n";
    std::cout << "Задание 2\n";
    std::cout << "Задание 3\n";
    std::cout << "Задание 4\n";
    std::cout << "Задание 5\n";
    std::cout << "Задание 6\n";
    std::cout << "Задание 7\n";
    std::cout << "Задание 8\n";
    std::cout << "Ваш выбор: ";
}


// ---------- Главная функция ----------
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
