#include <vector>
#include <fstream>
#include <iostream>
#include "split.h"

class BuffListLoader {
private:
    std::vector<std::string> readFile() {
        std::vector<std::string> list_of_buffs;
        std::string line;
        std::ifstream file_read;
        file_read.open("../src/Game/Buff/Buffs.h");
        if (file_read.is_open()) {
            while (file_read) {
                std::getline(file_read, line);
                std::vector<std::string> v = split(line, ' ');
                if (v[0] == "class") {
                    std::string class_name = v[1];
                    if (class_name[class_name.length()-1] == ':') {
                        class_name.pop_back();
                    }
                    list_of_buffs.push_back(class_name);
                }
            }
        }
        file_read.close();
        return list_of_buffs;
    }
    void writeFile(std::vector<std::string> list_of_buffs) {
        std::ofstream file_write;
        file_write.open("../src/Game/Buff/ListOfBuffs.h");
        if (file_write.is_open()) {
            file_write << "std::vector<std::variant<";
            for (int i = 0; i < list_of_buffs.size()-1; i++) {
                file_write << list_of_buffs[0] + ", ";
            }
            file_write << list_of_buffs[list_of_buffs.size()-1] << ">> v_buffs;";
        }
        file_write.close();
    }
public:
    BuffListLoader() = default;

    void loadBuffList() {
        writeFile(readFile());
    }
};

int main() {
    BuffListLoader buff_list_loader;
    buff_list_loader.loadBuffList();
    return 0;
}
