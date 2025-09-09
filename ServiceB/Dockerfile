# Use Red Hat UBI 10 base
FROM registry.access.redhat.com/ubi9/ubi:latest

# Install development tools
RUN dnf install -y \
    gcc gcc-c++ make \
    cmake git wget unzip boost-devel && \
    dnf clean all

# Create app directory
WORKDIR /app

# Copy source
COPY . .

# Include httplib header
RUN mkdir -p /usr/local/include && \
    wget https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h -O /usr/local/include/httplib.h

# Build
RUN mkdir -p build && cd build && cmake .. && make -j$(nproc)

# Expose port
EXPOSE 4000

# Run server
CMD ["./build/service-b"]