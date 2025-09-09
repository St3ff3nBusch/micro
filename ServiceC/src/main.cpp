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
    std::chrono::system_clock::time_point deadline =
            std::chrono::system_clock::now() + std::chrono::seconds(2);
        context.set_deadline(deadline);
        Status status = stub_->GetMessage(&context, request, &reply);

        if (status.ok()) {
            return reply.message();
        }else if (status.error_code() == grpc::StatusCode::DEADLINE_EXCEEDED) {
            return "RPC timeout";
        }  else {
            return "RPC failed";
        }
    }

private:
    std::unique_ptr<MyService::Stub> stub_;
};

int main() {
      try {
    MyServiceClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    std::string response = client.GetMessage("World2");

      if (response.empty()) {
            std::cerr << "ERROR: Response is empty!" << std::endl;
            return 1;
            }else {
            std::cout << "ServiceC received test: " << response <<"return "<< !response.compare("Helloooo World")<<std::endl;
                return !response.compare("Helloooo World");
        }
     } catch (const std::exception& e) {
        std::cerr << "ServiceC error: " << e.what() << std::endl;
        return 1;
     }
}