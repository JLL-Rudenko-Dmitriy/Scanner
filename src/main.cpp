#include <iostream>
#include <Scanner.cpp>
#include <parser.cpp>

int main(int argc, const char **argv) {
    
    ArgParser* parser = new ArgParser(argc, argv);
    if (parser->isCorrect()) {
        std::string ip = parser->getIp();

        if (parser->isRanged()) {
            std::pair<uint32_t,uint32_t> range = parser->getRange();
            for (uint32_t port = range.second; port < range.first; ++port) {
                tryConnect(ip,port);
            }
        } else {
            for (auto port: parser->getValues()) {
                tryConnect(ip,port);
            }
        } 
    }
    return 0;
}