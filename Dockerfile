# daemon runs in the background
# run something like tail /var/log/zumcoind/current to see the status
# be sure to run with volumes, ie:
# docker run -v $(pwd)/zumcoind:/var/lib/zumcoind -v $(pwd)/wallet:/home/zumcoin --rm -ti zumcoin:0.2.2
ARG base_image_version=0.10.0
FROM phusion/baseimage:$base_image_version

ADD https://github.com/just-containers/s6-overlay/releases/download/v1.21.2.2/s6-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/s6-overlay-amd64.tar.gz -C /

ADD https://github.com/just-containers/socklog-overlay/releases/download/v2.1.0-0/socklog-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/socklog-overlay-amd64.tar.gz -C /

ARG ZUMCOIN_BRANCH=master
ENV ZUMCOIN_BRANCH=${ZUMCOIN_BRANCH}

# install build dependencies
# checkout the latest tag
# build and install
RUN apt-get update && \
    apt-get install -y \
      build-essential \
      python-dev \
      gcc-4.9 \
      g++-4.9 \
      git cmake \
      libboost1.58-all-dev && \
    git clone https://github.com/zumcoin/zumcoin.git /src/zumcoin && \
    cd /src/zumcoin && \
    git checkout $ZUMCOIN_BRANCH && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_CXX_FLAGS="-g0 -Os -fPIC -std=gnu++11" .. && \
    make -j$(nproc) && \
    mkdir -p /usr/local/bin && \
    cp src/ZumCoind /usr/local/bin/ZumCoind && \
    cp src/walletd /usr/local/bin/walletd && \
    cp src/zumwallet /usr/local/bin/zumwallet && \
    cp src/miner /usr/local/bin/miner && \
    strip /usr/local/bin/ZumCoind && \
    strip /usr/local/bin/walletd && \
    strip /usr/local/bin/zumwallet && \
    strip /usr/local/bin/miner && \
    cd / && \
    rm -rf /src/zumcoin && \
    apt-get remove -y build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost1.58-all-dev && \
    apt-get autoremove -y && \
    apt-get install -y  \
      libboost-system1.58.0 \
      libboost-filesystem1.58.0 \
      libboost-thread1.58.0 \
      libboost-date-time1.58.0 \
      libboost-chrono1.58.0 \
      libboost-regex1.58.0 \
      libboost-serialization1.58.0 \
      libboost-program-options1.58.0 \
      libicu55

# setup the zumcoind service
RUN useradd -r -s /usr/sbin/nologin -m -d /var/lib/zumcoind zumcoind && \
    useradd -s /bin/bash -m -d /home/zumcoin zumcoin && \
    mkdir -p /etc/services.d/zumcoind/log && \
    mkdir -p /var/log/zumcoind && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/zumcoind/run && \
    echo "fdmove -c 2 1" >> /etc/services.d/zumcoind/run && \
    echo "cd /var/lib/zumcoind" >> /etc/services.d/zumcoind/run && \
    echo "export HOME /var/lib/zumcoind" >> /etc/services.d/zumcoind/run && \
    echo "s6-setuidgid zumcoind /usr/local/bin/ZumCoind" >> /etc/services.d/zumcoind/run && \
    chmod +x /etc/services.d/zumcoind/run && \
    chown nobody:nogroup /var/log/zumcoind && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/zumcoind/log/run && \
    echo "s6-setuidgid nobody" >> /etc/services.d/zumcoind/log/run && \
    echo "s6-log -bp -- n20 s1000000 /var/log/zumcoind" >> /etc/services.d/zumcoind/log/run && \
    chmod +x /etc/services.d/zumcoind/log/run && \
    echo "/var/lib/zumcoind true zumcoind 0644 0755" > /etc/fix-attrs.d/zumcoind-home && \
    echo "/home/zumcoin true zumcoin 0644 0755" > /etc/fix-attrs.d/zumcoin-home && \
    echo "/var/log/zumcoind true nobody 0644 0755" > /etc/fix-attrs.d/zumcoind-logs

VOLUME ["/var/lib/zumcoind", "/home/zumcoin","/var/log/zumcoind"]

ENTRYPOINT ["/init"]
CMD ["/usr/bin/execlineb", "-P", "-c", "emptyenv cd /home/zumcoin export HOME /home/zumcoin s6-setuidgid zumcoin /bin/bash"]
