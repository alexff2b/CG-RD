# CG Research & Development

## Описание проекта
Этот проект является частью исследовательской и разработческой деятельности **CG R&D**. 
Включает в себя различные математические классы и алгоритмы для работы с линейной алгеброй, в том числе реализацию работы с комплексными числами.

## Структура проекта
```
<корень проекта>/
│── iaAi/                   # Основные библиотеки
│   ├── iaMath/             # Математические библиотеки
│   │   ├── iaLinearAlgebra/ # Линейная алгебра
│   │   │   ├── iaComplex/   # Работа с комплексными числами
│── tests/                  # Тесты
│   ├── iaComplexTest/       # Тесты для iaComplex
│   │   ├── Makefile         # Makefile для тестирования
│── scripts/                 # Скрипты для сборки и автоматизации
```

## Установка и компиляция
Для работы с классами необходимо добавить соответствующие файлы в ваш проект и использовать заголовочные файлы.

### Компиляция с использованием `Makefile`
Пример Makefile находится в директории:
```
tests/iaComplexTest/Makefile
```
Для сборки тестов выполните:
```sh
cd tests/iaComplexTest
make
```

### Компиляция вручную (без Makefile)
```sh
clang++ -std=c++17 -Wall -Wextra -Werror -pedantic -I./iaAi tests/iaComplexTest/iaComplexTest.cpp iaAi/iaMath/iaLinearAlgebra/iaComplex/iaComplex.cpp -o tests/iaComplexTest/iaComplexTest
```
Пример компиляции с использованием `g++`:
```sh
g++ -std=c++17 -Wall -Wextra -Werror -pedantic -I../../iaAi tests/iaComplexTest/iaComplexTest.cpp ../../iaAi/iaMath/iaLinearAlgebra/iaComplex/iaComplex.cpp -o tests/iaComplexTest/iaComplexTest

```

## Контакты
Разработчик: **Александр Юшкевич**  
Email: alexff.2b@gmail.com  
Проект: **Helios Prime - Nova Terra (CosmoGenesis)(c)**
