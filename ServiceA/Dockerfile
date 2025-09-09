#FROM registry.access.redhat.com/ubi9/ubi:latest

#  RUN dnf install -y \
#      gcc gcc-c++ make \
#      cmake git wget unzip  && \
#      dnf clean all
From ghcr.io/st3ff3nbusch/service:latest
RUN dnf install -y wget
WORKDIR /app
COPY . .
RUN rm -fR build/*
# Include httplib header
RUN mkdir -p /usr/local/include && \
    wget https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h -O /usr/local/include/httplib.h

RUN mkdir -p build && cd build && cmake .. && make -j$(nproc)

CMD ["./build/service-a"]