
/***************************************************************************
 *   Copyright (C) 2004 by Sébastien SIVERA & Sevin Roland                 *
 *   upsis@club-internet.fr                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "C_ClickableLed.h"
#include <QMouseEvent>

	static const char * gray_xpm[]={
	/* width height num_colors chars_per_pixel */
	"    17    17      128            2",
	/* colors */
	"`` c none",
	"`. c #ffffff",
	"`# c #000000",
	"`a c #010101",
	"`b c #080808",
	"`c c #444444",
	"`d c #696969",
	"`e c #7e7e7e",
	"`f c #5f5f5f",
	"`g c #363636",
	"`h c #060606",
	"`i c #4a4a4a",
	"`j c #9a9a9a",
	"`k c #a2a2a2",
	"`l c #9b9b9b",
	"`m c #8b8b8b",
	"`n c #818181",
	"`o c #777777",
	"`p c #666666",
	"`q c #2a2a2a",
	"`r c #424242",
	"`s c #636363",
	"`t c #b0b0b0",
	"`u c #bbbbbb",
	"`v c #b9b9b9",
	"`w c #adadad",
	"`x c #989898",
	"`y c #868686",
	"`z c #6b6b6b",
	"`A c #656565",
	"`B c #343434",
	"`C c #020202",
	"`D c #474747",
	"`E c #c4c4c4",
	"`F c #cccccc",
	"`G c #c6c6c6",
	"`H c #b4b4b4",
	"`I c #9f9f9f",
	"`J c #858585",
	"`K c #757575",
	"`L c #6c6c6c",
	"`M c #646464",
	"`N c #5d5d5d",
	"`O c #252525",
	"`P c #0d0d0d",
	"`Q c #9d9d9d",
	"`R c #c0c0c0",
	"`S c #cfcfcf",
	"`T c #dddddd",
	"`U c #cecece",
	"`V c #737373",
	"`W c #5a5a5a",
	"`X c #515151",
	"`Y c #acacac",
	"`Z c #d3d3d3",
	"`0 c #e1e1e1",
	"`1 c #d2d2d2",
	"`2 c #b8b8b8",
	"`3 c #9e9e9e",
	"`4 c #828282",
	"`5 c #717171",
	"`6 c #6f6f6f",
	"`7 c #5b5b5b",
	"`8 c #565656",
	".` c #282828",
	".. c #767676",
	".# c #bfbfbf",
	".a c #c7c7c7",
	".b c #cbcbcb",
	".c c #a9a9a9",
	".d c #969696",
	".e c #7d7d7d",
	".f c #464646",
	".g c #888888",
	".h c #a3a3a3",
	".i c #b2b2b2",
	".j c #a6a6a6",
	".k c #6d6d6d",
	".l c #676767",
	".m c #626262",
	".n c #606060",
	".o c #6a6a6a",
	".p c #979797",
	".q c #a1a1a1",
	".r c #a0a0a0",
	".s c #919191",
	".t c #848484",
	".u c #6e6e6e",
	".v c #686868",
	".w c #414141",
	".x c #878787",
	".y c #909090",
	".z c #8c8c8c",
	".A c #7c7c7c",
	".B c #494949",
	".C c #030303",
	".D c #727272",
	".E c #808080",
	".F c #939393",
	".G c #838383",
	".H c #333333",
	".I c #707070",
	".J c #929292",
	".K c #8d8d8d",
	".L c #393939",
	".M c #3d3d3d",
	".N c #484848",
	".O c #2c2c2c",
	".P c #616161",
	".Q c #8e8e8e",
	".R c #373737",
	".S c #5c5c5c",
	".T c #000000",
	".U c #000000",
	".V c #000000",
	".W c #000000",
	".X c #000000",
	".Y c #000000",
	".Z c #000000",
	".0 c #000000",
	".1 c #000000",
	".2 c #000000",
	".3 c #000000",
	".4 c #000000",
	".5 c #000000",
	".6 c #000000",
	".7 c #000000",
	".8 c #000000",
	/* pixels */
	"```````````.`#`#`#`#`#````````````",
	"```````.`a`b`c`d`e`f`g`a`#````````",
	"`````.`h`i`j`k`l`m`n`o`p`q`#``````",
	"`````r`s`t`u`v`w`x`y`o`z`A`B`#````",
	"```C`D`t`E`F`G`H`I`J`K`L`M`N`O`#``",
	"```P`Q`R`S`T`U`v`I`J`V`L`A`W`X`#``",
	"`#`i`Y`G`Z`0`1`2`3`4`5`6`p`7`8.``#",
	"`#..`Y.#.a.b.#.c.d.e`6`d`M`W`8.f`#",
	"`#.g.h`t.i`t.j`x`y`K.k.l.m.n.l`p`#",
	"`#.o.p.q.r`x.s.t`o.k`p.m.m.u`4.v`#",
	"`#.w.x.y.z`y.A`o.k.l`M`A`L.t.y.B`#",
	"``.C.D.e.A`o...k.o`s`s`6.E.F.G.C``",
	"```#.H.k.I.u.o.v`M`M`V.x.J.K.L`#``",
	"`````#.M.m.m`M`M`A`K.x.F`m.N`#````",
	"```````#.O`8.P`z`o.t.Q`e`g`#``````",
	"`````````#`a.R.S..`d`r.C`#````````",
	"`````````````#`#`#`#`#````````````"
    };
    static const char * red_xpm[]={
        /* width height num_colors chars_per_pixel */
        "    17    17      128            2",
        /* colors */
        "`` c #340204",
        "`. c #ec8276",
        "`# c #941204",
        "`a c #ac463c",
        "`b c #c40e04",
        "`c c #c43220",
        "`d c #c46a64",
        "`e c #ec0e04",
        "`f c #f4c2bc",
        "`g c #d44e40",
        "`h c #c41e0c",
        "`i c #8c261c",
        "`j c #e42a14",
        "`k c #eca294",
        "`l c #dc665c",
        "`m c #545654",
        "`n c #640a04",
        "`o c #d41204",
        "`p c #e45a4c",
        "`q c #ec7664",
        "`r c #b40a04",
        "`s c #dc361c",
        "`t c #ec928c",
        "`u c #bc5e54",
        "`v c #7c0e04",
        "`w c #cc3a28",
        "`x c #d41e0c",
        "`y c #bc2614",
        "`z c #dc6e64",
        "`A c #c41604",
        "`B c #ec2614",
        "`C c #e44e44",
        "`D c #a4362c",
        "`E c #f4b2ac",
        "`F c #b41a0c",
        "`G c #7c1a0c",
        "`H c #d42a14",
        "`I c #e41604",
        "`J c #dc4e40",
        "`K c #c42618",
        "`L c #ec361c",
        "`M c #1c1a1c",
        "`N c #ec8a80",
        "`O c #c4463c",
        "`P c #bc7264",
        "`Q c none",
        "`R c #8c2e24",
        "`S c #ec321c",
        "`T c #e46658",
        "`U c #d41a04",
        "`V c #dc6254",
        "`W c #bc1204",
        "`X c #e43e2c",
        "`Y c #ec9e98",
        "`Z c #bc6258",
        "`0 c #cc1604",
        "`1 c #941608",
        "`2 c #f4d2cc",
        "`3 c #d4524c",
        "`4 c #cc1e04",
        "`5 c #ec2e14",
        "`6 c #ecaaa4",
        "`7 c #ac1204",
        "`8 c #e43620",
        ".` c #841208",
        ".. c #b43a2c",
        ".# c #341214",
        ".a c #bc5244",
        ".b c #f4dedc",
        ".c c #340e0c",
        ".d c #cc726c",
        ".e c #f41a04",
        ".f c #e47e74",
        ".g c #740a04",
        ".h c #cc2e14",
        ".i c #d42614",
        ".j c #a43e34",
        ".k c #f4bab4",
        ".l c #d4321c",
        ".m c #942614",
        ".n c #e46e60",
        ".o c #bc1604",
        ".p c #841e14",
        ".q c #c47264",
        ".r c #9c0e04",
        ".s c #cc1204",
        ".t c #eca6a4",
        ".u c #dc1204",
        ".v c #dc3a2c",
        ".w c #c45a54",
        ".x c #840a04",
        ".y c #ec1604",
        ".z c #f4aea4",
        ".A c #c44e44",
        ".B c #d43a2c",
        ".C c #e46250",
        ".D c #6c0a04",
        ".E c #dc1a04",
        ".F c #b41204",
        ".G c #d45244",
        ".H c #e42e18",
        ".I c #e45e54",
        ".J c #ec7a6c",
        ".K c #ec968f",
        ".L c #c41a08",
        ".M c #f4b6b4",
        ".N c #7c1e14",
        ".O c #d42e1c",
        ".P c #ec8e84",
        ".Q c #e46a5c",
        ".R c #cc220c",
        ".S c #942a1c",
        ".T c #e47264",
        ".U c #c4766c",
        ".V c #c41204",
        ".W c #ec1204",
        ".X c #f4c6bc",
        ".Y c #c4220c",
        ".Z c #dc6a5c",
        ".0 c #d41604",
        ".1 c #b40e04",
        ".2 c #d4220c",
        ".3 c #e41a04",
        ".4 c #1c1e1c",
        ".5 c #8c3224",
        ".6 c #cc1a04",
        ".7 c #c45e54",
        ".8 c #c45244",
        /* pixels */
        "`Q`Q`Q`Q`Q`Q`M`M`M`M`M`Q`Q`Q`Q`Q`Q",
        "`Q`Q`Q`Q`M.c`1`K.H`A.x```M`Q`Q`Q`Q",
        "`Q`Q`Q.4.S`l.n`V`J`j`I.0.g`M`Q`Q`Q",
        "`Q`Q`m`a`..K.K.f.I`X`I.u.s`v`M`Q`Q",
        "`Q.4.5`..t.M.t`N`T`8`I.u`0.o`n`M`Q",
        "`Q.#.Q`k`f`2.k.K`T`S.3.0.s`W`7```Q",
        "`M.m.f.t`f.b.X`t.C`B.3`o.s`W`r.D`M",
        "`M`w`.`Y.z`E`Y`q`C.e.E`0.V.1.1.r`M",
        "`M`g.n`N`N.f`q`p`S.3.0`0.V`b`4`y`M",
        "`M.h`V.Z.Z.I`J`8`e`o`0.V.V.h.A..`M",
        "`M`#.A`3`J.v`j`e.u.s.V`A`x.w.q`i`M",
        "`Q``.O.B`s`j`I.u`0.V.s.2.G.U`Z```Q",
        "`Q`M.`.R`H.2`U`o`0.s.O.7.q`d.N`M`Q",
        "`Q`Q`M`#.Y.L.6`A`4`w.7.U`d`i`M`Q`Q",
        "`Q`Q`Q`M.g`F`y`c`O`Z`P`u`G`M`Q`Q`Q",
        "`Q`Q`Q`Q`M``.x`D.a`a.p```M`Q`Q`Q`Q",
        "`Q`Q`Q`Q`Q`Q`M`M`M`M`M`Q`Q`Q`Q`Q`Q"
    };
    static const char * green_xpm[]={
        /* width height num_colors chars_per_pixel */
        "    17    17      128            2",
        /* colors */
        "`` c #040204",
        "`. c #248604",
        "`# c #94d27c",
        "`a c #4cae2c",
        "`b c #548244",
        "`c c #2c9a04",
        "`d c #1c460c",
        "`e c #3c822c",
        "`f c #74be54",
        "`g c #1c660c",
        "`h c #54a234",
        "`i c #449e24",
        "`j c #d4eac4",
        "`k c #3c921c",
        "`l c #6ca25c",
        "`m c #b4dea4",
        "`n c #444244",
        "`o c #2c9204",
        "`p c #64be44",
        "`q c #2ca20c",
        "`r c #7cca64",
        "`s c #54aa34",
        "`t c #245614",
        "`u c #a4d68c",
        "`v c #0c3a04",
        "`w c #5cae44",
        "`x c #4c823c",
        "`y c #3c8a1c",
        "`z c #447634",
        "`A c #649a54",
        "`B c #44a61c",
        "`C c #4c962c",
        "`D c #2c9604",
        "`E c #34821c",
        "`F c #349a14",
        "`G c #244614",
        "`H c #74c654",
        "`I c #3ca21c",
        "`J c #8cce74",
        "`K c #5c8e4c",
        "`L c #247a04",
        "`M c #44922c",
        "`N c #c4e2b4",
        "`O c #2c9214",
        "`P c #6cc64c",
        "`Q c #acde9c",
        "`R c #5cba44",
        "`S c #0c1204",
        "`T c #2c8a0c",
        "`U c #9cd684",
        "`V c #44a22c",
        "`W c #74aa5c",
        "`X c #bcdeac",
        "`Y c #345a24",
        "`Z c #6cbe4c",
        "`0 c #34a20c",
        "`1 c #64a654",
        "`2 c #2c5e1c",
        "`3 c #acda9c",
        "`4 c #143e04",
        "`5 c #64b248",
        "`6 c #448a2f",
        "`7 c #64a254",
        "`8 c #649654",
        ".` c #34761c",
        ".. c none",
        ".# c #54963c",
        ".a c #5c9e4c",
        ".b c #144e04",
        ".c c #348a0c",
        ".d c #4ca62c",
        ".e c #040a04",
        ".f c #5caa40",
        ".g c #7cc664",
        ".h c #54ae34",
        ".i c #7cc25c",
        ".j c #84ca64",
        ".k c #2c561c",
        ".l c #4c7a3c",
        ".m c #348e16",
        ".n c #74a65c",
        ".o c #34960c",
        ".p c #1c4e0c",
        ".q c #248a04",
        ".r c #2c9e0c",
        ".s c #3c8627",
        ".t c #74c25c",
        ".u c #44a221",
        ".v c #d4eecc",
        ".w c #3c961c",
        ".x c #a4da8c",
        ".y c #649e51",
        ".z c #44aa24",
        ".A c #349e14",
        ".B c #244a18",
        ".C c #8cd274",
        ".D c #5c9244",
        ".E c #247e08",
        ".F c #bce2af",
        ".G c #345e24",
        ".H c #6cc254",
        ".I c #34a614",
        ".J c #84ce6c",
        ".K c #040604",
        ".L c #0c3e04",
        ".M c #5cb244",
        ".N c #3ca61c",
        ".O c #44962c",
        ".P c #54b234",
        ".Q c #2c5a1c",
        ".R c #24860c",
        ".S c #94d284",
        ".T c #2c9a0c",
        ".U c #54a23c",
        ".V c #3c9224",
        ".W c #2c920c",
        ".X c #a4d694",
        ".Y c #3c8a24",
        ".Z c #4c9634",
        ".0 c #349a1c",
        ".1 c #74c65c",
        ".2 c #8cce7c",
        ".3 c #9cd68c",
        ".4 c #74aa64",
        ".5 c #345a2c",
        ".6 c #6cbe54",
        ".7 c #34a214",
        ".8 c #143e0c",
        /* pixels */
        "............``````````............",
        "........``.e.Q.Y.d`E.p````........",
        ".......K.G`f.1`f.M.d.u.m`4``......",
        "....`n.l`J.3`U.j.6.h`i.w.c.b``....",
        "..``.5.C`3`m`3`#.1.h`I.w.m`T`v``..",
        "..`S`f.x.F`j`X.S`H`a`I.A`O.R`L``..",
        "``.G.J`3.F`j.F.S`P.h.7`0.o`..E.L``",
        "``.Z.j.X`Q`m.x.j`p.z.7`c`D`..E`g``",
        "```w.g.2.2`J.g.H.P.N`q.T`o`T`6.s``",
        "```6`p.i.i`p`R`a`B.r`c`o`T`M.a`x``",
        "```t.f`5.M.f.d.u.A`D`D.W.V.y`W`Y``",
        "...K.Z.U`h`V`i.0`F.W`O.O.a.4`A.K..",
        "..```d`M`M.O`k`k`O.c.Z`7`W.n.B``..",
        "....``.p.s`E.Y`E.Y.Z`7.4`l`2``....",
        "......``.8.``e`6.D`A.n`8.B``......",
        "........`````G`z`K`b.k.K``........",
        "............``````````............"
    };

