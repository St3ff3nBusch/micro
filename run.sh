#!/bin/bash
set -e

# Get the directory of the script (project root)
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
echo "Project root: $PROJECT_ROOT"
# Remove old containers if they exist
podman rm -f service-b service-a 2>/dev/null || true

# Build Service B
cd "$PROJECT_ROOT/ServiceB"
podman build -t service-b .

# Build Service A
cd "$PROJECT_ROOT/ServiceA"
podman build -t service-a .

# Run Service B (server) using host networking
podman run -d --name service-b --network=host service-b

# Run Service A (client)
podman run --rm --name service-a --network=host service-a