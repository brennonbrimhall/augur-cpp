FROM ubuntu:latest

RUN apt-get update && apt-get install build-essential cmake -y

RUN mkdir augur-cpp

COPY CMakeLists.txt augur-cpp/CMakeLists.txt
COPY License.txt augur-cpp/License.txt
COPY src augur-cpp/src
COPY examples augur-cpp/examples

RUN gcc --version && g++ --version

RUN cd .. \
&& mkdir build \
&& cd build \
&& cmake ../augur-cpp -DCMAKE_BUILD_TYPE=Release \
&& make && make install

RUN rm -rf augur build && apt-get purge build-essential cmake -y && apt-get autoremove -y