#! /bin/sh
#----- DEB FOR MAC --------
  QTDIR="/Users/rolandsevin/Documents/medintux/Programmes/Qt"
 export QTDIR
  PATH=$PATH":/Users/rolandsevin/Documents/medintux/Programmes/Qt/bin"
 export PATH
#----- END FOR MAC --------
DYLD_LIBRARY_PATH=$QTDIR/lib:$DYLD_LIBRARY_PATH
DYLD_LIBRARY_PATH=$QTDIR/plugins/sqldrivers:$DYLD_LIBRARY_PATH
DYLD_LIBRARY_PATH=/usr/local/mysql/lib:$DYLD_LIBRARY_PATH
INCLUDE=/usr/local/mysql/include:$INCLUDE
QMAKESPEC=$QTDIR/mkspecs/macx-g++
export QMAKESPEC
export DYLD_LIBRARY_PATH
export INCLUDE
cd '/Users/rolandsevin/Documents/medintux/Programmes/set_bases/bin/'
./MakeAllMac.sh 'qfselib' '/Users/rolandsevin/Documents/medintux/Programmes/Qt'