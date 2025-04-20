# Use slim Debian for a minimal and stable base
FROM ubuntu

# Avoid interactive prompts during apt install
ENV DEBIAN_FRONTEND=noninteractive

# Install core tools and dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    ninja-build \
    curl \
    unzip \
    pkg-config \
    python3 \
    ca-certificates \
    libx11-dev \
    libxrandr-dev \
    libxcursor-dev \
    libxext-dev \
    libxi-dev \
    libgl1-mesa-dev \
    libvulkan-dev \
    libasound2-dev \
    libpulse-dev \
    yasm \
    nasm \
    automake \
    autoconf \
    libtool \
    python3-jinja2 \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Optional: Set up user for non-root dev environment (improves Git integration)
ARG USERNAME=vscode
ARG USER_UID=1001
ARG USER_GID=$USER_UID

# Check if group exists; if not, create it
RUN if ! getent group $USER_GID; then groupadd --gid $USER_GID $USERNAME; fi \
    && if ! id -u $USERNAME > /dev/null 2>&1; then useradd --uid $USER_UID --gid $USER_GID -m $USERNAME; fi

# Set user to non-root (VS Code DevContainer expects this)
USER $USERNAME

# Clone vcpkg (if needed by your devcontainer.json)
WORKDIR /home/$USERNAME
RUN git clone https://github.com/microsoft/vcpkg.git && \
    cd vcpkg && ./bootstrap-vcpkg.sh -disableMetrics

ENV PATH="/home/$USERNAME/vcpkg:${PATH}"
ENV VCPKG_ROOT="/home/$USERNAME/vcpkg}"
ENV CMAKE_TOOLCHAIN_FILE="/home/$USERNAME/vcpkg/scripts/buildsystems/vcpkg.cmake"

# Default workdir for devcontainer
WORKDIR /workspace

