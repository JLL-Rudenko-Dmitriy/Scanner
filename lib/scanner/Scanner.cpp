#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <string>

void tryConnect(std::string& ip, uint32_t& port) {
    uint32_t sock = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip.c_str());
    address.sin_port = htons(port);
    
    if (connect(sock, (struct sockaddr*)&address, sizeof(address)) < 0){
        close(sock);
        return ;
    }
    else {
        printf("PORT: %u is open!\n", port);
    }
    close(sock);
}; 