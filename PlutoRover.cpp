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

void PlutoRover::GoForward()
{
	switch (m_position.m_heading) {
	case 'N':
		++m_position.m_y;
		break;
	case 'E':
		++m_position.m_x;
		break;
	case 'S':
		--m_position.m_y;
		break;
	case 'W':
		--m_position.m_x;
		break;
	default:
		break;
	}
}

void PlutoRover::GoBack()
{
	switch (m_position.m_heading) {
	case 'N':
		--m_position.m_y;
		break;
	case 'E':
		--m_position.m_x;
		break;
	case 'S':
		++m_position.m_y;
		break;
	case 'W':
		++m_position.m_x;
		break;
	default:
		break;
	}
}

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
