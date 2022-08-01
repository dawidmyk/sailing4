#pragma once

#include "Defines/StringListPointer.hpp"

class Seeker {
	
	public:
	virtual StringListPointer takeEntryList() = 0;
	
	virtual ~Seeker();
	
};
