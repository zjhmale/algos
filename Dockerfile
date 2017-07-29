 FROM gcc:4.9
 RUN mkdir /code
 WORKDIR /code
 ADD . /code/