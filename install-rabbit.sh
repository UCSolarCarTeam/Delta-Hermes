#!/usr/bin/env bash

CWD=$(pwd)
RABBITC_DIR="rabbitmq-c"

sudo apt-get install cmake
sudo apt-get install libssl-dev

git clone https://github.com/alanxz/rabbitmq-c.git
cd rabbitmq-c
git checkout e1746f92585d59364fc48b6305ce25d7fc86c2a4
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr/local -BUILD_EXAMPLES=OFF BUILD_TESTS=OFF  BUILD_TOOLS=OFF BUILD_TOOLS_DOCS=OFF ENABLE_SSL_SUPPORT=OFF ..
sudo cmake --build . --config Release --target install

git clone https://github.com/akalend/amqpcpp.git
cd amqpcpp
make
sudo cp include/AMQPcpp.h /usr/local/include
sudo cp libamqpcpp.a /usr/local/lib 

cd $CWD
rm -rf "$CWD/$RABBITC_DIR" 
