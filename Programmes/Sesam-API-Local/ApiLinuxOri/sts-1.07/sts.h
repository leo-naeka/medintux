/*
 * -------------------------------------------------------------------
 * (c) 2003 GIE SESAM-VITALE
 *
 * PROJET   : Services de Tarification Sp�cifiques
 *
 * FICHIER  : sts.h (v1)
 *
 * Declaration des prototypes des fonctions STS
 * -------------------------------------------------------------------
 */

#ifndef __STS_H__
#define __STS_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Inclusions
 */
#include <stddef.h>
/* Inclure le fichier de declarations specifiques systeme :
   win32def.h, macosdef.h, unixdef.h, etc. */



/*
 * Declarations des fonctions publiques "standards"
 */

/* Tarification de la part complementaire des actes de la facture. */
typedef unsigned short (API_ENTRY TFCTSTSTARIFICATION)
                       (char               MotifAppel,
                        void FARPTR        ZDonneesEntree,
                        size_t             TailleDonneesEntree,
                        void FARPTR FARPTR ZDonneesSortie,
                        size_t FARPTR      TailleDonneesSortie);
extern TFCTSTSTARIFICATION STS_Tarification;

/* Assistance � la tarification complementaire. */
typedef unsigned short (API_ENTRY TFCTSTSASSISTANCE)
                       (char               MotifAppel,
                        unsigned short     PorteeAppel,
                        void FARPTR        ZDonneesEntree,
                        size_t             TailleDonneesEntree,
                        void FARPTR FARPTR ZDonneesSortie,
                        size_t FARPTR      TailleDonneesSortie);
extern TFCTSTSASSISTANCE STS_Assistance;

/* Lecture de la version des modules et des fichiers de tables externes. */
typedef unsigned short (API_ENTRY TFCTSTSLIREVERSION)
                       (void FARPTR FARPTR ZDonneesSortie,
                        size_t FARPTR      TailleDonneesSortie);
extern TFCTSTSLIREVERSION STS_LireVersion;

/* Activation de la trace. */
typedef unsigned short (API_ENTRY TFCTSTSINITTRACE)
                       (const char FARPTR  NomFichier,
                        const char FARPTR  ModeOuverture,
                        unsigned short     Module,
                        unsigned char      Niveau);
extern TFCTSTSINITTRACE STS_InitTrace;

/* Initialisation des modules STS. */
typedef unsigned short (API_ENTRY TFCTSTSINITLIB)();
extern TFCTSTSINITLIB STS_InitLIB;

/* Terminaison des modules STS. */
typedef unsigned short (API_ENTRY TFCTSTSTERMLIB)();
extern TFCTSTSTERMLIB STS_TermLIB;

/* Allocation d'une zone memoire. */
typedef unsigned short (API_ENTRY TFCTSTSALLOUERZMEM)
                       (void FARPTR FARPTR Zone,
                        size_t             Taille);
extern TFCTSTSALLOUERZMEM STS_AllouerZoneMem;

/* Liberation d'une zone memoire. */
typedef void (API_ENTRY TFCTSTSLIBERERZMEM) (void FARPTR Zone);
extern TFCTSTSLIBERERZMEM STS_LibererZoneMem;


#ifdef SGD

/*
 * Declarations des fonctions publiques "simplifiees"
 */

/* Tarification de la part complementaire des actes de la facture. */
typedef unsigned short (API_ENTRY TFCTSTSTARIFICATION_S)
                       (char           MotifAppel,
                        unsigned short NumeroSession);
extern TFCTSTSTARIFICATION_S STS_Tarification_S;

/* Assistance � la tarification complementaire. */
typedef unsigned short (API_ENTRY TFCTSTSASSISTANCE_S)
                       (char           MotifAppel,
                        unsigned short PorteeAppel,
                        unsigned short NumeroSession);
extern TFCTSTSASSISTANCE_S STS_Assistance_S;

/* Lecture de la version des modules et des fichiers de tables externes. */
typedef unsigned short (API_ENTRY TFCTSTSLIREVERSION_S)
                       (unsigned short NumeroSession);
extern TFCTSTSLIREVERSION_S STS_LireVersion_S;

#endif /* SGD */


#ifdef __cplusplus
}
#endif

#endif /* __STS_H__ */
