#!/bin/bash

# Определяем корневую папку проекта
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

# Путь к научным библиотекам
SCIENCE_DIR="$PROJECT_ROOT/iaAi/iaScience"

# Создаём массив с названиями научных библиотек
SCIENCE_LIBS=(
    "iaBiochemicalModeling"
    "iaGeneticModeling"
    "iaNewtonianPhysics"
    "iaQuantumPhysics"
    "iaAeroPhysics"
    "iaChemistry"
    "iaStatistics"
    "iaProbabilityTheory"
    "iaOrbitalMechanics"
    "iaGIS"
    "iaMathematicalModeling"
    "iaAstrobiology"
    "iaGeophysics"
    "iaNeuroscienceModeling"
    "iaClimateModeling"
    "iaEnergySystems"
)

# Создаём директории
for LIB in "${SCIENCE_LIBS[@]}"; do
    mkdir -p "$SCIENCE_DIR/$LIB"
    echo "Создана папка: $SCIENCE_DIR/$LIB"
done

echo "Все научные библиотеки добавлены!"
