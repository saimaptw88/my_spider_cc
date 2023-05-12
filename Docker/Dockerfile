FROM ubuntu:20.04

ENV GOOGLE_TEST_VERSION 1.12.0
ENV CMAKE_VERSION 3.24.2

RUN apt-get update \
  && apt-get install -y \
      build-essential \
      clang \
      curl \
      libssl-dev \
      python3-pip \
  && pip3 install cpplint \
  && apt-get clean \
  && rm -r /var/lib/apt/lists/* \
  && mkdir /tmp/src

WORKDIR /tmp/src
RUN curl -OL https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}.tar.gz \
    && tar zxvf cmake-${CMAKE_VERSION}.tar.gz \
    && cd cmake-${CMAKE_VERSION}/ \
    && ./bootstrap \
    && make \
    && make install

RUN curl -OL https://github.com/google/googletest/archive/release-${GOOGLE_TEST_VERSION}.tar.gz \
    && tar -zxvf release-${GOOGLE_TEST_VERSION}.tar.gz \
    && mkdir ./googletest-release-${GOOGLE_TEST_VERSION}/build \
    && cd /tmp/src/googletest-release-${GOOGLE_TEST_VERSION}/build \
    && cmake .. \
    && make \
    && make install

WORKDIR /tmp
RUN rm -rf ./src/
