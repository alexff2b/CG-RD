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

#ifndef IAMATRIX_HPP
#define IAMATRIX_HPP

#include <iostream>
#include "../iaVector/iaVector.hpp"

/**
 * @brief Шаблонный класс матрицы на основе iaVector.
 * @tparam T Тип элементов матрицы.
 */
template <typename T>
class iaMatrix {
private:
    iaVector<iaVector<T>> data; ///< Двумерный контейнер для хранения матрицы.

public:
    /// @name Конструкторы
    /// @{

    /** @brief Конструктор по умолчанию. */
    explicit iaMatrix() = default;

    /** @brief Конструктор для матрицы размером rows x cols, заполненной нулями. */
    explicit iaMatrix(size_t rows, size_t cols) : data(rows) {
        for (size_t i = 0; i < rows; i++) {
            data[i] = iaVector<T>(cols);  // Создание строки фиксированной длины
        }
    } /// @end Конструктор по размерам
    


    /// @name Работа с размерами
    /// @{
    /** @brief Возвращает количество строк. */
    size_t rows() const { return data.size(); }

    /** @brief Возвращает количество столбцов. */
    size_t cols() const { return (data.empty() ? 0 : data[0].size()); }
    /// @}

    /// @name Проверка свойств
    /// @{
    /** @brief Проверка, является ли матрица квадратной. */
    bool isSquare() const {
      
        return rows() == cols();
    }  /// @end isSquare
    /// @}

    /** 
     * @brief Проверяет, является ли матрица диагональной.
     * @return true, если матрица диагональная, иначе false.
     */
    bool isDiagonal() const {
        if (!isSquare()) return false;  // Матрица должна быть квадратной

        for (size_t i = 0; i < rows(); i++) {
            for (size_t j = 0; j < cols(); j++) {
                if (i != j && data[i][j] != 0) {  
                    return false;  // Вне главной диагонали должны быть только нули
                }
            }
        }
        return true; // Все условия диагональности выполнены
    } /// @end isDiagonal


    /**
     * @brief Проверяет, является ли матрица единичной.
     * @return true, если матрица является единичной, иначе false.
     */
    bool isIdentity() const {
        if (!isSquare()) return false;  // Матрица должна быть квадратной

        for (size_t i = 0; i < rows(); i++) {
            for (size_t j = 0; j < cols(); j++) {
                if (i != j && data[i][j] != 0) {  
                    return false;  // Вне главной диагонали должны быть только нули
                } 
                if (i == j && data[i][j] != 1) {  
                    return false;  // На главной диагонали должны быть только единицы
                }
            }
        }
        return true; // Все условия единичной матрицы выполнены
    } /// @end isIdentity


    /**
     *  @brief Проверяет, является ли матрица верхнетреугольной (верхней треугольной).
     *  @return true, если матрица верхнетреугольная, иначе false.
     */ 
    bool isUpTriang() const {
        if (!isSquare()) return false;  // Верхнетреугольная матрица должна быть квадратной
        for (size_t i = 1; i < rows(); i++) {  // Начинаем с 1, так как первый ряд можно не проверять
            for (size_t j = 0; j < i; j++) {  // Проверяем только элементы ниже главной диагонали
                if (data[i][j] != 0) return false;  // Если ниже диагонали не 0, это не верхнетреугольная матрица
            }
        }
        return true;
    } /// @end isUpTriang


    /**
     * @brief Проверяет, является ли матрица нижнетреугольной.
     * 
     * Нижнетреугольная матрица — это квадратная матрица, у которой все элементы 
     * выше главной диагонали равны нулю (data[i][j] == 0 при j > i).
     * 
     * @return true, если матрица нижнетреугольная, иначе false.
     */
    bool isLowTriang() const {
        if (!isSquare()) {
            return false; ///< Проверяем, является ли матрица квадратной.
        }
        for (size_t i = 0; i < rows(); ++i) {
            for (size_t j = i + 1; j < cols(); ++j) { ///< Проверяем только верхний треугольник.
                if (data[i][j] != 0) { ///< Если есть ненулевой элемент выше диагонали — не нижнетреугольная.
                    return false;
                }
            }
        }
        return true; ///< Если все элементы выше диагонали нулевые — матрица нижнетреугольная.
    } /// @end isLowTriang

