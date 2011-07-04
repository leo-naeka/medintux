/****************************************************************************
** Form implementation generated from reading ui file 'Dlg_MainDialog.ui'
**
** Created: mer. mai 4 22:15:45 2011
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Dlg_MainDialog.h"

#include <qvariant.h>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <qeventloop.h>
#include <qlistbox.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qprogressbar.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qcombobox.h>
#include <qgroupbox.h>
#include <qcheckbox.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "CApp.h"
#include "../../MedinTuxTools/CHtmlTools.h"
#include "../../MedinTuxTools/CW_EditText.h"
static const unsigned char image0_data[] = { 
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x55,
    0x08, 0x06, 0x00, 0x00, 0x00, 0x82, 0x56, 0x20, 0x3a, 0x00, 0x00, 0x08,
    0xf2, 0x49, 0x44, 0x41, 0x54, 0x78, 0x9c, 0xed, 0x5d, 0x31, 0x6f, 0xdb,
    0x46, 0x14, 0x7e, 0x54, 0x24, 0x32, 0x74, 0x63, 0xb8, 0x45, 0xec, 0x22,
    0x32, 0x32, 0x14, 0x41, 0xd4, 0x00, 0xf9, 0x07, 0xf1, 0xa0, 0x45, 0x4b,
    0x86, 0x4c, 0x5a, 0xbc, 0xa4, 0x40, 0x32, 0x04, 0x30, 0xd0, 0x06, 0x48,
    0x86, 0xc2, 0x40, 0x82, 0x4c, 0x46, 0x0a, 0x18, 0x1d, 0x5c, 0xa0, 0x2d,
    0x10, 0xa0, 0x83, 0x33, 0x64, 0xa8, 0x17, 0x0d, 0x45, 0x06, 0x2f, 0x5a,
    0x84, 0x42, 0xd9, 0x3b, 0x04, 0x28, 0x94, 0xa1, 0x28, 0x8a, 0xd8, 0x88,
    0x1d, 0xc0, 0x81, 0x12, 0xcb, 0x24, 0x15, 0xb1, 0x03, 0x73, 0x34, 0x79,
    0xba, 0x23, 0xef, 0xc8, 0x3b, 0xf2, 0x24, 0xea, 0x03, 0x08, 0x48, 0xe4,
    0x91, 0x3c, 0xf2, 0xbb, 0xef, 0xf1, 0xbd, 0x77, 0x47, 0x9e, 0xd6, 0xed,
    0x76, 0x61, 0x86, 0xe9, 0x45, 0x29, 0xef, 0x0a, 0xcc, 0x20, 0x17, 0x85,
    0x26, 0xb8, 0xd6, 0xa8, 0xbb, 0x79, 0xd7, 0x41, 0x36, 0x0a, 0x4b, 0x70,
    0x11, 0xc8, 0x05, 0x28, 0x30, 0xc1, 0x45, 0x41, 0x21, 0x09, 0x0e, 0xaa,
    0x77, 0xda, 0x95, 0x5c, 0x48, 0x82, 0x71, 0xac, 0xaf, 0xac, 0xba, 0xeb,
    0x2b, 0xab, 0x53, 0x49, 0x74, 0xe1, 0x08, 0x9e, 0x76, 0xc5, 0xe2, 0x28,
    0x1c, 0xc1, 0x51, 0x98, 0x46, 0x15, 0x97, 0xf3, 0xae, 0x40, 0x96, 0xa8,
    0x35, 0xea, 0xee, 0xd0, 0x99, 0x0b, 0xad, 0x2b, 0x57, 0x8e, 0x73, 0xaa,
    0x4d, 0x36, 0xd0, 0x8a, 0x94, 0xc9, 0xf2, 0x08, 0x5e, 0x1a, 0x5b, 0x5f,
    0xae, 0x1c, 0x40, 0x73, 0x50, 0xf5, 0xff, 0x6f, 0x76, 0x77, 0x34, 0x7c,
    0xbf, 0x24, 0xe7, 0xeb, 0xb5, 0x3b, 0x5a, 0x7c, 0x29, 0xb9, 0x28, 0x8c,
    0x82, 0x6b, 0x8d, 0xba, 0x6b, 0x3b, 0x35, 0xca, 0xd6, 0x83, 0xb1, 0xb2,
    0xa2, 0xce, 0x89, 0xaf, 0xcb, 0x9a, 0xf4, 0xc2, 0x10, 0xec, 0xa1, 0x92,
    0x77, 0x05, 0x42, 0xa4, 0x67, 0x41, 0xb6, 0x52, 0x4e, 0x96, 0x2c, 0x0f,
    0xb7, 0xd6, 0xa8, 0xbb, 0xc7, 0xce, 0x35, 0x18, 0xc2, 0x02, 0x71, 0x39,
    0x76, 0xae, 0x41, 0xcb, 0xdc, 0xf3, 0xcb, 0x07, 0xcd, 0xb5, 0x4c, 0x64,
    0xe1, 0xd1, 0x2b, 0xa7, 0xe0, 0x5a, 0xa3, 0xee, 0xca, 0x68, 0xd9, 0x23,
    0x58, 0xe0, 0x2a, 0x8f, 0x3b, 0x63, 0xb2, 0x80, 0x48, 0x96, 0xa5, 0x66,
    0xe5, 0x08, 0x06, 0x90, 0x43, 0xb2, 0xeb, 0xf2, 0x5e, 0xea, 0xe7, 0x22,
    0x4f, 0x4f, 0xc5, 0xd0, 0xf1, 0xce, 0x23, 0xab, 0x61, 0x2b, 0xe3, 0x45,
    0xcb, 0x72, 0x48, 0x6a, 0x8d, 0xba, 0xdb, 0xb7, 0x6f, 0x32, 0x95, 0x9d,
    0xd7, 0x9f, 0x85, 0xcc, 0xf3, 0xef, 0xe5, 0x2f, 0xd2, 0x9e, 0x9e, 0x09,
    0x25, 0x38, 0x02, 0x80, 0x23, 0x28, 0x57, 0x8e, 0x85, 0x2b, 0x59, 0x49,
    0x05, 0x23, 0xac, 0xaf, 0xac, 0xba, 0x78, 0xc8, 0x92, 0x04, 0x23, 0x30,
    0x13, 0xed, 0x37, 0xa4, 0x98, 0xf5, 0xb9, 0xca, 0x0b, 0xe2, 0xfa, 0x63,
    0xe7, 0x1a, 0xf7, 0x39, 0xca, 0xf0, 0x2e, 0xf4, 0x5f, 0xb4, 0xc9, 0x56,
    0x8a, 0x60, 0xfc, 0xb9, 0xd7, 0x32, 0xf7, 0xa0, 0x29, 0x80, 0x64, 0xc7,
    0x35, 0x12, 0xed, 0x47, 0x23, 0x92, 0xe6, 0x84, 0xb5, 0xcc, 0x70, 0xf9,
    0xf7, 0xce, 0xf5, 0xc8, 0xe3, 0x97, 0x30, 0x72, 0x83, 0x10, 0x65, 0xb2,
    0x95, 0x22, 0x18, 0xe0, 0x33, 0xec, 0x7f, 0xba, 0x2c, 0x53, 0xad, 0x51,
    0x77, 0x0f, 0xad, 0xfb, 0xd4, 0xed, 0x8b, 0xc6, 0x16, 0x04, 0xb7, 0x1f,
    0x5a, 0xf7, 0xa1, 0x65, 0x6e, 0xf9, 0x04, 0xf2, 0x7a, 0xd3, 0x78, 0xf9,
    0x96, 0xb9, 0xeb, 0xff, 0xee, 0xdb, 0xab, 0xa1, 0x6d, 0x9a, 0x46, 0x27,
    0x17, 0x41, 0x04, 0xc9, 0x4a, 0x11, 0x3c, 0x82, 0x70, 0x96, 0xc9, 0x76,
    0x96, 0xa0, 0x65, 0xbe, 0x4c, 0xa9, 0xe2, 0x38, 0x6f, 0x58, 0x9e, 0xb7,
    0x1c, 0x24, 0xbc, 0x65, 0xee, 0x00, 0x00, 0xc0, 0x3b, 0xfb, 0x16, 0x94,
    0x60, 0x20, 0xed, 0x9c, 0x38, 0x94, 0x88, 0x83, 0xa3, 0xe2, 0xd4, 0x34,
    0xc7, 0xdc, 0xb7, 0x36, 0x60, 0x08, 0x67, 0x89, 0xcb, 0xa2, 0xf1, 0x18,
    0x9a, 0x83, 0x2a, 0x2c, 0x1a, 0x8f, 0x43, 0xeb, 0x65, 0xa1, 0x39, 0xa8,
    0x42, 0x73, 0x50, 0x85, 0x05, 0xfd, 0x29, 0xcc, 0xeb, 0x3b, 0x5c, 0xd7,
    0x91, 0xa6, 0x13, 0x44, 0x19, 0x05, 0xd3, 0xe2, 0xd4, 0xf7, 0xce, 0x75,
    0x68, 0x99, 0xbb, 0x89, 0x54, 0x3c, 0x82, 0x33, 0xdc, 0xe5, 0x5e, 0x5b,
    0x3f, 0x40, 0xcb, 0x7c, 0x10, 0x69, 0x9e, 0x79, 0xeb, 0x11, 0x24, 0xa8,
    0x39, 0xa8, 0xc2, 0x9b, 0x2b, 0x73, 0xf0, 0xe7, 0xbf, 0xbb, 0x5c, 0x4e,
    0x59, 0x52, 0x87, 0x53, 0x19, 0x82, 0xf9, 0xe3, 0x54, 0x16, 0x90, 0xcd,
    0xef, 0xb2, 0x71, 0x0f, 0x23, 0x30, 0x58, 0x6e, 0xfc, 0xb9, 0x9f, 0xd6,
    0xc9, 0xc3, 0xf7, 0x5f, 0x5f, 0x59, 0x75, 0x9b, 0x50, 0x85, 0x96, 0xf9,
    0x02, 0x6c, 0xe7, 0x6a, 0xec, 0xfe, 0x2d, 0x73, 0x0f, 0x9a, 0x83, 0x6a,
    0x22, 0x92, 0x95, 0x30, 0xd1, 0x1e, 0x96, 0x22, 0x16, 0x0f, 0xac, 0xa6,
    0xaa, 0xd6, 0xa8, 0xbb, 0xff, 0x59, 0x3f, 0xc3, 0x08, 0xce, 0x8c, 0x2d,
    0xe3, 0xe4, 0x82, 0xbf, 0x0d, 0x61, 0xdf, 0xda, 0x08, 0xa5, 0x2e, 0x45,
    0x63, 0xb3, 0xbb, 0xa3, 0x6d, 0x76, 0x77, 0xb4, 0xe6, 0xa0, 0x0a, 0x7a,
    0xe5, 0x25, 0xd3, 0x3e, 0x49, 0xeb, 0xa3, 0x0c, 0xc1, 0x36, 0x18, 0xd4,
    0xe5, 0xad, 0xbd, 0xc6, 0x7d, 0x81, 0x43, 0x28, 0x11, 0x17, 0x1c, 0xcd,
    0x41, 0x15, 0x2e, 0x1a, 0x77, 0x23, 0x8f, 0x25, 0x6b, 0x20, 0xc0, 0x66,
    0x77, 0x47, 0xeb, 0xb5, 0x3b, 0x5a, 0xb9, 0xf2, 0x9a, 0x79, 0x1f, 0xde,
    0xba, 0xe4, 0x4e, 0x30, 0x0a, 0x65, 0x5c, 0xd7, 0xa4, 0x2e, 0x41, 0xb0,
    0x5e, 0x20, 0x49, 0xbd, 0x5f, 0x19, 0xdf, 0x66, 0xd6, 0x91, 0xc0, 0x03,
    0x8f, 0xe4, 0xf8, 0x90, 0x30, 0x89, 0x8a, 0x73, 0x27, 0xd8, 0xc3, 0x9c,
    0xbf, 0x2c, 0x1a, 0x5b, 0xa1, 0xff, 0xbc, 0xa8, 0x35, 0xea, 0xee, 0x3f,
    0xd6, 0xaf, 0x00, 0x10, 0x26, 0xf9, 0x92, 0xb1, 0x46, 0x25, 0xb7, 0xd7,
    0xee, 0x68, 0xb8, 0x8a, 0x0f, 0xad, 0x87, 0xa1, 0x1b, 0xaa, 0xd2, 0x70,
    0x1e, 0x9e, 0xba, 0x28, 0x41, 0x30, 0x1e, 0xa6, 0xa0, 0xd0, 0x25, 0x88,
    0xbe, 0x7d, 0xdb, 0xbf, 0xe1, 0x3c, 0x17, 0x38, 0x82, 0xb3, 0x30, 0x92,
    0x18, 0xfe, 0x88, 0x02, 0x6b, 0x42, 0x83, 0x57, 0xc5, 0x4a, 0x10, 0x8c,
    0x48, 0x48, 0x4b, 0x04, 0x72, 0xae, 0x70, 0x7c, 0x6d, 0x7c, 0x43, 0x55,
    0x2f, 0xf2, 0x4a, 0x7b, 0xed, 0x8e, 0xb6, 0x6c, 0xdc, 0x0b, 0x6d, 0xf3,
    0x32, 0x5b, 0xf2, 0x9c, 0xad, 0x34, 0x60, 0x6d, 0xe4, 0xb9, 0x10, 0x8c,
    0x12, 0xea, 0xa7, 0xde, 0xae, 0x47, 0xee, 0xb2, 0xf1, 0xbd, 0x9f, 0x10,
    0xb8, 0x60, 0x3c, 0x1a, 0xdb, 0xaf, 0x6f, 0xdf, 0x48, 0xa4, 0x62, 0x1a,
    0xd2, 0xc4, 0xb3, 0x93, 0x82, 0x4c, 0x09, 0xae, 0x35, 0xea, 0x2e, 0x9e,
    0x5f, 0x1d, 0xc2, 0x47, 0x7f, 0x49, 0x7b, 0xec, 0xd7, 0xd6, 0x4f, 0x63,
    0xeb, 0x69, 0xea, 0x25, 0x91, 0xeb, 0xa9, 0xf8, 0x41, 0xaa, 0x7a, 0x64,
    0x09, 0x96, 0x06, 0x97, 0x09, 0xc1, 0x88, 0x58, 0x80, 0xf1, 0x67, 0x0d,
    0xcd, 0x3c, 0xa3, 0x34, 0x62, 0x14, 0xb2, 0x50, 0xd4, 0xa1, 0xf5, 0x9d,
    0xb2, 0x66, 0x9a, 0x05, 0xd2, 0x09, 0x46, 0x79, 0x66, 0x80, 0x30, 0xb9,
    0xb5, 0x46, 0xdd, 0x7d, 0x65, 0x3d, 0xf5, 0xc9, 0x25, 0x79, 0xb9, 0x1e,
    0xc9, 0x5b, 0xa1, 0x75, 0x5e, 0xea, 0x32, 0x7c, 0xc3, 0x3d, 0xf5, 0xfe,
    0x30, 0x76, 0xee, 0xcb, 0xc6, 0x1d, 0x66, 0xf5, 0x22, 0xf4, 0xda, 0x1d,
    0x8d, 0xf4, 0x78, 0x40, 0xc8, 0xdb, 0x4c, 0xf3, 0x86, 0x79, 0xd2, 0x08,
    0x46, 0xaa, 0x7d, 0xef, 0x5c, 0x87, 0xb9, 0xca, 0x0b, 0xa2, 0x97, 0x88,
    0x67, 0x90, 0x70, 0xa0, 0x44, 0xc0, 0x79, 0xfd, 0x09, 0xb5, 0x0c, 0xed,
    0x86, 0xd3, 0xc2, 0xa2, 0x24, 0x69, 0xc7, 0x77, 0xf6, 0x9d, 0x89, 0x55,
    0xb1, 0x70, 0x82, 0x11, 0xb1, 0x7d, 0xfb, 0x06, 0xf4, 0xed, 0x1b, 0x91,
    0x39, 0xe6, 0x11, 0x78, 0x1d, 0xf1, 0x97, 0x8d, 0x5b, 0x5c, 0x2d, 0x33,
    0x38, 0x0a, 0xb2, 0x65, 0xee, 0xc1, 0xbe, 0xb5, 0x91, 0xae, 0xd2, 0x18,
    0x7a, 0xed, 0x8e, 0x16, 0xf5, 0x78, 0xc8, 0x5b, 0xc5, 0x3c, 0x10, 0x4a,
    0xb0, 0x47, 0xec, 0x6d, 0xe8, 0xdb, 0xb7, 0x01, 0xe5, 0x91, 0xe7, 0xf5,
    0xe7, 0x63, 0xea, 0xad, 0x35, 0xea, 0xee, 0x5f, 0xd6, 0x1f, 0xcc, 0xc7,
    0xed, 0xb5, 0x3b, 0xda, 0xbc, 0xbe, 0xcd, 0x5c, 0x9e, 0x96, 0xb1, 0x12,
    0x31, 0xfc, 0x67, 0xd2, 0x20, 0x8c, 0xe0, 0x5a, 0xa3, 0xee, 0xbe, 0xb5,
    0xd7, 0x42, 0x39, 0xe4, 0x79, 0x7d, 0x7b, 0x8c, 0x5c, 0xd4, 0xfa, 0x75,
    0x38, 0x89, 0x3c, 0x1e, 0x4e, 0x86, 0x47, 0xf2, 0x73, 0xff, 0xbf, 0xed,
    0x5c, 0x95, 0x6a, 0x36, 0x3d, 0x15, 0x9f, 0x3e, 0xff, 0xfb, 0xf6, 0xcd,
    0xdc, 0xcd, 0x74, 0x92, 0x34, 0xab, 0x10, 0x82, 0x49, 0xf9, 0xe4, 0xf3,
    0xfa, 0x93, 0x10, 0xb9, 0xf8, 0x3b, 0xb8, 0x25, 0xb0, 0xa0, 0x04, 0x56,
    0x64, 0x12, 0x02, 0x47, 0xaf, 0xdd, 0xd1, 0xce, 0x55, 0x76, 0x23, 0xcb,
    0x5c, 0x34, 0xee, 0x66, 0xa2, 0xde, 0x49, 0x31, 0xd3, 0xa9, 0x09, 0xf6,
    0xc8, 0x7d, 0x08, 0x78, 0x3e, 0x19, 0x91, 0x8b, 0x13, 0xdb, 0x32, 0xf7,
    0xe0, 0x95, 0xf5, 0x14, 0x4a, 0xf0, 0x11, 0x4a, 0x09, 0x62, 0xdf, 0x5e,
    0xbb, 0xa3, 0xa1, 0xc1, 0x70, 0xe8, 0x45, 0x32, 0xe4, 0xf5, 0x92, 0xba,
    0x02, 0xd3, 0xc0, 0x53, 0xf1, 0x2f, 0xfe, 0xff, 0x60, 0xa2, 0x45, 0x34,
    0xe2, 0xde, 0x72, 0x48, 0x7a, 0x5d, 0x89, 0x7b, 0xd9, 0x51, 0x85, 0xa2,
    0x1c, 0x1c, 0x5a, 0x2b, 0x2f, 0x7d, 0x32, 0xcf, 0x97, 0x8c, 0x35, 0xaf,
    0x21, 0x48, 0x54, 0xc3, 0x9b, 0x2b, 0x73, 0xb0, 0xbd, 0xbd, 0x2d, 0x40,
    0xbd, 0x47, 0xe9, 0x0f, 0x21, 0x18, 0x6f, 0xae, 0xc4, 0x77, 0xc6, 0x24,
    0x52, 0x30, 0x52, 0xed, 0xbe, 0xb5, 0x11, 0x4a, 0x54, 0x8c, 0xe0, 0x2c,
    0x5c, 0x30, 0x1e, 0x41, 0xaf, 0xdd, 0xd1, 0x48, 0xe4, 0x22, 0x33, 0x59,
    0x82, 0x13, 0x9f, 0x64, 0x12, 0xe2, 0xcc, 0x69, 0xaf, 0xdd, 0xd1, 0x50,
    0x47, 0x39, 0x1a, 0x6a, 0xbb, 0x6c, 0x90, 0x87, 0xd9, 0x7c, 0xf9, 0x77,
    0xba, 0x91, 0x99, 0xbd, 0x76, 0x47, 0x5b, 0xd0, 0x7f, 0x03, 0xd2, 0x9b,
    0x0e, 0xa2, 0xcc, 0x34, 0xe9, 0xbd, 0xe5, 0x20, 0x68, 0xea, 0x65, 0x69,
    0xb8, 0xdc, 0x04, 0x93, 0x86, 0xa2, 0x06, 0x73, 0xc9, 0x71, 0xe4, 0x02,
    0x00, 0x94, 0xe1, 0x0c, 0x94, 0x3f, 0xc5, 0xbf, 0x49, 0x6f, 0x92, 0xd7,
    0x87, 0x7a, 0xfa, 0xda, 0x67, 0x5c, 0x67, 0x82, 0x28, 0x90, 0x12, 0x2d,
    0x2a, 0x83, 0x8b, 0x60, 0xe4, 0x29, 0x93, 0x70, 0xd1, 0xb8, 0x1b, 0x4b,
    0xae, 0x97, 0x71, 0xfa, 0x11, 0x4a, 0x70, 0xe2, 0x97, 0x4f, 0x54, 0xeb,
    0x4f, 0x08, 0x76, 0x94, 0xcb, 0xf6, 0xa8, 0xe7, 0xf5, 0x67, 0x52, 0x8e,
    0xed, 0xa9, 0x77, 0x99, 0xba, 0x3d, 0x6d, 0xc3, 0x65, 0x26, 0x18, 0xc5,
    0xb8, 0x51, 0x88, 0x53, 0xae, 0x77, 0xc2, 0x74, 0xe6, 0x99, 0x07, 0x59,
    0xc4, 0xbd, 0x32, 0xbd, 0x69, 0x11, 0x0e, 0xa3, 0x90, 0x30, 0x89, 0x16,
    0x9a, 0x90, 0x50, 0x86, 0x13, 0xff, 0x39, 0x2d, 0xe2, 0xdc, 0xc1, 0xe3,
    0xc8, 0x57, 0xb1, 0x17, 0x87, 0xe3, 0xef, 0x13, 0x27, 0x85, 0xf7, 0xd5,
    0x01, 0xf2, 0xa8, 0x4a, 0x51, 0xc3, 0x76, 0x99, 0x08, 0x46, 0xa9, 0x47,
    0x12, 0x50, 0x1f, 0x2e, 0x6b, 0x45, 0x34, 0xed, 0x2d, 0x6b, 0xdd, 0x98,
    0x41, 0x6a, 0x2c, 0x93, 0x9c, 0xb5, 0x12, 0x19, 0xea, 0xa5, 0x52, 0xf0,
    0x05, 0xe3, 0x11, 0x33, 0xb9, 0xc8, 0xc4, 0xeb, 0x60, 0xf9, 0xeb, 0x70,
    0xf3, 0x96, 0x86, 0x14, 0x44, 0xb2, 0x6c, 0x15, 0xa3, 0x44, 0x4b, 0x30,
    0x93, 0x96, 0xc4, 0x4c, 0xa3, 0x67, 0x6f, 0x89, 0x33, 0xfc, 0x12, 0x3e,
    0x2e, 0x1a, 0xf5, 0x08, 0x89, 0xa9, 0xc4, 0x01, 0x31, 0x7d, 0x29, 0x0a,
    0x78, 0xe6, 0x4c, 0xc6, 0x39, 0x44, 0xe0, 0x34, 0x2c, 0x3a, 0x0a, 0x2c,
    0x1e, 0x44, 0xbe, 0x51, 0x01, 0x10, 0x43, 0x70, 0xb0, 0x2f, 0x17, 0x07,
    0x7a, 0xb7, 0x87, 0xa7, 0x12, 0x9a, 0x36, 0xa4, 0x9e, 0x4b, 0x94, 0x49,
    0x95, 0xfd, 0x61, 0x93, 0x60, 0x26, 0x2d, 0x09, 0x50, 0x82, 0xa8, 0x5c,
    0x39, 0x1e, 0x5b, 0x44, 0x93, 0x0b, 0x90, 0xf1, 0x90, 0x9d, 0x73, 0x95,
    0xdd, 0x4c, 0xbe, 0x2c, 0x83, 0x6e, 0x86, 0x5c, 0x15, 0x3b, 0x60, 0x3b,
    0x35, 0x61, 0x63, 0xc4, 0x64, 0x90, 0x0b, 0x10, 0x41, 0x70, 0x94, 0x87,
    0xb7, 0x68, 0x6c, 0x71, 0xa9, 0x97, 0x74, 0x2c, 0xd9, 0x26, 0x54, 0xa6,
    0x93, 0xe5, 0x65, 0xd2, 0x7a, 0xdc, 0xcf, 0x4f, 0x5a, 0xbe, 0x59, 0xe6,
    0x60, 0xfc, 0xcc, 0x14, 0xac, 0x57, 0x5e, 0x52, 0xd5, 0x2b, 0x8b, 0x0c,
    0xf9, 0x9e, 0xf4, 0x07, 0xe6, 0x92, 0x49, 0xc9, 0x4d, 0x7b, 0x0d, 0x44,
    0x82, 0x69, 0x9f, 0xfc, 0x03, 0x00, 0x38, 0xaf, 0x3f, 0x99, 0x75, 0xa6,
    0x03, 0x39, 0x8b, 0x46, 0xb3, 0x4a, 0x79, 0x91, 0x0b, 0xa0, 0xc0, 0xeb,
    0xa3, 0xd3, 0xdc, 0x30, 0xd2, 0x98, 0x64, 0x51, 0xf7, 0x65, 0x4c, 0xc1,
    0x51, 0xfd, 0x92, 0xf3, 0xfa, 0x36, 0xb7, 0x7a, 0x49, 0xc3, 0x65, 0x55,
    0x0e, 0x61, 0x78, 0x10, 0xe5, 0x30, 0xaa, 0x40, 0x2e, 0x40, 0xce, 0xaf,
    0xae, 0x4c, 0x93, 0x7a, 0x83, 0x66, 0x5a, 0x15, 0x72, 0x01, 0x30, 0x82,
    0x93, 0x7c, 0x3b, 0x91, 0xa5, 0x42, 0x2a, 0x7c, 0x56, 0x37, 0x6f, 0x04,
    0xc9, 0xa5, 0x75, 0xd4, 0xcb, 0x68, 0xf0, 0x99, 0x2b, 0x78, 0x5a, 0xcc,
    0x33, 0x02, 0xa9, 0xf1, 0x92, 0x06, 0xf0, 0x07, 0x81, 0x0f, 0x42, 0x40,
    0x6f, 0xfc, 0x4b, 0xa8, 0xde, 0x29, 0xc1, 0x2c, 0xea, 0x0d, 0xbe, 0xc2,
    0xc9, 0x82, 0xa8, 0x63, 0x4e, 0x93, 0x79, 0x46, 0x20, 0xdd, 0x9b, 0x2c,
    0x3c, 0xe5, 0x28, 0x48, 0x57, 0x70, 0x11, 0xcc, 0x33, 0x4d, 0xc5, 0x79,
    0x93, 0x0b, 0xc0, 0x4d, 0xf0, 0x41, 0x7c, 0x11, 0x06, 0x4c, 0xa3, 0x7a,
    0x79, 0x91, 0xd5, 0x3d, 0x60, 0x26, 0x58, 0xd3, 0x86, 0x91, 0x9d, 0x05,
    0x38, 0x48, 0x9f, 0xe1, 0x9b, 0xb6, 0xe7, 0x6f, 0x10, 0xac, 0xdd, 0x95,
    0x32, 0x9f, 0xb7, 0x24, 0x30, 0x25, 0x3a, 0xa2, 0x3e, 0x9a, 0x39, 0x03,
    0x3b, 0xf2, 0xb0, 0x5c, 0xb1, 0x04, 0xe3, 0x9f, 0xbb, 0xf5, 0x3a, 0xba,
    0xbd, 0x21, 0xab, 0x49, 0x92, 0xe4, 0xd3, 0x6c, 0x9e, 0x7b, 0xed, 0x8e,
    0x46, 0x72, 0x2c, 0xf3, 0xbc, 0xe6, 0x48, 0x13, 0x5d, 0x82, 0x03, 0xe2,
    0x32, 0x74, 0x96, 0x60, 0xe8, 0x2c, 0x71, 0x79, 0xd4, 0xd3, 0x6c, 0x9e,
    0x71, 0x04, 0xef, 0x4b, 0xde, 0x0d, 0x3a, 0x82, 0xe0, 0x0f, 0xb1, 0xcb,
    0xd0, 0x99, 0x23, 0x86, 0x42, 0xb4, 0xcf, 0xe0, 0xe6, 0x7d, 0xb1, 0x59,
    0x40, 0x35, 0xbf, 0xc3, 0x27, 0x18, 0xaf, 0x18, 0x69, 0xc4, 0x01, 0x69,
    0x01, 0x08, 0x7f, 0xa2, 0x61, 0x06, 0x0f, 0xaa, 0x0c, 0x8e, 0x0f, 0x29,
    0x38, 0x6d, 0xcc, 0x4a, 0xfa, 0xc8, 0x0a, 0x40, 0xfe, 0xad, 0x38, 0x6b,
    0xa0, 0xeb, 0x57, 0xc1, 0x62, 0x11, 0x27, 0xe5, 0x10, 0xad, 0xc6, 0xe6,
    0xa0, 0xaa, 0xc4, 0xc5, 0xe6, 0x01, 0xd4, 0xb8, 0xf3, 0xba, 0xfe, 0x4c,
    0x72, 0xd1, 0x2d, 0x73, 0xcf, 0x57, 0x77, 0xd1, 0x4c, 0x79, 0xde, 0x0d,
    0x9b, 0x3a, 0xad, 0x4e, 0x9e, 0x44, 0x4c, 0x5b, 0x7a, 0x33, 0x4f, 0x15,
    0x47, 0xce, 0x9b, 0x34, 0x09, 0x6a, 0x9b, 0x94, 0xc6, 0x20, 0x6a, 0x8a,
    0x20, 0x5e, 0x30, 0x4d, 0x8c, 0x35, 0x09, 0x44, 0xc7, 0x61, 0x52, 0x1a,
    0x82, 0x68, 0x30, 0xa5, 0x2a, 0xc3, 0xb3, 0x87, 0xa8, 0xe1, 0xfe, 0xb3,
    0xc2, 0xaf, 0x7b, 0x4e, 0x0a, 0xca, 0x1b, 0xcc, 0x53, 0xdb, 0xe1, 0xa1,
    0x8e, 0xaa, 0x44, 0xab, 0xd0, 0x45, 0xa7, 0x12, 0xb8, 0xe6, 0x2e, 0xa4,
    0xc5, 0xb3, 0x79, 0x92, 0x9d, 0x74, 0xd0, 0x78, 0x51, 0x88, 0x4e, 0x34,
    0x39, 0x25, 0x6f, 0xe2, 0x22, 0x69, 0x03, 0x10, 0x3d, 0xe2, 0xbf, 0x28,
    0xa4, 0x06, 0x91, 0x6a, 0xf6, 0x51, 0xd5, 0x33, 0x54, 0x45, 0x24, 0x14,
    0x87, 0xb0, 0xe9, 0x65, 0x55, 0x20, 0x7b, 0x46, 0xe8, 0x38, 0x84, 0xcf,
    0x1f, 0x9c, 0x05, 0xd1, 0x33, 0x22, 0xd9, 0x91, 0xf9, 0x04, 0xd1, 0x3c,
    0x0d, 0x60, 0x46, 0x64, 0x7a, 0x28, 0x33, 0x03, 0xf8, 0x0c, 0x72, 0xa0,
    0xc4, 0xac, 0x2b, 0x33, 0xc8, 0xc3, 0x8c, 0xe0, 0x29, 0xc7, 0xff, 0xd4,
    0xf2, 0x1f, 0xb3, 0x3b, 0xcc, 0xe1, 0x30, 0x00, 0x00, 0x00, 0x00, 0x49,
    0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

static const char* const image1_data[] = { 
"85 85 2114 2",
"b8 c #b81f3b",
"ls c #b8384f",
"k. c #b91740",
"lF c #b91e3d",
"fO c #bb1334",
"BB c #bc1d39",
"kN c #bc3b51",
"s. c #bd0a32",
"qm c #bd173f",
"qT c #bd1842",
"nr c #bd1d3f",
"k3 c #bd2439",
"ei c #be123a",
"rX c #be193b",
"s7 c #bf0c34",
"q3 c #bf123d",
"eY c #bf1339",
"jK c #bf1834",
"CF c #bf1a3a",
"m0 c #bf1c3b",
"AN c #c01041",
"tt c #c0133e",
"xN c #c0143a",
"Dj c #c0163a",
"cd c #c01832",
"AX c #c0183b",
"sW c #c01945",
"mF c #c02141",
"wP c #c02642",
"d4 c #c0294a",
"i9 c #c02a47",
"t4 c #c11137",
"DR c #c1113f",
"fE c #c1143f",
"u8 c #c1153b",
"EZ c #c1153d",
"mZ c #c11640",
"gT c #c1173c",
"BC c #c11839",
"qn c #c11a48",
"fP c #c12041",
"cw c #c1324e",
"qc c #c20837",
"nU c #c20f2f",
"u3 c #c20f37",
"yJ c #c20f39",
"hq c #c21034",
"r. c #c2113d",
"e6 c #c21239",
"A# c #c21240",
"tP c #c2133a",
"pj c #c21439",
"xb c #c21540",
"Ez c #c21542",
"na c #c21737",
"qH c #c21739",
"rP c #c2183f",
"v1 c #c21e41",
"j. c #c22746",
"nb c #c22947",
"hu c #c22948",
"yc c #c23651",
"bV c #c30529",
"p3 c #c30e39",
"iX c #c30e41",
"ra c #c30f3e",
"vZ c #c31135",
"A0 c #c31341",
"r8 c #c3143b",
"EY c #c3143d",
"CI c #c31643",
"nV c #c31838",
"CG c #c3183a",
"h4 c #c31940",
"jO c #c3313c",
"oa c #c35061",
"tJ c #c40d3b",
"oO c #c40f3c",
"v0 c #c41037",
"qv c #c4103f",
"sE c #c4112f",
"fK c #c41139",
"zZ c #c4113b",
"i3 c #c41234",
"h8 c #c41236",
"pb c #c41242",
"vx c #c4133d",
"rh c #c4133f",
"gg c #c4143b",
"AM c #c41443",
"h3 c #c4153c",
"d9 c #c4153e",
"xP c #c41540",
"fx c #c4163b",
"x. c #c41735",
"vH c #c41742",
"uS c #c41744",
"qI c #c41745",
"y7 c #c41939",
"p. c #c41a37",
"dA c #c41f3f",
"bC c #c42c45",
"iF c #c44058",
"pe c #c50a37",
"yn c #c50d41",
"wW c #c50d43",
"sc c #c50e3c",
"tQ c #c50e3e",
"Br c #c50e46",
"AL c #c50f37",
"mt c #c50f38",
"r2 c #c50f3f",
"vw c #c51039",
"es c #c5103b",
"pt c #c51136",
"ij c #c51138",
"gy c #c5113e",
"kQ c #c51141",
"u4 c #c5123c",
"uk c #c51249",
"EW c #c51343",
"tD c #c5143e",
"uT c #c51440",
"Ei c #c51539",
"gI c #c5153b",
"rk c #c51543",
"ck c #c5163d",
"xO c #c51641",
"A2 c #c5173c",
"d7 c #c5174a",
"rr c #c51845",
"xT c #c51a3c",
"b3 c #c51b40",
"kY c #c51c3b",
"ft c #c52042",
"cG c #c52845",
"gl c #c53451",
"kt c #c53648",
"n6 c #c53751",
"jc c #c53953",
"i0 c #c60931",
"oL c #c60b38",
"xW c #c60f2e",
"yK c #c60f3b",
"xq c #c60f3d",
"gc c #c61036",
"vk c #c61039",
"x8 c #c61040",
"EH c #c61041",
"y6 c #c61132",
"qO c #c6113e",
"tk c #c61239",
"hG c #c6123f",
"no c #c61241",
"bx c #c6133a",
"o1 c #c6133d",
"eP c #c61444",
"py c #c6163a",
"pq c #c6163c",
"EU c #c6163d",
"EE c #c61644",
"uW c #c6183d",
"bG c #c61935",
"cc c #c61937",
"bU c #c61d3c",
"xX c #c61e38",
"nm c #c61f3d",
"Di c #c6314f",
"lX c #c63f50",
"wV c #c65857",
"nn c #c70935",
"o2 c #c70c39",
"on c #c70e37",
"pK c #c70e38",
"Cn c #c70e3a",
"EI c #c70f41",
"xg c #c70f43",
"BY c #c7103e",
"km c #c71046",
"pp c #c71139",
"fl c #c7113a",
"EQ c #c71141",
"EV c #c71142",
"zi c #c7123b",
"gz c #c7123f",
"eQ c #c71336",
"Ej c #c71338",
"Dk c #c7133a",
"pc c #c71340",
"xA c #c71342",
"EG c #c71343",
"qN c #c7143c",
"cY c #c7143e",
"bv c #c71539",
"ia c #c71549",
"bM c #c71633",
"eW c #c71640",
"tR c #c71642",
"mK c #c7173d",
"h. c #c71839",
"Eu c #c71c46",
"Cq c #c71d44",
"ly c #c71e3f",
"vr c #c71f43",
"of c #c72d45",
"rH c #c72e4d",
"wB c #c7334b",
"jH c #c73d56",
"px c #c80c3c",
"qV c #c80e3f",
"xQ c #c80e40",
"pJ c #c80f3b",
"j8 c #c81036",
"xh c #c81042",
"pL c #c8113d",
"iw c #c8113f",
"tv c #c81141",
"El c #c81238",
"mM c #c8123b",
"sK c #c81242",
"BI c #c81243",
"p0 c #c81245",
"b9 c #c81336",
"yq c #c8133c",
"wu c #c8133e",
"yt c #c81346",
"bB c #c8142f",
"wv c #c81439",
"sR c #c8143b",
"CH c #c81441",
"Cp c #c81443",
"mT c #c81533",
"c4 c #c8153c",
"f7 c #c8153d",
"t2 c #c8153f",
"tb c #c81646",
"o3 c #c81741",
"xc c #c81743",
"jy c #c81745",
"yH c #c8183e",
"bW c #c81938",
"yj c #c81c42",
"eB c #c81e42",
"i8 c #c81f48",
"sD c #c84d5f",
"mo c #c85164",
"eC c #c85a63",
"uK c #c90b3b",
"nq c #c90c36",
"rm c #c90e39",
"ib c #c90e3b",
"gm c #c90f36",
"vz c #c90f3e",
"jr c #c90f40",
"Ac c #c90f41",
"pm c #c91039",
"vG c #c9103c",
"bw c #c91135",
"t1 c #c91137",
"BE c #c91145",
"cU c #c9123e",
"ff c #c91240",
"tu c #c91242",
"pu c #c91339",
"nK c #c91343",
"qM c #c91346",
"it c #c9143d",
"jh c #c91441",
"ht c #c9153c",
"mL c #c91542",
"EF c #c91545",
"m5 c #c9163e",
"o0 c #c91640",
"n7 c #c91739",
"vj c #c91844",
"Aa c #c91846",
"ul c #c91a45",
"sv c #c91b3e",
"Ca c #c91b40",
"lv c #c91e42",
"cM c #c91f44",
"d0 c #c92049",
"hN c #c9334e",
"ms c #c93952",
"DV c #c94048",
"hy c #c95063",
"dU c #c95761",
"vc c #ca0935",
"zY c #ca0938",
"us c #ca0a33",
"js c #ca0a3b",
"s0 c #ca0b3e",
"vF c #ca0c38",
"wt c #ca0d43",
"Bs c #ca0e3e",
"qs c #ca0e40",
"uV c #ca0f3a",
"wG c #ca0f3c",
"xf c #ca0f44",
"iJ c #ca1037",
"wZ c #ca1039",
"nJ c #ca103f",
"qB c #ca1041",
"EJ c #ca1042",
"lK c #ca113a",
"bX c #ca113b",
"p9 c #ca113d",
"oT c #ca1238",
"ee c #ca133f",
"fh c #ca1341",
"ry c #ca1343",
"qj c #ca1349",
"oS c #ca143c",
"yZ c #ca143d",
"Ab c #ca1445",
"sF c #ca1536",
"DP c #ca153e",
"q9 c #ca1540",
"dV c #ca1542",
"xF c #ca163b",
"j9 c #ca163d",
"oP c #ca1643",
"pW c #ca1646",
"qf c #ca173f",
"u6 c #ca1741",
"t5 c #ca183c",
"zV c #ca1a40",
"kH c #ca1b42",
"pd c #ca1b46",
"jV c #ca1c41",
"lf c #ca2245",
"zE c #ca294b",
"y8 c #ca2b49",
"Cr c #ca2b4b",
"ko c #ca314d",
"w3 c #ca344d",
"BO c #ca384b",
"ou c #ca3b41",
"l7 c #ca3b59",
"kI c #ca3e59",
"nC c #cb0830",
"ni c #cb092b",
"pT c #cb0b3e",
"ha c #cb0c37",
"b2 c #cb0c38",
"AK c #cb0d33",
"b0 c #cb0d39",
"bz c #cb0d3b",
"p6 c #cb0d3d",
"p# c #cb0e34",
"uw c #cb0f32",
"q2 c #cb0f3f",
"pH c #cb0f41",
"rx c #cb0f42",
"xm c #cb0f49",
"w2 c #cb102d",
"o7 c #cb102f",
"cj c #cb103b",
"cW c #cb103d",
"yV c #cb1045",
"kC c #cb1136",
"c9 c #cb1138",
"jE c #cb1140",
"qp c #cb1142",
"lI c #cb1143",
"y5 c #cb1234",
"fN c #cb123b",
"cl c #cb123c",
"pN c #cb123e",
"oX c #cb1339",
"xi c #cb1345",
"pQ c #cb1347",
"BF c #cb1349",
"xn c #cb134f",
"q4 c #cb1440",
"dW c #cb1442",
"gU c #cb1444",
"wr c #cb153d",
"eu c #cb153e",
"j1 c #cb1548",
"rn c #cb163f",
"dc c #cb1641",
"yI c #cb1643",
"tL c #cb1649",
"ln c #cb183f",
"iA c #cb1840",
"wa c #cb1842",
"vB c #cb193b",
"yx c #cb1a37",
"fF c #cb1b49",
"gD c #cb1c43",
"lx c #cb1d42",
"zD c #cb2347",
"fz c #cb274a",
"Eg c #cb303e",
"zU c #cb364a",
"m# c #cb4057",
"eJ c #cb5865",
"j0 c #cc0a3f",
"Et c #cc0b38",
"fU c #cc0c3b",
"v9 c #cc0c3f",
"j2 c #cc0d2f",
"c# c #cc0d38",
"y2 c #cc0d39",
"q0 c #cc0d40",
"kf c #cc0d43",
"qG c #cc0e3a",
"oZ c #cc0e3c",
"pE c #cc0e3e",
"kl c #cc0e4e",
"jB c #cc0f35",
"Af c #cc0f37",
"DS c #cc0f39",
"Ey c #cc0f45",
"fL c #cc0f47",
"oQ c #cc1040",
"nL c #cc1042",
"xk c #cc1043",
"zX c #cc113c",
"po c #cc113e",
"yW c #cc1146",
"xp c #cc1239",
"ca c #cc123b",
"oN c #cc1241",
"du c #cc1243",
"uz c #cc1244",
"kS c #cc133c",
"q7 c #cc133d",
"eg c #cc133f",
"qE c #cc143a",
"pR c #cc1448",
"pM c #cc1541",
"b1 c #cc163f",
"dt c #cc1646",
"hh c #cc1647",
"lC c #cc1740",
"qb c #cc1744",
"pr c #cc183f",
"dY c #cc1845",
"tx c #cc1848",
"fV c #cc1941",
"o# c #cc1a3e",
"ka c #cc1b49",
"zC c #cc1c43",
"lw c #cc2145",
"x7 c #cc264e",
"nH c #cc2944",
"vV c #cc2f4e",
"BN c #cc324a",
"mJ c #cc324e",
"sy c #cc334f",
"kB c #cc3653",
"v8 c #cc3a47",
"ub c #cc4c59",
"yR c #cc6276",
"gs c #cd063d",
"cx c #cd0a34",
"tm c #cd0c39",
"ef c #cd0c3b",
"dI c #cd0d32",
"qX c #cd0d3e",
"wJ c #cd0e37",
"fr c #cd0e39",
"iB c #cd0e3a",
"rq c #cd0e42",
"iU c #cd0f33",
"f5 c #cd0f35",
"bZ c #cd0f3b",
"f. c #cd0f3d",
"rF c #cd0f3f",
"d. c #cd1036",
"pz c #cd1038",
"rC c #cd103a",
"BH c #cd1046",
"yo c #cd1048",
"hl c #cd104a",
"kG c #cd1141",
"qZ c #cd1143",
"iW c #cd1144",
"gA c #cd114c",
"cm c #cd123d",
"rA c #cd123f",
"qK c #cd1249",
"h9 c #cd1338",
"wY c #cd133c",
"pG c #cd1342",
"y1 c #cd1344",
"xj c #cd1345",
"cC c #cd1434",
"ql c #cd143d",
"nB c #cd143e",
"by c #cd1440",
"gQ c #cd1632",
"di c #cd1642",
"u5 c #cd1646",
"Dl c #cd173f",
"v# c #cd1747",
"rU c #cd1748",
"ut c #cd174a",
"uY c #cd1839",
"ci c #cd1841",
"de c #cd1843",
"ud c #cd1845",
"qP c #cd1948",
"fJ c #cd1a42",
"dB c #cd2139",
"vP c #cd233e",
"xr c #cd2441",
"h0 c #cd244b",
"fW c #cd2546",
"l6 c #cd2548",
"l5 c #cd274b",
"hb c #cd274d",
"eR c #cd2a47",
"i4 c #cd2d4f",
"vm c #cd2f52",
"zF c #cd3453",
"dq c #cd6274",
"xB c #ce0845",
"AY c #ce0936",
"vU c #ce0937",
"uj c #ce093e",
"u7 c #ce0a38",
"qz c #ce0b43",
"rG c #ce0d3a",
"yw c #ce0d3c",
"B0 c #ce0e35",
"re c #ce0e3d",
"t8 c #ce0e3f",
"rj c #ce0e41",
"y# c #ce0f38",
"wK c #ce0f3a",
"ev c #ce0f3b",
"cA c #ce0f42",
"pS c #ce0f43",
"pX c #ce0f45",
"vQ c #ce1032",
"Ew c #ce1034",
"co c #ce103c",
"dg c #ce103e",
"rg c #ce1040",
"Ex c #ce1137",
"ps c #ce1139",
"pP c #ce1147",
"kR c #ce1242",
"f6 c #ce1244",
"Ep c #ce1245",
"rM c #ce133e",
"w0 c #ce1340",
"gt c #ce1348",
"qL c #ce134a",
"oJ c #ce1439",
"iv c #ce143b",
"Bq c #ce143d",
"tI c #ce1443",
"ys c #ce1445",
"np c #ce153e",
"vb c #ce153f",
"Co c #ce1541",
"hz c #ce1638",
"Ek c #ce163c",
"cz c #ce1747",
"xo c #ce1750",
"oR c #ce183e",
"t9 c #ce1946",
"Ck c #ce1e45",
"tW c #ce214e",
"eM c #ce2635",
"BU c #ce2743",
"CE c #ce2d4e",
"jp c #ce3553",
"g5 c #ce425d",
"r4 c #ce425f",
"bK c #ce5568",
"nw c #ce667d",
"bL c #cf0128",
"ER c #cf093a",
"lG c #cf093c",
"uN c #cf0a35",
"ho c #cf0b3b",
"oK c #cf0c34",
"iz c #cf0c36",
"jx c #cf0d3f",
"pB c #cf0d41",
"eA c #cf0e3a",
"mn c #cf0e3b",
"hm c #cf0e3d",
"qQ c #cf0e43",
"df c #cf0f3e",
"pU c #cf0f40",
"rE c #cf0f42",
"sI c #cf0f48",
"EK c #cf0f4a",
"BX c #cf1039",
"uu c #cf103b",
"fg c #cf1043",
"EB c #cf1044",
"i. c #cf1046",
"o9 c #cf1135",
"om c #cf113d",
"kD c #cf113f",
"kO c #cf1141",
"wF c #cf123a",
"pZ c #cf1248",
"jD c #cf124c",
"y4 c #cf1334",
"th c #cf1343",
"d6 c #cf1345",
"ws c #cf1346",
"wH c #cf143f",
"rO c #cf1441",
"g1 c #cf153a",
"c. c #cf153c",
"sS c #cf153e",
"r7 c #cf1544",
"wX c #cf1547",
"fq c #cf1640",
"r1 c #cf1642",
"tl c #cf1749",
"tS c #cf1844",
"hk c #cf1942",
"sM c #cf1b40",
"zk c #cf1b48",
"nO c #cf1e48",
"zA c #cf2047",
"Eh c #cf2144",
"eV c #cf2446",
"BV c #cf2542",
"kb c #cf274b",
"BM c #cf2846",
"lL c #cf2a4a",
"ux c #cf3050",
"Bo c #cf3341",
"sk c #cf3750",
"uO c #cf435d",
"nj c #cf4554",
"C# c #cf455c",
"nv c #cf4868",
"AW c #cf4b62",
"ce c #cf6772",
"lp c #cf6f73",
"mO c #d00837",
"zs c #d00b36",
"n8 c #d00c32",
"hX c #d00c34",
"rN c #d00c3a",
"oY c #d00c3c",
"zu c #d00c3e",
"oW c #d00d35",
"EX c #d00d39",
"va c #d00e40",
"qq c #d00e42",
"lH c #d00e43",
"iQ c #d00f3c",
"dd c #d00f3e",
"pO c #d00f44",
"jW c #d01037",
"cV c #d0103f",
"lJ c #d01041",
"e8 c #d01043",
"sZ c #d0113c",
"cy c #d0113d",
"gS c #d01144",
"e9 c #d01145",
"ic c #d01236",
"wM c #d01238",
"DK c #d0123e",
"kF c #d01240",
"dX c #d01242",
"eO c #d01339",
"wI c #d0133d",
"AO c #d01437",
"uA c #d01444",
"pD c #d01446",
"DL c #d01542",
"kg c #d0154c",
"jZ c #d01645",
"Eq c #d01647",
"y. c #d01739",
"oI c #d01743",
"lt c #d01b44",
"uJ c #d01b46",
"id c #d01c3f",
"ip c #d02641",
"f4 c #d0264b",
"AH c #d02748",
"l4 c #d02750",
"BT c #d02d48",
"my c #d02d4c",
"hD c #d02f41",
"zy c #d03151",
"vi c #d0334e",
"wi c #d03650",
"BK c #d03f5e",
"xz c #d04059",
"E1 c #d05661",
"jd c #d10938",
"lb c #d10b24",
"y0 c #d10b3c",
"yv c #d10b40",
"sT c #d10c39",
"sL c #d10c3a",
"pI c #d10c41",
"Cl c #d10c44",
"Ev c #d10d3b",
"qe c #d10d3d",
"nM c #d10d3f",
"BZ c #d10e36",
"EN c #d10e3a",
"pw c #d10e48",
"uc c #d10f31",
"eX c #d10f41",
"ji c #d10f43",
"bA c #d1103c",
"fi c #d1103d",
"hE c #d1103f",
"EL c #d11049",
"EO c #d1113a",
"rJ c #d11140",
"gR c #d11142",
"ri c #d11144",
"wL c #d1114a",
"kn c #d1123d",
"pg c #d1123e",
"ym c #d11245",
"kP c #d11246",
"ru c #d1133f",
"nI c #d11341",
"qU c #d11343",
"g6 c #d1143a",
"pF c #d11545",
"jF c #d11547",
"yU c #d11548",
"iY c #d11643",
"og c #d1173c",
"gh c #d1173e",
"B1 c #d1193d",
"tV c #d11c49",
"gM c #d12348",
"dw c #d1294a",
"kT c #d12a48",
"l2 c #d12f54",
"z8 c #d13153",
"yy c #d1384a",
"BP c #d13d53",
"Cs c #d13d55",
"DW c #d14e54",
"fp c #d1506c",
"eF c #d15b71",
"cp c #d16e73",
"aU c #d17b7a",
"bj c #d1807c",
"z# c #d18176",
"Cv c #d18d9a",
"eI c #d20337",
"vA c #d20a39",
"ED c #d20a3b",
"uC c #d20b42",
"Cm c #d20b46",
"ya c #d20c3d",
"p5 c #d20c3f",
"xd c #d20d42",
"o4 c #d20d43",
"oi c #d20d45",
"io c #d20e32",
"xV c #d20e34",
"pi c #d20e3c",
"kk c #d20e3e",
"d5 c #d20e40",
"hM c #d20f39",
"l1 c #d20f3b",
"EM c #d20f47",
"uX c #d21035",
"qC c #d21042",
"xe c #d21044",
"y3 c #d2113e",
"BD c #d21140",
"w1 c #d2114a",
"iV c #d21237",
"hL c #d21239",
"jC c #d2123b",
"cX c #d21241",
"p7 c #d21243",
"m8 c #d21245",
"qS c #d21346",
"hn c #d21349",
"e. c #d21440",
"nN c #d21442",
"t. c #d21444",
"pV c #d21648",
"uI c #d21742",
"en c #d21847",
"gH c #d21943",
"ec c #d21b47",
"BW c #d22543",
"jt c #d22a4e",
"ur c #d23351",
"xY c #d2344b",
"Cj c #d23550",
"A4 c #d23f5b",
"zG c #d23f5c",
"AG c #d24555",
"eL c #d25364",
"wQ c #d25b61",
"Dh c #d25b6f",
"C2 c #d25f5c",
"C3 c #d2615d",
"CL c #d26779",
"sn c #d2686a",
"xZ c #d26a71",
"qR c #d30840",
"vl c #d30939",
"AI c #d30945",
"q# c #d30a3e",
"oj c #d30a40",
"se c #d30b32",
"ta c #d30b3a",
"cb c #d30c35",
"ty c #d30c37",
"qx c #d30c43",
"DQ c #d30d3e",
"rz c #d30d40",
"q. c #d30d42",
"DJ c #d30e39",
"wN c #d30e3b",
"s8 c #d30e3c",
"xS c #d30e43",
"mv c #d30e44",
"uU c #d30f3d",
"wq c #d30f3f",
"dv c #d30f41",
"pa c #d3103c",
"pY c #d31048",
"rf c #d31143",
"ui c #d31145",
"EA c #d31146",
"cL c #d3123e",
"rB c #d3123f",
"m6 c #d31241",
"mw c #d31247",
"rp c #d31249",
"wE c #d3133a",
"z9 c #d3133c",
"xE c #d31342",
"vR c #d31346",
"hY c #d3143d",
"hZ c #d31440",
"rb c #d31447",
"e7 c #d31541",
"xl c #d31543",
"vy c #d31545",
"Ae c #d31640",
"sq c #d31843",
"sd c #d31940",
"qW c #d3194a",
"lu c #d31a43",
"fe c #d31c48",
"eG c #d3252e",
"go c #d32f54",
"yL c #d33f57",
"Ef c #d3424f",
"z0 c #d3425f",
"ww c #d3435c",
"k7 c #d34d58",
"vI c #d3506f",
"tc c #d3515b",
"w9 c #d35a69",
"gV c #d36b6a",
"mE c #d37887",
"ox c #d3797b",
"cs c #d38288",
"ew c #d38489",
"mH c #d3929a",
"lm c #d39aa3",
"tK c #d4053d",
"rV c #d40742",
"sp c #d40938",
"lo c #d40a30",
"dZ c #d40b3f",
"Dp c #d40c3b",
"o6 c #d40c4a",
"sz c #d40d36",
"qu c #d40d44",
"nh c #d40e32",
"mx c #d40e41",
"xD c #d40e43",
"w. c #d40f3a",
"gn c #d40f3c",
"yu c #d40f44",
"zB c #d40f45",
"xR c #d40f47",
"yS c #d4103e",
"cB c #d41040",
"c7 c #d41042",
"kX c #d41131",
"t3 c #d41246",
"i# c #d4133f",
"kj c #d41340",
"A1 c #d41348",
"EP c #d4143b",
"er c #d41445",
"hg c #d41447",
"in c #d41540",
"uv c #d4163a",
"k5 c #d4163c",
"Ad c #d41644",
"p4 c #d41646",
"DT c #d4173f",
"r9 c #d41741",
"ts c #d41848",
"l3 c #d4204f",
"xG c #d42745",
"zz c #d4284e",
"k6 c #d4294b",
"iM c #d42b52",
"nT c #d43752",
"rv c #d43a56",
"BQ c #d43f55",
"oo c #d4415d",
"vs c #d44561",
"wp c #d44b5d",
"mP c #d44e69",
"BA c #d45365",
"tn c #d4596b",
"h2 c #d45c5d",
"wb c #d46578",
"dm c #d46671",
"wC c #d46a78",
"hH c #d46c69",
"yd c #d47e81",
"tr c #d50037",
"uL c #d5063e",
"cn c #d50738",
"sY c #d50747",
"g2 c #d50a37",
"mG c #d50c36",
"m9 c #d50c40",
"pC c #d50c42",
"Em c #d50d3e",
"DM c #d50e45",
"qy c #d50e47",
"iL c #d50f40",
"rs c #d50f42",
"qY c #d50f44",
"p1 c #d5103d",
"fM c #d5103e",
"qw c #d51045",
"oV c #d51139",
"zW c #d5113f",
"pf c #d51141",
"ET c #d51143",
"sJ c #d5123a",
"je c #d5123c",
"AZ c #d5123e",
"n9 c #d51338",
"oU c #d5153c",
"qd c #d51544",
"tF c #d51546",
"vT c #d51642",
"hp c #d5173d",
"Bp c #d51840",
"gd c #d52b50",
"BS c #d53750",
"uD c #d54151",
"E4 c #d5575b",
"t0 c #d55b66",
"C4 c #d56460",
"f9 c #d56969",
"dn c #d57277",
"jY c #d57374",
"ej c #d5746e",
"k2 c #d57e84",
"gC c #d60735",
"zt c #d6073d",
"jG c #d60b38",
"wO c #d60b40",
"qA c #d60b43",
"Dn c #d60c3c",
"pl c #d60d39",
"yb c #d60d41",
"rW c #d60d43",
"ma c #d60e32",
"uB c #d60e3d",
"pk c #d60f3a",
"w# c #d60f46",
"ed c #d61041",
"tG c #d61043",
"qD c #d6113f",
"d8 c #d61147",
"yT c #d61242",
"q1 c #d61244",
"uM c #d6133f",
"r# c #d61446",
"ue c #d61448",
"ez c #d6274e",
"ii c #d6284d",
"DH c #d63054",
"BR c #d63e55",
"y9 c #d6425c",
"E3 c #d6585b",
"tz c #d66171",
"d# c #d66676",
"mb c #d6676e",
"u9 c #d6707e",
"jA c #d67773",
"aB c #d67b78",
"B4 c #d67b80",
"ov c #d67d75",
"h7 c #d67d79",
"sw c #d68993",
"sX c #d70534",
"lB c #d7073b",
"vq c #d7083c",
"Dm c #d7093a",
"Eo c #d70a42",
"DN c #d70a43",
"pn c #d70b3c",
"yl c #d70b3e",
"mu c #d70b40",
"x# c #d70c37",
"BL c #d70c39",
"ok c #d70c41",
"BG c #d70c44",
"o8 c #d70d33",
"bY c #d70d3d",
"rt c #d70d3f",
"hF c #d70e42",
"f8 c #d70e44",
"qo c #d70e45",
"et c #d70f3e",
"fT c #d70f40",
"qF c #d7103b",
"mm c #d71142",
"vS c #d71146",
"fs c #d7123f",
"qr c #d71247",
"p2 c #d71341",
"pA c #d71343",
"qa c #d71345",
"eH c #d71642",
"jq c #d71746",
"r3 c #d71748",
"k4 c #d7183a",
"rR c #d72350",
"hW c #d72e4f",
"jj c #d7415a",
"zH c #d74663",
"zT c #d75a62",
"kE c #d76766",
"yi c #d76c7c",
"q6 c #d7777b",
"n2 c #d77872",
"fw c #d77a8c",
"oq c #d77d7c",
"aA c #d78378",
"CK c #d78884",
"q5 c #d8083c",
"yk c #d80a3b",
"qJ c #d80b44",
"ds c #d80c3f",
"o. c #d80e36",
"Cb c #d80e40",
"oM c #d80f3b",
"dr c #d80f3d",
"xC c #d80f46",
"h# c #d8113a",
"m7 c #d81245",
"Dq c #d8243f",
"zh c #d82447",
"yG c #d82a4d",
"ng c #d83c54",
"Ci c #d85662",
"eK c #d85a68",
"cT c #d85c76",
"zI c #d85e6b",
"yz c #d86167",
"mU c #d8626e",
"ix c #d86c6a",
"CX c #d8736b",
"n1 c #d87b73",
"a0 c #d87f7b",
"bk c #d8807e",
"rK c #d8808e",
"iu c #d9093d",
"q8 c #d90a3e",
"qk c #d90a40",
"c5 c #d90b3c",
"gi c #d90c37",
"oH c #d90c47",
"xU c #d90e3b",
"gB c #d91044",
"qt c #d91046",
"fy c #d9113f",
"ph c #d91140",
"ol c #d91545",
"ks c #d94553",
"s1 c #d94a5c",
"sN c #d95b5e",
"n# c #d95f74",
"fa c #d96669",
"C5 c #d96864",
"fS c #d96d7c",
"od c #d9757f",
"oF c #d97a78",
"aG c #d97c87",
"CW c #d97d72",
"a2 c #d97e7b",
"aD c #d97e7d",
"o5 c #da0545",
"k# c #da0845",
"yr c #da0b3f",
"DI c #da0f3c",
"vp c #da1243",
"dH c #da1437",
"AJ c #da163e",
"zj c #da1644",
"cH c #da223e",
"B2 c #da3553",
"AP c #da384d",
"zr c #da4666",
"mA c #da516f",
"E2 c #da545b",
"xs c #da545d",
"n5 c #da5a73",
"vv c #da5f62",
"e# c #da6379",
"c3 c #da6b7b",
"bT c #da6c79",
"AF c #da6d70",
"sm c #da6e7e",
"e5 c #da6f83",
"su c #da7070",
"yF c #da707e",
"sA c #da7271",
"tw c #da736a",
"ti c #da736e",
"nQ c #da7384",
"nG c #da7481",
"a4 c #da7676",
"n0 c #da7972",
"nX c #da7973",
"tg c #da798c",
"os c #da8077",
"a1 c #da827e",
"w4 c #da828e",
"uf c #db053b",
"En c #db0a41",
"dh c #db0b3f",
"mN c #db0d3d",
"lO c #db0e37",
"p8 c #db0f42",
"tE c #db0f44",
"eh c #db1143",
"oh c #db1344",
"dG c #db334d",
"Bn c #db4a57",
"kW c #db576c",
"hT c #db576e",
"B3 c #db586a",
"cK c #db5f77",
"fD c #db6362",
"sf c #db677a",
"pv c #db6b69",
"s9 c #db6f6f",
"um c #db737e",
"oz c #db7477",
"s6 c #db7487",
"op c #db7583",
"hj c #db7b7f",
"xH c #db7b87",
"tq c #db7d8d",
"iI c #db818b",
"CV c #db887a",
"tX c #db8b8e",
"t6 c #db9595",
"wo c #db9f94",
"gf c #dba7ab",
"f# c #dc0540",
"rQ c #dc0940",
"A. c #dc0e3c",
"vd c #dc1341",
"DU c #dc1f45",
"nD c #dc435f",
"Ct c #dc5365",
"lN c #dc536d",
"Ee c #dc5a62",
"kx c #dc646e",
"jX c #dc6a6a",
"CY c #dc6c68",
"nP c #dc707f",
"ES c #dc7272",
"nZ c #dc7671",
"gx c #dc777f",
"ba c #dc7787",
"oA c #dc787a",
"bh c #dc7c7d",
"bb c #dc7c88",
"aE c #dc7d79",
"or c #dc7d7b",
"aY c #dc7e7c",
"bn c #dc7e7e",
"Bz c #dc878c",
"zS c #dc9486",
"f0 c #dc98a5",
"c6 c #dd0f40",
"z. c #dd516b",
"i7 c #dd5770",
"zl c #dd5772",
"ve c #dd6066",
"DX c #dd6265",
"zJ c #dd6b75",
"C6 c #dd6d69",
"jf c #dd6d6c",
"xM c #dd6e74",
"sB c #dd6e77",
"a9 c #dd7282",
"DO c #dd7377",
"g0 c #dd7471",
"is c #dd767a",
"gb c #dd7775",
"z7 c #dd7888",
"ki c #dd7979",
"bi c #dd7f7f",
"aT c #dd8184",
"yA c #dd8e8a",
"ay c #dd9690",
"c8 c #de083c",
"eN c #de0937",
"iK c #de0e3f",
"rl c #de0e42",
"Bt c #de254f",
"vC c #de4f6d",
"Bu c #de565a",
"iP c #de595c",
"jw c #de595e",
"A5 c #de697b",
"n4 c #de6a6d",
"tU c #de6b70",
"Ed c #de6d71",
"fj c #de7270",
"cZ c #de7385",
"dj c #de7476",
"fI c #de7778",
"be c #de7883",
"gJ c #de7885",
"oE c #de7a7a",
"az c #de7b76",
"bl c #de8382",
"Dg c #de848e",
"ie c #de8a97",
"nl c #de8c90",
"CU c #de8f80",
"dF c #de9795",
"za c #de9e95",
"Cw c #dea5ae",
"Cg c #deb9b0",
"t# c #df1352",
"Dr c #df3d54",
"DG c #df506c",
"ke c #df5d67",
"v2 c #df657e",
"yp c #df6c73",
"tO c #df6f7f",
"sG c #df7174",
"n3 c #df7575",
"nR c #df7589",
"Ec c #df7b7b",
"nY c #df7c76",
"aC c #df7c7f",
"b# c #df7d8a",
"g3 c #df888e",
"D. c #df8f90",
"tT c #e00339",
"x9 c #e00a40",
"vE c #e00c3f",
"eZ c #e00e3d",
"C1 c #e05b5e",
"C0 c #e06061",
"CZ c #e06665",
"nf c #e0707e",
"oD c #e07376",
"sU c #e07378",
"nF c #e07b8b",
"dJ c #e07c88",
"fm c #e07d8f",
"bd c #e08189",
"k8 c #e0878d",
"E5 c #e08e9c",
"jU c #e09093",
"x0 c #e0989c",
"vh c #e09993",
"gG c #e0aaa8",
"iZ c #e10737",
"eD c #e1526e",
"eS c #e1566b",
"hf c #e15963",
"gr c #e15b64",
"u2 c #e15d74",
"x6 c #e1607c",
"gj c #e16c7c",
"rc c #e16e69",
"oc c #e16e7d",
"jg c #e17376",
"nS c #e17686",
"oB c #e1777b",
"iT c #e17b77",
"ob c #e17d85",
"DZ c #e1827c",
"dM c #e18d8d",
"D0 c #e18f84",
"la c #e19297",
"zm c #e19a9e",
"B5 c #e1afa6",
"zg c #e25566",
"sQ c #e26279",
"nW c #e26378",
"qg c #e27070",
"EC c #e27173",
"fk c #e27175",
"DF c #e27183",
"aX c #e27280",
"DY c #e27473",
"A3 c #e27578",
"AQ c #e2757a",
"ik c #e2808f",
"Eb c #e28887",
"hA c #e28888",
"zf c #e2898b",
"yM c #e2898f",
"dL c #e28c8d",
"iC c #e28f97",
"dC c #e2928b",
"dN c #e29291",
"dO c #e29492",
"AE c #e2958f",
"D1 c #e29a8c",
"bf c #e2a2a3",
"E. c #e2a89d",
"jm c #e2a9af",
"A7 c #e2ada9",
"u# c #e2bcaf",
"me c #e2c9c4",
"CD c #e35973",
"bu c #e36e88",
"hK c #e36f70",
"aZ c #e37c7d",
"zK c #e37f87",
"aJ c #e38391",
"ug c #e38d90",
"dD c #e39291",
"D9 c #e3a99e",
"vu c #e3c1b8",
"ot c #e44a54",
"Cu c #e4616f",
"ky c #e46961",
"C7 c #e47470",
"oy c #e4757b",
"oC c #e47679",
"ow c #e4777c",
"bm c #e47a7e",
"rY c #e48490",
"Bv c #e48583",
"xt c #e48b87",
"dK c #e48e8f",
"sh c #e49898",
"zq c #e498a4",
"Bk c #e49994",
"D# c #e49d9b",
"j# c #e4a2ac",
"D3 c #e4a89e",
"a5 c #e4c0aa",
"eE c #e54e6d",
"Bm c #e56971",
"gP c #e56981",
"nE c #e57184",
"bc c #e57988",
"aV c #e57c81",
"a3 c #e57d7e",
"C. c #e58189",
"jL c #e58593",
"lE c #e58890",
"xy c #e58b8b",
"m4 c #e59699",
"CM c #e59da1",
"Du c #e5a3a7",
"oG c #e5a6a1",
"D4 c #e5a99f",
"D8 c #e5aba0",
"Bw c #e5bab4",
"eq c #e5c1c3",
"sj c #e6063a",
"yY c #e66d76",
"tH c #e67370",
"g9 c #e67788",
"b. c #e67b8b",
"dz c #e67b97",
"Bl c #e68485",
"j7 c #e68493",
"Ch c #e68982",
"zL c #e69a9c",
"aM c #e69ba0",
"lD c #e69fa5",
"D2 c #e6a393",
"i1 c #e6a9b0",
"Bj c #e6ada4",
"Ds c #e76273",
"em c #e76974",
"uZ c #e76d78",
"wD c #e76e77",
"bF c #e77485",
"aF c #e77c86",
"wj c #e77d89",
"DE c #e79099",
"yE c #e7a0a4",
"vJ c #e7a1ab",
"bo c #e7aaa9",
"D5 c #e7aba1",
"D7 c #e7ada2",
"Dv c #e7bdbe",
"kZ c #e7c6c1",
"wS c #e7e6e1",
"u. c #e83360",
"Do c #e86875",
"l0 c #e86f80",
"tC c #e87185",
"Es c #e87379",
"xa c #e8757c",
"e0 c #e87989",
"aO c #e87a83",
"oe c #e87d87",
"rD c #e88b93",
"BJ c #e89a98",
"dP c #e89d9a",
"Df c #e8a1a5",
"wg c #e8a9b1",
"D6 c #e8aca2",
"ze c #e8bcb9",
"CN c #e8c0b8",
"br c #e8c0be",
"jP c #e8cccb",
"zx c #e95b75",
"iy c #e97075",
"C8 c #e97975",
"Dt c #e9858f",
"Ea c #e99392",
"hr c #e995a4",
"vn c #e997a3",
"wU c #e9a49d",
"a8 c #e9acb1",
"yQ c #e9adb5",
"AR c #e9b6b3",
"Ap c #e9c0be",
"vf c #e9c2bd",
"jz c #e9c3b8",
"wc c #e9cdca",
"eb c #e9d7cb",
"hS c #ea929e",
"v7 c #ea9694",
"j3 c #eaa1ac",
"A8 c #eab9b5",
"aQ c #eaf5e7",
"#3 c #eafffd",
"uH c #eb8696",
"cD c #eb8793",
"fQ c #eb889c",
"lc c #eb8b96",
"l8 c #eb98a8",
"CT c #eba394",
"vt c #ebaba2",
"v3 c #ebaeb5",
"Ar c #ebb6bc",
"jN c #ebb8b4",
"zM c #ebb8b5",
"Aq c #ebbabd",
"cS c #ebbcc2",
"yB c #ebbeb8",
"lh c #ebf4e3",
"Ah c #ebffff",
"z1 c #ec798a",
"vO c #ec7f85",
"vW c #ec8894",
"wA c #ec96a1",
"iG c #eca6ae",
"DD c #eca7aa",
"bS c #ecafae",
"ro c #ecb2b0",
"As c #ecb5bb",
"kp c #ecb6b6",
"AD c #ecb7af",
"lP c #ecbfc2",
"ua c #eccdcb",
"lU c #ece1dd",
"C9 c #ed7d79",
"wR c #ed8f87",
"E# c #ed9997",
"mS c #ed9ca2",
"uE c #eda1a1",
"wx c #edabac",
"zR c #edb1a6",
"sr c #edb2b6",
"CS c #edb5a4",
"Bi c #edbeb4",
"uP c #edbfbf",
"z2 c #edc4be",
"Ao c #edc7c4",
"td c #eddfdf",
"ld c #edfff3",
"aW c #ee7886",
"AV c #ee8997",
"x5 c #eea7ad",
"hi c #eebcb5",
"bN c #eec4b6",
"By c #eec8c5",
"eU c #eec8c7",
"h6 c #eefdf6",
"b5 c #eefff6",
"CC c #ef8d9c",
"gL c #ef9ca6",
"uy c #ef9dab",
"s# c #efabb6",
"z6 c #efbbbd",
"aR c #efbdbe",
"At c #efbdc0",
"Au c #efc1c3",
"Cx c #efc6ca",
"lT c #efcfd0",
"cE c #effbf7",
"sH c #effff8",
"A6 c #f08692",
"w8 c #f0b5b1",
"hs c #f0c5bf",
"cN c #f0c7c5",
"k9 c #f0d7d3",
"bJ c #f0fff4",
"hw c #f0fff6",
"#Q c #f0fffa",
"e3 c #f0fffc",
"cP c #f0fffd",
"#I c #f0ffff",
"aN c #f17985",
"dE c #f18b96",
"aS c #f1919c",
"lW c #f19aaa",
"wk c #f1c4bf",
"lR c #f1c7c8",
"zb c #f1c8c4",
"An c #f1d3cb",
"zp c #f1d7d6",
"hV c #f1dad4",
"kL c #f1faff",
"dS c #f1fdf3",
"md c #f1ffed",
"d2 c #f1fff0",
"s4 c #f1fffa",
"gq c #f1fffd",
"zv c #f1fffe",
"aq c #f1ffff",
"dQ c #f2a7a4",
"CB c #f2babd",
"Bh c #f2c8bc",
"mh c #f2cac8",
"Av c #f2caca",
"Da c #f2cbc4",
"CR c #f2d3be",
"Bg c #f2d8db",
"lQ c #f2e0dc",
"uR c #f2fbf6",
"kV c #f2fef4",
"te c #f2fff6",
"xJ c #f2fff8",
"yX c #f2fffa",
"c1 c #f2fffc",
"kv c #f2fffd",
".P c #f2ffff",
"jJ c #f38c8f",
"A9 c #f3cac6",
"aH c #f3cbcc",
"zN c #f3d8cf",
"to c #f3e0d9",
"sg c #f3e0da",
"dx c #f3e1d7",
"Ai c #f3edcd",
"ll c #f3eddf",
"mR c #f3faf2",
"Er c #f3fff8",
".O c #f3ffff",
"uq c #f4a9ad",
"im c #f4acc0",
"fG c #f4bab8",
"cv c #f4bcc5",
"xu c #f4c7c2",
"gN c #f4cbc5",
"eo c #f4cdce",
"wf c #f4d1cb",
"fd c #f4d3ca",
"aP c #f4d8ca",
"B8 c #f4e6db",
"#r c #f4f5f7",
"#q c #f4fdfa",
"vM c #f4fef5",
"Ak c #f4ffec",
"rT c #f4fff3",
"yh c #f4fff4",
"ep c #f4fff6",
"#P c #f4fff9",
"ja c #f4fffa",
".U c #f4fffb",
"l9 c #f4fffc",
"hU c #f4fffd",
"aw c #f4ffff",
"m1 c #f5b1b2",
"DC c #f5bdbc",
"mg c #f5c3c6",
"iR c #f5c5b7",
"Aw c #f5d6d3",
"AS c #f5edea",
"z4 c #f5faf4",
"il c #f5fcf4",
"wy c #f5fdff",
"cJ c #f5fff6",
".t c #f5fff8",
"hP c #f5fffa",
"#X c #f5fffb",
"g8 c #f5fffc",
"ao c #f5fffd",
".Q c #f5ffff",
"lg c #f6abb2",
"g7 c #f6bfbc",
"h5 c #f6c6b8",
"gk c #f6cfd0",
"x1 c #f6d6d7",
"Db c #f6e2d9",
"CO c #f6e3e5",
"un c #f6e4cc",
"jS c #f6e4e2",
"bg c #f6e6cc",
"fA c #f6f3e2",
"h1 c #f6f3ee",
"wn c #f6f4f5",
"#9 c #f6f9fe",
"j4 c #f6fbfe",
"yO c #f6fcfa",
"ig c #f6feff",
"ss c #f6fff5",
"iH c #f6fff6",
"#j c #f6fff7",
"#O c #f6fff8",
"#S c #f6fffb",
".x c #f6fffc",
"#p c #f6fffd",
"#z c #f6fffe",
".j c #f6ffff",
"eT c #f7a1aa",
"ns c #f7a7b0",
"i2 c #f7b8b1",
"xL c #f7bcc2",
"mi c #f7c7c7",
"aI c #f7dbd8",
"lM c #f7eae4",
"kc c #f7f4ef",
"lA c #f7fcff",
"ek c #f7fdf9",
".s c #f7fef6",
"rd c #f7feff",
"gK c #f7fff3",
"mq c #f7fff6",
"#i c #f7fff8",
"v5 c #f7fff9",
"uo c #f7fffa",
"#7 c #f7fffb",
"w6 c #f7fffc",
"Qt c #f7fffd",
"hI c #f7fffe",
".Z c #f7ffff",
"B9 c #f8aead",
"AU c #f8bbc0",
"ne c #f8bcbe",
"De c #f8c4d0",
"AC c #f8d2c9",
"db c #f8d7d0",
"yD c #f8dfda",
"Bf c #f8dfe2",
"mr c #f8e1d9",
"zn c #f8e8db",
"ag c #f8eeec",
"#Z c #f8f1f8",
"AB c #f8f4f5",
"gv c #f8f9f4",
"yg c #f8f9fd",
"ax c #f8fae4",
"#C c #f8faf9",
"kd c #f8fcfb",
".w c #f8fcff",
".7 c #f8fdf6",
"#Y c #f8fdf7",
"nz c #f8fdff",
"at c #f8fefa",
"ap c #f8fefe",
"x3 c #f8fff0",
"aa c #f8fff3",
"a# c #f8fff5",
"fY c #f8fff8",
"iO c #f8fff9",
"gY c #f8fffa",
"#W c #f8fffb",
"#8 c #f8fffc",
"bI c #f8fffd",
"e2 c #f8fffe",
".k c #f8ffff",
"zw c #f99b99",
"ct c #f9b1b2",
"sx c #f9c7c6",
"gu c #f9c8c4",
"fX c #f9cec8",
"rS c #f9d3d2",
"le c #f9d4cb",
"yN c #f9d8d1",
"B. c #f9dbd3",
"w5 c #f9dcde",
"ge c #f9ded3",
"fZ c #f9e4df",
"jQ c #f9e6e2",
"jn c #f9eae7",
"CQ c #f9f1da",
"Aj c #f9f4e0",
"CJ c #f9f6ff",
".d c #f9f7fa",
"wd c #f9f9f7",
"E9 c #f9fcff",
"#N c #f9fdfc",
"#A c #f9fdfe",
"g# c #f9fdff",
"#w c #f9fefa",
"bO c #f9feff",
"e1 c #f9fff2",
"hB c #f9fff3",
"vL c #f9fff5",
"#E c #f9fff6",
"uQ c #f9fff8",
"f2 c #f9fff9",
"a7 c #f9fffa",
".V c #f9fffb",
".p c #f9fffd",
".g c #f9ffff",
"b7 c #fab2b6",
"b4 c #fabcbd",
"kh c #fac2c3",
"mj c #facccc",
"xx c #fad3c4",
"tA c #fadbd8",
"hO c #fae1dd",
"Ax c #fae3dd",
"B# c #fae6df",
"Cf c #fae8da",
"wT c #fae8dc",
"Dw c #fae8e6",
"zd c #fae8e8",
"Ba c #faf0e6",
"CP c #faf1ec",
"tf c #faf8ec",
"z3 c #faf8fb",
"E6 c #faf9f5",
"lZ c #faf9fe",
"#x c #fafaf8",
"l. c #fafafa",
"a. c #fafafc",
"#V c #fafcf7",
"hQ c #fafcf9",
".G c #fafdff",
"#f c #fafef0",
"gp c #fafefd",
".0 c #fafeff",
"Al c #faffea",
"b6 c #fafff1",
"jM c #fafff8",
".T c #fafffa",
"#H c #fafffb",
".1 c #fafffc",
"tj c #fafffe",
"af c #faffff",
"mB c #fbbfc7",
"gE c #fbc3cc",
"f3 c #fbccd2",
"ey c #fbced3",
"rI c #fbd9d0",
"mD c #fbdbdc",
"vN c #fbe3e3",
"lk c #fbebdc",
"zO c #fbf3e6",
"uG c #fbf4ea",
"fC c #fbf7ee",
"mY c #fbf8ff",
"if c #fbf9fc",
"bq c #fbfaf6",
"fb c #fbfaff",
"si c #fbfbf1",
"t7 c #fbfbff",
"mV c #fbfcf6",
"do c #fbfcfe",
".v c #fbfcff",
"k0 c #fbfdfa",
".4 c #fbfdfc",
"j6 c #fbfef3",
"aL c #fbfef5",
".H c #fbfeff",
"fn c #fbfff3",
"gO c #fbfff6",
"mW c #fbfff8",
"ga c #fbfff9",
"ac c #fbfffa",
"fc c #fbfffb",
"fv c #fbfffc",
".2 c #fbfffd",
".b c #fbfffe",
".e c #fbffff",
"ku c #fcdbd4",
"bD c #fcddda",
"yC c #fce4da",
"tM c #fcf4e7",
"vX c #fcf5eb",
"Cd c #fcf6dc",
"tB c #fcf7f3",
"g. c #fcf9ff",
"AA c #fcfafb",
"Bc c #fcfbf6",
"#T c #fcfbf7",
"gW c #fcfbff",
"j5 c #fcfcf2",
"sb c #fcfcfc",
"r0 c #fcfcff",
"cg c #fcfdf7",
"jT c #fcfdf8",
".9 c #fcfdff",
"wm c #fcfef3",
"jv c #fcfef9",
"Dy c #fcfefb",
"#. c #fcfefd",
"i6 c #fcfff4",
"#g c #fcfff6",
"#d c #fcfff8",
".X c #fcfffa",
".6 c #fcfffb",
"#y c #fcfffd",
".m c #fcffff",
"vD c #fdbcc2",
"d3 c #fdc2c6",
"mf c #fdc6cb",
"xI c #fdc9cb",
"iq c #fdd5d5",
"u0 c #fdd8df",
"i5 c #fdd9d9",
"x4 c #fde1d6",
"CA c #fde1dd",
"B6 c #fde2d1",
"tZ c #fde2e7",
"lY c #fde4e0",
"Cy c #fde8e5",
"tN c #fdeef3",
"li c #fdefe4",
"Ay c #fdf0e7",
"g4 c #fdf3ea",
"ir c #fdf7ff",
"E7 c #fdf8f4",
"fR c #fdf8f5",
"kw c #fdf8ff",
"#D c #fdfbfc",
"#M c #fdfbff",
"lz c #fdfcf7",
".# c #fdfcfa",
"#K c #fdfcff",
"wh c #fdfdfb",
".K c #fdfdfd",
"#h c #fdfdff",
"mX c #fdfef6",
"yf c #fdfef8",
"ny c #fdfeff",
"rL c #fdffef",
"iD c #fdfff4",
"#G c #fdfff5",
"ab c #fdfff7",
"#m c #fdfffa",
"gX c #fdfffe",
"hC c #fecccf",
"ye c #fed0c1",
"jI c #fededf",
"mI c #fedfda",
"DA c #fee5e8",
"sl c #fee7df",
"Be c #feeaeb",
"s2 c #feece2",
"yP c #feecea",
"mp c #feede3",
"kU c #feede6",
"wz c #feefec",
"aK c #fef0f0",
"Bx c #fef1eb",
".3 c #fef9fd",
"x2 c #fefaf9",
".o c #fefafb",
"#n c #fefbf4",
"nt c #fefced",
"#J c #fefcff",
".D c #fefdf8",
".R c #fefdf9",
"s3 c #fefdfb",
"#L c #fefdff",
"ml c #fefefc",
"#o c #fefefe",
".I c #fefeff",
"ak c #fefff5",
"bP c #fefff6",
"qh c #fefff8",
".A c #fefff9",
"#k c #fefffa",
".q c #fefffb",
".a c #fefffd",
".n c #feffff",
"nc c #ffbac2",
"u1 c #ffc4c5",
"lr c #ffc5c8",
"ch c #ffc7c8",
"fu c #ffced1",
"lS c #ffced2",
"ih c #ffd0cb",
"dR c #ffd1df",
"cF c #ffd2d5",
"DB c #ffd3cf",
"d1 c #ffd4d4",
"jo c #ffd4d7",
"bR c #ffd6d4",
"jb c #ffd8d6",
"zQ c #ffd9ce",
"kM c #ffd9d2",
"dT c #ffd9d4",
"mk c #ffd9d5",
"jk c #ffdadb",
"iE c #ffdbdc",
"hv c #ffddd8",
"v. c #ffdddb",
"sC c #ffdee1",
"Dd c #ffdee4",
"sP c #ffe2df",
"jR c #ffe3e4",
"m. c #ffe4e3",
"nu c #ffe4e8",
"kA c #ffe5d9",
"r5 c #ffe5e4",
"mQ c #ffe5e7",
"Am c #ffe7db",
"ju c #ffe7e8",
"hc c #ffe7ef",
"v6 c #ffe8ed",
"z5 c #ffe9e4",
"sa c #ffeae7",
"rw c #ffebeb",
"sO c #ffecf5",
"bs c #ffede7",
"iN c #ffedeb",
"kJ c #ffeee6",
"nk c #ffeee9",
"nd c #ffeeea",
"mz c #ffeeec",
"zc c #ffeeee",
"n. c #ffefeb",
"bH c #ffeff0",
"vg c #ffeff6",
"lj c #fff0e5",
"Dz c #fff0f1",
"bt c #fff0f5",
"hx c #fff0fb",
"c2 c #fff1ec",
"Cc c #fff1f6",
"vK c #fff2eb",
"v4 c #fff2ec",
"fH c #fff2f1",
"ar c #fff2fd",
"k1 c #fff3ec",
"bQ c #fff3ee",
"am c #fff3ef",
"fo c #fff4f1",
"xv c #fff4f5",
"dk c #fff4fa",
"mC c #fff4fd",
"kK c #fff4ff",
"an c #fff5f1",
"AT c #fff5f3",
"Ag c #fff5f5",
"kr c #fff5fa",
"e4 c #fff5ff",
"m3 c #fff6e8",
"tp c #fff6ee",
"zP c #fff6ef",
"jl c #fff6f2",
"lV c #fff6f4",
"uF c #fff6f6",
"#b c #fff6f7",
"#R c #fff6f8",
"ae c #fff6fc",
"hd c #fff6ff",
"Ce c #fff7ea",
"m2 c #fff7eb",
"s5 c #fff7ee",
"E0 c #fff7f0",
"kq c #fff7f3",
"Bd c #fff7f4",
".r c #fff7f5",
"#6 c #fff7f6",
".8 c #fff7f8",
"a6 c #fff7fa",
"he c #fff7fb",
"cQ c #fff7fc",
"ad c #fff7fe",
".M c #fff7ff",
"xw c #fff8ec",
"au c #fff8f1",
"cI c #fff8f2",
"zo c #fff8f3",
"Dc c #fff8f5",
"qi c #fff8f7",
"sV c #fff8fb",
"Dx c #fff8fc",
"ea c #fff8fd",
"vY c #fff8fe",
".Y c #fff8ff",
"as c #fff9f0",
"vo c #fff9f2",
"cr c #fff9f3",
"cq c #fff9f7",
"#l c #fff9f8",
"r6 c #fff9f9",
"gF c #fff9fa",
"gZ c #fff9fd",
"#B c #fff9fe",
".N c #fff9ff",
"B7 c #fffaee",
"so c #fffaf2",
"#1 c #fffaf3",
"we c #fffaf4",
"rZ c #fffaf7",
"E8 c #fffaf8",
"F. c #fffaf9",
".E c #fffafa",
"#0 c #fffafb",
"#u c #fffafd",
"#t c #fffafe",
".L c #fffaff",
"l# c #fffbed",
"uh c #fffbee",
"Az c #fffbef",
"Bb c #fffbf0",
"lq c #fffbf1",
"up c #fffbf2",
"fB c #fffbf4",
"hR c #fffbf5",
"kz c #fffbf7",
"ah c #fffbf8",
"#4 c #fffbf9",
"gw c #fffbfa",
".h c #fffbfb",
"#a c #fffbfc",
"#v c #fffbfd",
"## c #fffbfe",
".i c #fffbff",
"w7 c #fffcef",
"aj c #fffcf3",
"bE c #fffcf4",
"dl c #fffcf6",
"nx c #fffcf7",
"f1 c #fffcf8",
"nA c #fffcf9",
"cR c #fffcfa",
"#s c #fffcfb",
"dy c #fffcfc",
".5 c #fffcfd",
"hJ c #fffcfe",
".l c #fffcff",
"tY c #fffdf3",
"al c #fffdf4",
"av c #fffdf5",
"ai c #fffdf6",
"Cz c #fffdf7",
"dp c #fffdf8",
"F# c #fffdf9",
"el c #fffdfa",
"#U c #fffdfb",
"iS c #fffdfc",
".S c #fffdfd",
".z c #fffdfe",
".c c #fffdff",
"mc c #fffeef",
"cf c #fffef0",
"cu c #fffef4",
"ex c #fffef5",
"xK c #fffef6",
"cO c #fffef7",
".u c #fffef8",
".C c #fffef9",
"#5 c #fffefa",
"#2 c #fffefb",
"bp c #fffefc",
".y c #fffefd",
".F c #fffeff",
"c0 c #ffffef",
"wl c #fffff1",
"da c #fffff3",
"#c c #fffff4",
"#e c #fffff6",
"st c #fffff7",
"#F c #fffff8",
".B c #fffffa",
".W c #fffffb",
".f c #fffffd",
".J c #ffffff",
"Qt.#.a.b.c.d.e.f.c.g.h.i.j.k.l.m.n.o.p.q.r.s.t.u.v.c.w.e.x.y.z.c.A.A.B.A.C.D.D.C.E.F.G.H.I.F.J.K.e.L.M.N.O.P.L.Q.R.a.m.n.F.S.f.T.l.F.J.U.V.W.X.s.Y.O.Z.J.i.L.J.0.i.c.1.n.n",
".2.#.F.F.3.J.4.5.L.6.7.8.L.9#..X.i.F.j##.Y.c#a#b#c#d.V.W#e#f#g.S#h.J.F.F.F.F.F.c#i#j#k.h#l#m.X#n#o.J.z.K.m#p#q.i.F.L.Y.F#r.5.l#s.i.l#t.z.F#u.c.F#v.a#w#x.y.y#y.p#z.F.J#A#A",
".J.F#B.l#C.m#D.c#b.B#E#F#u.c.V#G#H#I.P.v.Y#J.Z.k.B#..L#t.f.U.k.l#K.F.F#L.c.F.F#M.i.I.K.S.y#y#N.l.B#O.X#P.B.C#Q#R.k.i.c.g.P.Q#SQt.Q.k.V.f.a.k.e.F#T#U.W.6.q#V.6#W#X#H.c.m.m",
".n.m.L.c.6#Y.F.n#I#Z.5.y.M.Y.F#0#1#g#2.k.m.n#3#4#z.m.i.e#b#5#6.m.2.2.p#7#7.p.p#8#9a..qa#aaabac.Z.i.l.F.ead.Y.naeaf.g.aagahaiaj#eakalajamanaoap.Haqar.L.F.F.L.i.Fas#y.c.J.J",
"at.g.m.Fauav.qawaxayazaAaBaCaDaEaFaGaH.W.h#5aIaJaK#v#uaLaMaNaOaP##.l.l#v#v.F.F.FaQaRaSaTaUaVaWaXaYaZa0a1a2a3a4a5a6a7#ea8a9b.b#babbbcbdbebf#cah.cbgbhbibjbkblbmbnbobp.m.y.y",
".T.n.Zbqbrbs#F.QbtbubvbwbxbybzbAbBbCbD#k#TbEbFbGbH.abIbJbKbLbMbN#L.F.F.n.mafbOafbPbQbRbSbTbUbVbWbXbYbZb0b1b2b3b4.5b5b6b7b8b9c.c#cacbcccdcecfcg.echcicjckclcmcncocpcq.m.y.y",
"#k#t.Zcrcsctcu.g.ncvcwcxcyczcAcBcCcD.ucE.2cFcGcHcI.A.qcJcKcLcMcNcOcO#F#F#FaL#d#dcP.ncQ.ScRcScTb2cUcBcVcWcXcYcZc0.mc1#ic2c3c4c5c6c7c8c9d.d#da.q.kdbdcdddedfdgdhdidj.h#K#m#m",
"#Fdk.kdldmdnajdoaqdpdqdrdsdtdudvdwdxdy.m.FdzdAdBdCdDdEdFdGdHdIdJdKdLdMdDdNdOdPdQdR#baw.ZdSdadTdUdVdWdXdYdZd0d1d2.L.N.f#cd3d4d5d6d7d8d9e.e#aiea.Nebecedeeefegeheiej.h.Y.V.V",
".cekelaqemeneoep.N#7eqereseteuevewex.Q.FeyezeAeBeCeDeEeFeGeHeIeJeKeLeFeMeNeOePeQeReSeT#g.P.3.BeUeVeWeXeYeZe0e1e2.Be3e4.f#ge5e6e7e8e9f.f#fa.afbfcfdfefffge8fhcUfifj.F.F.m.m",
".J.a.B.kfkflfmfn.J.ffofpfqfrfsftfu#Ffv.BfwfxfyfzfAfB#cfCfDfEfFfGc0ajfHfIfJfKfLfMfNfOfPfQ.h.efRaifSfTfUfVfWfXfY#KfZf0f1f2.Bf3f4f5fgf6f7f8f9.fg.#mfdfefffge8fhcUfifj.F.F.m.m",
"g#.Fga#agbgcgdge.U.S.ugfggghgigj#0#m.Xgkglgmgngoaggpgq.ggrgsgtgugvgw.NgxgygzgAdvgBcygCgDgE.2gF.VgGc5gHgIgJgK.2.cgLgMgNgO#o#ygPgQgRgSgTgUgV.f.l#kfdfefffge8fhcUfifj.F.F.m.m",
"gWgXgYgZg0g1g2g3acfc#kg4g5g6bwg7.eg8gOg9h.h#hahbhchd#Bhehfhghhhi.g#h.ihjdVhkhlhmhnhohphqhr.W.c#zhsgHhthuhvhw.nhxhyhzhAhBaq.ZhChDhEhFfxhGhH.S.l.Wfdfefffge8fhcUfifj.F.F.m.m",
".lhIa7hJhKhLhMhNhOhPhQhRhShqhTc0.HhUhVhWhXhYhZh0h1.cfv.qh2h3h4h5#Ih6.ah7h8h9i.i#iaibicidie.qifigihiiijikalil#7iminioipiq.nirgOisitiuiviwix#a.i.ffdfefffge8fhcUfifj.F.F.m.m",
".i.Q#k#oiyiziAiBiCiD.n.hiEiFiGiH.c#FiIiJiKf7iLiMiN.5iO.AiPiQb1iRiScR.EiTiUiViWfNiXiYiZi0i1#W.F.ki2i3i4i5#2#2i6i7i8i9j.j#gZ.NjajbjcjdjecXjfdy.v.ffdfefffge8fhcUfifj.F.F.m.m",
".c.pf1.mjgevjhjijjjk.e.cjljmjn.J#5jojpgcjqjrjsjtju.5#Wjvjwjxjyjz.kfc#2jAjBjCjDjEjFbZjGjHjI.2.n.yjJjKjLjM.c#2jNjOjPjQjRjSjT.fgX.ijUjVjWcXjX.f.e.yfdfefffge8fhcUfifj.F.F.m.m",
".m.fcR.mjYjZj0j1j2j3.Zj4gwj5bI.Yj6j7j8j9k.k#kakbkc.4#zkdkekfkgkh.n.J#0kikjkkklkmjxknkokpkq.S#Pkrksktkukvkw#2kxkycR.a.fcRaikz.n.ZkAkBkCkDkE.f.k.Efdfefffge8fhcUfifj.F.F.m.m",
".n.J.BaffkcokFkGkHkIkJa7kK.gkL.ikMkNkOkPkQkRkSkTkUbp.ckVkWkXkYkZk0#Fk1k2k3k4k5k6k7k8k9.fl.jal#lalblc.g.Fldlelflglhliljlkll#e.n.Q.Jlmlnlolplq.S.mlrlsltlulvlwlxlyjAlz.5lAlA",
".n.J.BaffkcokFkGlBlClD#e.i#K.bgwlElFlGlHlIlJlKlLlM.k.kQtlNlOc4lP.m.g.6lQlRlSlTlUlq.uk0af.elVlWfVlXlYlZ.mall0l1l2l3l4l5l6l7l8gFl9.qm.m#mambmcjT.mmdmemfmgmhcNmimjmk.Fml.J.J",
".n.J.BaffkcokFkGmmmnmomp#ijamqmrmsmtmumvmwmxcjmymz.gaw.6mAg2f7mB.YmC.l#scR#U#N.Qgp.QbI#2mDmEmFmGmH.U#JbImImJmKjEmvmLmMmNmOmPmQepmRdamSmTmUc0jMafil#5cRmVmWmX.ucO#ymY.eelel",
".n.J.BaffkcokFkGmZflm0m1m2dam3m4m5m6m7gSm8m9kFjtn.f1#sann#nanbnc.g.m.n.f.f.5.L.NfHndnenfngnhninjnkexf1aunlnmnnmvePnoesnpnqnrnsnt.F.Snunvnwnx.L.c.L.i#LlA.eny.nnznA.l.2#5#5",
".n.J.BaffkcokFkGjrnBnCnDnEnFnGnHcWnInJnKnLnMnNnOnPnQnRnSnTnUnVnWnXnYnZn0n1n2n3n4n5n6n7n8n9o.o#oaobocodoeofogohoiojokolomeHonooopoqorosotouovowoxoyozoAoBoCoDoEoFoG.5#5.m.m",
".n.J.BaffkcokFkGoHoIoJoKfMoLiAoMoNoNoOoPfhkOkOoQoRoScaoToUoVoWoXoYhEoZbyo0o1byf.mLo2kFo3fEo4o5o6o7o8o9p.p#padYpbdvpcpdpepfpgevphbzpipjpkplpmpnpopppqprpapkpsptpupv#F#4igig",
".n.J.BaffkcokFkGpwpxpypzpApBpCnNf6pDpEpFpGdWpHpIpJlCf7pKpLpMdcpNpOpPpQpRpSpTpUerddfTpVpWpXpYpZp0pyp1p2p3p4p5p6p7p8p9mLpUq.lJpUq#qac7qbqcqdoZhmnIpNo0pLqecyqff7piqgqhqi.m.m",
".n.J.BaffkcokFkGqjqkknqlqmqnqoqpqqqrdZiLcWmLqsqtqujFqvqwqxqyqzqAeXqBnoffqCqDknqEeQqFqGpLcBcmqHh9qIqJpXqKqLqMqabXqNeeqOqPqQqRqSqTd5qUqVqWqXqUcYkDqYqZq0q1q2q3q4q5q6#w#Unyny",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.F.m.m",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.F.m.m",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.F.m.m",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.F.m.m",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.F.m.m",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.F.m.m",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.F.m.m",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.F.m.m",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOq7cmq8q9r.r#rarbrc#Frd.f.f",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOcWf.rebyrfrgrhmxaYjT.m.W.W",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOrirjrkgRrlrmrncyro.n.c.D.D",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOrprqrrrsrtruknrvrw.m.l.C.C",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOpXrxryrzrArBrCrD.F.H.i.B.B",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOqsd6rErFdcrGrHrI.e.9.Fmlml",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOegcXrJcYrfpGrKrL.c.J.m.I.I",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOrMrNrOrPrQrRrSrThJ.Wat.F.F",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOiBrUrVrWrXrYrZ.Zr0.F.5.g.g",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOr1kOr2r3r4r5.W.e.J.1r6.F.F",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOr7r8r9s.s#acqifcsaa7sb.c.c",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOscsdsesfrZ.j#2sgshsi.e.e.e",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOnIsjsksl.q.p.usmsnso.F.J.J",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOspsqsrss.WstiGc.su.u.Y#t#t",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOsvsw.B.ykzsxsyszsA#5.Y.W.W",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOsB#c.Z.NsCsDsEsFsG.f.FsHsH",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOqUqUkOlJlJlJlJsIqIsJrNsKsLsMsNsO#a#gsPsQsRsSsTsU#J.esVsV",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOpEpEkOqUgRlJpUsWsXsYsZogs0s1s2s3s4s5s6s7s8iBr1s9.c.Z#y#y",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOt.p6pEqUkOrgkOrgbwt#tatbc#tctd.StetftgkRedegthfhti.Se2tjtj",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOt.rgdXqUpEq2thkRfitktltmtntofY.LtptqkRtrtstttutvtwbp.e.l.l",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOlJrgdXkOq2kRr7jEtxtytktztAbItBsVtCtDtEtFpGfhnJtGtH.f#p.i.i",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOlJlJrgoQkRtIfftJtKtLkitM.WaltNtOtPfTeXtQqBtRtStTtU.c#z.f.f",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOgRp7rgoQtIiwfftVtWtX.qdatYtZt0t1t2pUt3fgjrdct4t5t6t7.n#k#k",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOt8lJrgkGpGsct9u.u##Fs3.Fuaubn9ucp9udqVlIueufsvuguh.Z.L.u.u",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOqQfgcAuiq.ujrbtuukj1o0f7qVulumunawuoupuqurusnNm8utp6uuuvuwuxuy.ugY.5.g.i.i",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOuznKnKf6qCdvuAcYkFuBuCr7uDuEuF.mcJuGuHuIeAuJuKpOuLjquMuNuOuPuQuRiS.c.k.c.c",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOq.duuSuTdfuUuVuWuXdduYuZu0.Wqhaqu1u2qfu3u4oQfgu5u6u7u8u9v..u.K.g.i.chI.h.h",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOv#kGvadfq7vbvcvdkSvevf.c.5.FvgvhvigmpKvjdXt.eWvkvlvmvnvohP#q.c.Y#L#L.m.f.f",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOpopNnNvpvqfivrvsvtcQ.m#k.mvuvvkSvwvxvyqCvzvAg2vBvCvD#GhP.nny.9.c.k.4iSfvfv",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOvEetvFvGvHvIvJvK.QvLvMvNvOvPclvQvRvSnMrAvTvUvVvWvX#Ffc#z.cvY#sgYcq.W.S.e.e",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOvZv0v1v2v3v4mWv5hdv6v7v8o1v9w.e7w#jswauucowbwchR#Pwd.i.ido.WwewfwgfBwh.n.n",
".n.J.BaffkcokFkGkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOwiwjwkwlwm.B.hwnwowpwqnMhtwrwswtd6wuwvwwwxs5.W#J.V.F.iwy.QwzwAwBwCup.2.l.l",
".facuQ.JwDf.pGrgqZf6thdXkOlJrJm6pLcUeeq4eeeecUeewEwFoXoSpNrFdvqtwGwHwIwJwKpUqQwLwMwNwOpCnJwPwQwRwSah.JhIepwTwUwVwWwXrOwYwZw0pSw1w2w3w4w5.2w6.6.B#L#8gOw7w8w9x.x#fj.F.F.m.m",
"#v.Ba#.mxaqNxbxcxdd5vaeXgRgRrgf.rytuqpnLfgrixejixfxgxhxixjxkrjqqxlf6xmxnxopRp9xpjDxqxrxsxtxuxv.c.L.SxwxxxyxzxAxBt5cljxxCxDxExFxGxHxIf1.f.l.LdyelxJxKxLe#gTfikFeWfj.F.F.m.m",
"iS#2cR.LxMxNq9dsvHxOxPpcjhfhpGtIw#quo4lHpOpSrxxQxRmvxSlJposRpqxTjrfUtaxUxVxWxXxYxZx0x1x2.g.2#gx3x4x5x6x7x8qUrtx9y.y#yaybxqycydyeyf#s.l.wyg.l#2yhkpyiyjykylymynyofj.F.F.m.m",
".FjT.B.FypyqxlyrpodXqUdXpUt8vaxejie8riymd6ysgUgUytpQkPyuyvlGywdfrBpzyxyyyzyAyByC.u#F.Aa7qhyDyEyFyGyHf7gzdVyIyJqNyKpgqEyLyMyNi6ja#0yO.Q.e.yyPyQyRi#ySrNyTgRyUyVyWfj.F.F.m.m",
".cQtyX.ZyYwKvkyZy0qeddgRdXy1rytucoomomevy2tmiQy3y4y4y5y6y7y8y9z.z#zazbzc#h.Q.j.k.izdzezfzgzhy0f8gIzicXrzfTzjsZiJzkzlzmznfnuQ.c.YfY#FzozpzqzrwIzszteXmLyIqXrzzuwGfj.F.F.m.m",
"zv.gnAfbzwzxvszyzzzAo0iwkOuizBqxclrnzCzDzEzFzGzHzIzJzKzLzMzNzOwl.N.N.F#2zPzQzRzSzTzUzVerm8qscWhZzWzXq9thzYzZz0z1z2tp#F#yz3.i.yz4z5z6z7z8iBwKz9A.A#AaAbAcqsAdAeAffj.F.F.m.m",
".n.iAgAhAiAjAkAlAmgeAnAoApAqArAsAtAuAvAwAxAyAzda.S.y.f.f.J.JAAABACADAEAFAGAHvRAIAJAKALb1rOqsr2AMANegAOAPAQARAS.Oep#k#0.F.WATAUAVAWAXAYAZvkfKwuqOedvzA0pWA1d5cjA2fj.F.F.m.m",
".Fl.#2.NA3A4A5A6A7A8A9B.B#BaBb#e.X#dBcBdfHBeBfBgBhBiBjBkBlBmBnBoBpcap9ysrynJcmBqBrkgwsBspNflvbBtBuBvBwBx.Scq#5bP.i#KBdByBzBABBBCqlpmknySBDpDBEBFbvy3tEBGBHBIdXrtfj.F.F.m.m",
"#s.6dy.mBJBKm5BLo0wucjwYsMBMBNBOBPBQBRBSBTBUBVBWw0w0w0w0egpNpNpLc.BXeAuUfif.BYpcBZB0B1B2B3B4B5B6.9.b.2aci6#cB7B8B9C.C#CarNCbcBq2kOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.z.m.m",
"kv.6Cc.QCdCeCfCgChn3CiCjCkfgClCmrApNvGp9pNpNvGCnCobypNp9pLcUeeq4BHlICpCqCrCsCtCuCvCwCxCyxK#ebPi6.uCzcICACBCCCDCECFCGoScyhEkGCHCIkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.z.m.m",
".NwhelCJCKCLCMCNCOCPdac0CQCRCSCTCUCVCWCXCYCZC0C1C2C3C4C5C6C7C8C9D.D#roDaDbuGi6uQDc#duojaa7.rDdDeDfDgDhDiDjDkDlxFDmDniLcXdXqZfggSkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.z.m.m",
".cl9.q.NDoDpcBb1DqDrDsDtDuDvzpDwDx#t.lhJ#DsbgX.n.i.l.l.c.c.c#L#L.J.ngpDy.f#sDzDADBDCDDDEDFDGDHlCDIDJsZwryqq7DKrGDLoNqOqOturiDMDNkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.z.m.m",
".cQt.W.LDODPDQvqDRCpdWpNvFDSDTDUDVDWDXDYDZD0D1D2D3D4D5D6D7D8D9E.E#EaEbEcEdEeEfEgEhEiEjEkivoXqEElDPf.EmEnrQEoxeEpiwgUEqEqysqZqZf6kOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.z.m.m",
"hdQtEr.nEsEtibEuf.cWpNbypMCorAcWp6rFdXqUkOrFp6p6EvpipifififificyEwExxpbXiwqpBHEyoZcWw0CorAdgcVhmEznoduvREApOEBBHpHfguiyuxdjxkOthkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.z.m.m",
"#Laquo#oECwYrfqZyjDPiBEDdZjigUEEEFEGEHEIEJlIiWEpp7gRlJpUrgrgrgrgEKELEMyukkENEOEPjivRy1EQEQryf6ymqruicAiwgzpctRvjthkGoQkOgRhEqeERkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.z.m.m",
".Y#..B.FESijETpCojdvt.r7dWpNdgdfcocoomDKruDKomomq2q2jEjEoNoNfhfhEUzip9dXdXqpEVEWdfcVywkkyThEfUkDBYpLpNdgcybAENEXybvaffEYEZd9f7eukOkOkOkOkOkOkOkOkOkOkOkOkOkOkOkOfj.F.z.m.m",
".Y.g#WE0laE1E2E3E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E5f1.a.e.e",
".c.FhQ.aE6E7E8cq#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#v#vkq.B#a.c.c",
"#N.J.i#h.g.Z.ZE9#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o#o.ax2tj.k.k",
".e.g.m.f#UF.F#.B.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.m.l.k#v#v",
".e.g.m.f#UF.F#.B.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.f.m.l.k#v#v"};

static const char* const image2_data[] = { 
"91 25 1017 2",
"mA c #002e00",
"jX c #00300a",
"lR c #00330a",
"d. c #00330d",
"#E c #003501",
"#G c #00350b",
"dd c #003510",
"mK c #00360d",
"kV c #00370a",
"dv c #003711",
"f5 c #003810",
"mz c #003909",
"fY c #003a0c",
"#J c #003b0b",
"g7 c #003b14",
"mO c #003b16",
"gr c #003c01",
"#H c #003c10",
"mN c #003c11",
"gV c #003d0b",
"hJ c #003d14",
"lj c #003f12",
"h0 c #00400c",
"gi c #004010",
"l4 c #004113",
"lW c #00421c",
"j4 c #004411",
"iO c #004415",
"gv c #004419",
"mt c #00441a",
"jm c #00441c",
"e2 c #004514",
"gD c #004515",
"kK c #004520",
"hu c #00461e",
"hz c #004625",
"jG c #004717",
"kL c #00471a",
"ff c #00471d",
"lF c #004814",
"ec c #004815",
"gp c #004817",
"k6 c #004912",
"gg c #004916",
"hw c #00491a",
"in c #00491c",
"j0 c #004921",
"hB c #004b17",
"jJ c #004b20",
"hE c #004c1c",
"ek c #004c1e",
"lI c #004d19",
"mu c #004d1e",
"jz c #004e1c",
"dp c #004e20",
"lk c #004e21",
"iz c #004e26",
"go c #004f23",
"gw c #005018",
"iJ c #005025",
"iE c #005029",
"ky c #005121",
"lB c #005421",
"lJ c #005423",
"hF c #005627",
"kI c #005726",
"jt c #005727",
"iA c #005a32",
"hX c #01360c",
"e. c #013713",
"g3 c #013a0f",
"mm c #013b0b",
"gj c #013d17",
"m# c #013e12",
"#I c #013e15",
"k5 c #01451c",
"mg c #014520",
"lf c #01461a",
"mh c #014723",
"kp c #014917",
"hn c #014d1c",
"it c #014f28",
"jN c #015420",
"hA c #015a2c",
"ib c #023612",
"ji c #023814",
"mD c #023b04",
"iZ c #023b08",
"kZ c #023c0c",
"my c #02410a",
"mx c #024114",
"fe c #024519",
"ms c #024613",
"gE c #02461f",
"lC c #025020",
"kH c #025121",
"ez c #025521",
"iF c #02592e",
"dC c #03320e",
"he c #033a12",
"mr c #033d17",
"gA c #03410e",
"iX c #034419",
"kJ c #034623",
"lg c #034718",
"hI c #03511f",
"iB c #035129",
"aF c #042e06",
"eW c #043b1b",
"mH c #043c19",
"ju c #04421b",
"mG c #044620",
"gS c #044714",
"lr c #044c26",
"do c #045127",
"hv c #04522a",
"jb c #053913",
"jw c #053a0e",
"gh c #053b17",
"jO c #053c14",
"es c #053c1f",
"mE c #053f16",
"gc c #054014",
"ij c #054216",
"l8 c #054219",
"dr c #054220",
"ly c #05431a",
"hh c #05461e",
"ki c #054624",
"jn c #054a1b",
"kC c #055323",
"la c #062f05",
"i7 c #063b11",
"gn c #06441d",
"lo c #06491e",
"gF c #064e1e",
"l9 c #064f22",
"dk c #073518",
"jv c #073f1a",
"bw c #074013",
"e9 c #07441b",
"jo c #074724",
"eA c #074a1f",
"ed c #074e22",
"js c #074e24",
"kB c #075426",
"iG c #075523",
"l3 c #08451b",
"gu c #08451c",
"lV c #084526",
"ks c #084f25",
"ko c #085124",
"jK c #08522d",
"iK c #085430",
"e1 c #085e2f",
"dz c #093116",
"gq c #094416",
"ej c #09481d",
"fO c #096325",
"fQ c #0a3a08",
"h7 c #0a3c16",
"lX c #0b3511",
"mq c #0b3914",
"c# c #0b3e15",
"md c #0c4a21",
"du c #0c4c2a",
"kh c #0c4d25",
"jl c #0c5125",
"dn c #0c542c",
"dh c #0d4017",
"jE c #0d5933",
"#F c #0e3e18",
"bx c #0e421c",
"hk c #0e572c",
"dq c #0e5930",
"jA c #0e5d30",
"eS c #0f4f2c",
"im c #0f5428",
"gz c #105131",
"lU c #10522e",
"dJ c #13562a",
"dR c #13562b",
"dH c #13582b",
"dW c #14512f",
"dQ c #14572c",
"dV c #145831",
"k# c #155226",
"dN c #15562b",
"dS c #15582d",
"dX c #16462c",
"#6 c #165131",
"iW c #16522c",
"dO c #16592e",
"dK c #175a2e",
"dT c #175a2f",
"dI c #175c2f",
"k. c #175c30",
"aE c #184f25",
"ey c #18502d",
"di c #185529",
"dP c #185b30",
"l. c #186030",
"dG c #194f2b",
"kU c #195124",
"co c #195934",
"dM c #195a2f",
"dU c #195d34",
"lT c #1a5332",
"dL c #1a5b30",
"ho c #1a6635",
"dF c #1b5233",
"aW c #1b5733",
"j# c #1b582e",
"lY c #1b5930",
"j8 c #1d5f31",
"e6 c #1e653d",
"ln c #1f613d",
"et c #1f6243",
"kz c #1f6944",
"dc c #224b2d",
"le c #225a35",
"f3 c #226134",
"hg c #235935",
"lz c #235e42",
"j3 c #235f39",
"i# c #236138",
"bK c #24673e",
"gm c #265d33",
"mp c #276232",
"mw c #276a37",
"lS c #285a3d",
"aG c #295d36",
"de c #2a643c",
"k0 c #2b5733",
"dw c #2b653c",
"#K c #2c6242",
"jZ c #2c6b40",
"dg c #2d5d35",
"ca c #2d6643",
"jC c #2e6444",
"eM c #2e6c43",
"dy c #2f5f37",
"hr c #2f683b",
"e8 c #306946",
"eo c #315e3f",
"fG c #316b45",
"ay c #326238",
"hP c #326844",
"nm c #326b38",
"d3 c #326b4a",
"gK c #326c46",
"is c #346649",
"hm c #346c3f",
"c2 c #356440",
"iS c #366342",
"ce c #366440",
"b5 c #366a46",
"iN c #366f42",
"n. c #367349",
"mj c #377252",
"hG c #396a4d",
"ei c #3a6c46",
"mk c #3a734a",
"cn c #3a744c",
"dm c #3b664b",
"jS c #3b6a48",
"jp c #3b6e4d",
"kr c #3b814b",
"cv c #3d6c42",
"eL c #3d764b",
"kt c #3e7454",
"jF c #3f7855",
"kP c #40724d",
"fF c #40774f",
"lq c #40794e",
"gJ c #407950",
"hH c #416e4f",
"jr c #41744b",
"d2 c #417753",
"cw c #41784e",
"cd c #417954",
"cu c #427147",
"jR c #42714d",
"jW c #43714d",
"hO c #437750",
"dx c #437a50",
"m9 c #437d55",
"lb c #446c4a",
"bq c #446c51",
"bp c #447353",
"kD c #447756",
"b4 c #447b53",
"jB c #45714d",
"l7 c #457751",
"kO c #457752",
"jD c #457b57",
"jM c #467c5c",
"df c #467f56",
"c1 c #477550",
"iR c #477551",
"io c #477d5d",
"ax c #48754c",
"ls c #48755e",
"mi c #497657",
"nl c #497d4f",
"eV c #4b7663",
"l5 c #4b7851",
"n# c #4c7958",
"iu c #4c8262",
"cf c #4d7658",
"gb c #4d7e4f",
"lQ c #4e7755",
"jL c #507a62",
"nn c #508358",
"#D c #518557",
"hq c #527758",
"hp c #527b5b",
"dA c #537b59",
"mc c #547f64",
"#5 c #548065",
"k4 c #557d65",
"mJ c #558064",
"k9 c #558d6a",
"jh c #598c63",
"j7 c #5d8e6e",
"g5 c #5e8b6e",
"l6 c #5f8965",
"mB c #60785e",
"f2 c #60896b",
"kn c #638260",
"j. c #638e72",
"i. c #638f74",
"aV c #648d6f",
"eT c #659771",
"nu c #668e6c",
"kE c #688b6d",
"nt c #688f70",
"e5 c #689076",
"gk c #698e6f",
"bJ c #69a079",
"dY c #6a8b7a",
"fP c #6a8e74",
"lp c #6b8b76",
"gB c #6d9978",
"hi c #6e8e69",
"kM c #6e9276",
"kq c #6e9578",
"mL c #6f8873",
"en c #6f8f77",
"m. c #6f9379",
"fX c #709277",
"kw c #719677",
"cq c #719879",
"lE c #729778",
"ct c #739f7e",
"aD c #74957a",
"nq c #749e8a",
"cA c #779782",
"hC c #77997e",
"mX c #779e7f",
"fR c #798e7b",
"lG c #799b80",
"iC c #799c88",
"ml c #79a17e",
"cS c #7aa186",
"cD c #7b9e86",
"nd c #7ba07f",
"mY c #7ca384",
"cT c #7ca388",
"mW c #7ca47f",
"cV c #7d9683",
"nM c #7d9a7e",
"kF c #7d9e83",
"cL c #7da185",
"cR c #7da187",
"cj c #7e9585",
"i6 c #7e9e86",
"cG c #7ea286",
"cN c #7ea288",
"cE c #7f9d81",
"cg c #7fa189",
"cK c #7fa387",
"cO c #7fa389",
"kv c #80a089",
"nF c #80a184",
"cI c #80a287",
"dj c #80a385",
"cm c #80a488",
"cQ c #80a48a",
"cH c #81a388",
"cJ c #81a589",
"cM c #81a58b",
"iP c #829b88",
"nk c #82a088",
"nP c #82a182",
"kW c #82a587",
"cU c #82a58d",
"cF c #82a68a",
"cP c #82a68c",
"c9 c #82a98a",
"dB c #82ac86",
"iH c #839c87",
"nC c #83a38b",
"nv c #83aa98",
"hj c #83ad7f",
"kA c #849d87",
"jH c #859e89",
"nJ c #85a58e",
"i0 c #869e8e",
"cp c #869f8a",
"mZ c #86a48c",
"nQ c #87a38d",
"ng c #87b495",
"gs c #889e89",
"gG c #88a68a",
"lv c #88a98e",
"lD c #8aa28a",
"f6 c #8aa383",
"nB c #8ba892",
"cx c #8ba894",
"nG c #8da99d",
"ny c #8daa8e",
"nz c #8dac8c",
"nA c #90a88e",
"ns c #90af9f",
"ku c #91aa94",
"e# c #91ab8e",
"gT c #91ae9c",
"nI c #92ad9a",
"jc c #92ae98",
"no c #92b19f",
"lu c #92b29b",
"cc c #93b09c",
"bv c #93b594",
"na c #95ae99",
"kT c #97b194",
"iD c #99b09c",
"#L c #99b59f",
"nx c #9ab39d",
"cl c #9bac9c",
"g6 c #9db59d",
"lt c #9db9a0",
"ip c #9eac93",
"hd c #9eb49d",
"m8 c #9eb5a1",
"ia c #9eb99a",
"ii c #9fb79d",
"aC c #a1bca9",
"ix c #a2bfa3",
"ds c #a4bba7",
"m0 c #a5c4a5",
"mf c #a7c5ab",
"km c #a8bfab",
"nL c #a8cfba",
"jk c #abb9a8",
"hs c #abbbae",
"lA c #acb8ae",
"iw c #acbaad",
"hW c #acbfac",
"cW c #adb7ae",
"jY c #adc5ab",
"g2 c #afc7b1",
"lK c #afc8b3",
"gf c #b1cdb6",
"mM c #b2b8ae",
"l2 c #b2d1b1",
"gC c #b3b9ad",
"iq c #b3c9bc",
"kx c #b5c7bb",
"h6 c #b5c8b5",
"nf c #b5ccbc",
"mV c #b5ceb0",
"aB c #b5d1ba",
"lZ c #b6ccb7",
"gW c #b7cec4",
"hx c #b8c5bb",
"mC c #b8cfb3",
"jP c #babdb4",
"iI c #bac5bd",
"lx c #bac7bd",
"ma c #bacac0",
"fi c #bbc5bd",
"kG c #bbc9bc",
"nD c #bbcac5",
"az c #bcd4bc",
"hK c #bdcdc2",
"iy c #bec2c5",
"fj c #bec5be",
"iv c #beccbf",
"hD c #bfc6be",
"nN c #bfcdbe",
"aA c #bfd5be",
"lH c #c0ccbe",
"jI c #c0cdc4",
"## c #c0d7c7",
"l# c #c2d3c0",
"cr c #c2d3c3",
"dl c #c2d9c7",
"kl c #c3d1c0",
".K c #c3d9c4",
"jy c #c4cec3",
"g4 c #c5d5cb",
"ee c #c5e1cb",
"mI c #c6c9be",
"h1 c #c6cfca",
"ht c #c6d3cc",
"c. c #c6dfc2",
"mv c #c8cbc0",
"hl c #c8d5cb",
"h8 c #c8d5ce",
"gt c #cacfc8",
".N c #cad4c9",
"hZ c #cbd3d5",
"d# c #cbdac7",
".M c #ccd7c9",
"lw c #cdd2ce",
".L c #cdd7ce",
"mF c #cde0ca",
"ex c #cde4d4",
"fZ c #cedad0",
"k7 c #cedccf",
"j5 c #cfd5cb",
"ja c #cfdec7",
"el c #cfe2cf",
"fd c #d0d4c6",
"i8 c #d1d6d0",
"eB c #d2e7d6",
"e3 c #d3dbcc",
"g8 c #d3e1d0",
"cz c #d5e6d3",
".O c #d7d8d3",
"kY c #d7dddb",
"dt c #d7ecdb",
"li c #d8ddd7",
"mn c #d8ded0",
"db c #d8e9d6",
"#. c #d9e7da",
"dD c #dae7d6",
"er c #daefe0",
"hf c #dbe7e3",
"np c #dbe9d8",
".J c #dbe9da",
"lL c #dcd9d2",
"fx c #dcded9",
"nw c #dce0df",
"ic c #dce6dd",
"hY c #dde2dc",
"kg c #dde5e7",
"f4 c #dee6db",
"eX c #dff6e4",
"gU c #e0dfe4",
"fB c #e0e1e3",
"ft c #e0e2dd",
"fg c #e0e5de",
"lM c #e0e8db",
"af c #e0f2f2",
"nO c #e1e2dd",
"fp c #e1e3de",
"fk c #e1e8e1",
"dE c #e1ebe0",
"mP c #e1eee4",
"fs c #e2e4df",
"ik c #e2e7e1",
"nE c #e2ece4",
"ne c #e2ede9",
"m1 c #e3e4dc",
"fu c #e3e5e0",
"fC c #e3e7e8",
"nj c #e3e8e2",
"eh c #e3efdb",
"aH c #e3efe1",
"#d c #e3f7ec",
"gd c #e4e3e1",
"fo c #e4e6e1",
"#k c #e4f7f3",
"jj c #e5e5e7",
"fn c #e5e7e2",
"hM c #e5f3f3",
"eb c #e5f8f4",
"fm c #e6e8e3",
"ar c #e6eef0",
"k1 c #e6f4e3",
"nW c #e7f1f2",
"fA c #e8e6eb",
"ao c #e8e9ee",
"fl c #e8eae5",
"hy c #e8ebe0",
"as c #e8eced",
"at c #e8ecef",
"kN c #e8edf0",
"kk c #e8efe7",
"ck c #e8f2e7",
"nR c #e9e9e9",
"fw c #e9ebe6",
"d1 c #e9eef4",
"nV c #e9f0f8",
"b3 c #eaeaec",
"nU c #eaeaf2",
"#w c #eaebed",
"g# c #eaf4f5",
"ac c #eaf6f2",
"fM c #eafbf5",
".B c #ebeaef",
"eK c #ebebf3",
".u c #ebecf0",
".D c #ebecf1",
"ag c #ebeef3",
"lP c #ebeef7",
"bj c #ebeff0",
"au c #ebf0f3",
"kQ c #ebfff1",
".H c #ecebf0",
"mT c #ecebf3",
".s c #ecedf1",
".A c #ecedf2",
"d0 c #ecf4f7",
"#A c #ede8ef",
"ap c #edeaf3",
".v c #edecf1",
"bh c #edecf2",
"iQ c #ededeb",
".w c #ededef",
".r c #edeef2",
".z c #edeef3",
"#l c #edf1f2",
"if c #edf2ec",
"aq c #edf2f5",
"a9 c #edf2f8",
"#2 c #edf7f6",
"aR c #edf7ff",
"kj c #eee4ed",
"mU c #eeeced",
"#v c #eeecef",
".q c #eeedf2",
"fE c #eeedf3",
"nr c #eeedf5",
"nX c #eeeee6",
".t c #eeeff3",
"an c #eeeff4",
"jx c #eef1e6",
"lh c #eef1e8",
"#q c #eef2f5",
".4 c #eef3ef",
"by c #eef5ed",
"dZ c #eefff9",
"bm c #efedf0",
".p c #efeef3",
"ie c #efefed",
"b2 c #efefef",
"#x c #eff0f2",
"#r c #eff0f4",
"am c #eff0f5",
"cC c #eff1ec",
"#h c #eff2f7",
"#p c #eff3f4",
"g. c #eff4f7",
"lO c #eff4f8",
"a1 c #eff7f9",
"fV c #effafc",
"mS c #f0eaf6",
"gx c #f0ebe7",
"bl c #f0ebef",
"#y c #f0eef1",
".o c #f0eff4",
"nT c #f0eff7",
"h# c #f0f0ee",
"n2 c #f0f0f2",
"ci c #f0f1e9",
"#s c #f0f1f5",
"al c #f0f1f6",
"fh c #f0f4f5",
"cB c #f0f5ef",
".0 c #f0f5fb",
"gZ c #f0f8fa",
"aQ c #f0f8fb",
"id c #f0f9fe",
"#o c #f1e8e9",
"aa c #f1ebed",
"aj c #f1eef5",
"#B c #f1eef7",
"bb c #f1eff0",
"ab c #f1eff2",
"ai c #f1eff4",
".n c #f1f0f5",
"a6 c #f1f0f8",
"bk c #f1f1f3",
"ak c #f1f2f6",
"a# c #f1f3ee",
"aZ c #f1f4fb",
"#1 c #f1f5f6",
"bi c #f1f5f8",
".X c #f1f6f9",
"kd c #f1f6fa",
"je c #f1f7f5",
"eQ c #f1faf7",
"f8 c #f1fbfc",
"m4 c #f1fcf6",
"bA c #f1fdf9",
"bg c #f2ecf6",
"gI c #f2ecf8",
"bc c #f2f0f1",
"bf c #f2f0f3",
".m c #f2f1f6",
"jf c #f2f1f7",
".y c #f2f2f4",
"#t c #f2f3f7",
"eu c #f2f4ef",
"ae c #f2f5fa",
".1 c #f2f7fd",
"bR c #f2f8f4",
"hS c #f2f9ff",
"ir c #f2fcf4",
"aN c #f2fdf9",
"m6 c #f2fffc",
"d8 c #f2ffff",
"#u c #f3ecf3",
"b# c #f3f1f2",
"be c #f3f1f4",
".l c #f3f2f7",
".C c #f3f3f5",
"#c c #f3f4f8",
".8 c #f3f4f9",
"fy c #f3f5f0",
".Y c #f3f7f8",
".Z c #f3f7fa",
"c4 c #f3f8fb",
"fW c #f3ffff",
"nc c #f4ede5",
"#j c #f4f2f3",
"bd c #f4f2f5",
"#n c #f4f3f1",
".k c #f4f3f8",
".j c #f4f4f6",
"#e c #f4f5f0",
".3 c #f4f5f7",
".2 c #f4f5fa",
"#9 c #f4f6f3",
"fD c #f4f8f9",
"h4 c #f4f9f3",
"aK c #f4f9f5",
"hT c #f4fafa",
"aO c #f4fdfc",
"nb c #f4fef5",
"k3 c #f4fff6",
"j1 c #f4fffa",
"cY c #f5eaf2",
"aY c #f5edf8",
"#z c #f5eef5",
"kS c #f5f0ea",
"ba c #f5f3f4",
"eJ c #f5f3f6",
"n1 c #f5f4f9",
".i c #f5f5f7",
"#0 c #f5f6fb",
"nh c #f5f8ff",
"i3 c #f5f9f8",
"bT c #f5f9fa",
"hR c #f5f9fc",
"c5 c #f5faf6",
".W c #f5fbfb",
"ka c #f5fff3",
"e0 c #f5ffff",
"#i c #f6f0f4",
"gH c #f6f0fc",
"cs c #f6f3ec",
"g9 c #f6f3fc",
"#m c #f6f4f5",
"h3 c #f6f5f0",
".6 c #f6f5f3",
"#U c #f6f6f4",
".h c #f6f6f8",
"#V c #f6f7f1",
"fJ c #f6f7fb",
".5 c #f6f8f3",
"#P c #f6fafd",
"hc c #f6fff9",
"fH c #f6fffa",
"e7 c #f6fffb",
"fL c #f6fffc",
"cZ c #f7ebf5",
"#g c #f7ebf7",
".7 c #f7f2f6",
"ig c #f7f3f4",
"#b c #f7f3ff",
"#Q c #f7f5f8",
"n0 c #f7f6fb",
".g c #f7f7f9",
"d5 c #f7f7ff",
"b8 c #f7f8fa",
"fq c #f7f9f4",
"b9 c #f7faff",
"f. c #f7fbea",
"eO c #f7fbfa",
"j2 c #f7fbff",
"ga c #f7fcff",
"jT c #f7fdfb",
"jV c #f7fff3",
"mo c #f7fff8",
"#C c #f7fff9",
"eC c #f7fffb",
"kf c #f7fffd",
"il c #f7ffff",
"ll c #f8ecec",
"f9 c #f8eef7",
"#Z c #f8f1f9",
"a4 c #f8f3f9",
"aT c #f8f4f3",
"a2 c #f8f5fc",
"a3 c #f8f5fe",
"b. c #f8f6f7",
"i4 c #f8f6f9",
"m7 c #f8f7f5",
"aP c #f8f7fc",
"jd c #f8f7fd",
".f c #f8f8fa",
"g0 c #f8f9fd",
"a0 c #f8f9fe",
"hV c #f8fdf9",
"fc c #f8fdff",
"#M c #f8fef4",
".R c #f8fefe",
"iV c #f8fff6",
"lc c #f8fff8",
"eq c #f8fffa",
"m2 c #f8fffb",
"bE c #f8fffe",
"bo c #f8ffff",
"ad c #f9ecf6",
"a7 c #f9edfb",
"ha c #f9f0f3",
"ah c #f9f4fa",
"#R c #f9f7f8",
"l1 c #f9f7fc",
"nZ c #f9f8fd",
"gO c #f9f8fe",
"eI c #f9f9f7",
".a c #f9f9f9",
".b c #f9f9fb",
"hU c #f9f9ff",
"bH c #f9faf4",
".T c #f9fafe",
"fr c #f9fbf6",
"aI c #f9fcff",
"bI c #f9fef7",
"c7 c #f9feff",
"kR c #f9fff6",
"f7 c #f9fff8",
"ge c #f9fff9",
"lN c #f9fffa",
"b6 c #f9fffb",
"hQ c #f9fffd",
"bD c #f9ffff",
"#W c #faf2ef",
"gY c #faf4f8",
".U c #faf5f9",
"m3 c #faf5fc",
"ld c #faf6ea",
"aJ c #faf6f3",
"aS c #faf6f5",
"c6 c #faf6ff",
"d6 c #faf8f9",
"gN c #faf8fb",
"ke c #faf8ff",
"aL c #faf9f7",
"fU c #faf9fe",
"iU c #faf9ff",
".x c #fafafa",
".e c #fafafc",
"iL c #fafbf3",
"h2 c #fafbf6",
"eE c #fafbfd",
"fz c #fafcf7",
"eR c #fafefd",
"e4 c #fafeff",
"eG c #fafff8",
"eY c #fafff9",
"b0 c #fafffa",
"gQ c #fbf2f5",
"#3 c #fbf5ff",
"mR c #fbf6fc",
"m5 c #fbf7f4",
"a. c #fbf8f3",
"nY c #fbfaff",
".# c #fbfbfb",
".c c #fbfbfd",
"#a c #fbfcf4",
"me c #fbfdf8",
"cy c #fbfff4",
"gR c #fbfff7",
"gl c #fbfff8",
"em c #fbfffa",
"aw c #fbfffb",
"#N c #fbfffc",
"gL c #fbfffd",
"jU c #fbfffe",
"hL c #fbffff",
"a5 c #fceff9",
"ih c #fcf2fa",
"#Y c #fcf5fc",
"#S c #fcf5fd",
"d7 c #fcf6fa",
"fK c #fcf8f5",
"h5 c #fcf8f7",
"iT c #fcfaff",
"mb c #fcfbf9",
"bY c #fcfbff",
"ev c #fcfcfa",
"Qt c #fcfcfc",
".d c #fcfcfe",
"fS c #fcfdf5",
".P c #fcfff2",
"ch c #fcfff8",
"eH c #fcfffa",
"ew c #fcfffb",
"bZ c #fcfffd",
"bB c #fcffff",
"h. c #fdf2f8",
"#f c #fdf3fb",
"bS c #fdf6fe",
"#T c #fdf7fb",
"gP c #fdf9f8",
"cX c #fdf9fa",
"bO c #fdf9ff",
"eF c #fdfaf3",
"aU c #fdfaff",
"eP c #fdfbef",
"bz c #fdfbfe",
"bN c #fdfbff",
"cb c #fdfcf7",
"h9 c #fdfcfa",
"bX c #fdfcff",
"av c #fdfdfd",
".E c #fdfdff",
"d9 c #fdfeff",
"k8 c #fdfff9",
"fv c #fdfffa",
"b1 c #fdfffc",
"f0 c #fdfffe",
"i5 c #fef3f9",
"a8 c #fef3ff",
"fb c #fef4fd",
"#X c #fef5f6",
".9 c #fef8f8",
"aX c #fefcff",
"fN c #fefdf9",
"aM c #fefdfb",
"bW c #fefdff",
"hN c #fefefc",
"bn c #fefefe",
".F c #fefeff",
"bu c #fefff1",
"eD c #fefff8",
"l0 c #fefffa",
"bG c #fefffb",
"#7 c #fefffd",
".S c #feffff",
"hb c #ffeeff",
"jq c #fff1f0",
".V c #fff3fa",
"fa c #fff3fd",
"bP c #fff4ff",
"nH c #fff5fd",
"nS c #fff5ff",
"jg c #fff6f7",
"mQ c #fff6fa",
"#8 c #fff6fb",
".I c #fff6ff",
"kb c #fff7fb",
"kc c #fff7fc",
"g1 c #fff7ff",
"jQ c #fff8fc",
"gX c #fff8fd",
"d4 c #fff8fe",
"eZ c #fff8ff",
"gM c #fff9fd",
"br c #fff9fe",
"bt c #fff9ff",
"k2 c #fffaf7",
"eN c #fffafa",
"ni c #fffafb",
"fI c #fffafe",
"bs c #fffaff",
"nK c #fffbf9",
"da c #fffbfb",
"i2 c #fffbfc",
"j6 c #fffbfd",
"#O c #fffbff",
"i1 c #fffcf7",
"c8 c #fffcf8",
"i9 c #fffcf9",
"ef c #fffcfa",
"c0 c #fffcfc",
"c3 c #fffcfd",
"j9 c #fffcfe",
"#4 c #fffcff",
"bM c #fffdfa",
"eg c #fffdfb",
"fT c #fffdfc",
"b7 c #fffdfd",
"bC c #fffdfe",
"bF c #fffdff",
"eU c #fffef1",
"ea c #fffef5",
"ep c #fffef6",
"f1 c #fffefa",
"bQ c #fffefb",
"bU c #fffefd",
".Q c #fffeff",
"lm c #ffffef",
"iM c #fffff3",
"gy c #fffff4",
"kX c #fffff6",
"bV c #fffff8",
"iY c #fffffa",
"f# c #fffffb",
"bL c #fffffd",
".G c #ffffff",
"Qt.#.a.b.c.d.c.c.e.e.b.f.f.b.f.g.g.g.f.f.g.h.h.h.h.h.h.i.i.i.i.j.j.i.i.j.j.i.k.k.l.l.l.m.m.n.m.m.n.m.m.n.o.n.n.o.n.n.n.n.o.p.o.o.o.o.p.p.p.p.p.p.q.p.p.p.q.q.r.r.r.r.s.s.s.s.t.s.u.v.w",
".x.#.#.f.f.b.b.e.b.b.f.f.f.f.b.f.g.g.f.f.g.h.h.h.h.h.h.i.i.i.i.i.i.j.j.j.j.y.l.l.l.l.l.l.l.m.l.m.n.m.m.n.o.n.o.o.n.n.n.n.o.p.o.o.o.o.p.p.p.p.p.p.q.p.p.p.q.q.r.r.r.r.s.s.s.s.z.A.u.B.v",
".x.a.a.c.c.b.e.e.c.c.e.e.e.e.c.e.f.g.g.f.g.g.h.h.h.h.h.i.i.i.j.h.i.C.j.h.i.y.l.l.l.l.l.l.l.m.l.m.m.m.m.n.n.n.n.n.n.n.n.n.o.p.o.o.o.o.p.p.p.p.p.p.q.p.p.p.q.q.r.r.r.r.s.s.s.s.A.D.A.q.q",
".x.#.#.b.b.e.E.F.G.G.G.G.G.G.E.c.b.g.g.f.f.g.h.h.h.h.h.i.i.i.C.i.i.j.g.d.d.f.k.k.l.l.l.m.m.n.l.m.m.m.m.n.n.n.n.n.o.o.n.n.o.o.o.o.o.o.p.p.p.p.p.p.q.p.p.p.q.q.r.r.r.r.s.s.s.s.A.A.A.v.H",
".x.x.#.x.xQt.I.J.K.L.M.N.O.P.Q.R.S.T.U.V.W.X.Y.Z.0.1.2.3.4.5.6.7.8.l.9#.###a#b#c#d#e#f#g#h#i#j#k#l#m#n#o#p#q.n.l#r#s.r#s.t#t.n.n.p.n.p.p.n.H.o.n.v.p.o.H.q.o#u#v#w#x#y#z#A#B.s.s.r.s.s",
".x.x.#.x.xQt#C#D#E#F#G#H#I#J#K#L#M#N#O#P#Q#R#S#T#U#V#W#X#Y#Z#0#1#2#3#4#5#6#7#8#9a.a#aa.gabac.nadaeafagahaiaj.t#r#rak.t#t#r.sal.z.zalam.zaman.Aam.A.Aamam.Aaoapamaqarasatauar.s.s.r.s.s",
".x.x.x.a.xavawaxayazaAaBaCaDaEaFaGaH.GaI#1aJ#RaKaLaMaNaOaPaQaRaSaTaU#OaVaWaX.S#taYaZa0a1a2a3a4a5a6a7a8a9.l#2b.#jb#babb#jbab#b#b##jbcbbbababcbdbebfabbebeabbdbgbhbibjbkblbm.v.s.s.r.s.s",
".#.x.x.a.xbnbobpbq.S#ObrbsbtbubvbwbxbybobzaKbAbBbCbCbDbEbnbF#4bGbH.QbIbJbKbLbMbNbObP.GbQbGbB#7bRbobFbSbTbUbV.QaX.Q.Q.Q.Q.Q.Q.Q.Q.Q.QbW.Q.QbWbWbX.Q.Q.Q.QbYbWbLbZb0awb1b2b3.r.s.s.r.s.s",
".#.x.x.a.xbnbDb4b5b6b7b8b9bBbFbVc.c#cacb#4bW#Ob7cccdcecfcgchcicjckclcmcncocpcqcrbQcsctcucvcwcxcyczcAcBcCcDcEcmcFcmcGcHcIcIcHcJcGcKcFcFcKcLcJcMcMcMcNcOcPcQcRcScTcUcVcWcXcYcZ.s.s.r.s.s",
".#.x.x.a.xbnc0c1c2bGc3Qtc4c5c6c7c8c9d.d#da.SdbdcdddedfdgdhdidjdkdldmdndodpdqdrdsdtdudvdwdxdydzdAdBdCdDdEdFdGdHdIdIdJdKdLdMdNdOdPdQdRdSdSdTdTdSdQdQdPdTdRdTdPdUdVdWdXdYdZd0d1.s.s.r.s.s",
".x.x.#.x.xbn#4d2d3bDd4aPd5d6d7d8d9che.e#eaebecedeeefegeaeheiejekelbMemeneoepeqereseteuc3evewexeyezeAeB#7eCeDbBeE.S.S.G.c.Q.QaX.Qbz.Q.QbF.QaX.Q.QbN.Q.QaX.QaXeFbVeGeHeIeJ.veK.s.s.r.s.s",
".x.x.#.x.xbnbQeLeMeCeNeO.WbHePeQ#OeReSeTeUeVeWeXeY.GeZ.Se0.Qe1e2e3bse4e5e6e7bVe8e9f.f#fafbfc.Gfdfefffgbt.QfhfifjfkawewflfmfnfmfofpfqfrfsftfufvbGfwfxfsfyfzfpfAfBfCfD.G.UaifE.s.s.r.s.s",
".x.x.x.x.xaveffFfGfHfI.efJfKfLfMeZfNfOfPbLfQfRfSfTfUaZfVfWbFfXfYfZf0f1f2f3bnf4f5f6f7f8f9g.g#ga.QgbgcgdgegfggghgigjgkglgmgngogpgqgrgsgtgugvgwgxgygzffgAgBgCgDekgEgvgFgGbLgHgI.s.s.r.s.s",
".x.x.x.x.xavbLgJgKgLgMgNgOgPgQfzbBgRgSgTgUgVgWbogXgYgZg0g1eZg2g3g4bDbLg5dMbBg6g7g8bsg9h.h#hahbhchdhehfbDhghhhihjhkhhhlhmhnhohphqhrhshthuhvhwhxhyhzhAhBhChDhEhFhGhHhIhJhKhLhM.s.s.r.s.s",
".x.x.x.x.xavhNhOhPhQbrhRhShThUhVf1hWhXhYhZh0h1hQh2h3h4#eh5bZh6h7h8hLh9i.i#.QiaibicbFidieifigihchiiijikiliminioipiqir#Oisitiuiviwix#4iyiziAiBiCiDiEiFiGiHiIiJiKiLiMiNiOiP.QiQ.s.s.r.s.s",
".#.x.#.x.xbn.GiRiS#7#OiTiU.bbtbLiViWiXiYfyiZi0i1i2i3i4i5cXf0i6i7i8bFi9j.j#bFjajbjcd9jdb#jejfjg.SjhjijjawjkjljmjnjojpjqjrjsjtjujvjwjxjyjzjAjBjCjDjEjFjGjHjIjJjKjLjMjNjOjPjQbb.s.s.r.s.s",
".#.x.#.x.#bnhLjRjSeCbGjTbBbZjUjVjWjXjYfNbGjZj0j1#ObDj2bP#4e0j3j4j5j6iYj7j8j9#Ck.k#kakbkckdkekfkgkhkikjeRkkklkmknkokpkqkrksktkukvkwewkxkykzkAkBkCkDkEkpkFkGkHkIkJkKkLkM#7jdkN.s.s.r.s.s",
".#.x.#.x.#bnilkOkPkQkReHfTkSkTkUkVkWkX.F#OkYkZk0k1k2b7b7k3k4k5k6k7.Sk8k9l.f0g1l#lalblcj6#4hLldlelflglhliljlklllmlnlolplqlrlsltlulvlwlxlylzlAlBlClDlElFlGlHlIlJlKlLlMlNlOlPai.s.s.r.s.s",
".#.x.#.x.#bn.clQlRlSlTlUlVlWlXlYlZl0bsl1.Qbtl2l3l4l5l6l7l8l9m.m#mahLmbmcmd.QiTmemfmgmhmiaVmj#HmkmlmmmnmompmqmrmsmtmumvmwmxlgmymzmAmBmCmDmEmFmGmHmImJmKmLmMmNmOmPmQbCmRmSmTmU.s.s.r.s.s",
".#.x.#.x.#bnbtmVmWcImXmYmZm0m1m2.S.Fm3m4m5m6bBm7m8m9n.n#nanbncndneaIbsnfngbsnhgMninjnknlnmnnnobtnpnqnri2jgnsntnunvnwbFnxnynznAnBnCnDnEnFnGnHnInJnKnLnMnNnOnPnQnRnSnTnUnVnWnX.s.s.r.s.s",
".#.#.#.x.x.x.E.F.G.F.F.G.G.F.F.E.d.b.g.h.g.g.d.E.G.G.G.G.G.G.E.G.E.g.f.F.F.g.j.j.g.d.G.G.G.FbWbWbWbXnYnZnY.Q.G.G.F.d.d.E.F.G.F.G.F.F.F.F.F.dbWbWbXbYbWbXbXbWbXn0.n.q.q.q.v.q.v.v.v.v.v",
".#.#.#.x.x.x.e.d.d.d.d.d.d.d.c.c.e.f.f.g.f.f.g.f.b.e.b.b.f.f.g.f.h.y.C.g.h.y.j.C.C.i.g.g.g.gn1.l.l.l.m.n.m.k.j.j.j.C.y.C.j.C.y.C.C.y.y.C.yn2.m.l.n.n.m.m.n.m.n.p.q.q.q.v.v.v.v.v.v.v.v",
".#.#.#.x.x.x.b.e.c.e.b.e.e.b.b.f.f.f.f.f.f.f.h.h.g.g.h.i.i.i.h.i.j.i.i.i.j.C.i.C.y.y.ybkbk.y.l.n.n.m.m.n.n.n.y.y.ybkbk.ybkbk.o.o.o.p.p.o.p.q.p.o.q.q.p.p.q.p.v.v.p.o.p.v.H.v.v.v.v.v.v",
".#.#.#.x.x.x.b.e.e.b.b.b.b.f.b.f.f.f.f.f.g.g.f.f.g.g.h.h.h.i.i.j.j.i.i.j.j.j.j.C.C.j.C.ybk.y.l.m.n.m.l.m.n.n.y.ybkbkbk.y.yn2.o.o.o.o.o.o.o.p.o.o.p.p.o.o.p.p.p.p.o.o.q.v.v.q.v.v.v.v.v",
".#.#.#.x.x.x.e.c.c.b.b.b.b.f.b.f.f.f.f.f.g.g.f.f.g.h.h.h.h.h.j.j.j.j.j.j.j.j.y.y.C.j.j.y.y.y.n.n.n.n.n.o.o.n.n.n.o.p.o.n.n.o.p.p.o.o.o.p.p.p.p.o.p.q.o.p.q.q.p.q.v.q.q.v.q.p.v.v.v.v.v"};

static const unsigned char image3_data[] = { 
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10,
    0x08, 0x06, 0x00, 0x00, 0x00, 0x1f, 0xf3, 0xff, 0x61, 0x00, 0x00, 0x00,
    0x67, 0x49, 0x44, 0x41, 0x54, 0x78, 0x9c, 0xcd, 0x53, 0x41, 0x0e, 0xc0,
    0x20, 0x08, 0x2b, 0x8b, 0xaf, 0xe2, 0xc4, 0xd3, 0x39, 0xf1, 0xad, 0xed,
    0xb4, 0x68, 0x3a, 0x35, 0x2c, 0x5c, 0xec, 0xa9, 0xa1, 0xda, 0x40, 0x45,
    0x89, 0x08, 0x54, 0xd0, 0x66, 0x45, 0x55, 0xbd, 0xb9, 0x16, 0x11, 0x92,
    0x36, 0x00, 0x00, 0xf8, 0xc0, 0x6d, 0xdd, 0xc1, 0xb5, 0x96, 0x72, 0x28,
    0x1b, 0x34, 0x60, 0x3e, 0x33, 0x83, 0xcf, 0xbc, 0x99, 0xf4, 0x0c, 0x7c,
    0x73, 0x9b, 0x35, 0xeb, 0xf4, 0x90, 0x0c, 0x00, 0x7c, 0x9f, 0xca, 0x07,
    0xce, 0x1a, 0x1b, 0xf0, 0x92, 0xfc, 0x59, 0xa4, 0x93, 0x32, 0x60, 0x58,
    0xce, 0x40, 0xaa, 0xbf, 0xb1, 0x3c, 0xc2, 0x03, 0xad, 0xfc, 0x19, 0x11,
    0x9a, 0xf7, 0x7f, 0xed, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44,
    0xae, 0x42, 0x60, 0x82
};

static const unsigned char image4_data[] = { 
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10,
    0x08, 0x06, 0x00, 0x00, 0x00, 0x1f, 0xf3, 0xff, 0x61, 0x00, 0x00, 0x01,
    0xc9, 0x49, 0x44, 0x41, 0x54, 0x78, 0x9c, 0xa5, 0x93, 0x41, 0x6b, 0x13,
    0x41, 0x18, 0x86, 0x9f, 0x4d, 0x03, 0x42, 0xab, 0x78, 0xc8, 0x49, 0x10,
    0x91, 0x7a, 0x51, 0xa1, 0xb0, 0xd0, 0x9c, 0xe6, 0x90, 0x3f, 0xe0, 0xc5,
    0xdf, 0xb1, 0x47, 0xfd, 0x2f, 0x01, 0xe7, 0x5f, 0x78, 0x88, 0x20, 0xe8,
    0x61, 0x5d, 0x99, 0xf6, 0xa0, 0x75, 0x60, 0xd9, 0xa5, 0xa7, 0x5e, 0x54,
    0x6c, 0x93, 0x2c, 0x6d, 0x12, 0x13, 0xdb, 0xcd, 0x6e, 0x3e, 0x0f, 0x99,
    0x0d, 0xbb, 0x35, 0x37, 0x3f, 0x18, 0x98, 0xdd, 0x99, 0xf7, 0x99, 0x77,
    0xde, 0x8f, 0xf1, 0x8c, 0x31, 0x04, 0x41, 0x20, 0xd4, 0xaa, 0xdf, 0xef,
    0x7b, 0x6c, 0xa9, 0x6d, 0xfb, 0x3c, 0xdf, 0xf7, 0xe5, 0xcb, 0xe1, 0x21,
    0x72, 0x74, 0x44, 0x99, 0xa6, 0x5c, 0x02, 0x0f, 0x00, 0x63, 0x4c, 0x03,
    0xa2, 0x94, 0x92, 0x52, 0x6b, 0xc4, 0x5a, 0x6c, 0x14, 0x31, 0x89, 0x63,
    0x5e, 0xfb, 0x3e, 0x2d, 0x80, 0xe2, 0xf8, 0x98, 0x22, 0x4d, 0x59, 0x01,
    0xbb, 0xc0, 0x0f, 0x27, 0xa8, 0x8b, 0x97, 0x5a, 0x53, 0x58, 0x4b, 0x11,
    0x86, 0x4c, 0xe2, 0x98, 0xef, 0x6e, 0xad, 0x0d, 0x90, 0x27, 0x09, 0xd5,
    0x71, 0xad, 0x1a, 0xe4, 0xa1, 0x83, 0xe4, 0x5a, 0x53, 0x5a, 0x4b, 0x19,
    0x86, 0xac, 0x92, 0x84, 0x47, 0xd0, 0x04, 0x8c, 0x80, 0x7b, 0xee, 0xa3,
    0x02, 0xed, 0x02, 0xd3, 0x6e, 0x97, 0x9d, 0x5e, 0x8f, 0xfc, 0xe4, 0x84,
    0x32, 0x8a, 0x58, 0x25, 0x09, 0xe7, 0x80, 0x01, 0x06, 0x95, 0x3d, 0x63,
    0x0c, 0x80, 0x9c, 0x82, 0xfc, 0x04, 0xb9, 0x00, 0x19, 0xba, 0x31, 0xea,
    0x74, 0x24, 0x3b, 0x38, 0x90, 0xf1, 0xfe, 0xbe, 0x0c, 0x41, 0x62, 0x90,
    0x37, 0x20, 0x2f, 0x41, 0x00, 0x31, 0xc6, 0xe0, 0x39, 0x00, 0x4a, 0x29,
    0x39, 0x05, 0xee, 0xba, 0x6b, 0xdc, 0xae, 0x4b, 0xe0, 0x33, 0xf0, 0x0e,
    0x78, 0x5b, 0x0b, 0x79, 0xb3, 0xd7, 0x18, 0xe3, 0x3d, 0x05, 0xbc, 0x6e,
    0x97, 0xb2, 0xd3, 0x61, 0x09, 0x8d, 0x31, 0x03, 0xc6, 0xb7, 0xc4, 0x9b,
    0x0c, 0xea, 0xd5, 0xee, 0xf5, 0xf8, 0x73, 0x73, 0x43, 0x91, 0x65, 0x8d,
    0xff, 0x7b, 0xc0, 0xb3, 0x2d, 0xce, 0x36, 0x0e, 0x94, 0x52, 0x92, 0x69,
    0xcd, 0x72, 0xb1, 0x20, 0x9f, 0xcf, 0xff, 0x71, 0xb0, 0x03, 0x3c, 0x06,
    0x3e, 0xd1, 0x6c, 0x71, 0xab, 0x12, 0x0f, 0xb5, 0xe6, 0xb7, 0xb5, 0xcc,
    0xa2, 0x88, 0xeb, 0xb3, 0x33, 0x46, 0xac, 0x5b, 0x35, 0x05, 0x72, 0xa0,
    0x70, 0x90, 0x3d, 0x20, 0xac, 0x41, 0x3c, 0xdf, 0xf7, 0xe5, 0x7d, 0x10,
    0xb0, 0xb0, 0x96, 0x79, 0x18, 0x92, 0x27, 0x09, 0x23, 0xc0, 0x02, 0x57,
    0xc0, 0x73, 0xe0, 0x09, 0x70, 0x87, 0x75, 0x8b, 0xc5, 0xc1, 0xe6, 0xc0,
    0x2b, 0xdf, 0x5f, 0x67, 0x30, 0xb5, 0x96, 0x99, 0x13, 0x8f, 0x81, 0x6f,
    0xee, 0x94, 0x0f, 0xce, 0xe6, 0x00, 0xb8, 0xef, 0x1c, 0x54, 0x90, 0xea,
    0xee, 0x6d, 0x80, 0x49, 0x14, 0x71, 0x9d, 0x24, 0x64, 0x4e, 0x1c, 0x01,
    0x1f, 0x6b, 0x69, 0x2b, 0xa5, 0x64, 0xe0, 0xec, 0x57, 0x90, 0xab, 0x7a,
    0x06, 0x93, 0x38, 0xe6, 0x17, 0xf0, 0xd5, 0x85, 0x54, 0x17, 0xe3, 0xe6,
    0x2f, 0x5c, 0x1e, 0x0b, 0xe0, 0x1c, 0x48, 0xdd, 0x9a, 0xf7, 0xbf, 0xcf,
    0xf9, 0x2f, 0x57, 0xcb, 0xf7, 0x02, 0x22, 0x5b, 0x98, 0x67, 0x00, 0x00,
    0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};


/*
 *  Constructs a Dlg_MainDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Dlg_MainDialog::Dlg_MainDialog( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl ),
      image1( (const char **) image1_data ),
      image2( (const char **) image2_data )
{
    QImage img;
    img.loadFromData( image0_data, sizeof( image0_data ), "PNG" );
    image0 = img;
    img.loadFromData( image3_data, sizeof( image3_data ), "PNG" );
    image3 = img;
    img.loadFromData( image4_data, sizeof( image4_data ), "PNG" );
    image4 = img;
    if ( !name )
	setProperty( "name", "Dlg_MainDialog" );
    QFont f( font() );
    f.setPointSize( 9 );
    setFont( f ); 
    setProperty( "icon", image0 );
    Dlg_MainDialogLayout = new QGridLayout( this, 1, 1, 3, 1, "Dlg_MainDialogLayout"); 

    textLabel_MedinTux = new QLabel( this, "textLabel_MedinTux" );
    textLabel_MedinTux->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel_MedinTux->sizePolicy().hasHeightForWidth() ) );
    textLabel_MedinTux->setProperty( "frameShape", "Box" );

    Dlg_MainDialogLayout->addWidget( textLabel_MedinTux, 1, 1 );

    textLabel_Progress = new QLabel( this, "textLabel_Progress" );
    textLabel_Progress->setProperty( "maximumSize", QSize( 32767, 25 ) );

    Dlg_MainDialogLayout->addMultiCellWidget( textLabel_Progress, 2, 2, 0, 1 );

    textEdit_Message = new CW_EditText( this, "textEdit_Message" );
    textEdit_Message->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)3, 0, 0, textEdit_Message->sizePolicy().hasHeightForWidth() ) );
    textEdit_Message->setProperty( "paletteForegroundColor", QColor( 0, 255, 0 ) );
    textEdit_Message->setProperty( "paletteBackgroundColor", QColor( 0, 0, 0 ) );
    QFont textEdit_Message_font(  textEdit_Message->font() );
    textEdit_Message_font.setFamily( "Courier [Adobe]" );
    textEdit_Message->setFont( textEdit_Message_font ); 

    Dlg_MainDialogLayout->addMultiCellWidget( textEdit_Message, 3, 3, 0, 1 );

    layout23 = new QGridLayout( 0, 1, 1, 0, 6, "layout23"); 

    pushButton_LancerDrTux = new QPushButton( this, "pushButton_LancerDrTux" );
    QFont pushButton_LancerDrTux_font(  pushButton_LancerDrTux->font() );
    pushButton_LancerDrTux_font.setFamily( "Lucida Grande" );
    pushButton_LancerDrTux->setFont( pushButton_LancerDrTux_font ); 

    layout23->addWidget( pushButton_LancerDrTux, 1, 0 );

    progressBar_Load = new QProgressBar( this, "progressBar_Load" );

    layout23->addMultiCellWidget( progressBar_Load, 0, 0, 0, 1 );

    quitPushButton = new QPushButton( this, "quitPushButton" );

    layout23->addWidget( quitPushButton, 1, 1 );

    Dlg_MainDialogLayout->addMultiCellLayout( layout23, 4, 4, 0, 1 );

    tabWidget_Instal = new QTabWidget( this, "tabWidget_Instal" );
    tabWidget_Instal->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, tabWidget_Instal->sizePolicy().hasHeightForWidth() ) );
    QFont tabWidget_Instal_font(  tabWidget_Instal->font() );
    tabWidget_Instal_font.setBold( TRUE );
    tabWidget_Instal->setFont( tabWidget_Instal_font ); 
    tabWidget_Instal->setProperty( "margin", 0 );

    tab_Bases = new QWidget( tabWidget_Instal, "tab_Bases" );
    tab_BasesLayout = new QGridLayout( tab_Bases, 1, 1, 0, 0, "tab_BasesLayout"); 

    layout21 = new QGridLayout( 0, 1, 1, 0, 6, "layout21"); 

    pushButton_SetBases = new QPushButton( tab_Bases, "pushButton_SetBases" );
    QFont pushButton_SetBases_font(  pushButton_SetBases->font() );
    pushButton_SetBases_font.setFamily( "Lucida Grande" );
    pushButton_SetBases_font.setBold( FALSE );
    pushButton_SetBases->setFont( pushButton_SetBases_font ); 
    pushButton_SetBases->setProperty( "autoDefault", QVariant( TRUE, 0 ) );

    layout21->addWidget( pushButton_SetBases, 0, 0 );

    pushButton_MajBases = new QPushButton( tab_Bases, "pushButton_MajBases" );
    pushButton_MajBases->setProperty( "paletteForegroundColor", QColor( 0, 0, 255 ) );
    QFont pushButton_MajBases_font(  pushButton_MajBases->font() );
    pushButton_MajBases->setFont( pushButton_MajBases_font ); 
    pushButton_MajBases->setProperty( "autoDefault", QVariant( TRUE, 0 ) );

    layout21->addWidget( pushButton_MajBases, 0, 1 );

    comboBox_Bases = new QComboBox( FALSE, tab_Bases, "comboBox_Bases" );
    QFont comboBox_Bases_font(  comboBox_Bases->font() );
    comboBox_Bases_font.setBold( FALSE );
    comboBox_Bases->setFont( comboBox_Bases_font ); 

    layout21->addWidget( comboBox_Bases, 0, 2 );

    pushButton_Load_SQL = new QPushButton( tab_Bases, "pushButton_Load_SQL" );
    QFont pushButton_Load_SQL_font(  pushButton_Load_SQL->font() );
    pushButton_Load_SQL_font.setFamily( "Lucida Grande" );
    pushButton_Load_SQL_font.setBold( FALSE );
    pushButton_Load_SQL->setFont( pushButton_Load_SQL_font ); 
    pushButton_Load_SQL->setProperty( "autoDefault", QVariant( TRUE, 0 ) );

    layout21->addWidget( pushButton_Load_SQL, 0, 3 );

    tab_BasesLayout->addLayout( layout21, 0, 0 );
    tabWidget_Instal->insertTab( tab_Bases, QString::fromLatin1("") );

    tab_Vidal = new QWidget( tabWidget_Instal, "tab_Vidal" );
    tab_VidalLayout = new QGridLayout( tab_Vidal, 1, 1, 0, 0, "tab_VidalLayout"); 

    groupBox1 = new QGroupBox( tab_Vidal, "groupBox1" );
    groupBox1->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, groupBox1->sizePolicy().hasHeightForWidth() ) );
    QFont groupBox1_font(  groupBox1->font() );
    groupBox1->setFont( groupBox1_font ); 
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 0 );
    groupBox1->layout()->setMargin( 3 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    layout9 = new QGridLayout( 0, 1, 1, 0, 6, "layout9"); 

    pushButton_IndexerDatasemp = new QPushButton( groupBox1, "pushButton_IndexerDatasemp" );
    QFont pushButton_IndexerDatasemp_font(  pushButton_IndexerDatasemp->font() );
    pushButton_IndexerDatasemp_font.setFamily( "Lucida Grande" );
    pushButton_IndexerDatasemp_font.setBold( FALSE );
    pushButton_IndexerDatasemp->setFont( pushButton_IndexerDatasemp_font ); 
    pushButton_IndexerDatasemp->setProperty( "iconSet", QIconSet( image1 ) );
    pushButton_IndexerDatasemp->setProperty( "flat", QVariant( FALSE, 0 ) );

    layout9->addWidget( pushButton_IndexerDatasemp, 0, 2 );

    pushButton_SetDatasemp = new QPushButton( groupBox1, "pushButton_SetDatasemp" );
    QFont pushButton_SetDatasemp_font(  pushButton_SetDatasemp->font() );
    pushButton_SetDatasemp_font.setFamily( "Lucida Grande" );
    pushButton_SetDatasemp_font.setBold( FALSE );
    pushButton_SetDatasemp->setFont( pushButton_SetDatasemp_font ); 
    pushButton_SetDatasemp->setProperty( "iconSet", QIconSet( image1 ) );
    pushButton_SetDatasemp->setProperty( "flat", QVariant( FALSE, 0 ) );

    layout9->addWidget( pushButton_SetDatasemp, 0, 0 );

    pushButtonJustOneTable = new QPushButton( groupBox1, "pushButtonJustOneTable" );
    pushButtonJustOneTable->setProperty( "maximumSize", QSize( 110, 32767 ) );
    QFont pushButtonJustOneTable_font(  pushButtonJustOneTable->font() );
    pushButtonJustOneTable_font.setFamily( "Lucida Grande" );
    pushButtonJustOneTable_font.setBold( FALSE );
    pushButtonJustOneTable->setFont( pushButtonJustOneTable_font ); 

    layout9->addWidget( pushButtonJustOneTable, 0, 1 );

    pushButtonImagesCopy = new QPushButton( groupBox1, "pushButtonImagesCopy" );
    pushButtonImagesCopy->setProperty( "maximumSize", QSize( 130, 32767 ) );
    QFont pushButtonImagesCopy_font(  pushButtonImagesCopy->font() );
    pushButtonImagesCopy_font.setFamily( "Lucida Grande" );
    pushButtonImagesCopy_font.setBold( FALSE );
    pushButtonImagesCopy->setFont( pushButtonImagesCopy_font ); 

    layout9->addWidget( pushButtonImagesCopy, 0, 3 );

    groupBox1Layout->addMultiCellLayout( layout9, 2, 2, 0, 2 );

    layout9_2 = new QHBoxLayout( 0, 0, 6, "layout9_2"); 

    checkBox_STD_MAJ = new QCheckBox( groupBox1, "checkBox_STD_MAJ" );
    QFont checkBox_STD_MAJ_font(  checkBox_STD_MAJ->font() );
    checkBox_STD_MAJ_font.setBold( FALSE );
    checkBox_STD_MAJ->setFont( checkBox_STD_MAJ_font ); 
    layout9_2->addWidget( checkBox_STD_MAJ );

    pushButtonMakeSQL = new QPushButton( groupBox1, "pushButtonMakeSQL" );
    QFont pushButtonMakeSQL_font(  pushButtonMakeSQL->font() );
    pushButtonMakeSQL_font.setFamily( "Lucida Grande" );
    pushButtonMakeSQL_font.setBold( FALSE );
    pushButtonMakeSQL->setFont( pushButtonMakeSQL_font ); 
    layout9_2->addWidget( pushButtonMakeSQL );
    spacer1 = new QSpacerItem( 167, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout9_2->addItem( spacer1 );

    textLabel3 = new QLabel( groupBox1, "textLabel3" );
    textLabel3->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    textLabel3->setProperty( "paletteForegroundColor", QColor( 255, 0, 0 ) );
    textLabel3->setProperty( "frameShape", "Box" );
    textLabel3->setProperty( "pixmap", image2 );
    layout9_2->addWidget( textLabel3 );

    groupBox1Layout->addMultiCellLayout( layout9_2, 0, 0, 0, 2 );

    checkBox_SQL_MAJ = new QCheckBox( groupBox1, "checkBox_SQL_MAJ" );
    QFont checkBox_SQL_MAJ_font(  checkBox_SQL_MAJ->font() );
    checkBox_SQL_MAJ_font.setBold( FALSE );
    checkBox_SQL_MAJ->setFont( checkBox_SQL_MAJ_font ); 

    groupBox1Layout->addWidget( checkBox_SQL_MAJ, 1, 0 );
    spacer3 = new QSpacerItem( 325, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    groupBox1Layout->addItem( spacer3, 1, 1 );

    pushButtonSwitchGetDatasemp = new QPushButton( groupBox1, "pushButtonSwitchGetDatasemp" );
    QFont pushButtonSwitchGetDatasemp_font(  pushButtonSwitchGetDatasemp->font() );
    pushButtonSwitchGetDatasemp_font.setFamily( "Lucida Grande" );
    pushButtonSwitchGetDatasemp_font.setBold( FALSE );
    pushButtonSwitchGetDatasemp->setFont( pushButtonSwitchGetDatasemp_font ); 

    groupBox1Layout->addWidget( pushButtonSwitchGetDatasemp, 1, 2 );

    tab_VidalLayout->addWidget( groupBox1, 0, 0 );
    tabWidget_Instal->insertTab( tab_Vidal, QString::fromLatin1("") );

    tab_Compilation = new QWidget( tabWidget_Instal, "tab_Compilation" );
    tab_CompilationLayout = new QGridLayout( tab_Compilation, 1, 1, 0, 0, "tab_CompilationLayout"); 

    pushButton_compilation = new QPushButton( tab_Compilation, "pushButton_compilation" );
    QFont pushButton_compilation_font(  pushButton_compilation->font() );
    pushButton_compilation_font.setFamily( "Lucida Grande" );
    pushButton_compilation_font.setBold( FALSE );
    pushButton_compilation->setFont( pushButton_compilation_font ); 

    tab_CompilationLayout->addWidget( pushButton_compilation, 2, 0 );

    comboBox_Executables = new QComboBox( FALSE, tab_Compilation, "comboBox_Executables" );
    QFont comboBox_Executables_font(  comboBox_Executables->font() );
    comboBox_Executables_font.setBold( FALSE );
    comboBox_Executables->setFont( comboBox_Executables_font ); 
    comboBox_Executables->setProperty( "sizeLimit", 30 );

    tab_CompilationLayout->addWidget( comboBox_Executables, 2, 1 );

    layout20 = new QGridLayout( 0, 1, 1, 0, 0, "layout20"); 

    layout18 = new QGridLayout( 0, 1, 1, 0, 6, "layout18"); 

    lineEdit_Qt3 = new QLineEdit( tab_Compilation, "lineEdit_Qt3" );
    QFont lineEdit_Qt3_font(  lineEdit_Qt3->font() );
    lineEdit_Qt3_font.setBold( FALSE );
    lineEdit_Qt3->setFont( lineEdit_Qt3_font ); 
    lineEdit_Qt3->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_Qt3->setProperty( "frameShadow", "Sunken" );

    layout18->addWidget( lineEdit_Qt3, 0, 0 );

    lineEdit_Qt4Sdk = new QLineEdit( tab_Compilation, "lineEdit_Qt4Sdk" );
    QFont lineEdit_Qt4Sdk_font(  lineEdit_Qt4Sdk->font() );
    lineEdit_Qt4Sdk_font.setBold( FALSE );
    lineEdit_Qt4Sdk->setFont( lineEdit_Qt4Sdk_font ); 
    lineEdit_Qt4Sdk->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_Qt4Sdk->setProperty( "frameShadow", "Sunken" );

    layout18->addWidget( lineEdit_Qt4Sdk, 1, 0 );

    layout20->addLayout( layout18, 0, 1 );

    layout19 = new QGridLayout( 0, 1, 1, 0, 0, "layout19"); 

    pushButton_Qt4Sdk = new QPushButton( tab_Compilation, "pushButton_Qt4Sdk" );
    QFont pushButton_Qt4Sdk_font(  pushButton_Qt4Sdk->font() );
    pushButton_Qt4Sdk_font.setFamily( "Lucida Grande" );
    pushButton_Qt4Sdk_font.setBold( FALSE );
    pushButton_Qt4Sdk->setFont( pushButton_Qt4Sdk_font ); 

    layout19->addWidget( pushButton_Qt4Sdk, 1, 0 );

    pushButton_Qt3 = new QPushButton( tab_Compilation, "pushButton_Qt3" );
    QFont pushButton_Qt3_font(  pushButton_Qt3->font() );
    pushButton_Qt3_font.setFamily( "Lucida Grande" );
    pushButton_Qt3_font.setBold( FALSE );
    pushButton_Qt3->setFont( pushButton_Qt3_font ); 

    layout19->addWidget( pushButton_Qt3, 0, 0 );

    layout20->addLayout( layout19, 0, 0 );

    tab_CompilationLayout->addMultiCellLayout( layout20, 1, 1, 0, 1 );

    textLabel_MacOS = new QLabel( tab_Compilation, "textLabel_MacOS" );
    textLabel_MacOS->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel_MacOS->sizePolicy().hasHeightForWidth() ) );
    textLabel_MacOS->setProperty( "maximumSize", QSize( 32767, 30 ) );
    QFont textLabel_MacOS_font(  textLabel_MacOS->font() );
    textLabel_MacOS_font.setBold( FALSE );
    textLabel_MacOS->setFont( textLabel_MacOS_font ); 

    tab_CompilationLayout->addMultiCellWidget( textLabel_MacOS, 0, 0, 0, 1 );
    tabWidget_Instal->insertTab( tab_Compilation, QString::fromLatin1("") );

    tab_Sesam = new QWidget( tabWidget_Instal, "tab_Sesam" );
    tab_SesamLayout = new QGridLayout( tab_Sesam, 1, 1, 0, 0, "tab_SesamLayout"); 

    groupBox5 = new QGroupBox( tab_Sesam, "groupBox5" );
    groupBox5->setColumnLayout(0, Qt::Vertical );
    groupBox5->layout()->setSpacing( 0 );
    groupBox5->layout()->setMargin( 0 );
    groupBox5Layout = new QGridLayout( groupBox5->layout() );
    groupBox5Layout->setAlignment( Qt::AlignTop );

    layout19_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout19_2"); 

    pushButton_setGalsINI = new QPushButton( groupBox5, "pushButton_setGalsINI" );
    QFont pushButton_setGalsINI_font(  pushButton_setGalsINI->font() );
    pushButton_setGalsINI_font.setFamily( "Lucida Grande" );
    pushButton_setGalsINI_font.setBold( FALSE );
    pushButton_setGalsINI->setFont( pushButton_setGalsINI_font ); 

    layout19_2->addWidget( pushButton_setGalsINI, 0, 0 );

    pushButton_LireVitale = new QPushButton( groupBox5, "pushButton_LireVitale" );
    QFont pushButton_LireVitale_font(  pushButton_LireVitale->font() );
    pushButton_LireVitale_font.setFamily( "Lucida Grande" );
    pushButton_LireVitale_font.setBold( FALSE );
    pushButton_LireVitale->setFont( pushButton_LireVitale_font ); 

    layout19_2->addWidget( pushButton_LireVitale, 0, 2 );

    pushButton_InstallSesam = new QPushButton( groupBox5, "pushButton_InstallSesam" );
    QFont pushButton_InstallSesam_font(  pushButton_InstallSesam->font() );
    pushButton_InstallSesam_font.setFamily( "Lucida Grande" );
    pushButton_InstallSesam_font.setBold( FALSE );
    pushButton_InstallSesam->setFont( pushButton_InstallSesam_font ); 

    layout19_2->addWidget( pushButton_InstallSesam, 0, 1 );

    groupBox5Layout->addMultiCellLayout( layout19_2, 5, 5, 0, 1 );

    comboBox_PortLecteurWin = new QComboBox( FALSE, groupBox5, "comboBox_PortLecteurWin" );
    comboBox_PortLecteurWin->setProperty( "editable", QVariant( TRUE, 0 ) );

    groupBox5Layout->addWidget( comboBox_PortLecteurWin, 4, 0 );

    comboBox_PortLecteur = new QComboBox( FALSE, groupBox5, "comboBox_PortLecteur" );
    comboBox_PortLecteur->setProperty( "editable", QVariant( TRUE, 0 ) );

    groupBox5Layout->addMultiCellWidget( comboBox_PortLecteur, 2, 3, 0, 0 );

    layout9_2_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout9_2_2"); 

    lineEdit_BinaryPath = new QLineEdit( groupBox5, "lineEdit_BinaryPath" );
    QFont lineEdit_BinaryPath_font(  lineEdit_BinaryPath->font() );
    lineEdit_BinaryPath_font.setBold( FALSE );
    lineEdit_BinaryPath->setFont( lineEdit_BinaryPath_font ); 
    lineEdit_BinaryPath->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_BinaryPath->setProperty( "frameShadow", "Sunken" );
    lineEdit_BinaryPath->setProperty( "echoMode", "Normal" );

    layout9_2_2->addWidget( lineEdit_BinaryPath, 0, 1 );

    textLabel_WindPathField = new QLabel( groupBox5, "textLabel_WindPathField" );
    QFont textLabel_WindPathField_font(  textLabel_WindPathField->font() );
    textLabel_WindPathField_font.setFamily( "Lucida Grande" );
    textLabel_WindPathField_font.setBold( FALSE );
    textLabel_WindPathField->setFont( textLabel_WindPathField_font ); 

    layout9_2_2->addWidget( textLabel_WindPathField, 0, 0 );

    groupBox5Layout->addLayout( layout9_2_2, 2, 1 );

    layout9_2_2_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout9_2_2_2"); 

    lineEdit_SesamPath = new QLineEdit( groupBox5, "lineEdit_SesamPath" );
    QFont lineEdit_SesamPath_font(  lineEdit_SesamPath->font() );
    lineEdit_SesamPath_font.setBold( FALSE );
    lineEdit_SesamPath->setFont( lineEdit_SesamPath_font ); 
    lineEdit_SesamPath->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_SesamPath->setProperty( "frameShadow", "Sunken" );
    lineEdit_SesamPath->setProperty( "echoMode", "Normal" );

    layout9_2_2_2->addWidget( lineEdit_SesamPath, 0, 1 );

    textLabel_SesamPath = new QLabel( groupBox5, "textLabel_SesamPath" );
    QFont textLabel_SesamPath_font(  textLabel_SesamPath->font() );
    textLabel_SesamPath_font.setFamily( "Lucida Grande" );
    textLabel_SesamPath_font.setBold( FALSE );
    textLabel_SesamPath->setFont( textLabel_SesamPath_font ); 

    layout9_2_2_2->addWidget( textLabel_SesamPath, 0, 0 );

    groupBox5Layout->addMultiCellLayout( layout9_2_2_2, 3, 4, 1, 1 );

    layout9_3 = new QGridLayout( 0, 1, 1, 0, 6, "layout9_3"); 

    lineEdit_RootPass = new QLineEdit( groupBox5, "lineEdit_RootPass" );
    lineEdit_RootPass->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_RootPass->setProperty( "frameShadow", "Sunken" );
    lineEdit_RootPass->setProperty( "echoMode", "Password" );

    layout9_3->addWidget( lineEdit_RootPass, 0, 1 );

    textLabel_RootField = new QLabel( groupBox5, "textLabel_RootField" );
    QFont textLabel_RootField_font(  textLabel_RootField->font() );
    textLabel_RootField_font.setFamily( "Lucida Grande" );
    textLabel_RootField_font.setBold( FALSE );
    textLabel_RootField->setFont( textLabel_RootField_font ); 

    layout9_3->addWidget( textLabel_RootField, 0, 0 );

    groupBox5Layout->addLayout( layout9_3, 1, 1 );

    textLabel_AdminLinux = new QLabel( groupBox5, "textLabel_AdminLinux" );
    QFont textLabel_AdminLinux_font(  textLabel_AdminLinux->font() );
    textLabel_AdminLinux_font.setFamily( "Lucida Grande" );
    textLabel_AdminLinux_font.setPointSize( 13 );
    textLabel_AdminLinux_font.setUnderline( TRUE );
    textLabel_AdminLinux->setFont( textLabel_AdminLinux_font ); 

    groupBox5Layout->addMultiCellWidget( textLabel_AdminLinux, 0, 0, 0, 1 );

    tab_SesamLayout->addWidget( groupBox5, 0, 0 );
    tabWidget_Instal->insertTab( tab_Sesam, QString::fromLatin1("") );

    Dlg_MainDialogLayout->addWidget( tabWidget_Instal, 1, 0 );

    groupBox3 = new QGroupBox( this, "groupBox3" );
    groupBox3->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, groupBox3->sizePolicy().hasHeightForWidth() ) );
    QFont groupBox3_font(  groupBox3->font() );
    groupBox3_font.setBold( TRUE );
    groupBox3->setFont( groupBox3_font ); 
    groupBox3->setProperty( "margin", 0 );
    groupBox3->setColumnLayout(0, Qt::Vertical );
    groupBox3->layout()->setSpacing( 0 );
    groupBox3->layout()->setMargin( 0 );
    groupBox3Layout = new QGridLayout( groupBox3->layout() );
    groupBox3Layout->setAlignment( Qt::AlignTop );

    tabWidget_Nomadisme = new QTabWidget( groupBox3, "tabWidget_Nomadisme" );
    tabWidget_Nomadisme->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, tabWidget_Nomadisme->sizePolicy().hasHeightForWidth() ) );
    tabWidget_Nomadisme->setProperty( "tabShape", "Rounded" );
    tabWidget_Nomadisme->setProperty( "margin", 0 );

    serveur_maitre = new QWidget( tabWidget_Nomadisme, "serveur_maitre" );
    serveur_maitreLayout = new QGridLayout( serveur_maitre, 1, 1, 11, 6, "serveur_maitreLayout"); 

    layout11 = new QGridLayout( 0, 1, 1, 0, 0, "layout11"); 

    lineEdit_Sql_Port = new QLineEdit( serveur_maitre, "lineEdit_Sql_Port" );
    lineEdit_Sql_Port->setProperty( "maximumSize", QSize( 150, 32767 ) );
    QFont lineEdit_Sql_Port_font(  lineEdit_Sql_Port->font() );
    lineEdit_Sql_Port_font.setBold( FALSE );
    lineEdit_Sql_Port->setFont( lineEdit_Sql_Port_font ); 

    layout11->addWidget( lineEdit_Sql_Port, 0, 3 );

    lineEdit_Hostname = new QLineEdit( serveur_maitre, "lineEdit_Hostname" );
    lineEdit_Hostname->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, lineEdit_Hostname->sizePolicy().hasHeightForWidth() ) );
    lineEdit_Hostname->setProperty( "maximumSize", QSize( 150, 32767 ) );
    lineEdit_Hostname->setProperty( "backgroundOrigin", "AncestorOrigin" );
    QFont lineEdit_Hostname_font(  lineEdit_Hostname->font() );
    lineEdit_Hostname_font.setBold( FALSE );
    lineEdit_Hostname->setFont( lineEdit_Hostname_font ); 

    layout11->addWidget( lineEdit_Hostname, 0, 1 );

    pushButton_FavPlus = new QPushButton( serveur_maitre, "pushButton_FavPlus" );
    pushButton_FavPlus->setProperty( "minimumSize", QSize( 25, 25 ) );
    pushButton_FavPlus->setProperty( "maximumSize", QSize( 25, 25 ) );
    QFont pushButton_FavPlus_font(  pushButton_FavPlus->font() );
    pushButton_FavPlus_font.setFamily( "Lucida Grande" );
    pushButton_FavPlus_font.setBold( FALSE );
    pushButton_FavPlus->setFont( pushButton_FavPlus_font ); 
    pushButton_FavPlus->setProperty( "pixmap", image3 );
    pushButton_FavPlus->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout11->addWidget( pushButton_FavPlus, 0, 5 );

    textLabel1_3_2 = new QLabel( serveur_maitre, "textLabel1_3_2" );
    QFont textLabel1_3_2_font(  textLabel1_3_2->font() );
    textLabel1_3_2_font.setFamily( "Lucida Grande" );
    textLabel1_3_2_font.setBold( FALSE );
    textLabel1_3_2->setFont( textLabel1_3_2_font ); 
    textLabel1_3_2->setProperty( "mouseTracking", QVariant( FALSE, 0 ) );
    textLabel1_3_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    layout11->addWidget( textLabel1_3_2, 0, 2 );

    pushButtonRemove = new QPushButton( serveur_maitre, "pushButtonRemove" );
    pushButtonRemove->setProperty( "minimumSize", QSize( 25, 25 ) );
    pushButtonRemove->setProperty( "maximumSize", QSize( 25, 25 ) );
    QFont pushButtonRemove_font(  pushButtonRemove->font() );
    pushButtonRemove_font.setFamily( "Lucida Grande" );
    pushButtonRemove_font.setBold( FALSE );
    pushButtonRemove->setFont( pushButtonRemove_font ); 
    pushButtonRemove->setProperty( "pixmap", image4 );
    pushButtonRemove->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout11->addWidget( pushButtonRemove, 0, 6 );

    comboBox_IP_Fav = new QComboBox( FALSE, serveur_maitre, "comboBox_IP_Fav" );
    comboBox_IP_Fav->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)4, 0, 0, comboBox_IP_Fav->sizePolicy().hasHeightForWidth() ) );

    layout11->addWidget( comboBox_IP_Fav, 0, 4 );

    textLabel1_2 = new QLabel( serveur_maitre, "textLabel1_2" );
    textLabel1_2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)4, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    QFont textLabel1_2_font(  textLabel1_2->font() );
    textLabel1_2_font.setFamily( "Lucida Grande" );
    textLabel1_2_font.setBold( FALSE );
    textLabel1_2->setFont( textLabel1_2_font ); 
    textLabel1_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    layout11->addWidget( textLabel1_2, 0, 0 );

    serveur_maitreLayout->addLayout( layout11, 1, 0 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    textLabel1 = new QLabel( serveur_maitre, "textLabel1" );
    QFont textLabel1_font(  textLabel1->font() );
    textLabel1_font.setFamily( "Lucida Grande" );
    textLabel1_font.setBold( FALSE );
    textLabel1->setFont( textLabel1_font ); 
    textLabel1->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    layout4->addWidget( textLabel1 );

    lineEdit_UserName = new QLineEdit( serveur_maitre, "lineEdit_UserName" );
    QPalette pal;
    QColorGroup cg;
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 236, 233, 216) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 245, 244, 235) );
    cg.setColor( QColorGroup::Dark, QColor( 118, 116, 108) );
    cg.setColor( QColorGroup::Mid, QColor( 157, 155, 143) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 236, 233, 216) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 236, 233, 216) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 255, 254, 249) );
    cg.setColor( QColorGroup::Dark, QColor( 118, 116, 108) );
    cg.setColor( QColorGroup::Mid, QColor( 157, 155, 143) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 236, 233, 216) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 236, 233, 216) );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, QColor( 255, 254, 249) );
    cg.setColor( QColorGroup::Dark, QColor( 118, 116, 108) );
    cg.setColor( QColorGroup::Mid, QColor( 157, 155, 143) );
    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, QColor( 236, 233, 216) );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 255) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 255, 0, 255) );
    pal.setDisabled( cg );
    lineEdit_UserName->setProperty( "palette", pal );
    QFont lineEdit_UserName_font(  lineEdit_UserName->font() );
    lineEdit_UserName_font.setBold( FALSE );
    lineEdit_UserName->setFont( lineEdit_UserName_font ); 
    lineEdit_UserName->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_UserName->setProperty( "frameShadow", "Plain" );
    layout4->addWidget( lineEdit_UserName );
    spacer2 = new QSpacerItem( 50, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout4->addItem( spacer2 );

    textLabel1_3 = new QLabel( serveur_maitre, "textLabel1_3" );
    QFont textLabel1_3_font(  textLabel1_3->font() );
    textLabel1_3_font.setFamily( "Lucida Grande" );
    textLabel1_3_font.setBold( FALSE );
    textLabel1_3->setFont( textLabel1_3_font ); 
    textLabel1_3->setProperty( "mouseTracking", QVariant( FALSE, 0 ) );
    textLabel1_3->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    layout4->addWidget( textLabel1_3 );

    lineEdit_PassWord = new QLineEdit( serveur_maitre, "lineEdit_PassWord" );
    QFont lineEdit_PassWord_font(  lineEdit_PassWord->font() );
    lineEdit_PassWord_font.setBold( FALSE );
    lineEdit_PassWord->setFont( lineEdit_PassWord_font ); 
    lineEdit_PassWord->setProperty( "echoMode", "Password" );
    layout4->addWidget( lineEdit_PassWord );

    serveur_maitreLayout->addLayout( layout4, 0, 0 );
    tabWidget_Nomadisme->insertTab( serveur_maitre, QString::fromLatin1("") );

    Serveur_nomade = new QWidget( tabWidget_Nomadisme, "Serveur_nomade" );
    Serveur_nomadeLayout = new QGridLayout( Serveur_nomade, 1, 1, 11, 6, "Serveur_nomadeLayout"); 

    layout4_2 = new QHBoxLayout( 0, 0, 6, "layout4_2"); 

    textLabel1_4 = new QLabel( Serveur_nomade, "textLabel1_4" );
    QFont textLabel1_4_font(  textLabel1_4->font() );
    textLabel1_4_font.setFamily( "Lucida Grande" );
    textLabel1_4_font.setBold( FALSE );
    textLabel1_4->setFont( textLabel1_4_font ); 
    textLabel1_4->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    layout4_2->addWidget( textLabel1_4 );

    lineEdit_UserName_2 = new QLineEdit( Serveur_nomade, "lineEdit_UserName_2" );
    QFont lineEdit_UserName_2_font(  lineEdit_UserName_2->font() );
    lineEdit_UserName_2_font.setBold( FALSE );
    lineEdit_UserName_2->setFont( lineEdit_UserName_2_font ); 
    lineEdit_UserName_2->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_UserName_2->setProperty( "frameShadow", "Sunken" );
    layout4_2->addWidget( lineEdit_UserName_2 );
    spacer2_2 = new QSpacerItem( 50, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout4_2->addItem( spacer2_2 );

    textLabel1_3_3 = new QLabel( Serveur_nomade, "textLabel1_3_3" );
    QFont textLabel1_3_3_font(  textLabel1_3_3->font() );
    textLabel1_3_3_font.setFamily( "Lucida Grande" );
    textLabel1_3_3_font.setBold( FALSE );
    textLabel1_3_3->setFont( textLabel1_3_3_font ); 
    textLabel1_3_3->setProperty( "mouseTracking", QVariant( FALSE, 0 ) );
    textLabel1_3_3->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    layout4_2->addWidget( textLabel1_3_3 );

    lineEdit_PassWord_2 = new QLineEdit( Serveur_nomade, "lineEdit_PassWord_2" );
    QFont lineEdit_PassWord_2_font(  lineEdit_PassWord_2->font() );
    lineEdit_PassWord_2_font.setBold( FALSE );
    lineEdit_PassWord_2->setFont( lineEdit_PassWord_2_font ); 
    lineEdit_PassWord_2->setProperty( "echoMode", "Password" );
    layout4_2->addWidget( lineEdit_PassWord_2 );

    Serveur_nomadeLayout->addLayout( layout4_2, 0, 0 );

    layout21_2 = new QGridLayout( 0, 1, 1, 0, 0, "layout21_2"); 

    lineEdit_Sql_Port_2 = new QLineEdit( Serveur_nomade, "lineEdit_Sql_Port_2" );
    lineEdit_Sql_Port_2->setProperty( "maximumSize", QSize( 150, 32767 ) );
    QFont lineEdit_Sql_Port_2_font(  lineEdit_Sql_Port_2->font() );
    lineEdit_Sql_Port_2_font.setBold( FALSE );
    lineEdit_Sql_Port_2->setFont( lineEdit_Sql_Port_2_font ); 

    layout21_2->addWidget( lineEdit_Sql_Port_2, 0, 3 );

    comboBox_IP_Fav_2 = new QComboBox( FALSE, Serveur_nomade, "comboBox_IP_Fav_2" );
    comboBox_IP_Fav_2->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, comboBox_IP_Fav_2->sizePolicy().hasHeightForWidth() ) );

    layout21_2->addWidget( comboBox_IP_Fav_2, 0, 4 );

    pushButton_FavPlus_2 = new QPushButton( Serveur_nomade, "pushButton_FavPlus_2" );
    pushButton_FavPlus_2->setProperty( "minimumSize", QSize( 25, 25 ) );
    pushButton_FavPlus_2->setProperty( "maximumSize", QSize( 25, 25 ) );
    QFont pushButton_FavPlus_2_font(  pushButton_FavPlus_2->font() );
    pushButton_FavPlus_2_font.setFamily( "Lucida Grande" );
    pushButton_FavPlus_2_font.setBold( FALSE );
    pushButton_FavPlus_2->setFont( pushButton_FavPlus_2_font ); 
    pushButton_FavPlus_2->setProperty( "pixmap", image3 );
    pushButton_FavPlus_2->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout21_2->addWidget( pushButton_FavPlus_2, 0, 5 );

    lineEdit_Hostname_2 = new QLineEdit( Serveur_nomade, "lineEdit_Hostname_2" );
    lineEdit_Hostname_2->setProperty( "maximumSize", QSize( 150, 32767 ) );
    QFont lineEdit_Hostname_2_font(  lineEdit_Hostname_2->font() );
    lineEdit_Hostname_2_font.setBold( FALSE );
    lineEdit_Hostname_2->setFont( lineEdit_Hostname_2_font ); 

    layout21_2->addWidget( lineEdit_Hostname_2, 0, 1 );

    pushButtonRemove_2 = new QPushButton( Serveur_nomade, "pushButtonRemove_2" );
    pushButtonRemove_2->setProperty( "minimumSize", QSize( 25, 25 ) );
    pushButtonRemove_2->setProperty( "maximumSize", QSize( 25, 25 ) );
    QFont pushButtonRemove_2_font(  pushButtonRemove_2->font() );
    pushButtonRemove_2_font.setFamily( "Lucida Grande" );
    pushButtonRemove_2_font.setBold( FALSE );
    pushButtonRemove_2->setFont( pushButtonRemove_2_font ); 
    pushButtonRemove_2->setProperty( "pixmap", image4 );
    pushButtonRemove_2->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout21_2->addWidget( pushButtonRemove_2, 0, 6 );

    textLabel1_3_2_2 = new QLabel( Serveur_nomade, "textLabel1_3_2_2" );
    QFont textLabel1_3_2_2_font(  textLabel1_3_2_2->font() );
    textLabel1_3_2_2_font.setFamily( "Lucida Grande" );
    textLabel1_3_2_2_font.setBold( FALSE );
    textLabel1_3_2_2->setFont( textLabel1_3_2_2_font ); 
    textLabel1_3_2_2->setProperty( "mouseTracking", QVariant( FALSE, 0 ) );
    textLabel1_3_2_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    layout21_2->addWidget( textLabel1_3_2_2, 0, 2 );

    textLabel1_2_2 = new QLabel( Serveur_nomade, "textLabel1_2_2" );
    QFont textLabel1_2_2_font(  textLabel1_2_2->font() );
    textLabel1_2_2_font.setFamily( "Lucida Grande" );
    textLabel1_2_2_font.setBold( FALSE );
    textLabel1_2_2->setFont( textLabel1_2_2_font ); 
    textLabel1_2_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    layout21_2->addWidget( textLabel1_2_2, 0, 0 );

    Serveur_nomadeLayout->addLayout( layout21_2, 1, 0 );
    tabWidget_Nomadisme->insertTab( Serveur_nomade, QString::fromLatin1("") );

    TabPage = new QWidget( tabWidget_Nomadisme, "TabPage" );
    TabPageLayout = new QGridLayout( TabPage, 1, 1, 11, 6, "TabPageLayout"); 

    layout4_2_2 = new QHBoxLayout( 0, 0, 6, "layout4_2_2"); 

    textLabel1_4_2 = new QLabel( TabPage, "textLabel1_4_2" );
    QFont textLabel1_4_2_font(  textLabel1_4_2->font() );
    textLabel1_4_2_font.setFamily( "Lucida Grande" );
    textLabel1_4_2_font.setBold( FALSE );
    textLabel1_4_2->setFont( textLabel1_4_2_font ); 
    textLabel1_4_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    layout4_2_2->addWidget( textLabel1_4_2 );

    lineEdit_UserName_3 = new QLineEdit( TabPage, "lineEdit_UserName_3" );
    QFont lineEdit_UserName_3_font(  lineEdit_UserName_3->font() );
    lineEdit_UserName_3_font.setBold( FALSE );
    lineEdit_UserName_3->setFont( lineEdit_UserName_3_font ); 
    lineEdit_UserName_3->setProperty( "frameShape", "LineEditPanel" );
    lineEdit_UserName_3->setProperty( "frameShadow", "Sunken" );
    layout4_2_2->addWidget( lineEdit_UserName_3 );
    spacer2_2_2 = new QSpacerItem( 50, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout4_2_2->addItem( spacer2_2_2 );

    textLabel1_3_3_2 = new QLabel( TabPage, "textLabel1_3_3_2" );
    QFont textLabel1_3_3_2_font(  textLabel1_3_3_2->font() );
    textLabel1_3_3_2_font.setFamily( "Lucida Grande" );
    textLabel1_3_3_2_font.setBold( FALSE );
    textLabel1_3_3_2->setFont( textLabel1_3_3_2_font ); 
    textLabel1_3_3_2->setProperty( "mouseTracking", QVariant( FALSE, 0 ) );
    textLabel1_3_3_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    layout4_2_2->addWidget( textLabel1_3_3_2 );

    lineEdit_PassWord_3 = new QLineEdit( TabPage, "lineEdit_PassWord_3" );
    QFont lineEdit_PassWord_3_font(  lineEdit_PassWord_3->font() );
    lineEdit_PassWord_3_font.setBold( FALSE );
    lineEdit_PassWord_3->setFont( lineEdit_PassWord_3_font ); 
    lineEdit_PassWord_3->setProperty( "echoMode", "Password" );
    layout4_2_2->addWidget( lineEdit_PassWord_3 );

    TabPageLayout->addLayout( layout4_2_2, 0, 0 );

    layout20_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout20_2"); 

    pushButton_FavPlus_3 = new QPushButton( TabPage, "pushButton_FavPlus_3" );
    pushButton_FavPlus_3->setProperty( "minimumSize", QSize( 25, 25 ) );
    pushButton_FavPlus_3->setProperty( "maximumSize", QSize( 25, 25 ) );
    QFont pushButton_FavPlus_3_font(  pushButton_FavPlus_3->font() );
    pushButton_FavPlus_3_font.setFamily( "Lucida Grande" );
    pushButton_FavPlus_3_font.setBold( FALSE );
    pushButton_FavPlus_3->setFont( pushButton_FavPlus_3_font ); 
    pushButton_FavPlus_3->setProperty( "pixmap", image3 );
    pushButton_FavPlus_3->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout20_2->addWidget( pushButton_FavPlus_3, 0, 5 );

    textLabel1_3_2_2_2 = new QLabel( TabPage, "textLabel1_3_2_2_2" );
    QFont textLabel1_3_2_2_2_font(  textLabel1_3_2_2_2->font() );
    textLabel1_3_2_2_2_font.setFamily( "Lucida Grande" );
    textLabel1_3_2_2_2_font.setBold( FALSE );
    textLabel1_3_2_2_2->setFont( textLabel1_3_2_2_2_font ); 
    textLabel1_3_2_2_2->setProperty( "mouseTracking", QVariant( FALSE, 0 ) );
    textLabel1_3_2_2_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    layout20_2->addWidget( textLabel1_3_2_2_2, 0, 2 );

    pushButtonRemove_3 = new QPushButton( TabPage, "pushButtonRemove_3" );
    pushButtonRemove_3->setProperty( "minimumSize", QSize( 25, 25 ) );
    pushButtonRemove_3->setProperty( "maximumSize", QSize( 25, 25 ) );
    QFont pushButtonRemove_3_font(  pushButtonRemove_3->font() );
    pushButtonRemove_3_font.setFamily( "Lucida Grande" );
    pushButtonRemove_3_font.setBold( FALSE );
    pushButtonRemove_3->setFont( pushButtonRemove_3_font ); 
    pushButtonRemove_3->setProperty( "mouseTracking", QVariant( FALSE, 0 ) );
    pushButtonRemove_3->setProperty( "pixmap", image4 );
    pushButtonRemove_3->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout20_2->addWidget( pushButtonRemove_3, 0, 6 );

    comboBox_IP_Fav_3 = new QComboBox( FALSE, TabPage, "comboBox_IP_Fav_3" );
    comboBox_IP_Fav_3->setProperty( "sizePolicy", QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, comboBox_IP_Fav_3->sizePolicy().hasHeightForWidth() ) );

    layout20_2->addWidget( comboBox_IP_Fav_3, 0, 4 );

    lineEdit_Hostname_3 = new QLineEdit( TabPage, "lineEdit_Hostname_3" );
    lineEdit_Hostname_3->setProperty( "maximumSize", QSize( 150, 32767 ) );
    QFont lineEdit_Hostname_3_font(  lineEdit_Hostname_3->font() );
    lineEdit_Hostname_3_font.setBold( FALSE );
    lineEdit_Hostname_3->setFont( lineEdit_Hostname_3_font ); 

    layout20_2->addWidget( lineEdit_Hostname_3, 0, 1 );

    lineEdit_Sql_Port_3 = new QLineEdit( TabPage, "lineEdit_Sql_Port_3" );
    lineEdit_Sql_Port_3->setProperty( "maximumSize", QSize( 150, 32767 ) );
    QFont lineEdit_Sql_Port_3_font(  lineEdit_Sql_Port_3->font() );
    lineEdit_Sql_Port_3_font.setBold( FALSE );
    lineEdit_Sql_Port_3->setFont( lineEdit_Sql_Port_3_font ); 

    layout20_2->addWidget( lineEdit_Sql_Port_3, 0, 3 );

    textLabel1_2_2_2 = new QLabel( TabPage, "textLabel1_2_2_2" );
    QFont textLabel1_2_2_2_font(  textLabel1_2_2_2->font() );
    textLabel1_2_2_2_font.setFamily( "Lucida Grande" );
    textLabel1_2_2_2_font.setBold( FALSE );
    textLabel1_2_2_2->setFont( textLabel1_2_2_2_font ); 
    textLabel1_2_2_2->setProperty( "alignment", int( QLabel::AlignVCenter | QLabel::AlignRight ) );

    layout20_2->addWidget( textLabel1_2_2_2, 0, 0 );

    TabPageLayout->addLayout( layout20_2, 1, 0 );
    tabWidget_Nomadisme->insertTab( TabPage, QString::fromLatin1("") );

    groupBox3Layout->addMultiCellWidget( tabWidget_Nomadisme, 0, 1, 0, 0 );

    layout21_3 = new QGridLayout( 0, 1, 1, 0, 6, "layout21_3"); 

    pushButton_APropos = new QPushButton( groupBox3, "pushButton_APropos" );
    pushButton_APropos->setProperty( "minimumSize", QSize( 30, 30 ) );
    pushButton_APropos->setProperty( "maximumSize", QSize( 30, 30 ) );
    pushButton_APropos->setProperty( "flat", QVariant( TRUE, 0 ) );

    layout21_3->addWidget( pushButton_APropos, 0, 1 );

    checkBox_Nomadisme = new QCheckBox( groupBox3, "checkBox_Nomadisme" );
    checkBox_Nomadisme->setProperty( "enabled", QVariant( TRUE, 0 ) );
    QFont checkBox_Nomadisme_font(  checkBox_Nomadisme->font() );
    checkBox_Nomadisme_font.setBold( FALSE );
    checkBox_Nomadisme->setFont( checkBox_Nomadisme_font ); 
    checkBox_Nomadisme->setProperty( "checked", QVariant( FALSE, 0 ) );

    layout21_3->addWidget( checkBox_Nomadisme, 0, 0 );

    groupBox3Layout->addLayout( layout21_3, 0, 1 );

    pushButtonConnexionAppl = new QPushButton( groupBox3, "pushButtonConnexionAppl" );
    pushButtonConnexionAppl->setProperty( "default", QVariant( TRUE, 0 ) );

    groupBox3Layout->addWidget( pushButtonConnexionAppl, 1, 1 );

    Dlg_MainDialogLayout->addMultiCellWidget( groupBox3, 0, 0, 0, 1 );
    languageChange();
    resize( QSize(613, 660).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( quitPushButton, SIGNAL( clicked() ), this, SLOT( close() ) );

    // tab order
    setTabOrder( pushButton_SetBases, comboBox_Bases );
    setTabOrder( comboBox_Bases, lineEdit_UserName );
    setTabOrder( lineEdit_UserName, lineEdit_PassWord );
    setTabOrder( lineEdit_PassWord, lineEdit_Hostname );
    setTabOrder( lineEdit_Hostname, pushButtonConnexionAppl );
    setTabOrder( pushButtonConnexionAppl, checkBox_STD_MAJ );
    setTabOrder( checkBox_STD_MAJ, checkBox_SQL_MAJ );
    setTabOrder( checkBox_SQL_MAJ, pushButtonSwitchGetDatasemp );
    setTabOrder( pushButtonSwitchGetDatasemp, pushButton_SetDatasemp );
    setTabOrder( pushButton_SetDatasemp, pushButtonJustOneTable );
    setTabOrder( pushButtonJustOneTable, quitPushButton );

    // buddies
    textLabel1_3_2->setBuddy( lineEdit_PassWord );
    textLabel1_2->setBuddy( lineEdit_Hostname );
    textLabel1->setBuddy( lineEdit_UserName );
    textLabel1_3->setBuddy( lineEdit_PassWord );
    textLabel1_4->setBuddy( lineEdit_UserName );
    textLabel1_3_3->setBuddy( lineEdit_PassWord );
    textLabel1_3_2_2->setBuddy( lineEdit_PassWord );
    textLabel1_2_2->setBuddy( lineEdit_Hostname );
    textLabel1_4_2->setBuddy( lineEdit_UserName );
    textLabel1_3_3_2->setBuddy( lineEdit_PassWord );
    textLabel1_3_2_2_2->setBuddy( lineEdit_PassWord );
    textLabel1_2_2_2->setBuddy( lineEdit_Hostname );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Dlg_MainDialog::~Dlg_MainDialog()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Dlg_MainDialog::languageChange()
{
    setProperty( "caption", tr( "Dlg_MainDialog" ) );
    textLabel_MedinTux->setProperty( "text", QString::null );
    textLabel_Progress->setProperty( "text", QString::null );
    pushButton_LancerDrTux->setProperty( "text", trUtf8( "\x26\x44\xc3\xa9\x6d\x61\x72\x72\x65\x72\x20\x4d\x65\x64\x69\x6e\x54\x75\x78" ) );
    pushButton_LancerDrTux->setProperty( "accel", QKeySequence( tr( "Alt+D" ) ) );
    quitPushButton->setProperty( "text", tr( "&Quitter" ) );
    quitPushButton->setProperty( "accel", QKeySequence( tr( "Alt+Q" ) ) );
    QToolTip::add( quitPushButton, trUtf8( "\x51\x75\x69\x74\x74\x65\x20\x63\x65\x74\x20\x69\x6e\x73\x74\x61\x6c\x6c\x61\x74\x65"
    "\x75\x72\x2c\x3c\x62\x72\x3e\x70\x61\x73\x20\x6c\x65\x73\x20\x70\x72\x6f\x67\x72"
    "\x61\x6d\x6d\x65\x73\x20\x71\x75\x27\x69\x6c\x20\x61\x20\x6c\x61\x6e\x63\xc3\xa9"
    "\x73" ) );
    pushButton_SetBases->setProperty( "text", tr( "Installer &les bases de  MedinTux" ) );
    pushButton_SetBases->setProperty( "accel", QKeySequence( tr( "Alt+L" ) ) );
    QToolTip::add( pushButton_SetBases, trUtf8( "\x53\xc3\xa9\x6c\x65\x63\x74\x69\x6f\x6e\x6e\x65\x7a\x20\xc3\xa0\x20\x64\x72\x6f\x69"
    "\x74\x65\x20\x71\x75\x65\x6c\x6c\x65\x28\x73\x29\x20\x62\x61\x73\x65\x28\x73\x29"
    "\x20\x69\x6e\x73\x74\x61\x6c\x6c\x65\x72" ) );
    pushButton_MajBases->setProperty( "text", trUtf8( "\x26\x4d\x65\x74\x74\x72\x65\x20\xc3\xa0\x20\x6a\x6f\x75\x72" ) );
    pushButton_MajBases->setProperty( "accel", QKeySequence( tr( "Alt+M" ) ) );
    QToolTip::add( pushButton_MajBases, trUtf8( "\x4c\x61\x20\x62\x61\x73\x65\x20\x64\x65\x20\x64\x6f\x6e\x6e\xc3\xa9\x65\x73\x20\x61"
    "\x63\x74\x75\x65\x6c\x6c\x65\x20\x6e\x27\x65\x73\x74\x20\x70\x61\x73\x20\xc3\xa0"
    "\x20\x6a\x6f\x75\x72\x20\x3c\x62\x72\x3e\x63\x6c\x69\x71\x75\x65\x7a\x20\x73\x75"
    "\x72\x20\x63\x65\x20\x62\x6f\x75\x74\x6f\x6e\x20\x70\x6f\x75\x72\x20\x61\x63\x63"
    "\xc3\xa9\x64\x65\x72\x20\xc3\xa0\x20\x6c\x27\x75\x74\x69\x6c\x69\x74\x61\x69\x72"
    "\x65\x20\x64\x65\x20\x6d\x69\x73\x65\x20\xc3\xa0\x20\x6a\x6f\x75\x72\x2e" ) );
    pushButton_Load_SQL->setProperty( "text", tr( "Res&taurer un fichier SQL" ) );
    pushButton_Load_SQL->setProperty( "accel", QKeySequence( tr( "Alt+T" ) ) );
    QToolTip::add( pushButton_Load_SQL, trUtf8( "\x45\x78\xc3\xa9\x63\x75\x74\x65\x72\x20\x75\x6e\x20\x66\x69\x63\x68\x69\x65\x72\x20"
    "\x53\x51\x4c\x20\x28\x70\x65\x72\x6d\x65\x74\x20\x6c\x61\x20\x72\x65\x73\x74\x61"
    "\x75\x72\x61\x74\x69\x6f\x6e\x20\x64\x65\x20\x64\x6f\x6e\x6e\xc3\xa9\x65\x73\x29"
    "\x2e" ) );
    tabWidget_Instal->changeTab( tab_Bases, tr( "Installation des bases" ) );
    groupBox1->setProperty( "title", QString::null );
    pushButton_IndexerDatasemp->setProperty( "text", tr( "&Reindexer ..." ) );
    pushButton_IndexerDatasemp->setProperty( "accel", QKeySequence( tr( "Alt+R" ) ) );
    QToolTip::add( pushButton_IndexerDatasemp, trUtf8( "\x43\x72\xc3\xa9\x65\x20\x6c\x65\x73\x20\x69\x6e\x64\x65\x78\x20\x61\x63\x63\xc3\xa9"
    "\x6c\xc3\xa9\x72\x61\x74\x65\x75\x72\x73\x20\x69\x6e\x64\x69\x73\x70\x65\x6e\x73"
    "\x61\x62\x6c\x65\x73\x2e\x3c\x62\x72\x3e\x4f\x70\xc3\xa9\x72\x61\x74\x69\x6f\x6e"
    "\x20\x74\x72\xc3\xa8\x73\x20\x6c\x6f\x6e\x67\x75\x65\x20\x3c\x62\x72\x3e\x6d\x61"
    "\x69\x73\x20\x69\x6e\x64\x69\x73\x70\x65\x6e\x73\x61\x62\x6c\x65\x20\x61\x70\x72"
    "\xc3\xa8\x73\x20\x63\x68\x61\x71\x75\x65\x20\x6e\x6f\x75\x76\x65\x6c\x6c\x65\x3c"
    "\x62\x72\x3e\x20\x63\x6f\x70\x69\x65\x20\x64\x65\x20\x64\x6f\x6e\x6e\xc3\xa9\x65"
    "\x73\x20\x56\x69\x64\x61\x6c\x20\x44\x61\x74\x61\x73\x65\x6d\x70\x3c\x62\x72\x3e"
    "\x20\x28\x70\x72\xc3\xa9\x76\x6f\x69\x72\x20\x75\x6e\x65\x20\x6e\x75\x69\x74\x29"
    "" ) );
    pushButton_SetDatasemp->setProperty( "text", trUtf8( "\x43\x6f\x70\x69\x65\x72\x20\x6c\x65\x73\x20\x64\x6f\x6e\x6e\xc3\xa9\x65\x73\x20\x2e"
    "\x2e\x2e" ) );
    pushButton_SetDatasemp->setProperty( "accel", QKeySequence( QString::null ) );
    QToolTip::add( pushButton_SetDatasemp, trUtf8( "\x43\x6c\x69\x71\x75\x65\x7a\x20\xc3\xa0\x20\x64\x72\x6f\x69\x74\x65\x20\x73\x69\x20"
    "\x76\x6f\x75\x73\x20\x76\x6f\x75\x6c\x65\x7a\x3c\x62\x72\x3e\x6e\x27\x69\x6e\x73"
    "\x74\x61\x6c\x6c\x65\x72\x20\x71\x75\x27\x75\x6e\x65\x20\x74\x61\x62\x6c\x65\x2e"
    "" ) );
    pushButtonJustOneTable->setProperty( "text", tr( "&Juste une table" ) );
    pushButtonJustOneTable->setProperty( "accel", QKeySequence( tr( "Alt+J" ) ) );
    pushButtonImagesCopy->setProperty( "text", tr( "&Copier les images" ) );
    pushButtonImagesCopy->setProperty( "accel", QKeySequence( tr( "Alt+C" ) ) );
    checkBox_STD_MAJ->setProperty( "text", trUtf8( "\x41\x76\x65\x63\x20\x6d\x69\x73\x65\x20\x26\xc3\xa0\x20\x6a\x6f\x75\x72\x20\x64\x65"
    "\x73\x20\x64\x6f\x6e\x6e\xc3\xa9\x65\x73\x20\x73\x74\x61\x6e\x64\x61\x72\x64\x20"
    "\x28\x66\x69\x63\x68\x69\x65\x72\x73\x20\x2e\x6d\x61\x6a\x29" ) );
    checkBox_STD_MAJ->setProperty( "accel", QKeySequence( trUtf8( "\x41\x6c\x74\x2b\xc3\xa0" ) ) );
    pushButtonMakeSQL->setProperty( "text", trUtf8( "\x47\xc3\xa9\x6e\xc3\xa9\x72\x65\x72\x20\x66\x69\x63\x26\x68\x69\x65\x72\x73\x20\x53"
    "\x51\x4c" ) );
    textLabel3->setProperty( "text", QString::null );
    checkBox_SQL_MAJ->setProperty( "text", trUtf8( "\x41\x76\x26\x65\x63\x20\x6d\x69\x73\x65\x20\xc3\xa0\x20\x6a\x6f\x75\x72\x20\x64\x65"
    "\x73\x20\x64\x6f\x6e\x6e\xc3\xa9\x65\x73\x20\x53\x51\x4c\x20\x28\x66\x69\x63\x68"
    "\x69\x65\x72\x73\x20\x2e\x73\x71\x6c\x29" ) );
    checkBox_SQL_MAJ->setProperty( "accel", QKeySequence( tr( "Alt+E" ) ) );
    pushButtonSwitchGetDatasemp->setProperty( "text", tr( "Activer la &base Get" ) );
    pushButtonSwitchGetDatasemp->setProperty( "accel", QKeySequence( tr( "Alt+B" ) ) );
    tabWidget_Instal->changeTab( tab_Vidal, trUtf8( "\x26\x42\x61\x73\x65\x73\x20\x54\x68\xc3\xa9\x72\x61\x70\x65\x75\x74\x69\x71\x75\x65"
    "\x73" ) );
    pushButton_compilation->setProperty( "text", trUtf8( "\x26\x43\x6f\x6d\x70\x69\x6c\x61\x74\x69\x6f\x6e\x20\x64\x65\x73\x20\x65\x78\xc3\xa9"
    "\x63\x75\x74\x61\x62\x6c\x65\x73" ) );
    pushButton_compilation->setProperty( "accel", QKeySequence( tr( "Alt+C" ) ) );
    QToolTip::add( pushButton_compilation, trUtf8( "\x43\x68\x6f\x69\x73\x69\x73\x73\x65\x7a\x20\xc3\xa0\x20\x64\x72\x6f\x69\x74\x65\x20"
    "\x71\x75\x65\x6c\x28\x73\x29\x20\x70\x72\x6f\x67\x72\x61\x6d\x6d\x65\x28\x73\x29"
    "\x20\x63\x6f\x6d\x70\x69\x6c\x65\x72" ) );
    lineEdit_Qt3->setProperty( "text", tr( "ds" ) );
    lineEdit_Qt4Sdk->setProperty( "text", tr( "ds" ) );
    pushButton_Qt4Sdk->setProperty( "text", tr( "&Localiser le Sdk de QT4" ) );
    pushButton_Qt4Sdk->setProperty( "accel", QKeySequence( tr( "Alt+L" ) ) );
    QToolTip::add( pushButton_Qt4Sdk, tr( "Localiser le Sdk de QT4" ) );
    pushButton_Qt3->setProperty( "text", trUtf8( "\x4c\x6f\x63\x61\x6c\x69\x73\x65\x72\x20\x6c\x65\x20\x72\xc3\xa9\x70\x65\x72\x74\x6f"
    "\x69\x72\x65\x20\x64\x65\x20\x51\x54\x26\x33" ) );
    pushButton_Qt3->setProperty( "accel", QKeySequence( tr( "Alt+3" ) ) );
    QToolTip::add( pushButton_Qt3, tr( "Localiser le Sdk de QT4" ) );
    textLabel_MacOS->setProperty( "text", tr( "<u><font color=\"#d6001e\"><b>Sous Mac OS se mettre en mode Adminitrateur</b></font></u>" ) );
    tabWidget_Instal->changeTab( tab_Compilation, tr( "Compilation" ) );
    groupBox5->setProperty( "title", QString::null );
    pushButton_setGalsINI->setProperty( "text", trUtf8( "\x45\x6e\x72\x65\x67\x69\x73\x74\x72\x65\x72\x20\x6c\x65\x73\x20\x70\x61\x72\x61\x6d"
    "\xc3\xa8\x74\x72\x65\x73" ) );
    QToolTip::add( pushButton_setGalsINI, trUtf8( "\x45\x6e\x72\x65\x67\x69\x73\x74\x72\x65\x20\x6c\x65\x20\x70\x6f\x72\x74\x20\x61\x75"
    "\x71\x75\x65\x6c\x20\x65\x73\x74\x20\x63\x6f\x6e\x6e\x65\x63\x74\xc3\xa9\x20\x76"
    "\x6f\x74\x72\x65\x20\x6c\x65\x63\x74\x65\x75\x72\x20\x64\x65\x20\x63\x61\x72\x74"
    "\x65\x73" ) );
    pushButton_LireVitale->setProperty( "text", tr( "Tester" ) );
    QToolTip::add( pushButton_LireVitale, tr( "Teste en lisant une carte" ) );
    pushButton_InstallSesam->setProperty( "text", tr( "Installer les composants Sesam Vitale" ) );
    comboBox_PortLecteurWin->clear();
    comboBox_PortLecteurWin->insertItem( tr( "COM1" ) );
    comboBox_PortLecteurWin->insertItem( tr( "COM2" ) );
    comboBox_PortLecteurWin->insertItem( tr( "COM3" ) );
    comboBox_PortLecteurWin->insertItem( tr( "COM4" ) );
    comboBox_PortLecteurWin->insertItem( tr( "COM5" ) );
    comboBox_PortLecteurWin->insertItem( tr( "COM6" ) );
    QToolTip::add( comboBox_PortLecteurWin, tr( "Choisissez le port d'instalation du lecteur de carte" ) );
    comboBox_PortLecteur->clear();
    comboBox_PortLecteur->insertItem( tr( "COM1=/dev/ttyS0" ) );
    comboBox_PortLecteur->insertItem( tr( "COM1=/dev/tts/USB0" ) );
    comboBox_PortLecteur->insertItem( tr( "COM1=/dev/ttyUSB0" ) );
    comboBox_PortLecteur->insertItem( tr( "COM2=/dev/ttyS1" ) );
    comboBox_PortLecteur->insertItem( tr( "COM2=/dev/tts/USB1" ) );
    comboBox_PortLecteur->insertItem( tr( "COM2=/dev/ttyUSB1" ) );
    QToolTip::add( comboBox_PortLecteur, tr( "Choisissez le port d'instalation du lecteur de carte" ) );
    QToolTip::add( lineEdit_BinaryPath, trUtf8( "\x52\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72\x65\x20\x73\x79\x73\x74\xc3\xa8\x6d\x65\x20"
    "\x64\x65\x20\x57\x69\x6e\x64\x6f\x77\x73\x20\x6c\x65\x20\x70\x6c\x75\x73\x20\x73"
    "\x6f\x75\x76\x65\x6e\x74\x20\x22\x43\x3a\x5c\x57\x49\x4e\x44\x4f\x57\x53\x22\x20"
    "\x28\x64\x65\x73\x20\x63\x6f\x6d\x70\x6f\x73\x61\x6e\x74\x73\x20\x53\x65\x73\x61"
    "\x6d\x2d\x56\x69\x74\x61\x6c\x65\x20\x64\x6f\x69\x76\x65\x6e\x74\x20\x79\x20\xc3"
    "\xaa\x74\x72\x65\x20\x70\x6c\x61\x63\xc3\xa9\x29" ) );
    textLabel_WindPathField->setProperty( "text", trUtf8( "\x52\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72\x65\x20\x73\x79\x73\x74\xc3\xa8\x6d\x65\x20"
    "\x57\x49\x4e\x44\x4f\x57\x53" ) );
    QToolTip::add( lineEdit_SesamPath, trUtf8( "\x45\x6e\x64\x72\x6f\x69\x74\x20\x6f\xc3\xb9\x20\x70\x6c\x61\x63\x65\x72\x20\x6c\x65"
    "\x20\x72\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72\x65\x20\x73\x65\x73\x61\x6d\x20\x28"
    "\x73\x69\x20\x76\x6f\x75\x73\x20\x6e\x27\x61\x76\x65\x7a\x20\x70\x61\x73\x20\x64"
    "\x27\x69\x64\xc3\xa9\x65\x2c\x20\x6c\x61\x69\x73\x73\x65\x72\x20\x6c\x65\x73\x20"
    "\x70\x61\x72\x61\x6d\xc3\xa8\x74\x72\x65\x73\x20\x61\x63\x74\x75\x65\x6c\x73\x29"
    "" ) );
    textLabel_SesamPath->setProperty( "text", trUtf8( "\x52\xc3\xa9\x70\x65\x72\x74\x6f\x69\x72\x65\x20\x27\x73\x65\x73\x61\x6d\x27" ) );
    textLabel_RootField->setProperty( "text", tr( "Mot de passe root" ) );
    textLabel_AdminLinux->setProperty( "text", tr( "<u><font color=\"#d6001e\"><b>Sous Mac OS se mettre en mode Adminitrateur</b></font></u>" ) );
    tabWidget_Instal->changeTab( tab_Sesam, tr( "Sesam-&Vitale" ) );
    groupBox3->setProperty( "title", trUtf8( "\x50\x61\x72\x61\x6d\xc3\xa8\x74\x72\x65\x73\x20\x64\x65\x20\x63\x6f\x6e\x6e\x65\x78"
    "\x69\x6f\x6e\x20\x61\x75\x20\x73\x65\x72\x76\x65\x75\x72" ) );
    QToolTip::add( tabWidget_Nomadisme, QString::null );
    lineEdit_Sql_Port->setProperty( "text", tr( "3306" ) );
    QToolTip::add( lineEdit_Sql_Port, trUtf8( "\x53\x61\x69\x73\x69\x65\x20\x64\x75\x20\x70\x6f\x72\x74\x20\x61\x75\x71\x75\x65\x6c"
    "\x20\x6c\x61\x20\x63\x6f\x6e\x6e\x65\x78\x69\x6f\x6e\x20\x53\x51\x4c\x20\x64\x6f"
    "\x69\x74\x20\xc3\xaa\x74\x72\x65\x20\xc3\xa9\x74\x61\x62\x6c\x65\x20\x28\x68\x61"
    "\x62\x69\x74\x75\x65\x6c\x6c\x65\x6d\x65\x6e\x74\x20\x33\x33\x30\x36\x29" ) );
    QToolTip::add( lineEdit_Hostname, trUtf8( "\x43\x65\x20\x70\x65\x75\x74\x20\xc3\xaa\x74\x72\x65\x20\xc2\xab\x20\x6c\x6f\x63\x61"
    "\x6c\x68\x6f\x73\x74\x20\xc2\xbb\x20\x3c\x62\x72\x3e\x70\x6f\x75\x72\x20\x75\x6e"
    "\x65\x20\x62\x61\x73\x65\x20\x6c\x6f\x63\x61\x6c\x65\x2c\x20\x6f\x75\x20\x75\x6e"
    "\x65\x20\x61\x64\x72\x65\x73\x73\x65\x20\xc3\xa0\x20\x71\x75\x61\x74\x72\x65\x20"
    "\x6e\x6f\x6d\x62\x72\x65\x73\x20\x28\x63\x6f\x6d\x6d\x65\x20\x31\x39\x32\x2e\x31"
    "\x36\x38\x2e\x30\x2e\x31\x29\x2c\x20\x6f\x75\x20\x75\x6e\x20\x6e\x6f\x6d\x20\x64"
    "\x65\x20\x6d\x61\x63\x68\x69\x6e\x65" ) );
    pushButton_FavPlus->setProperty( "text", QString::null );
    pushButton_FavPlus->setProperty( "accel", QKeySequence( QString::null ) );
    QToolTip::add( pushButton_FavPlus, tr( "Ajouter l'adresse IP aux favoris" ) );
    textLabel1_3_2->setProperty( "text", tr( "Port :" ) );
    QToolTip::add( textLabel1_3_2, tr( "Le port du casque est obligatoire." ) );
    pushButtonRemove->setProperty( "text", QString::null );
    pushButtonRemove->setProperty( "accel", QKeySequence( QString::null ) );
    QToolTip::add( pushButtonRemove, tr( "Retirer l'adresse IP des favoris" ) );
    textLabel1_2->setProperty( "text", tr( "&Nom ou adresse IP :" ) );
    QToolTip::add( textLabel1_2, trUtf8( "\x43\x65\x20\x70\x65\x75\x74\x20\xc3\xaa\x74\x72\x65\x20\xc2\xab\x20\x6c\x6f\x63\x61"
    "\x6c\x68\x6f\x73\x74\x20\xc2\xbb\x20\x3c\x62\x72\x3e\x70\x6f\x75\x72\x20\x75\x6e"
    "\x65\x20\x62\x61\x73\x65\x20\x6c\x6f\x63\x61\x6c\x65\x2c\x20\x6f\x75\x20\x75\x6e"
    "\x65\x20\x61\x64\x72\x65\x73\x73\x65\x20\xc3\xa0\x20\x71\x75\x61\x74\x72\x65\x20"
    "\x6e\x6f\x6d\x62\x72\x65\x73\x20\x28\x63\x6f\x6d\x6d\x65\x20\x31\x39\x32\x2e\x31"
    "\x36\x38\x2e\x30\x2e\x31\x29\x2c\x20\x6f\x75\x20\x75\x6e\x20\x6e\x6f\x6d\x20\x64"
    "\x65\x20\x6d\x61\x63\x68\x69\x6e\x65" ) );
    textLabel1->setProperty( "text", tr( "Nom de conne&xion :" ) );
    QToolTip::add( textLabel1, tr( "C'est le nom d'utilisateur MySQL" ) );
    QToolTip::add( lineEdit_UserName, tr( "C'est le nom d'utilisateur MySQL" ) );
    textLabel1_3->setProperty( "text", tr( "Mo&t de passe : " ) );
    QToolTip::add( textLabel1_3, tr( "Mot de passe d'utilisateur MySQL" ) );
    QToolTip::add( lineEdit_PassWord, tr( "Mot de passe d'utilisateur MySQL" ) );
    tabWidget_Nomadisme->changeTab( serveur_maitre, trUtf8( "\x20\x53\x65\x72\x76\x65\x75\x72\x20\x6d\x61\x26\xc3\xae\x74\x72\x65" ) );
    textLabel1_4->setProperty( "text", tr( "Nom de conne&xion :" ) );
    QToolTip::add( textLabel1_4, tr( "C'est le nom d'utilisateur MySQL" ) );
    QToolTip::add( lineEdit_UserName_2, tr( "C'est le nom d'utilisateur MySQL" ) );
    textLabel1_3_3->setProperty( "text", tr( "Mo&t de passe : " ) );
    QToolTip::add( textLabel1_3_3, tr( "Mot de passe d'utilisateur MySQL" ) );
    QToolTip::add( lineEdit_PassWord_2, tr( "Mot de passe d'utilisateur MySQL" ) );
    lineEdit_Sql_Port_2->setProperty( "text", tr( "3306" ) );
    QToolTip::add( lineEdit_Sql_Port_2, trUtf8( "\x53\x61\x69\x73\x69\x65\x20\x64\x75\x20\x70\x6f\x72\x74\x20\x61\x75\x71\x75\x65\x6c"
    "\x20\x6c\x61\x20\x63\x6f\x6e\x6e\x65\x78\x69\x6f\x6e\x20\x53\x51\x4c\x20\x64\x6f"
    "\x69\x74\x20\xc3\xaa\x74\x72\x65\x20\xc3\xa9\x74\x61\x62\x6c\x65\x20\x28\x68\x61"
    "\x62\x69\x74\x75\x65\x6c\x6c\x65\x6d\x65\x6e\x74\x20\x33\x33\x30\x36\x29" ) );
    pushButton_FavPlus_2->setProperty( "text", QString::null );
    pushButton_FavPlus_2->setProperty( "accel", QKeySequence( QString::null ) );
    QToolTip::add( pushButton_FavPlus_2, tr( "Ajouter l'adresse IP aux favoris" ) );
    QToolTip::add( lineEdit_Hostname_2, trUtf8( "\x43\x65\x20\x70\x65\x75\x74\x20\xc3\xaa\x74\x72\x65\x20\xc2\xab\x20\x6c\x6f\x63\x61"
    "\x6c\x68\x6f\x73\x74\x20\xc2\xbb\x20\x3c\x62\x72\x3e\x70\x6f\x75\x72\x20\x75\x6e"
    "\x65\x20\x62\x61\x73\x65\x20\x6c\x6f\x63\x61\x6c\x65\x2c\x20\x6f\x75\x20\x75\x6e"
    "\x65\x20\x61\x64\x72\x65\x73\x73\x65\x20\xc3\xa0\x20\x71\x75\x61\x74\x72\x65\x20"
    "\x6e\x6f\x6d\x62\x72\x65\x73\x20\x28\x63\x6f\x6d\x6d\x65\x20\x31\x39\x32\x2e\x31"
    "\x36\x38\x2e\x30\x2e\x31\x29\x2c\x20\x6f\x75\x20\x75\x6e\x20\x6e\x6f\x6d\x20\x64"
    "\x65\x20\x6d\x61\x63\x68\x69\x6e\x65" ) );
    pushButtonRemove_2->setProperty( "text", QString::null );
    pushButtonRemove_2->setProperty( "accel", QKeySequence( QString::null ) );
    QToolTip::add( pushButtonRemove_2, tr( "Retirer l'adresse IP des favoris" ) );
    textLabel1_3_2_2->setProperty( "text", tr( "Port :" ) );
    QToolTip::add( textLabel1_3_2_2, tr( "Le port du casque est obligatoire." ) );
    textLabel1_2_2->setProperty( "text", tr( "&Nom ou adresse IP :" ) );
    QToolTip::add( textLabel1_2_2, trUtf8( "\x43\x65\x20\x70\x65\x75\x74\x20\xc3\xaa\x74\x72\x65\x20\xc2\xab\x20\x6c\x6f\x63\x61"
    "\x6c\x68\x6f\x73\x74\x20\xc2\xbb\x20\x3c\x62\x72\x3e\x70\x6f\x75\x72\x20\x75\x6e"
    "\x65\x20\x62\x61\x73\x65\x20\x6c\x6f\x63\x61\x6c\x65\x2c\x20\x6f\x75\x20\x75\x6e"
    "\x65\x20\x61\x64\x72\x65\x73\x73\x65\x20\xc3\xa0\x20\x71\x75\x61\x74\x72\x65\x20"
    "\x6e\x6f\x6d\x62\x72\x65\x73\x20\x28\x63\x6f\x6d\x6d\x65\x20\x31\x39\x32\x2e\x31"
    "\x36\x38\x2e\x30\x2e\x31\x29\x2c\x20\x6f\x75\x20\x75\x6e\x20\x6e\x6f\x6d\x20\x64"
    "\x65\x20\x6d\x61\x63\x68\x69\x6e\x65" ) );
    tabWidget_Nomadisme->changeTab( Serveur_nomade, tr( "Serveur nomade" ) );
    textLabel1_4_2->setProperty( "text", tr( "Nom de conne&xion :" ) );
    QToolTip::add( textLabel1_4_2, tr( "C'est le nom d'utilisateur MySQL" ) );
    QToolTip::add( lineEdit_UserName_3, tr( "C'est le nom d'utilisateur MySQL" ) );
    textLabel1_3_3_2->setProperty( "text", tr( "Mo&t de passe : " ) );
    QToolTip::add( textLabel1_3_3_2, tr( "Mot de passe d'utilisateur MySQL" ) );
    QToolTip::add( lineEdit_PassWord_3, tr( "Mot de passe d'utilisateur MySQL" ) );
    pushButton_FavPlus_3->setProperty( "text", QString::null );
    pushButton_FavPlus_3->setProperty( "accel", QKeySequence( QString::null ) );
    QToolTip::add( pushButton_FavPlus_3, tr( "Ajouter l'adresse IP aux favoris" ) );
    textLabel1_3_2_2_2->setProperty( "text", tr( "Port :" ) );
    QToolTip::add( textLabel1_3_2_2_2, tr( "Le port du casque est obligatoire." ) );
    pushButtonRemove_3->setProperty( "text", QString::null );
    pushButtonRemove_3->setProperty( "accel", QKeySequence( QString::null ) );
    QToolTip::add( pushButtonRemove_3, tr( "Retirer l'adresse IP des favoris" ) );
    QToolTip::add( lineEdit_Hostname_3, trUtf8( "\x43\x65\x20\x70\x65\x75\x74\x20\xc3\xaa\x74\x72\x65\x20\xc2\xab\x20\x6c\x6f\x63\x61"
    "\x6c\x68\x6f\x73\x74\x20\xc2\xbb\x20\x3c\x62\x72\x3e\x70\x6f\x75\x72\x20\x75\x6e"
    "\x65\x20\x62\x61\x73\x65\x20\x6c\x6f\x63\x61\x6c\x65\x2c\x20\x6f\x75\x20\x75\x6e"
    "\x65\x20\x61\x64\x72\x65\x73\x73\x65\x20\xc3\xa0\x20\x71\x75\x61\x74\x72\x65\x20"
    "\x6e\x6f\x6d\x62\x72\x65\x73\x20\x28\x63\x6f\x6d\x6d\x65\x20\x31\x39\x32\x2e\x31"
    "\x36\x38\x2e\x30\x2e\x31\x29\x2c\x20\x6f\x75\x20\x75\x6e\x20\x6e\x6f\x6d\x20\x64"
    "\x65\x20\x6d\x61\x63\x68\x69\x6e\x65" ) );
    lineEdit_Sql_Port_3->setProperty( "text", tr( "3306" ) );
    QToolTip::add( lineEdit_Sql_Port_3, trUtf8( "\x53\x61\x69\x73\x69\x65\x20\x64\x75\x20\x70\x6f\x72\x74\x20\x61\x75\x71\x75\x65\x6c"
    "\x20\x6c\x61\x20\x63\x6f\x6e\x6e\x65\x78\x69\x6f\x6e\x20\x53\x51\x4c\x20\x64\x6f"
    "\x69\x74\x20\xc3\xaa\x74\x72\x65\x20\xc3\xa9\x74\x61\x62\x6c\x65\x20\x28\x68\x61"
    "\x62\x69\x74\x75\x65\x6c\x6c\x65\x6d\x65\x6e\x74\x20\x33\x33\x30\x36\x29" ) );
    textLabel1_2_2_2->setProperty( "text", tr( "&Nom ou adresse IP :" ) );
    QToolTip::add( textLabel1_2_2_2, trUtf8( "\x43\x65\x20\x70\x65\x75\x74\x20\xc3\xaa\x74\x72\x65\x20\xc2\xab\x20\x6c\x6f\x63\x61"
    "\x6c\x68\x6f\x73\x74\x20\xc2\xbb\x20\x3c\x62\x72\x3e\x70\x6f\x75\x72\x20\x75\x6e"
    "\x65\x20\x62\x61\x73\x65\x20\x6c\x6f\x63\x61\x6c\x65\x2c\x20\x6f\x75\x20\x75\x6e"
    "\x65\x20\x61\x64\x72\x65\x73\x73\x65\x20\xc3\xa0\x20\x71\x75\x61\x74\x72\x65\x20"
    "\x6e\x6f\x6d\x62\x72\x65\x73\x20\x28\x63\x6f\x6d\x6d\x65\x20\x31\x39\x32\x2e\x31"
    "\x36\x38\x2e\x30\x2e\x31\x29\x2c\x20\x6f\x75\x20\x75\x6e\x20\x6e\x6f\x6d\x20\x64"
    "\x65\x20\x6d\x61\x63\x68\x69\x6e\x65" ) );
    tabWidget_Nomadisme->changeTab( TabPage, tr( "&Reverse" ) );
    pushButton_APropos->setProperty( "text", QString::null );
    pushButton_APropos->setProperty( "accel", QKeySequence( QString::null ) );
    checkBox_Nomadisme->setProperty( "text", tr( "Nomadisme actif" ) );
    checkBox_Nomadisme->setProperty( "accel", QKeySequence( QString::null ) );
    pushButtonConnexionAppl->setProperty( "text", trUtf8( "\x53\x65\x20\x63\x6f\x6e\x6e\x65\x63\x74\x65\x72\x20\x26\xc3\xa0\x20\x6c\x61\x20\x62"
    "\x61\x73\x65\x20\x64\x65\x20\x64\x6f\x6e\x6e\xc3\xa9\x65\x73" ) );
    pushButtonConnexionAppl->setProperty( "accel", QKeySequence( trUtf8( "\x41\x6c\x74\x2b\xc3\xa0" ) ) );
}

