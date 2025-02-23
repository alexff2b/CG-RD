README.txt

Описание структуры проекта

Этот файл поясняет назначение каждой папки в проекте.

1. Основные каталоги

iaAi/
Главная папка с библиотеками искусственного интеллекта и научного моделирования.

- iaMl/ – библиотеки для машинного обучения и работы с ИИ.
  - iaVector/ – классы для работы с векторами и линейной алгеброй.
  - iaPerceptron/ – базовые нейронные сети и персептроны.
  - iaLexer/ – обработка текстов, разбиение на токены.
  - iaToken/ – классы для представления токенов.
  - iaMemory/ – долгосрочная память ИИ, база данных знаний.

- iaMath/ – математические библиотеки.
  - iaLinearAlgebra/ – матричные операции, линейная алгебра.
  - iaProbability/ – вероятностные модели, теория вероятностей.
  - iaStatistics/ – статистика и анализ данных.

- iaPhysics/ – физические модели.
  - iaNewtonian/ – ньютоновская механика.
  - iaQuantum/ – квантовая физика.
  - iaAstrophysics/ – астрофизические расчёты.

- iaOs/ – корпоративная операционная система для работы с ИИ.

- iaDatabase/ – база данных для хранения объектов и знаний ИИ.

- iaGis/ – геоинформационные системы и картографические модели.

- iaSimulation/ – моделирование научных процессов.

2. Тестирование

- test/ – тестовые данные и результаты тестирования.
  - dataToTests/ – входные файлы для тестов.
  - testsResults/ – результаты тестирования.

3. Скрипты и инструменты

- scripts/ – вспомогательные скрипты.
  - create_project_structure.sh – создаёт структуру проекта с нуля.

Как использовать:
- Все библиотеки разрабатываются внутри iaAi/.
- Тестирование проводится в test/.
- Скрипты для автоматизации лежат в scripts/.

Проект развивается и дополняется новыми библиотеками и функционалом.