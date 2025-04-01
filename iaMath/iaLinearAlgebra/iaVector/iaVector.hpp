/*
****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaVector.hpp
 *    @brief      : Реализация шаблонного класса iaVector (Математический вектор).
 *    @author     : Александр Юшкевич
 *    @aka        : iA, alexff
 *    @project    : Все проекты CG. CG Research & Development(c) Projects
 *    @version    : 3.1.0 (Development) // Увеличена версия в связи с доработкой под комплексные числа
 *    @license    : Apache License 2.0
 *    @contact    : 
 *                  Email:  
 *                      - alexff.2b@hotmail.com  
 *                      - alexff.2b@gmail.com  
 *                      - alexff.2b@icloud.com  
 *                      - alexff.2b@yandex.ru  
 *                  Телефон:  
 *                      - Франция: +33 6 58 04 64 56  
 *                      - Россия:  +7 985 975 1326  
 *
 *    @created    : Октябрь 2021
 *    @modified   : Март 2025
 *    @released   : [Добавить дату релиза, если применимо]
 *
 *    @previous_version: 3.0.1 (Production)
 *
 *    @note       : Изменения с предыдущей версии:
 *                  - Класс стал шаблонным (`iaVector<T>`).
 *                  - Добавлена поддержка работы с разными типами данных (int, double, float и др.).
 *                  - Оптимизированы операции сложения, вычитания и умножения.
 *                  - Добавлены методы `begin()`, `end()` для совместимости с `std::vector`.
 *                  - Реализованы методы вычисления угла и расстояния между векторами.
 *                  - Улучшена документация и стиль кода.
 *                  - Ведется доработка для поддержки работы с комплексными числами (iaComplex).
 *                  - Некоторые функции еще не полностью протестированы с комплексными числами.
 *
 *    @description: 
 *                  Этот заголовочный файл содержит определение шаблонного класса `iaVector<T>`, предназначенного
 *                  для работы с математическими векторами. Поддерживает арифметические операции, вычисление 
 *                  математических характеристик, а также работу с итераторами.  
 *
 *                  Основные возможности класса:  
 *                    - Создание векторов с различными типами данных  
 *                    - Арифметические операции: сложение, вычитание, умножение на скаляр  
 *                    - Вычисление математических характеристик: норма, угол, расстояние  
 *                    - Итераторы для совместимости со стандартными контейнерами  
 *
 *    @applications:
 *                  Класс `iaVector` применяется в различных областях науки и техники, таких как:
 *                  - **Физика**: моделирование механических систем, векторные вычисления.
 *                  - **Компьютерная графика**: работа с 2D/3D-векторами, трансформации.
 *                  - **Машинное обучение**: операции с признаковыми пространствами.
 *                  - **Численные методы**: линейная алгебра, оптимизация.
 *                  - **Робототехника**: анализ движений, кинематика.
 *                  - **Инженерия**: проектирование и анализ механических систем.
 *                  - **География и картография**: работа с геопространственными данными.
 *                  - **Экономика**: векторизация данных для анализа и моделирования.
 *
 *    @tested_types:
 *                  Класс `iaVector` прошел тестирование на следующих типах данных:
 *                  - `int` – целочисленные данные
 *                  - `double` – числа с плавающей запятой двойной точности
 *                  - `iaVector<T>` – работа с векторами других типов (рекурсивная поддержка)
 *                  - `iaComplex` – комплексные числа (поддержка в разработке)
 *
 *    @methods    :
 *                   - iaVector(); // Конструктор по умолчанию
 *                   - iaVector(int m); // Конструктор с размером
 *                   - iaVector(int m, const T values[]); // Конструктор со значениями
 *                   - iaVector(const iaVector<T>& otherVector); // Конструктор копирования
 *                   - iaVector& operator=(const iaVector<T>& otherVector) noexcept; // Оператор присваивания
 *                   - ~iaVector(); // Деструктор
 *                   - int size() const; // Возвращает размер вектора
 *                   - void print(std::ostream& out = std::cout) const; // Вывод вектора
 *                   - T& operator[](int j); // Оператор доступа
 *                   - iaVector operator+(const iaVector<T>& otherVector) const; // Сложение
 *                   - iaVector operator-(const iaVector<T>& otherVector) const; // Вычитание
 *                   - iaVector operator*(T scalar) const; // Умножение на скаляр
 *                   - T dotProduct(const iaVector<T>& otherVector) const; // Скалярное произведение
 *                   - T L1norm() const; // Вычисление L1 нормы
 *                   - T L2norm() const; // Вычисление L2 нормы
 *                   - T sum() const; // Вычисление суммы элементов
 *                   - T maxElement() const; // Максимальный элемент
 *                   - T minElement() const; // Минимальный элемент
 *                   - bool isPalindrome() const; // Проверка, является ли вектор палиндромом
 *                   - double angleBetween(const iaVector<T>& otherVector) const noexcept; // Угол между векторами
 *                   - T distanceTo(const iaVector<T>& otherVector) const noexcept; // Расстояние между векторами
 *                   - void push_back(T value); // Добавить элемент в конец
 *                   - void pop_back(); // Удалить последний элемент
 *                   - T* begin(); // Итератор на начало
 *                   - T* end(); // Итератор на конец
 *
 *    @license    :
 *                  Этот файл лицензирован под Apache License 2.0.
 *                  Полный текст лицензии находится в файле LICENSE в корне проекта.
 *                  Официальный текст лицензии доступен по адресу:  
 *                  https://www.apache.org/licenses/LICENSE-2.0
 *
 *    @project_website: [Добавить ссылку на сайт проекта, когда он появится]
 *
 * **************************************************************************************************
 */
