#pragma once

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
	PlutoRover() : m_position(0, 0, 'N') {}
	virtual ~PlutoRover() {}

	Position GetPos() { return m_position; }

private:
	Position m_position;
};