//------------------------------------------ C_ClickableLed ----------------------------------------------------------------------
C_ClickableLed::C_ClickableLed(QWidget * parent /*= 0*/,
                               ledColor color/*= Gray*/)
    : QWidget (parent)
{   m_HBoxLayout  = new QHBoxLayout(this);
    m_PixMapLabel = new QLabel(this);
    m_TextLabel   = new QLabel(this);
    setLedColor(color);
    m_HBoxLayout->setSpacing(4);
    m_HBoxLayout->addWidget(m_TextLabel);
    m_HBoxLayout->addWidget(m_PixMapLabel);
}

//------------------------------------------ ~C_ClickableLed ----------------------------------------------------------------------
C_ClickableLed::~C_ClickableLed()
{

}

//------------------------------------------ mouseReleaseEvent ----------------------------------------------------------------------
void C_ClickableLed::mouseReleaseEvent ( QMouseEvent * e )
{
    if (e->button() == Qt::LeftButton) emit clicked();
}

//------------------------------------------ setText ----------------------------------------------------------------------
void C_ClickableLed::setText(const QString &text)
{m_TextLabel->setText(text);
}

//------------------------------------------ text ----------------------------------------------------------------------
QString C_ClickableLed::text()
{return m_TextLabel->text();
}

//------------------------------------------ setLedPixmap ----------------------------------------------------------------------
void C_ClickableLed::setLedPixmap(const QPixmap &pixmap)
{ m_PixMapLabel->setPixmap(pixmap);
}

//------------------------------------------ setLedPixmap ----------------------------------------------------------------------
void C_ClickableLed::setLedPixmap(const QString &pixmapPath)
{ m_PixMapLabel->setPixmap(QPixmap(pixmapPath));
}

//------------------------------------------ setLedColor ----------------------------------------------------------------------
void C_ClickableLed::setLedColor(int color)
{

    QPixmap pixmap(gray_xpm);

    switch ((C_ClickableLed::ledColor)color) {
    case C_ClickableLed::Gray:
        break;
    case C_ClickableLed::Green:
        pixmap = green_xpm;
        break;
    case C_ClickableLed::Red:
        pixmap = red_xpm;
        break;
    }
    m_PixMapLabel->setPixmap(pixmap);
}

