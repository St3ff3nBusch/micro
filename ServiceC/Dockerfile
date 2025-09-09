FROM fedora:40

RUN dnf -y install git cmake make gcc-c++ libstdc++-devel


WORKDIR /tmp
RUN git clone --recurse-submodules -b v1.54.3 https://github.com/grpc/grpc
WORKDIR /tmp/grpc
RUN dnf -y install openssl-devel
RUN mkdir -p cmake/build && cd cmake/build && \
    cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF \
          -DCMAKE_BUILD_TYPE=Release \
          -DCMAKE_CXX_STANDARD=17 \
          -DCMAKE_C_STANDARD=11 \
          -DCMAKE_C_FLAGS="-std=gnu11" \
          ../.. && \
    make -j$(nproc) && make install
RUN ldconfig


WORKDIR /app

COPY . .


RUN mkdir -p src/proto && \
    protoc -Iproto \
      --cpp_out=src/proto \
      --grpc_out=src/proto \
        --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin \
      proto/service.proto
RUN cmake -S . -B build && cmake --build build --target service_c -- -j$(nproc)

CMD ["./build/service_c"]