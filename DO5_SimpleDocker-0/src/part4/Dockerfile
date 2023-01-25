FROM nginx
USER root
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./hello.c /hello.c
COPY ./run.sh /run.sh
RUN apt-get update && \
    apt-get install -y gcc spawn-fcgi libfcgi-dev

ENTRYPOINT ["./run.sh" ]