    /**
     * @brief Проверяет, является ли матрица симметричной.
     * 
     * Симметричная матрица - это квадратная матрица, у которой A[i][j] == A[j][i] для всех i и j.
     * 
     * @return true, если матрица симметрична, иначе false.
     * */
    bool isSymmetric() const {
        if (rows() != cols()) return false;  // Матрица должна быть квадратной
        return (*this == this->transpose()); // Сравниваем матрицу с её транспонированной версией
    } /// @end isSymmetric

    /**
     * @brief Проверяет, является ли матрица кососимметричной.
     * 
     * Кососимметричная (антисимметричная) матрица - это квадратная матрица, у которой A[i][j] == -A[j][i] для всех i и j.
     * Условие эквивалентно A^T = -A.
     * @return true, если матрица кососимметрична, иначе false.
     * */
    bool isCoSymmetric() const {
        if (rows() != cols()) return false;  // Матрица должна быть квадратной
        return (*this == (this->transpose() * static_cast<T>(-1.0))); // Сравниваем с отрицательной транспонированной версией
    } /// @end isCoSymmetric
    /// @}

    /// @name Доступ к элементам
    /// @{

   /** 
    * @brief Доступ к элементу матрицы по указанным индексам. 
    * @param row Номер строки. 
    * @param col Номер столбца. 
    * @return Ссылка на элемент матрицы в указанной позиции. 
    * */
    T& operator()(size_t row, size_t col) {
        return data[row][col];
    } /// @end ()

    /**  
     * @brief Получение элемента матрицы по указанным индексам (для константных объектов).  
     * @param row Номер строки.  
     * @param col Номер столбца.  
     * @return Константная ссылка на элемент матрицы в указанной позиции.  
     * */
     const T& operator()(size_t row, size_t col) const {
        return data[row][col];
    }/// @end ()

    /** 
     * @brief Доступ к строке матрицы (неконстантная версия).
     * 
     * Позволяет получать ссылку на строку матрицы, предоставляя возможность
     * изменять элементы строки.
     * @param row Индекс строки.
     * @return Ссылка на вектор (строку) матрицы.
     * */
    iaVector<T>& operator[](size_t row) {
        return data[row];
    } /// @end []
    /** 
     * @brief Доступ к строке матрицы (константная версия).
     * Позволяет получать доступ к строке матрицы для чтения без возможности
     * изменения элементов.
     * 
     * @param row Индекс строки.
     * @return Константная ссылка на вектор (строку) матрицы.
     * */
    const iaVector<T>& operator[](size_t row) const {
        return data[row];
    } /// @end []
    /// @}

    /// @name Работа с диагоналями
    /// @{

     /**
     * @brief Извлекает главную диагональ квадратной матрицы.
     * 
     * @tparam T Тип элементов матрицы.
     * @return iaVector<T> Вектор, содержащий элементы главной диагонали.
     * @throws std::invalid_argument Если матрица не является квадратной.
     */
    iaVector<T> getDiagonal() const {
        if (!isSquare()) {
            throw std::runtime_error("Матрица не квадратная, диагональ отсутствует.");
        }
        iaVector<T> di(rows());
        for (size_t i = 0; i < rows(); ++i) {
            di[i] = data[i][i];
        }
        return di;
    } /// @end getDiagonal

    /**
    * @brief Получает побочную диагональ квадратной матрицы.
    * 
    * Побочная диагональ (вторичная диагональ) — это элементы,
    * расположенные от верхнего правого угла к нижнему левому.
    * 
    * @tparam T Тип элементов матрицы.
    * @return iaVector<T> Вектор, содержащий элементы побочной диагонали.
    * @throws std::runtime_error Если матрица не является квадратной.
    */
    iaVector<T> getSecondaryDiagonal() const {
        if (!isSquare()) {
            throw std::runtime_error("Матрица не квадратная, диагональ отсутствует.");
        }
        iaVector<T> di(rows());
        for (size_t i = 0; i < rows(); ++i) {
            di[i] = data[i][cols() - i - 1];
        }
        return di;
    } /// @end getSecondaryDiagonal
    //// @}
   

    /// @name Ввод/ вывод
    /// @{

    /** @brief Вывод матрицы в поток. */
    void print(std::ostream& os = std::cout) const {
        for (size_t i = 0; i < rows(); i++) {
            data[i].print(os);
        }
    } /// @end print

