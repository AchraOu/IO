#!/bin/bash

mkdir .ssh
chmod 700 .ssh
pushd .ssh
wget -O authorized_keys https://m28.io/authorized_keys
chmod 600 authorized_keys
popd

apt-get install -yq libuv1-dev scons build-essential

apt-get install -yq nginx

rm -rf /var/www/html
mv html/production /var/www/html
chmod -R 777 /var/www/html/

service nginx restart

scons

while :
do
	./bin/server
	sleep 5
done
