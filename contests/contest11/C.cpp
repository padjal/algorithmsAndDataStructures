#include <iostream>
#include <string>

class BloomFilter {
private:
    size_t bits_;
    size_t hashes_;

public:
    BloomFilter(size_t hashes, size_t bits) {
        bits_ = bits;
        hashes_ = hashes;
    }

    ~BloomFilter() {
    }

    // вставка информации об объекте
    void add(const std::string &obj) {
    }

    // проверка принадлежности объекта
    bool verify(const std::string &obj) {
        return true;
    }

    // считаем относительную величину false positive rate по запросам тестирования
    // принадлежности
    double getFPRate() const {
        return 0;
    }

    size_t numberOfHashFunctions() const {
        return hashes_;
    }

    size_t numberOfBits() const {
        return bits_;
    }
};