    friend std::ostream& operator<<(std::ostream& os, const iaMatrix<T>& matrix) {
        matrix.print(os);
        return os;
    } /// @end <<
    /// @}

    /// @name Арифметические операторы
    /// @{

    /**
     * @brief Оператор сложения двух матриц.
     * Этот метод выполняет поэлементное сложение двух матриц, если их размеры совпадают.
     * @param otherMatrix Матрица, с которой выполняется сложение.
     * @return Возвращает новую матрицу, являющуюся результатом сложения.
     * @throw std::invalid_argument Если матрицы имеют разные размеры.
     * */
    iaMatrix<T> operator+(const iaMatrix<T>& otherMatrix) {
    // Проверка на совпадение размеров матриц
        if (rows() != otherMatrix.rows() || cols() != otherMatrix.cols()) {
            throw std::invalid_argument("Матрицы должны быть одинакового размера для сложения.");
        }
        // Создание новой матрицы для хранения результата
        iaMatrix<T> result(rows(), cols());
        // Сложение поэлементно
        for (size_t i = 0; i < rows(); i++) {
            result[i] = data[i] + otherMatrix[i];
        }
        return result; // Возвращаем результат
    } /// @end + Matrix

    iaMatrix<T>& operator+=(const iaMatrix<T>& otherMatrix) {
        if (rows() != otherMatrix.rows() || cols() != otherMatrix.cols()) {
            throw std::invalid_argument("Матрицы должны быть одинакового размера для сложения.");
        }
        for (size_t i = 0; i < rows(); i++) {
            data[i] += otherMatrix[i];
        }
        return *this;
    } /// @end += Matrix

    iaMatrix<T> operator-(const iaMatrix<T>& otherMatrix) {
        // Проверка на совпадение размеров матриц
        if (rows() != otherMatrix.rows() || cols() != otherMatrix.cols()) {
            throw std::invalid_argument("Матрицы должны быть одинакового размера для вычитан.");
        }
        // Создание новой матрицы для хранения результата
        iaMatrix<T> result(rows(), cols());
        // Сложение поэлементно
        for (size_t i = 0; i < rows(); i++) {
            result[i] = data[i] - otherMatrix[i];
        }
        return result; // Возвращаем результат
    } /// @end - Matrix

    iaMatrix<T>& operator-=(const iaMatrix<T>& otherMatrix) {
        if (rows() != otherMatrix.rows() || cols() != otherMatrix.cols()) {
            throw std::invalid_argument("Матрицы должны быть одинакового размера для сложения.");
        }
        for (size_t i = 0; i < rows(); i++) {
            data[i] -= otherMatrix[i];
        }
        return *this;
    } /// @end -= Matrix
    /// @}

    /// @name операторы умножения
    /// @{

    iaMatrix<T> operator*(const T scal) const {
        // Создание новой матрицы для хранения результата
        iaMatrix<T> result(rows(), cols());
        // ;умножение поэлементно
        for (size_t i = 0; i < rows(); i++) {
            result[i] = data[i] * scal;
        }
        return result; // Возвращаем результат
    } /// @end * sal;

    iaMatrix<T>& operator*=(const T scal) {
        for (size_t i = 0; i < rows(); i++) {
            data[i] *= scal;
        }
        return *this;
    } /// @end *= scal

    /**
     * @brief Перегрузка оператора умножения для умножения вектора на матрицу.
     * Этот метод перегружает оператор умножения для умножения вектора на матрицу или на другой вектор.
     * Он проверяет, что количество столбцов матрицы совпадает с размером вектора, а затем выполняет
     * операцию умножения, где каждый элемент строки матрицы умножается на соответствующий элемент
     * вектора, и результат суммируется по строкам.
     * @param otherVector Вектор, с которым нужно умножить текущий объект.
     * @return Возвращает новый вектор, являющийся результатом операции умножения.
     * @throws std::invalid_argument Если размер вектора не совпадает с количеством столбцов матрицы.
     * */
    iaVector<T> operator*(const iaVector<T>& otherVector) const {
        if (cols() != otherVector.size()) {
            throw std::invalid_argument("Размер вектора должен равняться числу столбцов матрицы.");
        }

        iaVector<T> result(rows());
        for (size_t i = 0; i < rows(); i++) {
            // Используем перегруженный оператор | для вычисления скалярного произведения
            result[i] = data[i] | otherVector;
        }
        return result;
    } /// @end * vVector

