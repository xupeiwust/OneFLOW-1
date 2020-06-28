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
#include <vector>
#include <string>
#include <fstream>
using namespace std;

BeginNameSpace( ONEFLOW )
class NodeMesh;
class FaceMesh;
class CellMesh;
class Mesh;
class DataBase;

class HXRandomClass
{
public:
    HXRandomClass();
    ~HXRandomClass();
public:
    static void Initialize();
    static int Random( int rangeMin, int rangeMax );
    static void RangeRandom( int rangeMin, int rangeMax, vector< int > & results );
};

class SimpleMesh2D
{
public:
    SimpleMesh2D();
    ~SimpleMesh2D();
public:
    int ni, nj;
    RealField2D xx;
    RealField2D yy;
    RealField2D zz;
    LinkField ijkNodeMapping;
    Mesh * mesh;
public:
    void SetMesh( Mesh * mesh ) { this->mesh = mesh; }
    void GenerateMesh();
public:
    void GenerateCircleMesh();
    void GenerateExtrapolationMesh();
    void GenerateRectangleMesh();
    void PushElement( IntField & nodeArray1, IntField & nodeArray2, int shift = 0 );
private:
    void ConstructElement();
protected:
    void GenerateCircleSurface( RealField & xArray, RealField & yArray, int ni );
    void DomputeX2Y2Array( RealField & x1Array, RealField & y1Array, RealField & x2Array, RealField & y2Array );
    void DomputeX2Y2ArrayNoLoop( RealField & x1Array, RealField & y1Array, RealField & x2Array, RealField & y2Array );
    void PushCircleNode( RealField & xArray, RealField & yArray, IntField & nodeArray );
};

class NodeMesh;
class Mesh
{
public:
    Mesh();
    ~Mesh();
public:
    NodeMesh * nodeMesh;
    FaceMesh * faceMesh;
    CellMesh * cellMesh;
    DataBase * dataBase;
public:
    void CreateMesh();
public:
    DataBase * GetDataBase() { return dataBase;  };
public:
    void ConstructTopology();
    void SwapBoundary();
    void DomputeMetrics();
    void AllocateMetrics();
private:
    void DomputeMetrics1D();
    void DomputeMetrics2D();
    void DomputeMetrics3D();
private:
    void DomputeFaceCenter1D();
    void DomputeCellCenterVol1D();
    void DomputeFaceNormal1D();
    void DomputeGhostCellCenterVol1D();
private:
    void DomputeFaceNormal2D();
    void DomputeFaceCenter2D();
    void DomputeCellCenterVol2D();
private:
    void DomputeFaceNormal3D();
    void DomputeFaceCenter3D();
    void DomputeCellCenterVol3D();
};

EndNameSpace