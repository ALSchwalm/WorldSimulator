# SConstruct
import os
import sys
import re
import platform
import fnmatch
import glob
from subprocess import Popen

UNITTEST = int(ARGUMENTS.get("unittest", True))
SHARED_LIB = int(ARGUMENTS.get("lib", True))
CXX = ARGUMENTS.get('CXX', 'g++')
BIN_NAME = "simulator"
BUILD_PATH = "build/"

env = Environment(CXX=CXX, ENV=os.environ)

env.Append(CXXFLAGS=['-Wall', '-Wextra', '-std=c++11', '-DBOOST_LOG_DYN_LINK=1'])

env.Append(LIBS = ['python2.7', 'boost_python',
                   'boost_system', 'boost_log_setup', 'boost_log',
                   'pthread', 'boost_date_time', 'boost_thread'])

if platform.system() == "Windows":
   env["LIBS"] += ["pdcurses"]
elif platform.system() == "Linux":
   env["LIBS"] += ["ncurses"]


env.Append(CPPPATH=["include", "/usr/include/python2.7"])

def create_objs(SRCS):
    return [env.Object(src) for src in SRCS]

src_list = []
for root, dirnames, filenames in os.walk('src/'):
    for filename in fnmatch.filter(filenames, '*.cpp'):
        src_list.append(os.path.join(root, filename))


if SHARED_LIB:
   lib_env = env.Clone()
   lib_env["CXXFLAGS"] += ["-shared", "-fPIC"]
   lib_src_list = ["lib/"+src_file.name for src_file in Glob("lib/*.cpp")]
   LIB_NAME = "simulator.so"
   lib_env.SharedLibrary(target=BUILD_PATH + LIB_NAME,
                         source = lib_src_list,
                         SHLIBPREFIX='')

if UNITTEST:
   test_src_list = list(src_list)
   test_src_list.remove("src/main.cpp")
   test_src_list += ["tests/"+test.name for test in Glob("tests/*.cpp")]
   env["LIBS"] += ["boost_unit_test_framework"]
   env.Program(target =BUILD_PATH + "unittest", source = create_objs(test_src_list))

if platform.system() == "Windows":
    env.Program(target = BUILD_PATH + BIN_NAME + ".exe", source = create_objs(src_list))
elif platform.system() == "Linux":
    env.Program(target =BUILD_PATH + BIN_NAME, source = create_objs(src_list))