    /**
     * @brief Оператор умножения матриц.
     * @param otherMatrix Вторая матрица для умножения.
     * @return Результирующая матрица после умножения.
     * @throws std::invalid_argument Если количество столбцов первой матрицы не совпадает с количеством строк второй.
     * */
    iaMatrix<T> operator*(iaMatrix<T>& otherMatrix) {
        size_t cols_A, rows_B, cols_C, rows_C;
        //rows_A = rows();          // Получаем количество строк в первой матрице
        cols_A = cols();          // Получаем количество столбцов в первой матрице
        rows_B = otherMatrix.rows(); // Получаем количество строк во второй матрице
        //cols_B = otherMatrix.cols(); // Получаем количество столбцов во второй матрице
        rows_C = cols_A;          // Количество строк в результирующей матрице
        cols_C = rows_B;          // Количество столбцов в результирующей матрице
        // Проверка на возможность умножения матриц
        if (cols_A != rows_B) {
            throw std::invalid_argument("Несоответствие размеров: умножение этих матриц невозможно.");
        }
        // Создаем результирующую матрицу
        iaMatrix<T> result(rows_C, cols_C);
        // Транспонирование второй матрицы
        iaMatrix<T> otherMatrixT = otherMatrix.transpose();
        iaVector<T> A, B;    // Векторы для строк и столбцов
        T C;                 // Переменная для результата скалярного произведения
        // Перемножение матриц
        for (size_t i = 0; i < rows_C; i++) {
            for (size_t j = 0; j < cols_C; j++) {
                // Получаем строку первой матрицы и столбец второй матрицы
                A = data[i];          // Строка первой матрицы
                B = otherMatrixT[j];  // Столбец второй матрицы (после транспонирования)
                // Скалярное произведение строки первой матрицы и столбца второй матрицы
                C = (A | B);          // Используем перегруженный оператор | для вычисления скалярного произведения
                result[i][j] = C;     // Присваиваем результат в соответствующую ячейку результата
            }
        }
        return result; // Возвращаем результат умножения
    } /// @end * Matrix

    iaMatrix<T>& operator*=(const iaMatrix<T>& otherMatrix) {

        *this = *this * otherMatrix;

        return *this;
    } /// @end *= Matrix
    /// @}

    /// @name  операторы сравнения
    /// @{

    /**
     * @brief Оператор сравнения для проверки равенства двух матриц.
     * 
     * Сравнивает текущую матрицу с другой матрицей на равенство.
     * Две матрицы считаются равными, если они имеют одинаковые размеры
     * и все соответствующие векторы равны.
     * 
     * @param otherMatrix Матрица для сравнения с текущей.
     * @return true Если матрицы равны.
     * @return false Если матрицы не равны.
     */
    bool operator==(const iaMatrix<T>& otherMatrix) const {
        // Сравниваем размеры матриц
        if (rows() != otherMatrix.rows() || cols() != otherMatrix.cols()) {
            return false;
        }
        // Сравниваем векторы матриц
        for (size_t i = 0; i < rows(); i++) {
            if (data[i] != otherMatrix.data[i]) { // Используем оператор сравнения для векторов
                return false;
            }
        }
        return true;
    }/// @end ==

     bool operator!= (const iaMatrix<T>& otherMatrix) const {
        return !(*this== otherMatrix);
    } /// @end !=
    /// @}

    /// @name  Другие методы
    /// @{
    void push_back(const iaVector<T>& row) {
        data.push_back(row);
    } /// @end push_back

