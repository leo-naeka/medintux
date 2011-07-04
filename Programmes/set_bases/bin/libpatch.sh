#!/bin/bash

Projet=Medintux

# Debut  
# clear
 echo -e "--------------------------------------"
 echo -e "Debut commande Pach lib QT pour projet $Projet"
 echo -e "--------------------------------------"
 
cd ../../QT/lib         #se mettre dans QT/lib  car on part de QT/set_bases/bin/
echo -e "................ libqt-mt.3.3.8.dylib ................"
otool -L libqt-mt.3.3.8.dylib
install_name_tool -id @executable_path/../../../../../QT/lib/libqt-mt.3.3.8.dylib libqt-mt.3.3.8.dylib
install_name_tool -change /usr/local/mysql/lib/mysql/libmysqlclient.15.dylib @executable_path/../../../../../QT/lib/libmysqlclient.15.dylib libqt-mt.3.3.8.dylib
otool -L libqt-mt.3.3.8.dylib

echo -e "................ libqui.1.0.0.dylib ................"
otool -L libqui.1.0.0.dylib
install_name_tool -id @executable_path/../../../../../QT/lib/libqui.1.0.0.dylib libqui.1.0.0.dylib
install_name_tool -change libqt-mt.3.dylib @executable_path/../../../../../QT/lib/libqt-mt.3.3.8.dylib libqui.1.0.0.dylib
otool -L libqui.1.0.0.dylib

echo -e "................ libmysqlclient.15.dylib ................"
otool -L libmysqlclient.15.dylib
install_name_tool -id @executable_path/../../../../../QT/lib/libmysqlclient.15.dylib libmysqlclient.15.dylib
otool -L libmysqlclient.15.dylib

echo -e "................ Patch designer ................"
cd ../bin/designer.app/Contents/MacOS
otool -L designer
install_name_tool -change libqt-mt.3.dylib @executable_path/../../../../../QT/lib/libqt-mt.3.3.8.dylib designer
install_name_tool -change libqui.1.dylib @executable_path/../../../../../QT/lib/libqui.1.0.0.dylib designer

install_name_tool -change @executable_path/../../../../QT/lib/libqt-mt.3.3.8.dylib @executable_path/../../../../../QT/lib/libqt-mt.3.3.8.dylib designer
install_name_tool -change @executable_path/../../../../QT/lib/libqui.1.0.0.dylib @executable_path/../../../../../QT/lib/libqui.1.0.0.dylib designer
otool -L designer

echo -e "................ Patch assistant ................"
cd ../../../assistant.app/Contents/MacOS
otool -L assistant
install_name_tool -change libqt-mt.3.dylib @executable_path/../../../../../QT/lib/libqt-mt.3.3.8.dylib assistant
install_name_tool -change @executable_path/../../../../QT/lib/libqt-mt.3.3.8.dylib @executable_path/../../../../../QT/lib/libqt-mt.3.3.8.dylib assistant
otool -L assistant
echo -e "................ Patch linguist ................"
cd ../../../linguist.app/Contents/MacOS
otool -L linguist
install_name_tool -change libqt-mt.3.dylib @executable_path/../../../../../QT/lib/libqt-mt.3.3.8.dylib linguist
install_name_tool -change @executable_path/../../../../QT/lib/libqt-mt.3.3.8.dylib @executable_path/../../../../../QT/lib/libqt-mt.3.3.8.dylib linguist
otool -L linguist
echo -e "................ Patch qtconfig ................"
cd ../../../qtconfig.app/Contents/MacOS
otool -L qtconfig
install_name_tool -change libqt-mt.3.dylib @executable_path/../../../../../QT/lib/libqt-mt.3.3.8.dylib qtconfig
install_name_tool -change @executable_path/../../../../QT/lib/libqt-mt.3.3.8.dylib @executable_path/../../../../../QT/lib/libqt-mt.3.3.8.dylib qtconfig
otool -L qtconfig

 echo -e "---------------------------------"
 echo -e "Fin commande Pach lib QT pour projet $Projet"
 echo -e "---------------------------------"


