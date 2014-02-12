# SConstruct
import os
import sys
import re
import platform
import fnmatch
import glob
from subprocess import Popen

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

if platform.system() == "Windows":
   env.Program(target = "build/simulator.exe", source = src_list)
elif platform.system() == "Linux":
   env.Program("build/simulator", source = src_list)
