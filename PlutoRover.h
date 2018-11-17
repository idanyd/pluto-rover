#pragma once

#include <string>
#include <vector>

class PlutoRover
{
public:

	struct Position
	{
		Position(unsigned long x, unsigned long y, const char heading) : m_x(x), m_y(y), m_heading(heading) {}

		bool operator==(const Position& rhs) const { return m_x == rhs.m_x && m_y == rhs.m_y && m_heading == rhs.m_heading; }

		unsigned long m_x;
		unsigned long m_y;
		char m_heading;
	};
	
public:
	// A rover must know the size of the grid on the planet it's on. 
	// Any non-zero value means there's a obstacle on that square,
	// and the rover can't move there
	PlutoRover(const std::vector<std::vector<uint8_t>>& grid) : 
		m_position(0, 0, 'N'), m_grid(grid) {}

	virtual ~PlutoRover() {}

	// Use this method to get the rover's current position
	// The returned format is (x, y, heading)
	Position GetPos() { return m_position; }

	// Use this method to give the rover commands. 
	// The commands are:
	// 'F' - move forward by 1 square
	// 'B' - move back by 1 square
	// 'L' - Turn 90 degrees left
	// 'L' - Turn 90 degrees right
	// Any other character will be ignored by the rover
	// The rover stops as soon as it hits an obstacle
	void Go(const std::string& commands);

private:
	bool GoForward();
	bool GoBack();
	void TurnLeft();
	void TurnRight();

private:
	Position m_position;
	std::vector<std::vector<uint8_t>> m_grid;
};


