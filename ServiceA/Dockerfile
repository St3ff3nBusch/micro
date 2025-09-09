FROM registry.access.redhat.com/ubi9/ubi:latest

RUN dnf install -y \
    gcc gcc-c++ make \
    cmake git wget unzip boost-devel && \
    dnf clean all

WORKDIR /app
COPY . .

# Include httplib header
RUN mkdir -p /usr/local/include && \
    wget https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h -O /usr/local/include/httplib.h

RUN mkdir -p build && cd build && cmake .. && make -j$(nproc)

CMD ["./build/service-a"]