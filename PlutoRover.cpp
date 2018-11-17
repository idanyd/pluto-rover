#include "PlutoRover.h"

void PlutoRover::Go(const std::string& commands)
{
	for (auto command : commands) {
		switch (command) {
		case 'F':
			GoForward();
			break;
		case 'B':
			GoBack();
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
	}
}

// Move one square forward, taking wrapping into consideration
void PlutoRover::GoForward()
{
	switch (m_position.m_heading) {
	case 'N':
		if (m_position.m_y == m_grid_y - 1)
			m_position.m_y = 0;
		else
			++m_position.m_y;
		break;
	case 'E':
		if (m_position.m_x == m_grid_x - 1)
			m_position.m_x = 0;
		else
			++m_position.m_x;
		break;
	case 'S':
		if (m_position.m_y == 0)
			m_position.m_y = m_grid_y - 1;
		else
			--m_position.m_y;
		break;
	case 'W':
		if (m_position.m_x == 0)
			m_position.m_x = m_grid_x - 1;
		else
			--m_position.m_x;
		break;
	default:
		break;
	}
}

// Move one square back, taking wrapping into consideration
void PlutoRover::GoBack()
{
	switch (m_position.m_heading) {
	case 'N':
		if (m_position.m_y == 0)
			m_position.m_y = m_grid_y - 1;
		else
			--m_position.m_y;
		break;
	case 'E':
		if (m_position.m_x == 0)
			m_position.m_x = m_grid_x - 1;
		else
			--m_position.m_x;
		break;
	case 'S':
		if (m_position.m_y == m_grid_y - 1)
			m_position.m_y = 0;
		else
			++m_position.m_y;
		break;
	case 'W':
		if (m_position.m_x == m_grid_x - 1)
			m_position.m_x = 0;
		else
			++m_position.m_x;
		break;
	default:
		break;
	}
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
