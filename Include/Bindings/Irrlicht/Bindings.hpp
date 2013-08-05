// LikeMagic C++ Binding Library
// Copyright 2008-2013 Dennis Ferron
// Co-founder DropEcho Studios, LLC.
// Visit our website at dropecho.com.
//
// LikeMagic is BSD-licensed.
// (See the license file in LikeMagic/Licenses.)


#pragma once

#include "LikeMagic/Utility/DLLHelper.hpp"

namespace LikeMagic { class RuntimeTypeSystem; }

namespace Iocaste { namespace LikeMagicAdapters {
    class IoVM;
}}


namespace Bindings { namespace Irrlicht {

DLL_PUBLIC void add_bindings(LikeMagic::RuntimeTypeSystem& type_sys);

void add_bindings_irr(LikeMagic::RuntimeTypeSystem& type_sys);
void add_bindings_gui(LikeMagic::RuntimeTypeSystem& type_sys);
void add_bindings_video(LikeMagic::RuntimeTypeSystem& type_sys);
void add_bindings_scene(LikeMagic::RuntimeTypeSystem& type_sys);
void add_bindings_core(LikeMagic::RuntimeTypeSystem& type_sys);
void add_bindings_custom(LikeMagic::RuntimeTypeSystem& type_sys);
void add_bindings_irr_io(LikeMagic::RuntimeTypeSystem& type_sys);

void add_bindings_orientation(LikeMagic::RuntimeTypeSystem& type_sys);

void add_protos_irr(Iocaste::LikeMagicAdapters::IoVM& vm);

}}
