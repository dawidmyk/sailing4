#pragma once

class PartialMark {
	private:
	int points;
	int totalPoints;
	
	public:
	PartialMark(int points, int totalPoints);
	
	int getPoints() const;
	
	int getTotalPoints() const;
	
};
