#! /bin/sh

QTDIR=/usr/lib/qt3
export QTDIR
QMAKE=$QTDIR/bin/qmake
cd set_bases/src
   $QMAKE src.pro
   make
   #make clean
   cd ../bin
   strip -s set_bases
cd ../../mise_a_jour/src
   $QMAKE src.pro
   make
   make clean
   cd ../bin
   strip -s mise_a_jour   
cd ../../set_bases/bin     
   exec  ./set_bases
   
   

