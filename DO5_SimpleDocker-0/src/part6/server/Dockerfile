FROM nginx:latest
LABEL version="0.1"
WORKDIR /home/
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./hello.c /home/hello.c
COPY ./run.sh /home/run.sh
RUN apt-get update && \
    apt-get install -y gcc spawn-fcgi libfcgi-dev ;\
    apt-get clean && rm -rf /var/lib/apt/lists/* ;\
    touch /var/run/nginx.pid ;\
    chown -R nginx:nginx /etc/nginx/nginx.conf nginx:nginx /var/cache/nginx nginx:nginx /home ; \
    touch /var/run/nginx.pid ;\
    chown -R nginx:nginx /var/run/nginx.pid ;\
    chmod u-s /usr/bin/gpasswd /usr/bin/newgrp /bin/su /bin/mount /bin/umount /usr/bin/chsh /usr/bin/chfn /usr/bin/chsh ;\
    chmod 255 /usr/bin/expiry /usr/bin/wall /sbin/unix_chkpwd /usr/bin/chage ;\
    chmod 755 /usr/bin/passwd
USER nginx

HEALTHCHECK --interval=1m --timeout=3s \ 
    CMD curl -f http://localhost/ || exit 1

ENTRYPOINT ["sh","/home/run.sh" ]
