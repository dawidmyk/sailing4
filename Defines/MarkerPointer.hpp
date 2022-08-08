#pragma once

#include "Marker/Marker.hpp"
#include <memory>

typedef Marker * MarkerPointer;

typedef const Marker * ConstMarkerPointer;

typedef std::unique_ptr<Marker> MarkerUniquePointer;
