FROM ghcr.io/st3ff3nbusch/service:latest


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