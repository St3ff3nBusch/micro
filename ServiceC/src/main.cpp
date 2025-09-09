#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "service.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using micro::MyService;
using micro::Request;
using micro::Response;

class MyServiceClient {
public:
    MyServiceClient(std::shared_ptr<Channel> channel)
        : stub_(MyService::NewStub(channel)) {}

    std::string GetMessage(const std::string& query) {
        Request request;
        request.set_query(query);

        Response reply;
        ClientContext context;

        Status status = stub_->GetMessage(&context, request, &reply);

        if (status.ok()) {
            return reply.message();
        } else {
            return "RPC failed";
        }
    }

private:
    std::unique_ptr<MyService::Stub> stub_;
};

int main() {
    std::cout<<"ServiceC started"<<std::endl;
    MyServiceClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    std::string response = client.GetMessage("World");
    std::cout << "ServiceC received: " << response << std::endl;
    return 0;
}