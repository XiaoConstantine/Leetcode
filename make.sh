#!/bin/sh

TEST_PATH="/Users/Constantine/interviewPractice/UnitTest++"

g++ -I TEST_PATH/src -c $1.cc -o $1.o 
g++ $1.o $TEST_PATH/libUnitTest++.a


