//
// C++ Interface: C_Atcd
//
// Description:
//
//
// Author: Eric MAEKER eric.maeker@free.fr, (C) 2008
// Author: Roland SEVIN roland-sevin@medintux.org (C) 2009 2010
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef ATCD_CODE_H
#define ATCD_CODE_H

#include <qstring.h>
#include <qstringlist.h>
#include <qdatetime.h>
#include <qvaluelist.h>
#include <qobject.h>
#include <qwidget.h>

#include <qlistview.h>

#include "CMoteur_Base.h"
#include "../../MedinTuxTools/CPrtQListViewItem.h"
#include "../../MedinTuxTools/CGenTools.h"
#include "../../MedinTuxTools/Theme.h"

#include "ui/DlgAtcd_txt.h"
#include "ui/Dlg_Calendar.h"
#define  TR        QObject::tr

//class QObject;

/**
        @author Sevin Roland <roland-sevin@medintux.org>
*/

/*! \class Atcd_Element
 *  \brief Classe Atcd et C_Atcd : Deux classes qui gèrent les ATCD pour toute l'application. Il suffit d'injecter le fichier de Terrain et le reste suit.
 *  Cette classe contient les items de chaque ATCD :
 *  - libellé
 *  - date
 *  - code CIM10
 *  - rubrique
 *  - commentaire
 *  - état
 */

class Atcd_Element
{
public :
        Atcd_Element()
                { m_Rubrique=""; m_Libelle=""; m_Code=""; m_Etat=0; m_Commentaire=""; m_Id_ATCD = -1; m_ald="";}

        Atcd_Element(const char*   rubrique,
                     const char*   libelle,
                     QDate&        dt,
                     const char*   code,
                     int           etat,
                     const char*   commentaire,
                     const QString &ald,
                     int           id_ATCD = -1)
                { set_Atcd_Element(rubrique, libelle,  dt,  code, etat,  commentaire, ald, id_ATCD);
                }

        ~Atcd_Element() {}
        void set_Atcd_Element(const char*   rubrique,
                              const char*   libelle,
                              QDate&        dt,
                              const char*   code,
                              int           etat,
                              const char*   commentaire,
                              const QString &ald,
                              int           id_ATCD)
                { m_Rubrique    = rubrique;
                  m_Libelle     = libelle;
                  m_Code        = code;
                  m_Etat        = etat;
                  m_Date        = dt;
                  m_Commentaire = commentaire;
                  m_ald         = ald;
                  m_Id_ATCD     = id_ATCD;
                }

        // Implémentation de l'opérateur inférieur pour accéder aux fonction qHeapSort
        // Trie selon le nom de la rubrique
        bool operator< (const Atcd_Element& e) const ;
        bool operator== (const Atcd_Element& e) const ;

        bool                 isAllergie();
        bool                 isCIM10();
        bool                 isCisp();
        //bool                 isVidal();
        QString              getLightCIM10();
        QPixmap              getPixmap();
        void                 setId            (int n)        { m_Id_ATCD = n ;   }
        int                  getId()                         { return m_Id_ATCD; }
        QString              getAld()                        { return m_ald;     }
public:
        QString              m_Libelle;                 /*!< libellé de l'ATCD */
        QString              m_Rubrique;                /*!< Rubrique de l'ATCD */
        QDate                m_Date;                    /*!< Date de l'ATCD */
        QString              m_Code;                    /*!< codage CIM10, allergie */
        QString              m_Commentaire;             /*!< Commentaire de l'ATCD */
        QString              m_ald;                     /*!< si est en rapport avec l'ALD du patient */
        int                  m_Etat;                    /*!< Passé(0) ou Actif(1) */
        int                  m_Id_ATCD;                 /*!< Id de l'ATCD défini lors de la lecture du terrain, non modifié par la suite */

};
// Définition d'un alias vers une liste d'antécédents
typedef QValueList<Atcd_Element> ATCD_LISTE;



class Atcd_Code : public QObject
{
  Q_OBJECT

public:
   enum changeMode {
        sendNotModifMessage = 0,
        sendModifMessage    = 1

    };


    Atcd_Code(CMoteurBase  *pCMoteurBase, QWidget *parent=0, const char *name=0);
    ~Atcd_Code();

        ////////////////////////////////////////////
        ///////////////  METHODES  /////////////////
        ////////////////////////////////////////////

        bool                isModified();
        void                setModifiedState( bool state );

        // RECUPERATION DU TERRAIN
        void                setTerrain(CRubRecord* pCRubRecord, CMoteurBase* pCMoteurBase);
        int                 setTerrain  (RUBREC_LIST::iterator it, CMoteurBase* pCMoteurBase);

