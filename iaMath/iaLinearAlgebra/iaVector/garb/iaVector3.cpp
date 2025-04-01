/*
 ****************************************************************************************************
 *
 *    Компания    : iA
 *    @file       : iaVector.cpp
 *    @brief      : Файл реализации класса iaVector.
 *    @author     : Александра Юшкевича
 *    @aka        : iA
 *    @project    : Все проекты iA. IA Projects
 *    @version    : 0.3.0 (Stable version - fully tested and optimized)
 *    @license    : MIT License
 *    @contact    : / alexff.2b@hotmail.com /
 *                   / alexff.2b@gmail.com   /
 *                   / alexff.2b@icloud.com  /
 *                   / alexff.2b@yandex.ru   /
 *    @tel        : Fr.+33658046456
 *                  rus. +79859751326
 *
 *    @created    : Октябрь 2021
 *    @modified   : Январь 2025
 *
 *    @note       : Изменения с предыдущей версии:
 *                  - Добавлены методы: sum(), dotProduct(const iaVector& otherVector),
 *                    angleBetween(const iaVector& otherVector) const noexcept,
 *                    sortAscending(), sortDescending(), maxElement() const,
 *                    minElement() const, avverage() const.
 *                  - Исправлены ошибки и улучшена документация для ясности и полноты.
 *
 *    @description: Этот файл содержит реализацию методов класса iaVector, который
 *                   предоставляет функциональность для работы с векторами.
 *
 *    @github      : https://github.com/alexff2b/Class-iaVector.git
                     https://github.com/alexff2b/Class-iaVector.git
 *
 *    @copyright    : Этот файл является частью проекта iA. Он лицензирован под MIT License.
 *                   Вы можете использовать, изменять и распространять этот код, при условии,
 *                   что Вы предоставите соответствующее упоминание автору.
 * **************************************************************************************************
 */

#include "iaVector.hpp"

iaVector::iaVector() {
    m = 0;
    value = nullptr;
}

iaVector::iaVector(int m) : m(m), value(m > 0 ? new double[m]() : nullptr) {
        for (int i = 0; i < m; i++) {
        value[i] = 0.0; // Инициализация значений вектора
    }
        }

iaVector::iaVector(int m, const double values[]) : m(m), value(nullptr) {
    if (m > 0) {
        value = new double[m](); // Выделение памяти для значений и инициализация нулями
        for (int i = 0; i < m; i++) {
            value[i] = values[i]; // Копирование значений из массива
        }
    }
}

iaVector::iaVector(const iaVector& otherVector) : m(otherVector.m), value(nullptr) {
//iaVector::iaVector(const iaVector& otherVector) {
    if (m > 0) {
        value = new double[m](); // Выделение памяти для значений
        for (int i = 0; i < m; i++) {
            value[i] = otherVector.value[i]; // Копирование значений
        }
    }
}

iaVector::~iaVector() {
    delete [] value; // Освобождение памяти
}

int iaVector::sizeOfVector() const {
    return m;
}

void iaVector::printVector() const {
    std::cout << "Vector size : " << m << std::endl;
    std::cout << "|";
    for (int j = 0; j < m; j++) {
//        std::cout << std::fixed << std::setprecision(2) << " " << value[j] << "|"; // Печать значений
        std::cout << std::fixed << std::setprecision(2) << " " << value[j] << "|"; // Печать значений
    }
        std::cout << std::endl;
}

double iaVector::sum() const {
    double sum = 0.0; // Переменная для хранения суммы
    for (int i = 0; i < this->m; i++) {
        sum += this->value[i]; // Суммируем элементы вектора
    }
    return sum; // Возвращаем сумму
}

double iaVector::L2norm() const {
    double sum = 0.0; // Переменная для хранения суммы квадратов
    for (int i = 0; i < this->m; i++) {
        sum += this->value[i] * this->value[i]; // Суммируем квадраты элементов
    }
    return sqrt(sum); // Возвращаем квадратный корень из суммы
}

double iaVector::L1norm() const {
    double sum = 0.0; // Переменная для хранения суммы абсолютных значений
    for (int i = 0; i < m; i++) {
        sum += abs(value[i]); // Суммируем абсолютные значения элементов
    }
    return sum; // Возвращаем сумму
}

