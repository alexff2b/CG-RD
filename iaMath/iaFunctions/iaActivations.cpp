/*
****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaActivations.cpp
 *    @brief      : Реализация библиотеки функций активации для нейронных сетей.
 *    @author     : Александр Юшкевич
 *    @aka        : iA, alexff
 *    @project    : Все проекты CG. CG Research & Development(c) Projects
 *    @version    : 1.0.0 (первая завершенная версия, протестирована, используется в разработке других классов)
 *    @license    : Apache License 2.0
 *    @contact    : 
 *                  Email:  
 *                      - alexff.2b@hotmail.com  
 *                      - alexff.2b@gmail.com  
 *                      - alexff.2b@icloud.cofm  
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
 *    @note       : Реализованы функции активации для нейронных сетей:
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
 *    
 *    @description: 
 *                  Этот файл содержит реализацию различных функций активации для нейронных сетей. 
 *                  Включает в себя все необходимые математические операции для вычисления значений 
 *                  активации для входных данных. Каждая функция активации возвращает вычисленное значение 
 *                  на основе переданного входа.
 *
 *                  Функции активации используются для добавления нелинейности в нейронные сети, что 
 *                  позволяет моделировать более сложные зависимости и улучшать способность модели к обучению.
 *                  
 *                  Все функции активации реализованы как статические методы в классе `iaActivations` и могут
 *                  быть использованы в любом контексте, где требуется вычисление значений активации.
 *
 *    @applications:
 *                  Этот файл используется в различных областях машинного обучения и искусственного интеллекта:
 *                  - **Искусственные нейронные сети**: для внедрения активации в сети для обучения и предсказания.
 *                  - **Обработка изображений**: для работы с глубокими сверточными нейронными сетями.
 *                  - **Прогнозирование временных рядов**: для анализа и прогнозирования данных.
 *                  - **Обработка сигналов**: для использования в фильтрах и анализе сигналов.
 *                  - **Робототехника и автоматизация**: для разработки интеллектуальных систем с нейронными сетями.
 *
 *    @methods    :
 *                   - static double identity(double x);         // Линейная активация
 *                   - static double heaviside(double x);        // Хевисайд
 *                   - static double sigmoid(double x);          // Сигмоида
 *                   - static double tanh(double x);             // Тангенс гиперболический
 *                   - static double arctanh(double x);          // Аркфункция гиперболического тангенса
 *                   - static double softsign(double x);         // Softsign
 *                   - static double relu(double x);             // ReLU
 *                   - static double lrelu(double x);            // Leaky ReLU
 *                   - static double hardSwish(double x);        // HardSwish
 *                   - static double softshrink(double x);       // SoftShrink
 *                   - static double isru(double x);             // ISRU
 *                   - static double rrelu(double x);            // RReLU
 *                   - static double selu(double x);             // SELU
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
 * ************************************************************************************************** */
#include "iaActivations.hpp"
#include <random>
#include <algorithm>
#include <cmath>  // Для std::sqrt и std::exp

namespace iaMath::iaFunctions {

/**
 * @brief ISRU функция активации.
 * 
 * ISRU (Inverse Square Root Unit) - функция активации, которая используется для улучшения сходимости нейронных сетей.
 * 
 * @param x Входное значение.
 * @param α Параметр, регулирующий форму функции.
 * @return Значение функции ISRU.
 */
template <typename T>
T isru(T x, T α) {
    return x / std::sqrt(static_cast<T>(1) + α * x * x);
}

/**
 * @brief Randomized ReLU (RReLU).
 * 
 * RReLU - это функция активации с элементом случайности.
 * Для отрицательных значений будет применяться случайное значение.
 * 
 * @param x Входное значение.
 * @param α Параметр для регулировки случайности.
 * @return Значение функции RReLU.
 */
template <typename T>
T rrelu(T x, T α) {
    static thread_local std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<T> dist(static_cast<T>(0), α);
    return (x > static_cast<T>(0)) ? x : dist(generator) * x;
}

/**
 * @brief Scaled Exponential Linear Unit (SELU).
 * 
 * Функция активации SELU используется для нормализации активации в нейронных сетях.
 * 
 * @param x Входное значение.
 * @param λ Параметр масштаба.
 * @param α Параметр наклона.
 * @return Значение функции SELU.
 */
template <typename T>
T selu(T x, T λ, T α) {
    return (x > static_cast<T>(0)) ? λ * x : λ * α * (std::exp(x) - static_cast<T>(1));
}

/**
 * @brief Softmax (модифицирует массив).
 * 
 * Функция softmax применяется к массиву и нормализует его элементы, преобразуя их в вероятности.
 * 
 * @param x Массив значений.
 * @param size Размер массива.
 */
template <typename T>
void softmax(T* x, int size) {
    T max_val = *std::max_element(x, x + size);  // Находим максимальное значение для предотвращения переполнения.
    T sum = 0;

    // Применяем экспоненциальную функцию для каждого элемента
    for (int i = 0; i < size; i++) {
        x[i] = std::exp(x[i] - max_val);  // Сдвиг по максимальному значению для предотвращения переполнения.
        sum += x[i];
    }

    // Нормализуем все элементы на сумму
    for (int i = 0; i < size; i++) {
        x[i] /= sum;
    }
}

// Эксплицитные инстанциации для double и float
template double isru(double, double);
template float isru(float, float);

template double rrelu(double, double);
template float rrelu(float, float);

template double selu(double, double, double);
template float selu(float, float, float);

template void softmax(double*, int);
template void softmax(float*, int);

} // namespace iaMath::iaFunctions
