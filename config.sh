SYSTEM_HEADER_PROJECTS="libc kernel"
PROJECTS="libc kernel"

export MAKE=${MAKE:-make}
export HOST=i686-elf

export AR=${HOST}-ar
export AS=${HOST}-as
export CXX=${HOST}-g++

export PREFIX=/usr
export EXEC_PREFIX=$PREFIX
export BOOTDIR=/boot
export LIBDIR=$EXEC_PREFIX/lib
export INCLUDEDIR=$PREFIX/include

export CXXFLAGS='-O2 -g -Werror'
export CPPFLAGS=''

export CXX="$CXX --sysroot=$PWD/sysroot"

#Workaround for not having a system include directory configured.
export CXX="$CXX -isystem=$INCLUDEDIR"