double iaVector::LMnorm() const {
    double max = abs(value[0]); // Инициализируем максимальное значение первым элементом
    if (m > 0) {
        for (int i = 1; i < m; i++) { // Начинаем с 1, так как 0 уже учтён
            if (abs(value[i]) > max) {
                max = abs(value[i]); // Обновляем максимальное значение
            }
        }
    }
    return max; // Возвращаем максимальное значение
}

double iaVector::dotProduct(const iaVector &otherVector) const {
    iaVector vec1(this->m, this->value); // Копируем текущий вектор
    iaVector vec2(otherVector); // Копируем другой вектор
    iaVector tmpres(this->m); // Вектор для хранения результатов произведения
    double result = 0.0; // Переменная для хранения результата

    if (vec1.m != vec2.m) {
        throw std::runtime_error("Ошибка: Размеры векторов не совпадают."); // Выбрасываем исключение
    }

    tmpres = vec1 * vec2; // Используем оператор * для перемножения векторов
    result = tmpres.sum(); // Суммируем элементы результата
    return result; // Возвращаем результат скалярного произведения
}

double iaVector::angleBetween(const iaVector &otherVector) const noexcept {
        // Проверка на совпадение размеров векторов
    if (this->m != otherVector.m) {
        throw std::runtime_error("Ошибка: Размеры векторов не совпадают."); // Выбрасываем исключение
    }

    double dotProd = this->dotProduct(otherVector); // Скалярное произведение
    double l2vec1 = this->L2norm(); // Норма первого вектора
    double l2vec2 = otherVector.L2norm(); // Норма второго вектора

        // Вычисление косинуса угла
    double cosangle = dotProd / (l2vec1 * l2vec2);

        // Вычисление угла в радианах
    double angle = acos(cosangle);

    return angle; // Возвращаем угол
}

void iaVector::sortAscending() {
        // Проверка на пустой вектор
    if (this->m <= 0) {
        throw std::runtime_error("Ошибка: Вектор пуст."); // Выбрасываем исключение
        return; // Ничего не делаем, если вектор пустой
    }

    double tmp = 0.0;
    for (int i = 0; i < this->m; i++) {
        for (int j = 0; j < this->m - 1 - i; j++) { // Исправлено на j
            if (this->value[j] > this->value[j + 1]) {
                    // Обмен значениями
                tmp = this->value[j];
                this->value[j] = this->value[j + 1];
                this->value[j + 1] = tmp;
            }
        }
    }
}

void iaVector::sortDescending() {
        // Проверка на пустой вектор
    if (this->m <= 0) {
        throw std::runtime_error("Ошибка: Вектор пуст."); // Выбрасываем исключение

        return; // Ничего не делаем, если вектор пустой
    }

    double tmp = 0.0;
    for (int i = 0; i < this->m; i++) {
        for (int j = 0; j < this->m - 1 - i; j++) { // Исправлено на j
            if (this->value[j] < this->value[j + 1]) {
                    // Обмен значениями
                tmp = this->value[j];
                this->value[j] = this->value[j + 1];
                this->value[j + 1] = tmp;
            }
        }
    }
}

double iaVector::maxElement() const {
    if (this->m == 0) { // Проверка на пустой вектор
        throw std::runtime_error("Ошибка: Вектор пуст."); // Выбрасываем исключение
    }

    double max = this->value[0]; // Инициализация максимального элемента
    for (int i = 1; i < this->m; i++) { // Начинаем с первого элемента
        if (this->value[i] > max) { // Сравниваем с текущим максимальным
            max = this->value[i]; // Обновляем максимальный элемент
        }
    }
    return max; // Возвращаем максимальный элемент
}

double iaVector::minElement() const {
    if (this->m == 0) { // Проверка на пустой вектор
        throw std::runtime_error("Ошибка: Вектор пуст."); // Выбрасываем исключение
    }

    double min = this->value[0]; // Инициализация минимального элемента
    for (int i = 1; i < this->m; i++) { // Начинаем с первого элемента
        if (this->value[i] < min) { // Сравниваем с текущим минимальным
            min = this->value[i]; // Обновляем минимальный элемент
        }
    }
    return min; // Возвращаем минимальный элемент
}

