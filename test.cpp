#include "gtest/gtest.h"

#include "..\PlutoRover\PlutoRover.h"

TEST(PlutoRoverTest, TestStartPosition) {

	PlutoRover rover;

	PlutoRover::Position position(0, 0, 'N');

	ASSERT_EQ(position, rover.GetPos());
}

TEST(PlutoRoverTest, TestForwardCommand) {

	PlutoRover rover;

	PlutoRover::Position position(0, 1, 'N');

	std::string commands("F");
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}