        // RECUPERATION DES ELEMENTS
        void                 createAtcdListView                   ();
        void                 createAtcdListView                   (CPrtQListViewItem& retour);
        void                 atcd_Element_To_ListViewItem(Atcd_Element& pAtcd_Element, QListView* pQListView);
        void                 atcd_To_ListView                     (QListView& retour);
        QString              get_ATCD_Rubname                     (Atcd_Element& pAtcd);
        //bool                 getIdRubrique(Atcd_Element& pAtcd, bool& isMed, bool& isChir, bool& isAllergie, int& id, QString  *pRubname  = 0 );
        //QString              getRubriqueName_Medical              (int id);
        //QString              getRubriqueName_Chirurgical          (int id);
        QDate                getDDR                               ();
        QString              getTermeObstetrical                  (QDate dt = QDate());
        Atcd_Element*        getAtcd_byID                         (int idAtcd);
        QString              getPkDocTerrain                      ();
        CPrtQListViewItem*   getListViewItemFromAtcd(Atcd_Element* pAtcd);
        Atcd_Element*        get_lastElementAdded();
        QString              ATCD_To_Text(  const QString &typePrefix = "<b>°&nbsp;<u>::TYPE:: :</u></b>",
                                            const QString &linePatern = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;::LIBELLE:: ::NOTE:: ::ALD::  ::DATE::",
                                            const QString &datePrefix = "en date du : ",
                                            const QString &aldPrefix  = "ALD");
        QString              GetSexe_FromBD();
        QChar                GetSexe_FMI_FromBD();
        QChar                GetSexe();
        // FONCTIONS DE TRI
        void                 setSort(int mode);
        void                 sort();

        // AJOUTS / MODIFICATIONS
        void                viewATCD                  (QWidget *parent, int id_ATCD);
        void                modifyDate                (QWidget *parent, Atcd_Element* pAtcd,  int sendModifMessage = Atcd_Code::sendModifMessage);
        void                addATCD_Textuel           (QWidget *parent, int sendModifMessage = Atcd_Code::sendModifMessage);
        void                addATCD                   (QWidget *parent, const QString &libelle, const QString &code, const QString familyGenre, int sendModifMessage  = Atcd_Code::sendModifMessage );
        void                modifyAtcd                (QWidget *parent, Atcd_Element* pAtcd,  int sendModifMessage = Atcd_Code::sendModifMessage);
        void                setDate                   (Atcd_Element* pAtcd,  const QDate &date,  int sendModifMessage = Atcd_Code::sendModifMessage);
        void                deleteDate                (Atcd_Element* pAtcd,  int sendModifMessage = Atcd_Code::sendModifMessage);
        void                changeEtat                (Atcd_Element* pAtcd);
        void                setEtat                   (Atcd_Element* pAtcd,  int etat,  int sendModifMessage = Atcd_Code::sendModifMessage);
        void                changeCommentaire         (Atcd_Element* pAtcd,  int sendModifMessage = Atcd_Code::sendModifMessage);
        void                eraseAtcd                 (Atcd_Element* pAtcd,  int sendModifMessage = Atcd_Code::sendModifMessage);
        void                setRubrique               (Atcd_Element* pAtcd, QString& rubrique,   int sendModifMessage = Atcd_Code::sendModifMessage);
        void                setALD                    (Atcd_Element* pAtcd, const QString& ald,  int sendModifMessage = Atcd_Code::sendModifMessage);
        void                setGrossesse              (bool etat);
        void                setAllaitement            (bool etat);
        void                setDDRTo                  (QDate dt);
        void                clear                     ();
        void                updateFromListViewTerrain(QListView* pQListView, int sendModifMessage = Atcd_Code::sendModifMessage);
        // GESTION DE LA SAUVEGARDE LECTURE
        QString             updateToBD();
        QString             updateFromBD();
        QString             toOldIni();
        void                setTerrain(const char* strTerrain, CMoteurBase* pCMoteurBase);


        ////////////////////////////////////////////
        ///////////////   SLOTS    /////////////////
        ////////////////////////////////////////////

public slots:
        // AJOUTS / MODIFICATIONS
        void                emitATCD_Changed        ();
        void                addATCD_CIM10           (int tabToSet=-1);
        void                addATCD_Allergie        ();
        void                changeDDR               (QWidget *parent);



        ////////////////////////////////////////////
        ///////////////   SIGNALS  /////////////////
        ////////////////////////////////////////////

signals:
        void                ATCD_Changed();                /*!< \brief Signal émit �  chaque modification des Antécédents. Attention ne modifie pas la propriété m_TerrainIsModified avant. Pour cela il faut appeler le Slot emitATCD_Changed(). */
private:
Atcd_Element*       m_pLastElementAdded;                   /*!< \brief copie du dernier element ajouté. */
CMoteurBase        *m_pCMoteurBase;

        ////////////////////////////////////////////
        ///////////////   DONNEES  /////////////////
        ////////////////////////////////////////////

public :

        QString            m_Terrain;                    /*!< Le fichier terrain �  analyser */
        ATCD_LISTE         m_Atcd_Liste;                 /*!< Liste des ATCD */
        bool               m_Grossesse;                  /*!< Contient TRUE si grossesse en cours. */
        QDate              m_DDR;                        /*!< Date des dernieres règles. */
        bool               m_Allaitement;                /*!< Contient TRUE si allaitement en cours. */
        QString            m_PkDocTerrain;               /*!< Contient le PkDoc du Terrain en cours, utile pour tester la synchronisation des terrains */
        bool               m_TerrainIsModified;          /*!< Se modifie en cas de modification des antécédents */
        QListView*         m_pAtcdFatherListView;        /*!< ListView qui affichera le menu rapide*/
        CPrtQListViewItem* m_pAtcdListViewItem;          /*!< ListViewItem qui affichera les atcd Allergiques Cim10 et textuels*/
        QChar              m_sexe;                       /*!< sexe du patient */
};

#endif
