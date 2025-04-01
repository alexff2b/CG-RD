/****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaDerivatives.cpp
 *    @brief      : Реализация библиотеки вычислений производных различных математических функций.
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
 *    @note       : Реализованы функции для вычисления производных различных математических функций:
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
 *                  - Множество других функций для вычисления производных.
 *
 *                  **Для этой версии реализованы производные функций активации**, которые находятся в
 *                  соответствующей библиотеке, и могут быть использованы для расчетов в различных областях науки и техники.
 *
 *    @description: 
 *                  Этот файл содержит реализацию различных математических функций для вычисления их производных. 
 *                  Производные играют важную роль в различных областях математики и науки, таких как:
 *                  - Математический анализ: для вычисления пределов, максимума, минимума функций.
 *                  - Физика: для описания скорости изменения физических величин.
 *                  - Экономика: для моделирования оптимизации и анализа изменения параметров.
 *                  - Инженерия: для расчета углов наклона и изменения значений в различных процессах.
 *                  
 *                  Каждая функция вычисления производной реализована как статический метод, который можно использовать
 *                  для получения производной от различных типов функций, включая функции активации.
 *
 *    @applications:
 *                  Этот файл может быть использован в различных областях науки и техники:
 *                  - **Математический анализ**: для решения задач оптимизации и нахождения экстремумов.
 *                  - **Физика**: для расчета производных физических величин (скорость, ускорение).
 *                  - **Экономика**: для моделирования экономических процессов и анализа изменений.
 *                  - **Инженерия**: для работы с изменением параметров в инженерных задачах.
 *                  - **Машинное обучение и нейронные сети**: для вычисления градиентов и оптимизации.
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

#include "iaDerivatives.hpp"

namespace iaMath::iaFunctions {

	/**
	 * @brief Производная функции ISRU (Inverse Square Root Unit).
	 *
	 * ISRU определяется как:
	 * \f[
	 * \text{ISRU}(x) = \frac{x}{\sqrt{1 + \alpha x^2}}
	 * \f]
	 * 
	 * Производная вычисляется по формуле:
	 * \f[
	 * \text{derIsru}(x) = \frac{1}{(1 + \alpha x^2)^{3/2}}
	 * \f]
	 *
	 * @tparam T Тип входного значения (например, `float` или `double`).
	 * @param x Входное значение.
	 * @param α Параметр ISRU (обычно положительный).
	 * @return Производная ISRU для данного x и α.
	 */
	template <typename T>
	constexpr T derIsru(T x, T α) {
	    return static_cast<T>(1) / std::pow(static_cast<T>(1) + α * x * x, static_cast<T>(1.5));
	}

	/**
	 * @brief Производная функции Scaled Exponential Linear Unit (SELU).
	 *
	 * Производная SELU используется в нейросетях для нормализации градиентов.
	 *
	 * Формула:
	 * \f[
	 * \text{SELU}'(x) =
	 * \begin{cases}
	 * \lambda, & x \geq 0 \\
	 * \lambda \alpha e^x, & x < 0
	 * \end{cases}
	 * \f]
	 *
	 * @tparam T Числовой тип данных (например, `float` или `double`).
	 * @param x Входное значение.
	 * @param λ Масштабирующий коэффициент.
	 * @param α Коэффициент левого наклона.
	 * @return Значение производной SELU.
	 */
	template <typename T>
	constexpr T derSelu(T x, T λ, T α) {
	    return (x >= static_cast<T>(0)) ? λ : λ * α * std::exp(x);
	}

	/**
	 * @brief Производная функции Randomized ReLU (RReLU).
	 *
	 * Функция активации RReLU:
	 * \f[
	 * \text{RReLU}(x) =
	 * \begin{cases}
	 * x, & x \geq 0 \\
	 * \alpha x, & x < 0
	 * \end{cases}
	 * \f]
	 *
	 * Производная этой функции:
	 * \f[
	 * \text{derRrelu}(x) =
	 * \begin{cases}
	 * 1, & x \geq 0 \\
	 * \alpha, & x < 0
	 * \end{cases}
	 * \f]
	 *
	 * @tparam T Тип входного значения (например, `float` или `double`).
	 * @param x Входное значение.
	 * @param α Параметр RReLU (обычно случайное число из диапазона `[α_min, α_max]`).
	 * @return Производная RReLU для заданного x и α.
	 */
	template <typename T>
	constexpr T derRrelu(T x, T α) {
		return (x >= static_cast<T>(0)) ? static_cast<T>(1) : α;
	}

}
