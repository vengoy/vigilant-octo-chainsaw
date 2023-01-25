FROM nginx:latest
LABEL version="0.1"
WORKDIR /home/
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./run.sh /home/run.sh
RUN \
    touch /var/run/nginx.pid ;\
    chown -R nginx:nginx /var/run/nginx.pid /var/log/nginx /var/cache/nginx ;\
    chmod +x /home/run.sh

USER nginx
HEALTHCHECK --interval=1m --timeout=3s \ 
    CMD curl -f http://localhost/ || exit 1

ENTRYPOINT ["/home/run.sh", "bash" ]
