#!/bin/sh

pushd html
node compile.node.js
popd

rm -rf bin
rm -rf server/src/*.o

m28n deploy -i cursors
