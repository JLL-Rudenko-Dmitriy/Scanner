#include <parser.hpp>
#include <string.h>

ArgParser::ArgParser(int argc, const char **argv) {
    num_args = argc-1;

    for (int args = 1; args < argc; args++) {
        if (argv[args][0] == '-') {
            if (argv[args][1] != 'r') {
                printf("invalid key argument: %s\n\t!Use -r for range\n",(char*)argv[args]);
                correct = false;
                break;
            }
            ranged = true;
        }
        else {
            bool is_correct_port = true;
            for(int ch = 0; ch < strlen(argv[args]); ++ch) {
                if ((argv[args][ch]<'0') || (argv[args][ch]>'9')) {
                    if (argv[args][ch] == '.') {
                        is_correct_port = false;
                        ip = argv[args];
                        break;
                    } else {
                        printf("invalid value argument: %s\n", (char*)argv[args]);
                        is_correct_port = false;
                        correct = false;
                        break;
                    }
                }
            }
            if (is_correct_port) {
                values.insert(std::atoi(argv[args]));
            }
        }
    };
    if ((isRanged()) && (values.size() != 2)) {
        printf("Incorrect count of ranged arguments\n");
        correct = false;
    }
    if (values.size() == 0) {
        correct = false;
        printf("Incorrect count of arguments\n");
    }
    if (ip==nullptr) {
        correct = false;
        printf("IP parameter not passed\n");
    }
}

std::pair<uint32_t, uint32_t> ArgParser::getRange(){
    auto s_value = values.begin();
    return std::pair<uint32_t, uint32_t>(*s_value, *(s_value++));
}