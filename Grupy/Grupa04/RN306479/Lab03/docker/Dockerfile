# Creates a layer from the latest ubuntu Docker image.
FROM ubuntu:latest

# Update Ubuntu repository
RUN apt-get update

# Set noninteractive mode
ARG DEBIAN_FRONTEND=noninteractive

# Install git
RUN apt-get install git -y

# Image description
LABEL version="0.1"
LABEL description="Radoslaw Niestroj docker image."

# Install nginx, php-fpm and supervisord from ubuntu repository
RUN apt-get install -y nginx php-fpm supervisor && \
    rm -rf /var/lib/apt/lists/* && apt clean

#Define the ENV variable
ENV nginx_vhost /etc/nginx/sites-available/default
ENV php_conf /etc/php/7.4/fpm/php.ini
ENV nginx_conf /etc/nginx/nginx.conf
ENV supervisor_conf /etc/supervisor/supervisord.conf

# Enable php-fpm on nginx virtualhost configuration
COPY default ${nginx_vhost}
RUN sed -i -e 's/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/g' ${php_conf} && \
    echo "\ndaemon off;" >> ${nginx_conf}

#Copy supervisor configuration
COPY supervisord.conf ${supervisor_conf}

RUN mkdir -p /run/php && \
    chown -R www-data:www-data /var/www/html && \
    chown -R www-data:www-data /run/php

# Volume configuration
VOLUME ["/etc/nginx/sites-enabled", "/etc/nginx/certs", "/etc/nginx/conf.d", "/var/log/nginx", "/var/www/html"]

# Configure Services and Port
COPY start.sh /start.sh
CMD ["./start.sh"]

EXPOSE 80 443
