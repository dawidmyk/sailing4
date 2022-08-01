#include "Mark.hpp"

Mark::Mark(): points(0), totalPoints(0)
	{
	}
	
void Mark::add(const PartialMark partialMark) {
	this->points += partialMark.getPoints();
	this->totalPoints += partialMark.getTotalPoints();
}

int Mark::getPoints() const {
	return points;
}

int Mark::getTotalPoints() const {
	return totalPoints;
}

QString toString(const Mark mark) {
	return QString::number(mark.getPoints()) + QString("/") + QString::number(mark.getTotalPoints());
}
