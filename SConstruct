# SConstruct
import os
import sys
import re
import platform
import fnmatch
import glob
from subprocess import Popen

UNITTEST = ARGUMENTS.get("unittest", 0)
SHARED_LIB = ARGUMENTS.get("lib", True)
CXX = ARGUMENTS.get('CXX', 'g++')
BIN_NAME = "simulator"
BUILD_PATH = "build/"

env = Environment(CXX=CXX, ENV=os.environ)

env.Append(CXXFLAGS=['-Wall', '-Wextra', '-std=c++11'])

if platform.system() == "Windows":
   env.Append(LIBS = ['pdcurses', 'jsoncpp', 'python2.7', 'boost_python'])
elif platform.system() == "Linux":
   env.Append(LIBS = ['ncurses', 'jsoncpp', 'python2.7', 'boost_python'])

env.Append(CPPPATH=["include", "/usr/include/python2.7"])

src_list = []
for root, dirnames, filenames in os.walk('src/'):
    for filename in fnmatch.filter(filenames, '*.cpp'):
        src_list.append(os.path.join(root, filename))

if UNITTEST:
   src_list.remove("src/main.cpp")
   src_list += ["tests/"+test.name for test in Glob("tests/*.cpp")]
   BIN_NAME = "unittest"
   env["LIBS"] += ["gtest_main", "gtest", "pthread"]

if SHARED_LIB:
   lib_env = env.Clone()
   lib_env["CXXFLAGS"] += ["-shared", "-fPIC"]
   lib_src_list = ["lib/"+src_file.name for src_file in Glob("lib/*.cpp")]
   LIB_NAME = "simulator.so"
   lib_env.SharedLibrary(BUILD_PATH + LIB_NAME, source = lib_src_list)

if platform.system() == "Windows":
    env.Program(target = BUILD_PATH + BIN_NAME + ".exe", source = src_list)
elif platform.system() == "Linux":
    env.Program(BUILD_PATH + BIN_NAME, source = src_list)
