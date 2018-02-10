#!/bin/bash
java -jar /usr/local/lib/antlr-4.7.1-complete.jar Zin.g4 -o build-test
javac build-test/Zin*.java
cd build-test
cat ../test.zn | java org.antlr.v4.gui.TestRig Zin program -gui
