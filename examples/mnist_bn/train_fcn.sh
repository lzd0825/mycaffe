#!/usr/bin/env sh

./build/tools/caffe train -solver examples/mnist_bn/fcn_solver.prototxt -gpu 2
