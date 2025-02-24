#include <iostream>
#include "../../iaAi/iaMath/iaLinearAlgebra/iaVector/iaVector.hpp" // Подключаем твой шаблонный класс

// Функция тестирования iaVector<T>
template <typename T>
void testVector(const std::string& typeName) {
    std::cout << "=== Тестирование iaVector<" << typeName << "> ===\n";

    // Создание вектора
    iaVector<T> vec(5);
    
    // Заполнение значениями
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = static_cast<T>(i * 2 + 1);
    }

    // Вывод вектора
    std::cout << "Вектор: ";
    vec.print();
    std::cout << "Сумма элементов: " << vec.sum() << "\n";
    std::cout << "Максимальный элемент: " << vec.maxElement() << "\n";
    std::cout << "Минимальный элемент: " << vec.minElement() << "\n\n";
}

int main() {
    // Тестирование на типе int
    testVector<int>("int");

    // Тестирование на типе double
    testVector<double>("double");

    // Тестирование на векторе векторов (iaVector<int>)
    std::cout << "=== Тестирование iaVector<iaVector<int>> ===\n";
    iaVector<iaVector<int>> vecVec(3);
    for (int i = 0; i < vecVec.size(); ++i) {
        vecVec[i] = iaVector<int>(3); // Вектор из трех элементов
        for (int j = 0; j < vecVec[i].size(); ++j) {
            vecVec[i][j] = (i + 1) * (j + 1); // Заполнение значениями
        }
    }

    // Вывод результата
    for (int i = 0; i < vecVec.size(); ++i) {
        std::cout << "Вектор " << i + 1 << ": ";
        vecVec[i].print();
    }

    return 0;
}
