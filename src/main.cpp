#include <httplib.h>
#include "service.hpp"
#include <iostream>

int main() {
    httplib::Server svr;

    svr.Get("/hello", [](const httplib::Request&, httplib::Response& res) {
        res.set_content(hello(), "text/plain");
    });

    std::cout << "Microservice running on port 8080\n";
    svr.listen("0.0.0.0", 8080);
}
