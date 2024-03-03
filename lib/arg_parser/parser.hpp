#include <iostream>
#include <set>
#include <utility>
#include <cstdint>

class ArgParser {
public: 
    ArgParser(int argc, const char **argv);

    bool isCorrect() {return correct;};
    bool isRanged() {return ranged;};
    const char* getIp() {return ip;};
    std::pair<uint32_t, uint32_t> getRange();
    std::set<uint32_t> getValues(){return values;};

private:
    std::set<uint32_t> values;
    size_t num_args;
    const char* ip;
    bool ranged = false;
    bool correct = true;
};