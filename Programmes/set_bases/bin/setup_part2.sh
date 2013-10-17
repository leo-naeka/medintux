#! /bin/sh
echo "."
echo "================================ compilation de MrPropre ================================="
cd ../../MrPropre/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s MrPropre


echo "."
echo "================================ compilation de calendrier ================================="
cd ../../calendrier/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s calendrier

echo "."
echo "================================ compilation de CCAM_View ================================="
cd ../../ccamview/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s ccamview
   
echo "================================ compilation de DrTux ================================="
cd ../../drtux/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s drtux
 
echo "================================ compilation de gest_user ================================="
cd ../../gest_user/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s gest_user
   
echo "================================ compilation de Personnes ================================="
cd ../../personnes/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s personnes
   
echo "================================ compilation de QLightPad ================================="
cd ../../QLightPad/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s QLightPad
   
echo "================================ compilation de QLaboFTP ================================="
cd ../../QLaboFTP/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s QLaboFTP
echo "================================ compilation de guinch ================================="
cd ../../guinch/src
   qmake guinch.pro
   make
   make clean
   cd ../bin
   strip -s guinch

echo "================================ compilation de Manager ================================="
cd ../../Manager/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s Manager
echo "================================ compilation de manu ================================="
cd ../../manu/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s manu 
echo "================================ compilation de mise_a_jour ================================="
cd ../../mise_a_jour/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s mise_a_jour   
echo "================================ compilation de qgetdatasemp ================================="
cd ../../qgetdatasemp/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s qgetdatasemp
echo "================================ compilation de QFseVitale ================================="
cd ../../QFseVitale/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s QFseVitale
echo "================================ compilation de med_stat ================================="
cd ../../med_stat/src
   qmake src.pro
   make
   make clean
   cd ../bin
   strip -s med_stat
echo "================================ compilation de comptabilite ================================="
cd ../../comptabilite/compta
   qmake compta.pro
   make
   make clean
   cd ../bin
   strip -s comptabilite
echo "================================ compilation de check_dus ================================="
cd ../../comptabilite/check_dus
   qmake check_dus.pro
   make
   make clean
   cd ../bin
   strip -s check_dus
echo "================================ compilation de compta-plugins ================================="
cd ../../comptabilite/compta-plugins
   qmake compta-plugins.pro
   make
   make clean
   cd ../bin
   strip -s compta-plugins
