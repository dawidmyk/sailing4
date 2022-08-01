#pragma once

#include "PartialMark.hpp"
#include <QString>

class Mark {
	private:
	int points;
	int totalPoints;
	
	public:
	Mark();
	void add(PartialMark mark);
	
	int getPoints() const;
	
	int getTotalPoints() const;
	
};

QString toString(Mark mark);
