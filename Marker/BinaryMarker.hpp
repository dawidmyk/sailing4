#pragma once

#include "Marker.hpp"

class BinaryMarker : public Marker {
    public:
    PartialMark mark(ConstQuestionPointer question, ConstSolutionPointer solution) const override;
};