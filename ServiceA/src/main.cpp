#include "httplib.h"
#include <iostream>

int main() {
    httplib::Client cli("http://localhost:4000");
while(true){
    auto res = cli.Get("/data");
    if (res) {
        std::cout << "Service A received: " << res->body << std::endl;
    } else {
        std::cout << "Request failed" << std::endl;
    }
sleep(1);
}
}