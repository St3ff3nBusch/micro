#include "httplib.h"
using namespace std;
int main() {
    httplib::Server svr;

    svr.Get("/data", [](const httplib::Request&, httplib::Response& res) {
        cout << "Service B received a request!" << endl;
        res.set_content("Hello from Service B!", "text/plain");
    });

    svr.listen("0.0.0.0", 4000);
}