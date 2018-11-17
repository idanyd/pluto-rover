#include "PlutoRover.h"

void PlutoRover::Go(const std::string& commands)
{
	for (auto command : commands) {
		bool success = true;
		switch (command) {
		case 'F':
			success = GoForward();
			break;
		case 'B':
			success = GoBack();
			break;
		case 'L':
			TurnLeft();
			break;
		case 'R':
			TurnRight();
			break;
		default:
			break;
		}

		if (!success)
			break;
	}
}

// Move one square forward, taking wrapping and obstacles into consideration
bool PlutoRover::GoForward()
{
	bool success = false;

	Position new_position(m_position);

	switch (new_position.m_heading) {
	case 'N':
		if (new_position.m_y == m_grid[new_position.m_x].size() - 1)
			new_position.m_y = 0;
		else
			++new_position.m_y;
		break;
	case 'E':
		if (new_position.m_x == m_grid.size() - 1)
			new_position.m_x = 0;
		else
			++new_position.m_x;
		break;
	case 'S':
		if (new_position.m_y == 0)
			new_position.m_y = m_grid[new_position.m_x].size() - 1;
		else
			--new_position.m_y;
		break;
	case 'W':
		if (new_position.m_x == 0)
			new_position.m_x = m_grid.size() - 1;
		else
			--new_position.m_x;
		break;
	default:
		break;
	}

	if (m_grid[new_position.m_x][new_position.m_y] == 0) {
		m_position = new_position;
		success = true;
	}
	
	return success;	
}

// Move one square back, taking wrapping and obstacles into consideration
bool PlutoRover::GoBack()
{
	bool success = false;

	Position new_position(m_position);

	switch (new_position.m_heading) {
	case 'N':
		if (new_position.m_y == 0)
			new_position.m_y = m_grid[new_position.m_x].size() - 1;
		else
			--new_position.m_y;
		break;
	case 'E':
		if (new_position.m_x == 0)
			new_position.m_x = m_grid.size() - 1;
		else
			--new_position.m_x;
		break;
	case 'S':
		if (new_position.m_y == m_grid[new_position.m_x].size() - 1)
			new_position.m_y = 0;
		else
			++new_position.m_y;
		break;
	case 'W':
		if (new_position.m_x == m_grid.size() - 1)
			new_position.m_x = 0;
		else
			++new_position.m_x;
		break;
	default:
		break;
	}

	if (m_grid[new_position.m_x][new_position.m_y] == 0) {
		m_position = new_position;
		success = true;
	}

	return success;
}

// Make a 90 degrees right turn
void PlutoRover::TurnRight()
{
	switch (m_position.m_heading) {
	case 'N':
		m_position.m_heading = 'E';
		break;
	case 'E':
		m_position.m_heading = 'S';
		break;
	case 'S':
		m_position.m_heading = 'W';
		break;
	case 'W':
		m_position.m_heading = 'N';
		break;
	default:
		break;
	}
}

// Make a 90 degrees left turn
void PlutoRover::TurnLeft()
{
	switch (m_position.m_heading) {
	case 'N':
		m_position.m_heading = 'W';
		break;
	case 'E':
		m_position.m_heading = 'N';
		break;
	case 'S':
		m_position.m_heading = 'E';
		break;
	case 'W':
		m_position.m_heading = 'S';
		break;
	default:
		break;
	}
}