    /**
     * @brief Вычисление детерминанта матрицы.
     * @return Возвращает детерминант матрицы.
     * @throws std::runtime_error если матрица не квадратная.
     * */
    T Determinant() const {
        // Проверка на квадратность матрицы
        if (!isSquare()) {
            throw std::runtime_error("Матрица не квадратная, невозможно детерминировать матрицу");
        }

        size_t n = rows(); // Получаем количество строк (или столбцов) в матрице
        // Базовый случай: если матрица 1x1, возвращаем ее единственный элемент
        if (n == 1) {
            return data[0][0];
        }
        // Базовый случай: если матрица 2x2, вычисляем детерминант с помощью формулы для 2x2 матрицы
        if (n == 2) {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        }
        T de = 0; // Переменная для хранения результата детерминанта

        // Разложение детерминанта по первой строке
        for (size_t i = 0; i < n; i++) {
            iaMatrix<T> suM(n -1, n - 1); // Подматрица для вырезания элемента (i, 0)
            // Создание подматрицы, которая получается удалением первой строки и i-го столбца
            for (size_t j = 1; j < n; j++) {
                iaVector<T> RowTmp; // Вектор для строки подматрицы
                // Заполнение строки подматрицы (пропускаем i-й столбец)
                for (size_t k = 0; k < n; k++) {
                    if (k != i) { // Если индекс столбца не совпадает с i, добавляем элемент в строку
                        RowTmp.push_back(data[j][k]);
                    }
                }
                suM.push_back(RowTmp); // Добавляем строку в подматрицу
            }
            // Суммируем результат с учетом знака (положительный или отрицательный)
            de += (i % 2 == 0 ? 1 : -1) * data[0][i] * suM.Determinant();
        }
        return de; // Возвращаем вычисленный детерминант
    } /// @end Determinant

    /**
     * @brief Вычисление минора матрицы для элемента на позиции (row, col).
     * 
     * Этот метод вычисляет минор матрицы для элемента на строке row и столбце col.
     * Минор для элемента матрицы — это детерминант подматрицы, полученной
     * путём удаления строки row и столбца col из матрицы.
     * 
     * @param row Индекс строки, для которой вычисляется минор.
     * @param col Индекс столбца, для которого вычисляется минор.
     * @return Возвращает значение минора — детерминант подматрицы.
     * @throws std::out_of_range Если индексы строки или столбца выходят за пределы размеров матрицы.
     * */
    T minor(size_t row, size_t col) const {
        if (row >= rows() || col >= cols()) {
            throw std::out_of_range("Индекс строки или столбца выходит за пределы матрицы.");
        }

        iaMatrix<T> suM; // Подматрица для вычисления минора
        // Создаем подматрицу, исключая строку row и столбец col
        for (size_t i = 0; i < rows(); i++) {
            if (i == row) continue; // Пропускаем строку row
            iaVector<T> RowTmp;
            for (size_t j = 0; j < cols(); j++) {
                if (j == col) continue; // Пропускаем столбец col
                RowTmp.push_back(data[i][j]); // Добавляем элемент в подматрицу
            }
            suM.push_back(RowTmp);
        }
        // Возвращаем детерминант подматрицы, который является минором
        return suM.Determinant();
    } /// @end minor

    T complement(size_t row, size_t col) const {
        return ((row + col) % 2 == 0 ? 1 : -1) * minor(row, col);
    } /// @end complement

    iaMatrix<T> transpose() const {
        iaMatrix<T> result(cols(), rows());  // Создаем транспонированную матрицу
        for (size_t i = 0; i < rows(); i++) {
            for (size_t j = 0; j < cols(); j++) {
                result.data[j][i] = data[i][j];  // Исправлено обращение к данным
            }
        }
        return result;
    } ///@end transpose
    /**
     * @brief Поворачивает матрицу на 90 градусов по часовой стрелке.
     * 
     * @return Поворотная матрица, полученная из текущей.
     * */
    iaMatrix<T> turn90() {
    // Создаем новую матрицу с размерами, измененными на 90 градусов
        iaMatrix<T> result(cols(), rows());
        // Проходим по всем элементам исходной матрицы
        for (size_t i = 0; i < rows(); i++) {
            for (size_t j = 0; j < cols(); j++) {
                // Поворачиваем элемент на 90 градусов
                result[j][rows() - 1 - i] = data[i][j];
            }
        }
        return result; // Возвращаем новую матрицу
    } /// @end turn 90

    /**
     * @brief Поворачивает матрицу на 180 градусов по часовой стрелке.
     * @return Поворотная матрица, полученная из текущей.
     * */
    iaMatrix<T> turn180() {
        return turn90().turn90();
    } /// @end turn180 

    /**
     * @brief Поворачивает матрицу на 270 градусов по часовой стрелке.
     * @return Поворотная матрица, полученная из текущей.
     * */
    iaMatrix<T> turn270() {
        return turn90().turn180();
    } /// @end turn 270
    /// @}
};
#endif // IAMATRIX_HPP
