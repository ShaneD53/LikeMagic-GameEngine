// LikeMagic C++ Binding Library
// Copyright 2008-2011 Dennis Ferron
// Co-founder DropEcho Studios, LLC.
// Visit our website at dropecho.com.
//
// LikeMagic is BSD-licensed.
// (See the license file in LikeMagic/Licenses.)

#pragma once

#include "irrlicht.h"

#include <map>

class btSoftBody;

namespace Bindings { namespace Custom {

class MeshTools
{
private:

    static irr::core::vector3df MeshTools::cutLineX(irr::core::line3df const& line, float xMin, float xMax);
    static irr::core::vector3df MeshTools::cutLineY(irr::core::line3df const& line, float yMin, float yMax);
    static irr::core::vector3df MeshTools::cutLineZ(irr::core::line3df const& line, float zMin, float zMax);

public:

    class LinkSplitter
    {
    private:
        irr::core::aabbox3df box;
        irr::scene::IMeshBuffer* oldMeshBuf;
        irr::scene::IMeshBuffer* newMeshBuf;
        std::map<pair<int, int>, int> oldLinksToNewIndices;  // Key is 2 old indices, Value is index in new meshbuf

    public:
        std::vector<int> splitB(int a, int b, int c);
    };

    static irr::scene::IMesh* createMeshFromSoftBody(btSoftBody* softBody);
    static btSoftBody* createSoftBodyFromMesh(btSoftBodyWorldInfo& worldInfo, irr::scene::IMesh* mesh);
    static irr::video::S3DVertex& getBaseVertex(irr::scene::IMeshBuffer* meshBuf, int n);
    static IMesh* sliceMesh(IMesh* mesh, irr::core::aabbox3df bounds);

    // Given a line in which the endpoint is in the box and the start point is outside it,
    // returns the point on the line where the box cuts it.
    // If the start point was actually inside the box, returns the start point.
    static line3df cutLine(line3df line, aabbox3df box);

    // Allows you to define a function on X and then re-use it to do Y and Z.
    inline vector3df rotateVector(vector3df const& vect)
    {
        return vector3df(vect.Y, vect.Z, vect.X);
    }

    template <typename T>
    inline T scaledAverage(float scale, T a, T b)
    {
        return static_cast<T>((scale*a + (1.0f-scale)*b) / 2.0f);
    }
};

}}