#ifndef IAVECTOR_HPP
#define IAVECTOR_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>
#include <type_traits>

/**
 * @brief Шаблонный класс вектора с базовыми операциями линейной алгебры.
 * @tparam T Тип элементов вектора.
 */
template <typename T>
class iaVector {
private:
    std::vector<T> data; ///< Внутреннее хранилище данных вектора.

public:
    /// @name Конструкторы и деструкторы
    /// @{
    
    /** @brief Конструктор по умолчанию. */
    iaVector() = default;

    /**
     * @brief Конструктор из массива данных.
     * @param n Размер вектора.
     * @param values Указатель на массив значений.
     */
    iaVector(size_t n, const T* values) : data(values, values + n) {}

    /**
     * @brief Конструктор инициализации нулями.
     * @param n Размер вектора.
     */
    explicit iaVector(size_t n) : data(n, T()) {}

    /**
     * @brief Конструктор инициализации списком.
     * @param list Список значений.
     */
    iaVector(std::initializer_list<T> list) : data(list) {}

    /** @brief Конструктор копирования. */
    iaVector(const iaVector<T>& other) = default;

    /** @brief Оператор присваивания копированием. */
    iaVector<T>& operator=(const iaVector<T>& other) = default;

    /** @brief Конструктор перемещения. */
    iaVector(iaVector<T>&& other) noexcept = default;

    /** @brief Оператор присваивания перемещением. */
    iaVector<T>& operator=(iaVector<T>&& other) noexcept = default;
    /** @brief Перегрузка оператора == (сравнение векторов). */
    bool operator==(const iaVector<T>& other) const {
        return data == other.data;
    }
    /** @brief Перегрузка оператора != (сравнение векторов). */
    bool operator!=(const iaVector<T>& other) const {
        return !(*this == other);
    }

    /** @brief Деструктор. */
    ~iaVector() = default;

    /// @}

    /** @brief Возвращает размер вектора. */
    size_t size() const { return data.size(); }

    bool empty() const {return data.size() == 0;}

    /** @brief Доступ к элементу по индексу. */
    T& operator[](size_t index) { return data.at(index); }

    /** @brief Доступ к элементу по индексу (константный). */
    const T& operator[](size_t index) const { return data.at(index); }

    /** @brief Вычисление суммы элементов. */
    template <typename U = T>
    typename std::enable_if<std::is_arithmetic<U>::value, U>::type sum() const {
        U total = 0;
        for (size_t i = 0; i < size(); i++) {
            total += data[i];
        }
        return total;
    }

    /** @brief Добавляет элемент в конец вектора. */
    void push_back(const T& value) { data.push_back(value); }

    /** @brief Удаляет последний элемент вектора. */
    void pop_back() { if (!data.empty()) data.pop_back(); }

    /** @brief Очищает содержимое вектора. */
    void clear() { data.clear(); }

    /**
     * @brief Перегрузка оператора + (покомпонентное сложение векторов).
     * @throws std::invalid_argument если размеры векторов не совпадают.
     */
    iaVector<T> operator+(const iaVector<T>& other) const {
        if (size() != other.size()) throw std::invalid_argument("Размеры не совпадают");
        iaVector<T> result(size());
        for (size_t i = 0; i < size(); ++i) result.data[i] = data[i] + other.data[i];
        return result;
    }

