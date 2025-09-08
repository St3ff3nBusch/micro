FROM registry.access.redhat.com/ubi8/ubi:8.9

# Dev tools
RUN yum install -y gcc-c++ cmake make git

WORKDIR /app
COPY src/ src/
COPY include/ include/
COPY tests/ tests/
COPY CMakeLists.txt CMakeLists.txt

RUN mkdir -p build && cd build && cmake .. && make -j

EXPOSE 8080
CMD ["./build/microservice"]