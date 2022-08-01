#include "PartialMark.hpp"

PartialMark::PartialMark(const int points, const int totalPoints):
	points(points), totalPoints(totalPoints)
	{
	}

int PartialMark::getPoints() const {
	return points;
}
	
int PartialMark::getTotalPoints() const {
	return totalPoints;
}
