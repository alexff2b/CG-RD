#!/bin/bash

# Устанавливаем корневую директорию проекта (скрипт должен выполняться из `scripts/`)
PROJECT_ROOT=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)

# Функция для создания папок с проверкой существования
create_dir() {
    if [ ! -d "$1" ]; then
        mkdir -p "$1"
        echo "Создана папка: $1"
    else
        echo "Папка уже существует: $1"
    fi
}

echo "Создание структуры проекта в $PROJECT_ROOT"

# Основные директории
create_dir "$PROJECT_ROOT/iaAi"
create_dir "$PROJECT_ROOT/iaScience"
create_dir "$PROJECT_ROOT/iaOs"
create_dir "$PROJECT_ROOT/iaSecurity"
create_dir "$PROJECT_ROOT/tests"
create_dir "$PROJECT_ROOT/scripts"

# Подкаталоги AI
create_dir "$PROJECT_ROOT/iaAi/iaMl"
create_dir "$PROJECT_ROOT/iaAi/iaMl/iaVector"
create_dir "$PROJECT_ROOT/iaAi/iaMl/iaNeuralNetworks"
create_dir "$PROJECT_ROOT/iaAi/iaMl/iaLanguageProcessing"
create_dir "$PROJECT_ROOT/iaAi/iaMl/iaSpeechSynthesis"
create_dir "$PROJECT_ROOT/iaAi/iaMl/iaObjectRecognition"
create_dir "$PROJECT_ROOT/iaAi/iaMl/iaMemory"

# Подкаталоги научных библиотек
create_dir "$PROJECT_ROOT/iaScience/iaBiochemicalModeling"
create_dir "$PROJECT_ROOT/iaScience/iaGeneticModeling"
create_dir "$PROJECT_ROOT/iaScience/iaNewtonianPhysics"
create_dir "$PROJECT_ROOT/iaScience/iaQuantumPhysics"
create_dir "$PROJECT_ROOT/iaScience/iaAeroPhysics"
create_dir "$PROJECT_ROOT/iaScience/iaChemistry"
create_dir "$PROJECT_ROOT/iaScience/iaStatistics"
create_dir "$PROJECT_ROOT/iaScience/iaProbabilityTheory"
create_dir "$PROJECT_ROOT/iaScience/iaOrbitalMechanics"
create_dir "$PROJECT_ROOT/iaScience/iaGIS"
create_dir "$PROJECT_ROOT/iaScience/iaMathematicalModeling"
create_dir "$PROJECT_ROOT/iaScience/iaAstrobiology"
create_dir "$PROJECT_ROOT/iaScience/iaGeophysics"
create_dir "$PROJECT_ROOT/iaScience/iaNeuroscienceModeling"
create_dir "$PROJECT_ROOT/iaScience/iaClimateModeling"
create_dir "$PROJECT_ROOT/iaScience/iaEnergySystems"

# Подкаталоги операционной системы
create_dir "$PROJECT_ROOT/iaOs/iaKernel"
create_dir "$PROJECT_ROOT/iaOs/iaDrivers"
create_dir "$PROJECT_ROOT/iaOs/iaFileSystem"
create_dir "$PROJECT_ROOT/iaOs/iaSecurity"
create_dir "$PROJECT_ROOT/iaOs/iaNetworking"

# Подкаталоги криптографической защиты
create_dir "$PROJECT_ROOT/iaSecurity/iaCryptography"
create_dir "$PROJECT_ROOT/iaSecurity/iaSecureProtocols"
create_dir "$PROJECT_ROOT/iaSecurity/iaDataProtection"
create_dir "$PROJECT_ROOT/iaSecurity/iaBlockchain"
create_dir "$PROJECT_ROOT/iaSecurity/iaPostQuantumCryptography"

# Тесты
create_dir "$PROJECT_ROOT/tests/iaVectorTest"
create_dir "$PROJECT_ROOT/tests/iaVectorTest/data_to_tests"
create_dir "$PROJECT_ROOT/tests/iaVectorTest/Tests_Results"

echo "Структура проекта успешно создана!"
