#!/bin/bash

File_Err=./Err.Mt
Projet=Medintux
MYSQL_LIB=libmysqlclient.18.dylib
Os=`uname`

echo -e "Compilation en cours sur : $Os \n"
echo -e " Arg 1 : $1\n Arg 2 : $2 " 

# Routine d'affichage Erreur
# Sign : String --> nil
#        Erreur --> nil
error()
{
	
	echo "		$1 "
	if [ -f $File_Err ];then
		cat $File_Err
	fi
	rm $File_Err
	exit 1
}
#
 if [[ -z "$2" ]];then
   export QTDIR
   QMAKE=$QTDIR/bin/qmake
 else
   QTDIR=$2
   export QTDIR
   QMAKE=$QTDIR/bin/qmake
 fi


# Debut  
# clear
 echo -e "\nQTDIR : $QTDIR"
 echo -e "\n-------------------------------------------------"
 echo -e "\nDebut commande MakeAllMac pour projet $Projet"
 echo -e "\n-------------------------------------------------"

 if [[ -z "$1" ]];then
 	LISTE="ccamview drtux gest_user personnes QLightPad QLaboFTP Manager guinch mise_a_jour set_bases comptabilite check_dus compta-plugins qgetdatasemp qmedicabase med_stat calendrier param_view MrPropre qgetdatasemp"
 else
 	LISTE=$1
 fi
 cd ../..
 for module in $LISTE
 do
         # echo -en "      - Patch executable Mac lib QT pour $module"
         echo -e " "
         echo -e "\n========================== compilation en cours de  $module  =======================" 
         rep_Module=$module
         if [ $module == 'compta-plugins' ]; then
             rep_Module=comptabilite
         else
              if [ $module == 'check_dus' ]; then
                  rep_Module=comptabilite
              else
                  if [ $module == 'guinch' ]; then
                       rep_Module=Manager
                  fi
              fi
         fi
         cd "$rep_Module"
         #......................... repertoires sources pour compilation ...................
         src_rep=./src
         if [ $module == 'compta-plugins' ]; then
              src_rep=./compta-plugins
         else
             if [ $module == 'check_dus' ]; then
                  src_rep=./check_dus
             else
                  if [ $module == 'comptabilite' ]; then
                       src_rep=./compta
                  else
                       if [ $module == 'guinch' ]; then
                            src_rep=./guinch
                       else
                            src_rep=./src
                       fi
                  fi
            fi
         fi
         cd "$src_rep"
         $QMAKE
	 make clean
         make
         
         if [ $Os == 'Darwin' ]; then   
            echo -e "\n on stripe un peu : ../bin/$module.app/Contents/MacOS/$module" 
            strip ../bin/$module.app/Contents/MacOS/$module    # pas d'option -s sous mac 
         else
            echo -e "\n on stripe un peu : ../bin/$module"
            strip -s ../bin/$module
            make install
         fi
         cd ..
         # ......................... QUE POUR MAC  patcher pour les infos sur les libs ...................
	 if [ $Os == 'Darwin' ]; then
             filestrip=./bin/$module.app/Contents/MacOS/$module
             # QTlib
             # install_name_tool -change libqt-mt.3.dylib @executable_path/../../../../../Qt/lib/libqt-mt.3.dylib $filestrip
             install_name_tool -change @executable_path/../../../../Qt/lib/libqt-mt.3.3.8.dylib @executable_path/../../../../../Qt/lib/libqt-mt.3.3.8.dylib $filestrip
	     # Mysqllib
             # install_name_tool -change /usr/local/mysql/lib/$MYSQL_LIB @executable_path/../../../../../Qt/lib/$MYSQL_LIB $filestrip
	 fi
         if [ $? == 0 ];then
                 echo -e "\n OK"
         else
                 error "Erreur : $? Patch sur $filestrip"
         fi
	 cd ..
 done
 echo -e " \n-------------------------------------------------"
 echo -e "\nFin commande MakeAllMac pour $Projet du module : ../bin/$module "
 echo -e "\n--------------------------------------------------"


