/*
****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaActivations.hpp
 *    @brief      : Заголовочный файл библиотеки функций активации для нейронных сетей.
 *    @author     : Александр Юшкевич
 *    @aka        : iA, alexff
 *    @project    : Все проекты CG. CG Research & Development(c) Projects
 *    @version    : 1.0.0 (первая завершенная версия, протестирована, используется в разработке других классов)
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
 *    @created    : Март 2025
 *    @modified   : Март 2025
 *    @released   : 12 марта 2025 (первая версия, завершенная, используется в разработке других классов)
 *    
 *    @previous_version: Нет
 *
 *    @note       : Реализованы основные функции активации для нейронных сетей:
 *                  - Линейная активация (identity).
 *                  - Хевисайд (heaviside).
 *                  - Сигмоида (sigmoid).
 *                  - Тангенс гиперболический (tanh).
 *                  - Аркфункция гиперболического тангенса (arctanh).
 *                  - Softsign.
 *                  - ReLU (Rectified Linear Unit).
 *                  - Leaky ReLU.
 *                  - HardSwish.
 *                  - SoftShrink.
 *                  - ISRU.
 *                  - RReLU.
 *                  - SELU (Scaled Exponential Linear Unit).
 *                  - Softmax.
 *                  - Другие функции для работы с нейронными сетями.
 *    
 *    @description: 
 *                  Этот файл содержит реализацию различных функций активации, используемых в нейронных сетях.
 *                  Основная цель — предоставить набор проверенных функций активации для обучения нейронных сетей,
 *                  обработки сигналов и других задач машинного обучения.
 *
 *                  Функции активации реализованы как стандартные математические операции и доступны через
 *                  статические методы, которые могут быть использованы в качестве строительных блоков для
 *                  создания сложных нейронных архитектур.
 *                  
 *                  Основные возможности библиотеки:  
 *                    - Реализация множества популярных функций активации  
 *                    - Возможность использования в различных архитектурах нейронных сетей  
 *                    - Легкость интеграции в другие проекты и расширения
 *
 *    @applications:
 *                  Библиотека функций активации применяется в различных областях машинного обучения и нейронных сетей:
 *                  - **Искусственные нейронные сети**: для построения и обучения сетей с различными функциями активации.
 *                  - **Обработка изображений и видео**: для создания глубоких сверточных нейронных сетей (CNN).
 *                  - **Прогнозирование и аналитика данных**: для построения и обучения моделей прогнозирования.
 *                  - **Генерация данных и модели с обучением**: для создания автокодировщиков и генеративных моделей.
 *                  - **Робототехника и автоматизация**: для разработки интеллектуальных систем с нейронными сетями.
 *
 *    @methods    :
 *                   - static double identity(double x);            // Линейная активация (identity)
 *                   - static double heaviside(double x);           // Хевисайд (heaviside)
 *                   - static double sigmoid(double x);             // Сигмоида (sigmoid)
 *                   - static double tanh(double x);                // Тангенс гиперболический (tanh)
 *                   - static double arctanh(double x);             // Аркфункция гиперболического тангенса (arctanh)
 *                   - static double softsign(double x);            // Softsign
 *                   - static double relu(double x);                // ReLU (Rectified Linear Unit)
 *                   - static double lrelu(double x);               // Leaky ReLU
 *                   - static double hardSwish(double x);           // HardSwish
 *                   - static double softshrink(double x);          // SoftShrink
 *                   - static double isru(double x);                // ISRU (Inverse Square Root Unit)
 *                   - static double rrelu(double x);               // RReLU (Randomized ReLU)
 *                   - static double selu(double x);                // SELU (Scaled Exponential Linear Unit)
 *                   - static std::vector<double> softmax(const std::vector<double>& x); // Softmax
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

#ifndef IA_ACTIVATIONS_HPP
#define IA_ACTIVATIONS_HPP

#include <cmath>    // Для exp, tanh, atanh, abs, fmax, fmin
#include <stdexcept>
#include "../../iaMath/iaLinearAlgebra/iaVector/iaVector.hpp"  // Подключаем класс вектора

namespace iaMath::iaFunctions {

/**
 * @brief Функция идентичности.
 * 
 * Функция возвращает входное значение без изменений.
 * 
 * @param x Входное значение.
 * @return Возвращает x.
 */
template <typename T>
constexpr T identity(T x) {
    return x;
}

/**
 * @brief Хевисайд (Heaviside) функция.
 * 
 * Функция возвращает 1, если x >= 0, и 0 в противном случае.
 * 
 * @param x Входное значение.
 * @return 1, если x >= 0, иначе 0.
 */
template <typename T>
constexpr T heaviside(T x) {
    return (x >= static_cast<T>(0)) ? static_cast<T>(1) : static_cast<T>(0);
}

/**
 * @brief Сигмоида (Sigmoid) функция.
 * 
 * Сигмоида — это математическая функция активации, которая преобразует входное значение в диапазон от 0 до 1.
 * 
 * @param x Входное значение.
 * @return Значение функции активации сигмоиды.
 */
template <typename T>
constexpr T sigmoid(T x) {
    return static_cast<T>(1) / (static_cast<T>(1) + std::exp(-x));
}

/**
 * @brief Гиперболический тангенс (Tanh) функция.
 * 
 * Функция гиперболического тангенса, преобразующая входное значение в диапазон от -1 до 1.
 * 
 * @param x Входное значение.
 * @return Значение функции гиперболического тангенса.
 */
