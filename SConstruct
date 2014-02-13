# SConstruct
import os
import sys
import re
import platform
import fnmatch
import glob
from subprocess import Popen

UNITTEST = ARGUMENTS.get("unittest", 0)
BIN_NAME = "simulator"
BIN_PATH = "build/"

env = Environment()

env.Append(LIBPATH = ['../lib'])
env.Append(CXXFLAGS=['-Wall', '-Wextra', '-std=c++11'])

if platform.system() == "Windows":
   env.Append(LIBS = ['pdcurses', 'jsoncpp'])
elif platform.system() == "Linux":
   env.Append(LIBS = ['ncurses', 'jsoncpp'])
   
env.Append(CPPPATH=['include'])

src_list = []
for root, dirnames, filenames in os.walk('scr/'):
    for filename in fnmatch.filter(filenames, '*.cpp'):
        src_list.append(os.path.join(root, filename))

if UNITTEST:
    src_list.remove("scr/main.cpp")
    tests = Glob("tests/*.cpp")
    src_list += ["tests/"+test.name for test in tests]
    BIN_NAME = "unittest"
    env["LIBS"] += ["gtest_main", "gtest", "pthread"]

if platform.system() == "Windows":
    env.Program(target = BIN_PATH + BIN_NAME + ".exe", source = src_list)
elif platform.system() == "Linux":
    env.Program(BIN_PATH + BIN_NAME, source = src_list)
