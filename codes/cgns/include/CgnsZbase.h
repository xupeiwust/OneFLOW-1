/*---------------------------------------------------------------------------*\
    OneFLOW - LargeScale Multiphysics Scientific Simulation Environment
    Copyright (C) 2017-2020 He Xin and the OneFLOW contributors.
-------------------------------------------------------------------------------
License
    This file is part of OneFLOW.

    OneFLOW is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OneFLOW is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OneFLOW.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/


#pragma once
#include "HXDefine.h"

BeginNameSpace( ONEFLOW )

#ifdef ENABLE_CGNS

class CgnsBase;
class CgnsZone;
class GridMediator;
class GridMediatorS;

class CgnsZbase
{
public:
    CgnsZbase ();
    ~CgnsZbase();
public:
    int fileId, nBases;
 
    HXVector< CgnsBase * > baseVector;
public:
    int GetSystemZoneType();
    void ReadCgnsGrid();
    void DumpCgnsGrid( GridMediatorS * gridMediators );
    void ReadCgnsGrid( const string & fileName );
    void OpenCgnsFile( const string & fileName, int cgnsOpenMode );
    void CloseCgnsFile();
    void ReadCgnsMultiBase();
    void DumpCgnsMultiBase( GridMediatorS * gridMediatorS );
    void ReadNumCgnsBase();

    void ReadCgnsMultiBase( CgnsZbase * strCgnsMultiBase );
public:
    void CreateDefaultCgnsZones( GridMediatorS * gridMediatorS );
    void PrepareCgnsZone( GridMediatorS * gridMediatorS );
    void AddCgnsBase( CgnsBase * cgnsBase );
    void InitCgnsBase();
    void ConvertStrCgns2UnsCgnsGrid( CgnsZbase * strCgnsMultiBase );
public:
    int GetNZone();
    CgnsBase * GetCgnsBase( int iBase );
    CgnsZone * GetCgnsZone( int globalZoneId );
    CgnsZone * GetMultiBaseCgnsZone( int iBase, int iZone );
};

#endif

EndNameSpace