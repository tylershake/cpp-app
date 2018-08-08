FROM nginx:1.14

RUN apt-get -y update && apt-get install -y build-essential cmake doxygen \
libboost-all-dev git

RUN useradd -m tempuser

WORKDIR /home/tempuser

RUN git clone https://github.com/google/googletest.git

RUN cd googletest && mkdir build && cd build && cmake .. && make && make install

COPY . /home/tempuser/cpp-app

RUN chown -R tempuser:tempuser /home/tempuser/cpp-app

WORKDIR /home/tempuser/cpp-app

USER tempuser

RUN mkdir build && cd build && cmake .. && make && make test

USER root

WORKDIR /home/tempuser/cpp-app/build

RUN make install && make docs

RUN ldconfig

RUN cp -r ./docs/html/* /usr/share/nginx/html/

