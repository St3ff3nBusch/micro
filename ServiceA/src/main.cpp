#include "httplib.h"
#include <iostream>

int main() {
    httplib::Client cli("http://localhost:4000");
for(int i=0;i<10;i++)   {
    auto res = cli.Get("/data");
    if (res) {
        std::cout << "Service A new received: " << res->body << std::endl;
    } else {
        std::cout << "Request failed" << std::endl;
    }
sleep(1);
}
return 0;
}