# GCPubSub
POC code for using Google Cloud PubSub

# Dependencies

## Build google-cloud-cpp 

```
git clone https://github.com/googleapis/google-cloud-cpp.git

brew install openssl
brew install openssl abseil
brew install protobuf grpc
brew install googletest

cd google-cloud-cpp
mkdir -p build
cd build

cmake .. \
  -GNinja \
  -DCMAKE_INSTALL_PREFIX=$HOME/.local \
  -DCMAKE_BUILD_TYPE=Release \
  -DBUILD_TESTING=OFF \
  -DGOOGLE_CLOUD_CPP_ENABLE=pubsub \
  -DGOOGLE_CLOUD_CPP_ENABLE_CXX_EXCEPTIONS=ON \
  -DGOOGLE_CLOUD_CPP_ENABLE_MACOS_OPENSSL_CHECK=OFF \
  -DOPENSSL_ROOT_DIR=$(brew --prefix openssl) \
  -Dabsl_DIR=$(brew --prefix)/lib/cmake/absl \
  -DProtobuf_DIR=$(brew --prefix)/lib/cmake/protobuf \
  -DgRPC_DIR=$(brew --prefix)/lib/cmake/grpc

```

```
ninja
ninja install
```

## Build GCPubSub

Back the GCPubSub/build

```
cd build
cmake .. -DCMAKE_PREFIX_PATH=$HOME/.local
ninja     # or: make

./pubsub_publisher your-project-id your-topic-id "Hello from Mac"

```
