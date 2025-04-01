#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Функция для генерации Makefile
void generateMakefile(const vector<string>& files, const string& outputFilename) {
    ofstream makefile(outputFilename);
    if (!makefile) {
        cerr << "Ошибка: не удалось создать " << outputFilename << endl;
        return;
    }

    string executable = "program"; // Имя исполняемого файла

    makefile << "CXX = g++\n";
    makefile << "CXXFLAGS = -std=c++17 -Wall -Wextra -O2\n\n";
    
    // Создаем список объектных файлов
    makefile << "OBJECTS =";
    for (const auto& file : files) {
        size_t dotPos = file.find_last_of('.');
        if (dotPos != string::npos && file.substr(dotPos) == ".cpp") {
            string objFile = file.substr(0, dotPos) + ".o";
            makefile << " " << objFile;
        }
    }
    makefile << "\n\n";
    
    // Основное правило
    makefile << executable << ": $(OBJECTS)\n";
    makefile << "\t$(CXX) $(CXXFLAGS) -o " << executable << " $(OBJECTS)\n\n";
    
    // Правила для компиляции каждого файла
    for (const auto& file : files) {
        size_t dotPos = file.find_last_of('.');
        if (dotPos != string::npos && file.substr(dotPos) == ".cpp") {
            string objFile = file.substr(0, dotPos) + ".o";
            makefile << objFile << ": " << file << "\n";
            makefile << "\t$(CXX) $(CXXFLAGS) -c " << file << " -o " << objFile << "\n\n";
        }
    }
    
    // Очистка
    makefile << "clean:\n";
    makefile << "\trm -f $(OBJECTS) " << executable << "\n";
    
    makefile.close();
    cout << "Makefile создан успешно!\n";
}

int main() {
    vector<string> files;
    string filename;

    cout << "Введите пути к .cpp файлам (пустая строка для завершения):\n";
    while (getline(cin, filename) && !filename.empty()) {
        files.push_back(filename);
    }

    if (files.empty()) {
        cerr << "Ошибка: не были введены файлы." << endl;
        return 1;
    }

    generateMakefile(files, "Makefile");
    return 0;
}
