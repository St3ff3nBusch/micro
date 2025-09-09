cmake_minimum_required(VERSION 3.10)
project(ServiceD CXX)
include_directories(${CMAKE_CURRENT_BINARY_DIR} src/proto include )
set(CMAKE_CXX_STANDARD 17)
find_package(Protobuf REQUIRED)
find_package(gRPC CONFIG REQUIRED)

set(PROTO_FILE ../proto/service.proto)
set(PROTO_SRCS
    src/proto/service.pb.cc
    src/proto/service.grpc.pb.cc
)

set(PROTO_HDRS
    src/proto/service.pb.h
    src/proto/service.grpc.pb.h
)
# Generate gRPC & Proto sources
# protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILE})
# grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_FILE})

add_executable(service_d src/main.cpp ${PROTO_SRCS} ${PROTO_HDRS} ${GRPC_SRCS} ${GRPC_HDRS})
find_package(absl REQUIRED)

target_link_libraries(service_d
    gRPC::grpc++
    protobuf::libprotobuf
    absl::base
    absl::strings
    absl::time
    absl::synchronization
)