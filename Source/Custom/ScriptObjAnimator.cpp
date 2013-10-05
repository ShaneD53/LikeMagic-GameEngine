// LikeMagic C++ Binding Library
// Copyright 2008-2013 Dennis Ferron
// Co-founder DropEcho Studios, LLC.
// Visit our website at dropecho.com.
//
// LikeMagic is BSD-licensed.
// (See the license file in LikeMagic/Licenses.)

#include "Bindings/Custom/ScriptObjAnimator.hpp"
#include "Bindings/Custom/CustomAnimatorTypes.hpp"

// TODO:  Fix this
//#include "IoObject.h"

#include <stdexcept>

using namespace irr;
using namespace irr::core;
using namespace irr::scene;

using namespace Bindings::Custom;

ScriptObjAnimator::ScriptObjAnimator(IoObject* io_obj_)
    : io_obj(io_obj_) {}


void ScriptObjAnimator::mark() const
{
    // TODO:  Fix this
    //IoObject_shouldMarkIfNonNull(io_obj);
}


IoObject* ScriptObjAnimator::getScriptObj() const
{
    return io_obj;
}


void ScriptObjAnimator::animateNode(ISceneNode* node, u32 timeMs)
{
    // Does nothing; maybe in the future I'll add a Script Block call.
}


ISceneNodeAnimator* ScriptObjAnimator::createClone(ISceneNode* node, ISceneManager* newManager)
{
    throw std::runtime_error("createClone not implemented.");
}

ScriptObjAnimator* ScriptObjAnimator::findIn(irr::scene::ISceneNode* node)
{
    for(auto it=node->getAnimators().begin(); it!=node->getAnimators().end(); ++it)
        if( (*it)->getType() == static_cast<irr::scene::ESCENE_NODE_ANIMATOR_TYPE>(C_ESNAT_SCRIPT_OBJ))
            return dynamic_cast<ScriptObjAnimator*>(*it);

    return NULL;
}

ESCENE_NODE_ANIMATOR_TYPE ScriptObjAnimator::getType() const
{
    return static_cast<ESCENE_NODE_ANIMATOR_TYPE>(C_ESNAT_SCRIPT_OBJ);
}
