#pragma once

#include "Seeker.hpp"

class CurrentDirSeeker : public Seeker {
	
	public:
	StringListPointer takeEntryList() override;
	
	~CurrentDirSeeker() override;
	
};
