#include <iostream>
#include <unordered_set>
#include <fstream>
#include "Time.h"

class Hash {
private:
    static int a, b;
public:
    size_t operator()(const std::string str_) const {
        long sum = 0;
        long mult = 1;
        for (char c:str_) {
            sum += c*mult;
            mult *=static_cast<long>(b);
        }
        return sum%a;
    }
};

typedef std::unordered_set<std::string, Hash> JustSet;
int Hash::a = 97;
int Hash::b = 128;
const int d = 128;
const int c = 97;
int main() {
    const std::string it_necessary_to_write = "Results.txt";
    const std::string elements = "Elements.txt";

    std::unordered_set<std::string, Hash> just_set;

    std::ifstream read_file("dostoevsky.txt");
    Time regisrtation(it_necessary_to_write);
    std::string buffer;
    regisrtation.start();
    read_file >> buffer;
    while (!read_file.eof()) {
        just_set.insert(buffer);
        read_file >> buffer;
    }
    read_file.close();
    regisrtation.end();
    regisrtation.log("unordered_set", "read", "a, b", 0);
    regisrtation.reset();
    regisrtation.start();
    just_set.find("выразить");
    regisrtation.end();
    regisrtation.log("unordered_set", "find", "b, a", 0);
    regisrtation.reset();
    std::ofstream write(elements);
    write << "hash; elements" << std::endl;
    for (size_t i = 0; i < c; i++) {
        write << i << ";" << just_set.bucket_size(i) << std::endl;
    }
    write.close();
    return 0;
}