double iaVector::avverage() const {
    double sum=this->value[0];
    int size = this->m;
    for (int i = 1; i < this->m; i++) {
        sum += this->value[i];
    }

    return sum / size;
}

iaVector& iaVector::operator=(const iaVector& otherVector) noexcept {
    if (this != &otherVector) { // Проверка на самоприсваивание
        this->m = otherVector.m; // Копирование размера
        for (int i = 0; i< otherVector.m; i++) {
            this->value[i] = otherVector.value[i];
        }
    }
    return *this; // Возврат текущего объекта
}

iaVector iaVector::operator+(const iaVector &otherVector) noexcept {
    iaVector result(otherVector.m);
    if (this->m != otherVector.m) {
        return 0; // Возврат 0, если размеры не совпадают
    } else {
        for (int j = 0; j < this->m; j++) {
            result.value[j] = this->value[j] + otherVector.value[j]; // Сложение соответствующих элементов
        }
    }
    return result;
}

iaVector iaVector::operator-(const iaVector &otherVector) noexcept {
    iaVector result(this->m);
    if (this->m == otherVector.m) {
        for (int i = 0; i < this->m; i++) {
            result.value[i] = this->value[i] - otherVector.value[i]; // Вычитание соответствующих элементов
        }
    }
    return result;
}

iaVector iaVector::operator*(const iaVector &otherVector) noexcept {
    iaVector result(this->m);
    if (this->m == otherVector.m) {
        for (int i = 0; i < this->m; i++) {
            result.value[i] = this->value[i] * otherVector.value[i]; // Умножение соответствующих элементов
        }
    }
    return result;
}

iaVector iaVector::operator*(double scal) {
    iaVector result(this->m);
    for (int i = 0; i < this->m; i++) {
        result.value[i] = this->value[i] * scal; // Умножение каждого элемента на скаляр
    }
    return result;
}

void iaVector::inverting() noexcept {
    int size = this->m;
    if (size == 0) {
        throw std::runtime_error("Ошибка: Вектор пуст."); // Выбрасываем исключение
    }
    int i = 0; // Индекс с начала вектора
    int j = size - 1; // Индекс с конца вектора
    do {
        double tmpvar = this->value[i]; // Сохраняем значение элемента с индексом i

        this->value[i] = this->value[j]; // Меняем местами элементы
        this->value[j] = tmpvar; // Восстанавливаем сохраненное значение
        i++; // Переходим к следующему элементу с начала
        j--; // Переходим к предыдущему элементу с конца
    } while (i < j); // Продолжаем, пока индексы не пересекутся
}

double& iaVector::operator[](int j) {
    if (j < 0 || j >= m) { // Проверка на выход за пределы
        throw std::out_of_range("Index out of bounds.");
    }
    return value[j]; // Возврат элемента
}

bool iaVector::operator==(const iaVector &otherVector) const noexcept {
    if (this->m != otherVector.m) return false; // Проверка на равенство размеров
    for (int i = 0; i < this->m; i++) {
        if (this->value[i] != otherVector.value[i]) {
            return false; // Если хотя бы одно значение не совпадает
        }
    }
    return true; // Векторы равны
}

bool iaVector::operator!=(const iaVector &otherVector) const noexcept {
    return !(*this == otherVector); // Используем оператор равенства
}

iaVector iaVector::operator||(const iaVector &otherVector) const noexcept {
    double norm = otherVector.L2norm();
        // Проверка на нулевую норму
    if (norm != 0) { // Включил проверку на нулевую норму
        std::cout << norm << std::endl;
        iaVector result(otherVector);

        for (int i = 0; i < this->m; i++) {
            std::cout << result.value[i] << std::endl;
            result.value[i] = result.value[i] / norm; // Деление каждого элемента на норму
            std::cout << result.value[i] << std::endl;
        }
        return result;
    } else {
            // Обработка случая, когда норма равна нулю
        std::cerr << "Ошибка: Норма равна нулю." << std::endl; // Вывод ошибки
        return iaVector(); // Возвращаем пустой вектор или можно выбросить исключение
    }

}