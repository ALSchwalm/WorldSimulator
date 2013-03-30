# SConstruct
import os
import sys
import re
from subprocess import Popen
from SConfig import *


# Minimum SCons and Python version for plugin
# SCons >= 2.0.0 drops Python pre-2.4 support!
EnsureSConsVersion(2, 0)
EnsurePythonVersion(2, 4)

# Set SCons options
WARN_PREFIX = "warn"
for (k, v) in SCONS_OPTIONS.iteritems():
    if k.startswith(WARN_PREFIX):
        SetOption(WARN_PREFIX, v[len(WARN_PREFIX) + 1:])
    else:
        SetOption(k, v)


# Setup Environment
def filter_includes(flags):
    return re.sub(r'\s*-I\S*', '', flags)


# Important to find compilers in system path to be in
# line with Eclipse CDT
env = Environment(ENV={'PATH': os.environ['PATH']})

if TOOLCHAIN_NAME.startswith('mingw') or TOOLCHAIN_NAME.startswith('cygwin'):
    Tool('mingw')(env) # Prefer MinGW over other compilers like cl.exe
else:
    env.Replace(CC=COMPILER_NAME, CXX=COMPILER_NAME)

if not COMP_INCLUDES_INTO_CCFLAGS:
    env.Append(CPPPATH=INCLUDES)
    C_FLAGS = filter_includes(C_FLAGS)
    CXX_FLAGS = filter_includes(CXX_FLAGS)

env.Append(CFLAGS=C_FLAGS, CXXFLAGS=CXX_FLAGS)
env.Append(CXXFLAGS=['-std=c++0x'])
LIBRARIES = ['pdcurses']
LIBRARY_PATHS = ['lib/']
env.Append(CPPPATH=["include"])
env.Replace(CCFLAGS='') # otherwise we have /nolink in Windows there
env.Decider(DECIDER)
env['SHOBJSUFFIX'] = '.o' # SCons otherwise uses .os suffix for Cygwin and MacOS X

excludes = "tests/*.cpp"

# Initialize variables
ARTIFACT_NAME = os.path.join(BUILD_CONFIGURATION, BUILD_ARTIFACT_NAME)
objs = []
pic = PROJECT_TYPE == 'so'


# Setup pre- and post-build steps
def call_command(command, msg):
    """Calls the given command and prints msg before."""
    print msg
    try:
        p = Popen(command)
        os.waitpid(p.pid, 0)
    except:
        sys.stderr.write("failed to call %s" % command)
        # Ignore exit status of command to always run build
        pass


def execute_pre_build_action(target=None, source=None, env=None):
    call_command(PRE_BUILD_COMMAND, PRE_BUILD_DESC)


pre = Action(execute_pre_build_action, PRE_BUILD_DESC)


def execute_post_build_action(target=None, source=None, env=None):
    call_command(POST_BUILD_COMMAND, POST_BUILD_DESC)


post = Action(execute_post_build_action, POST_BUILD_DESC)


# Search source directories for files
main_source_dir = os.path.abspath('.')
for subdir, excludes in SOURCE_PATHS.iteritems():
    excludes.append("tests") #there is a separate file for compiling tests
    if subdir == PROJECT_NAME:
        sconscript_path = 'SConscript'
        source_dir = main_source_dir
        out_dir = BUILD_CONFIGURATION
    else:
        sconscript_path = os.path.join(subdir, 'SConscript')
        source_dir = os.path.join(main_source_dir, subdir)
        out_dir = os.path.join(BUILD_CONFIGURATION, subdir)

    o = SConscript(sconscript_path, exports=['env', 'source_dir', 'excludes', 'pic'],
                   variant_dir=out_dir, duplicate=0)
    if o:
        objs.extend(o)

# Create artifact based on project type
params = {'target': ARTIFACT_NAME, 'source': objs, 'LIBS': LIBRARIES, 'LIBPATH': LIBRARY_PATHS, 'LINKFLAGS': LINKER_FLAGS}
if PROJECT_TYPE == "exe": # Executable
    artifact = env.Program(**params)
elif PROJECT_TYPE == "so": # Shared library
    artifact = env.SharedLibrary(**params)
elif PROJECT_TYPE == "a": # Static library
    artifact = env.StaticLibrary(**params)
else:
    print "Unkown project type!"
    Exit(1)

# Dependencies for pre- and post-build commands
PRE_BUILD_COMMAND and env.AddPreAction(objs, pre)
POST_BUILD_COMMAND and env.AddPostAction(artifact, post)

# Clean target with deletion of target directory
Clean('.', BUILD_CONFIGURATION)

# For the system includes performance trick, CCFLAGS (CXXFLAGS) have to come *after*
# CPPFLAGS (which are in $_CCCOMCOM), see http://www.scons.org/wiki/GoFastButton
if COMP_INCLUDES_INTO_CCFLAGS:
    if env['CXXCOM'] == "$CXX -o $TARGET -c $CXXFLAGS $_CCCOMCOM $SOURCES":
        # SCons 0.97
        env['CXXCOM'] = "$CXX -o $TARGET -c $_CCCOMCOM $CXXFLAGS $SOURCES"
    elif env['CXXCOM'] == "$CXX -o $TARGET -c $CXXFLAGS $CCFLAGS $_CCCOMCOM $SOURCES":
        # SCons 0.98
        env['CXXCOM'] = "$CXX -o $TARGET -c $_CCCOMCOM $CXXFLAGS $CCFLAGS $SOURCES"
    else:
        print "Unexpected default CXXCOM"
        Exit(1)

    if env['SHCXXCOM'] == "$SHCXX -o $TARGET -c $SHCXXFLAGS $_CCCOMCOM $SOURCES":
        # SCons 0.97
        env['SHCXXCOM'] = "$SHCXX -o $TARGET -c $_CCCOMCOM $SHCXXFLAGS $SOURCES"
    elif env['SHCXXCOM'] == "$SHCXX -o $TARGET -c $SHCXXFLAGS $SHCCFLAGS $_CCCOMCOM $SOURCES":
        # SCons 0.98
        env['SHCXXCOM'] = "$SHCXX -o $TARGET -c $_CCCOMCOM $SHCXXFLAGS $SHCCFLAGS $SOURCES"
    else:
        print "Unexpected default SHCXXCOM"
        Exit(1)
		
		
os.chdir("tests/")
os.system("scons")