template <typename T>
constexpr T tanh(T x) {
    return std::tanh(x);
}

/**
 * @brief Аркгиперболический тангенс (Arctanh) функция.
 * 
 * Возвращает аркгиперболический тангенс входного значения. Эта функция определена только для входных значений в интервале (-1, 1).
 * 
 * @param x Входное значение.
 * @return Значение функции аркгиперболического тангенса.
 * @throws std::domain_error Если x не в диапазоне (-1, 1).
 */
template <typename T>
T arctanh(T x) {
    if (x <= static_cast<T>(-1) || x >= static_cast<T>(1)) {
        throw std::domain_error("arctanh(x) определен только для -1 < x < 1");
    }
    return std::atanh(x);
}

/**
 * @brief Softsign функция.
 * 
 * Функция softsign нормализует входное значение в диапазон от -1 до 1.
 * 
 * @param x Входное значение.
 * @return Значение функции softsign.
 */
template <typename T>
constexpr T softsign(T x) {
    return x / (static_cast<T>(1) + std::abs(x));
}

/**
 * @brief ReLU (Rectified Linear Unit) функция.
 * 
 * Функция ReLU возвращает 0, если x < 0, и x, если x >= 0.
 * 
 * @param x Входное значение.
 * @return Значение функции ReLU.
 */
template <typename T>
constexpr T relu(T x) {
    return fmax(static_cast<T>(0), x);  // Используем fmax вместо std::max
}

/**
 * @brief Leaky ReLU (LReLU) функция.
 * 
 * Функция Leaky ReLU возвращает x, если x >= 0, и 0.01 * x в противном случае.
 * 
 * @param x Входное значение.
 * @return Значение функции Leaky ReLU.
 */
template <typename T>
constexpr T lrelu(T x) {
    return (x > static_cast<T>(0)) ? x : static_cast<T>(0.01) * x;
}

/**
 * @brief Softshrink функция.
 * 
 * Функция softshrink является модификацией L1-регуляризации и уменьшает значения по сравнению с порогом λ.
 * 
 * @param x Входное значение.
 * @param λ Пороговое значение.
 * @return Значение функции softshrink.
 */
template <typename T>
constexpr T softshrink(T x, T λ) {
    if (x > λ) return x - λ;
    if (x < -λ) return x + λ;
    return static_cast<T>(0);
}

/**
 * @brief HardSwish функция.
 * 
 * Функция HardSwish является аппроксимацией функции Swish и используется для улучшения обучения нейронных сетей.
 * 
 * @param x Входное значение.
 * @return Значение функции HardSwish.
 */
template <typename T>
constexpr T hardSwish(T x) {
    T temp = (x + static_cast<T>(3)) / static_cast<T>(6);
    T min_val = std::fmin(static_cast<T>(1), temp);
    T max_val = std::fmax(static_cast<T>(0), min_val);
    return x * max_val;
}

/**
 * @brief Применяет функцию активации ко всем элементам вектора.
 * 
 * Функция применяет переданную функцию ко всем элементам вектора.
 * 
 * @param vec Вектор значений.
 * @param func Функция активации.
 */
template <typename T>
void applyFunctionToVector(iaVector<T>& vec, T(*func)(T)) {
    for (size_t i = 0; i < vec.size(); ++i) {
        vec[i] = func(vec[i]);
    }
}

/**
 * @brief Применяет функцию sigmoid ко всем элементам вектора.
 * 
 * Применяет функцию сигмоиды ко всем элементам вектора.
 * 
 * @param vec Вектор значений.
 */
template <typename T>
void sigmoid(iaVector<T>& vec) {
    applyFunctionToVector(vec, sigmoid<T>);
}

/**
 * @brief Применяет функцию tanh ко всем элементам вектора.
 * 
 * Применяет функцию гиперболического тангенса ко всем элементам вектора.
 * 
 * @param vec Вектор значений.
 */
template <typename T>
void tanh(iaVector<T>& vec) {
    applyFunctionToVector(vec, std::tanh);
}

/**
 * @brief Применяет функцию ReLU ко всем элементам вектора.
 * 
 * Применяет функцию ReLU ко всем элементам вектора.
 * 
 * @param vec Вектор значений.
 */
template <typename T>
void relu(iaVector<T>& vec) {
    applyFunctionToVector(vec, [](T x) { return std::fmax(static_cast<T>(0), x); });
}

/**
 * @brief Применяет функцию Leaky ReLU ко всем элементам вектора.
 * 
 * Применяет функцию Leaky ReLU ко всем элементам вектора.
 * 
 * @param vec Вектор значений.
 */
template <typename T>
void lrelu(iaVector<T>& vec) {
    applyFunctionToVector(vec, [](T x) { return (x > static_cast<T>(0)) ? x : static_cast<T>(0.01) * x; });
}

/**
 * @brief Применяет функцию HardSwish ко всем элементам вектора.
 * 
 * Применяет функцию HardSwish ко всем элементам вектора.
 * 
 * @param vec Вектор значений.
 */
template <typename T>
void hardSwish(iaVector<T>& vec) {
    applyFunctionToVector(vec, [](T x) {
        T temp = (x + static_cast<T>(3)) / static_cast<T>(6);
        T min_val = std::fmin(static_cast<T>(1), temp);
        T max_val = std::fmax(static_cast<T>(0), min_val);
        return x * max_val;
    });
}

} // namespace iaMath::iaFunctions

#endif // IA_ACTIVATIONS_HPP
