/****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaDerivatives.hpp
 *    @brief      : Заголовочный файл для библиотеки вычислений производных различных математических функций.
 *    @author     : Александр Юшкевич
 *    @aka        : iA, alexff
 *    @project    : Все проекты CG. CG Research & Development(c) Projects
 *    @version    : 1.0.0 (первая завершенная версия, протестирована, используется для вычислений производных)
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
 *    @released   : 13 марта 2025 (первая версия, завершенная, используется для математических расчетов)
 *    
 *    @previous_version: Нет
 *
 *    @note       : Заголовочный файл для реализации функций вычисления производных различных математических функций:
 *                  - Линейная функция (identity).
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
 *                  - Множество других математических функций.
 *
 *                  **Для этой версии реализованы производные функций активации**, которые находятся в
 *                  соответствующей библиотеке и могут быть использованы для расчетов в различных областях науки и техники.
 *
 *    @description: 
 *                  Этот файл содержит объявления различных функций для вычисления их производных.
 *                  Производные используются в различных областях математики, физики, экономики и других наук.
 *                  Функции для вычисления производных реализованы как статические методы, которые могут быть использованы
 *                  для получения производных различных типов функций, включая функции активации.
 *
 *                  Эти методы применяются в задачах анализа изменения величин, оптимизации, а также в других
 *                  областях, где важно знать скорость изменения функции или величины.
 *
 *    @applications:
 *                  Этот файл может быть использован в различных областях науки и техники:
 *                  - **Математический анализ**: для нахождения экстремумов функций и решения задач оптимизации.
 *                  - **Физика**: для вычисления производных физических величин, таких как скорость и ускорение.
 *                  - **Экономика**: для анализа изменений экономических параметров и принятия решений.
 *                  - **Инженерия**: для вычисления углов наклона и оптимизации параметров.
 *                  - **Машинное обучение**: для вычисления градиентов и оптимизации в обучении моделей.
 *
 *    @methods    :
 *                   - static double derIdentity(double x);        // Производная линейной функции
 *                   - static double derHeaviside(double x);       // Производная Хевисайда
 *                   - static double derSigmoid(double x);         // Производная сигмоиды
 *                   - static double derTanh(double x);            // Производная тангенса гиперболического
 *                   - static double derArctanh(double x);         // Производная аркфункции гиперболического тангенса
 *                   - static double derSoftsign(double x);        // Производная Softsign
 *                   - static double derRelu(double x);            // Производная ReLU
 *                   - static double derLrelu(double x);           // Производная Leaky ReLU
 *                   - static double derHardSwish(double x);       // Производная HardSwish
 *                   - static double derSoftShrink(double x);      // Производная SoftShrink
 *                   - static double derIsru(double x);            // Производная ISRU
 *                   - static double derRrelu(double x);           // Производная RReLU
 *                   - static double derSelu(double x);            // Производная SELU
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
#ifndef IA_DERIVATIVES_HPP
#define IA_DERIVATIVES_HPP

#include <cmath>    // Для exp, tanh, atanh, abs, fmax, fmin
#include <stdexcept>  // Для обработки исключений
#include "iaActivations.hpp"  // Подключаем активационные функции (включая сигмоиду)
#include <cmath>

namespace iaMath::iaFunctions {

	/**
	 * @brief Производная функции идентичности.
	 * 
	 * Функция возвращает константу 1, так как производная x равна 1.
	 * 
	 * @tparam T Тип входного значения.
	 * @param x Входное значение (не используется в вычислении).
	 * @return Всегда 1.
	 */
	template <typename T>
	constexpr T derIdentity(T x) {
		return 1;
	}

	/**
	 * @brief Производная функции Хевисайда.
	 * 
	 * Функция возвращает 0 для отрицательных значений, 1 для положительных.
	 * 
	 * @tparam T Тип входного значения.
	 * @param x Входное значение.
	 * @return Производная функции Хевисайда (0 или 1).
	 */
	template <typename T>
	constexpr T derHeaviside(T x) {
		return (x > T(0)) ? T(1) : T(0);
	}

	/**
	 * @brief Производная сигмоидальной функции.
	 * 
	 * Производная сигмоиды = сигмоида(x) * (1 - сигмоида(x)).
	 * 
	 * @tparam T Тип входного значения.
	 * @param x Входное значение.
	 * @return Производная сигмоиды.
	 */
	template <typename T>
	T derSigmoid(T x) {
		T sig = sigmoid(x);  // Сначала вычисляем значение сигмоиды
		return sig * (T(1) - sig);  // Производная сигмоиды
	}

	/**
	 * @brief Производная гиперболического тангенса.
	 * 
	 * Производная tanh(x) = 1 - tanh(x)^2.
	 * 
	 * @tparam T Тип входного значения.
	 * @param x Входное значение.
	 * @return Производная гиперболического тангенса.
	 */
	template <typename T>
	T derTanh(T x) {
		T t = tanh(x);  // Сначала вычисляем значение tanh
		return T(1) - t * t;  // Производная tanh
	}

	/**
	 * @brief Производная арктангенса.
	 * 
	 * Производная arctanh(x) = 1 / (1 - x^2).
	 * Важно: Производная существует только для |x| < 1.
	 * 
	 * @tparam T Тип входного значения.
	 * @param x Входное значение.
	 * @return Производная арктангенса.
	 * @throws std::domain_error Если |x| >= 1.
	 */
	template <typename T>
	T derArctanh(T x) {
		if (std::abs(x) >= T(1)) {
			throw std::domain_error("Арктангенс не определен для |x| >= 1. Получено значение: " + std::to_string(x));
		}
		return T(1) / (T(1) - x * x);
	}

	/**
	 * @brief Производная функции Softsign.
	 * 
	 * Функция Softsign выражается как:
	 * \[
	 * \text{softsign}(x) = \frac{x}{1 + |x|}
	 * \]
	 * Производная этой функции для аргумента x вычисляется как:
	 * \[
	 * \text{derSoftsign}(x) = \frac{1}{(1 + |x|)^2}
	 * \]
	 * Это выражение описывает скорость изменения функции Softsign по отношению к x.
	 * 
	 * @tparam T Тип входного значения (например, float или double).
	 * @param x Входное значение.
	 * @return Производная функции Softsign для заданного x.
	 */
	template <typename T>
	constexpr T derSoftsign(T x) {
		T denominator = static_cast<T>(1) + std::abs(x);  ///< Вычисление знаменателя
		return static_cast<T>(1) / (denominator * denominator); ///< Возвращаем производную
	}

	/**
	 * @brief Производная функции ReLU.
	 * 
	 * Производная функции ReLU = 1 для положительных значений x, иначе 0.
	 * 
	 * @tparam T Тип входного значения.
	 * @param x Входное значение.
	 * @return Производная функции ReLU.
	 */
	template <typename T>
	constexpr T derRelu(T x) { 
		return (x >= static_cast<T>(0)) ? static_cast<T>(1) : static_cast<T>(0);
	}

	/**
	 * @brief Производная функции Leaky ReLU.
	 * 
	 * Производная функции Leaky ReLU определяется как:
	 * \[
	 * \text{derLrelu}(x) = \begin{cases}
	 * 1 & \text{если } x \geq 0 \\
	 * 0.01 & \text{если } x < 0
	 * \end{cases}
	 * \]
	 * где \(0.01\) — это коэффициент наклона для отрицательных значений.
	 * 
	 * Эта производная используется для обучения нейронных сетей с использованием метода
	 * обратного распространения ошибки, позволяя настраивать веса, даже если активация нейрона
	 * была отрицательной, но с маленьким значением наклона.
	 * 
	 * @tparam T Тип входного значения (например, `float` или `double`).
	 * @param x Входное значение.
	 * @return Возвращает значение производной функции Leaky ReLU для заданного x.
	 */
	template <typename T>
	constexpr T derLrelu(T x) {
	    return (x >= static_cast<T>(0)) ? static_cast<T>(1) : static_cast<T>(0.01);
	}

	/**
	 * @brief Производная функции Hard Swish.
	 * 
	 * Производная функции Hard Swish определяется как:
	 * \[
	 * \text{derHardSwish}(x) = 
	 * \begin{cases}
	 * 0 & \text{если } x < -3 \\
	 * \frac{x + 3}{6} & \text{если } -3 \leq x < 3 \\
	 * 1 & \text{если } x \geq 3
	 * \end{cases}
	 * \]
	 * 
	 * @tparam T Тип входного значения.
	 * @param x Входное значение.
	 * @return Производная функции Hard Swish для заданного x.
	 */
	template <typename T>
	constexpr T derHardSwish(T x) {
		if (x < static_cast<T>(-3)) {
			return static_cast<T>(0);
		} else if (x < static_cast<T>(3)) {
			return (x + static_cast<T>(3)) / static_cast<T>(6);
		} else {
			return static_cast<T>(1);
		}
	}

	/**
	 * @brief Производная функции Soft Shrink.
	 * 
	 * Функция возвращает производную Soft Shrink для заданного значения x и параметра λ.
	 * 
	 * @param x Входное значение.
	 * @param λ Параметр, определяющий уровень сжатия.
	 * @return Производная Soft Shrink для x.
	 */
	template <typename T>
	constexpr T derSoftShrink(T x, T λ) {
	    if (x > λ) {
	        return static_cast<T>(1);
	    } else if (x < -λ) {
	        return static_cast<T>(-1);
	    } else {
	        return static_cast<T>(0);
	    }
	}

}  // namespace iaMath::iaFunctions

#endif  // IA_DERIVATIVES_HPP