    /**
     * @brief Перегрузка оператора - (покомпонентное вычитание векторов).
     * @throws std::invalid_argument если размеры векторов не совпадают.
     */
    iaVector<T> operator-(const iaVector<T>& other) const {
        if (size() != other.size()) throw std::invalid_argument("Размеры не совпадают");
        iaVector<T> result(size());
        for (size_t i = 0; i < size(); ++i) result.data[i] = data[i] - other.data[i];
        return result;
    }

    /**
     * @brief Умножение вектора на скаляр.
     * @param scalar Скалярное значение.
     * @return Новый вектор.
     */
    iaVector<T> operator*(T scalar) const {
        iaVector<T> result(size());
        for (size_t i = 0; i < size(); ++i) result.data[i] = data[i] * scalar;
        return result;
    }

    /**
     * @brief Вычисление скалярного произведения векторов.
     * @throws std::invalid_argument если размеры векторов не совпадают.
     */
    T dotProduct(const iaVector<T>& other) const {
        if (size() != other.size()) throw std::invalid_argument("Размеры не совпадают");
        T sum = 0;
        for (size_t i = 0; i < size(); ++i) sum += data[i] * other.data[i];
            
        return sum;
    }

    /** @brief Вычисление L2-нормы (евклидовой нормы). */
    T L2norm() const {
        T sum = 0;
        for (const T& val : data) sum += val * val;
        return static_cast<T>(std::sqrt(sum));
    }

    /** @brief Вычисление L1-нормы (сумма модулей элементов). */
    T L1norm() const {
        T sum = 0;
        for (const T& val : data) sum += std::abs(val);
        return sum;
    }

    /**
     * @brief Вычисление угла между векторами.
     * @throws std::invalid_argument если размеры векторов не совпадают.
     * @throws std::runtime_error если один из векторов нулевой.
     */
    double angle(const iaVector<T>& other) const {
    double dotProduct = (*this | other);
    double normA = this->L2norm();
    double normB = other.L2norm();

    // Проверка деления на ноль
    if (normA == 0 || normB == 0) {
        throw std::runtime_error("Ошибка: один из векторов нулевой");
    }

    double cosTheta = dotProduct / (normA * normB);

    // Избегаем ошибок из-за округления (acos() принимает только [-1,1])
    if (cosTheta < -1.0) cosTheta = -1.0;
    if (cosTheta > 1.0) cosTheta = 1.0;

    return std::acos(cosTheta); // Результат в радианах
}
/*
    double angle(const iaVector<T>& other) const {
        if (size() != other.size()) throw std::invalid_argument("Размеры не совпадают");
        double dot = static_cast<double>(dotProduct(other));
        double norms = static_cast<double>(L2norm()) * static_cast<double>(other.L2norm());
        if (norms == 0) throw std::runtime_error("Один из векторов нулевой");
        double cosine = dot / norms;
        cosine = std::max(-1.0, std::min(1.0, cosine)); // Обрезаем до [-1,1]
        return std::acos(cosine);
    }
*/
    /**
     * @brief Вычисление евклидова расстояния между векторами.
     * @throws std::invalid_argument если размеры векторов не совпадают.
     */
    double distance(const iaVector<T>& other) const {
        if (size() != other.size()) throw std::invalid_argument("Размеры не совпадают");
        double sum = 0;
        for (size_t i = 0; i < size(); ++i) {
            double diff = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
            sum += diff * diff;
        }
        return std::sqrt(sum);
    }

    /** @brief Перегрузка оператора | (скалярное произведение). */
    T operator|(const iaVector<T>& other) const {
        return dotProduct(other);
    }

    /** @brief Возвращает максимальный элемент вектора. */
    T maxElement() const {
        if (data.empty()) throw std::runtime_error("Вектор пуст");
        return *std::max_element(data.begin(), data.end());
    }

    /** @brief Возвращает минимальный элемент вектора. */
    T minElement() const {
        if (data.empty()) throw std::runtime_error("Вектор пуст");
        return *std::min_element(data.begin(), data.end());
    }

    /** @brief Проверяет, является ли вектор палиндромом. */
    bool iaPalindrome() const {
        for (size_t i = 0, j = size() - 1; i < j; ++i, --j)
            if (data[i] != data[j]) return false;
        return true;
    }

    /** @brief Перегрузка оператора вывода. */
    friend std::ostream& operator<<(std::ostream& os, const iaVector<T>& vec) {
        os << "[ ";
        for (size_t i = 0; i < vec.size(); i++) {
            os << vec.data[i] << "\t";
        }
//        for (const T& val : vec.data) os << val << " ";
        os << "]";
        return os;
    }

    /** @brief Вывод вектора в поток. */
    void print(std::ostream& os = std::cout) const {
        os << *this << std::endl;
    }
};

#endif // IAVECTOR_HPP

