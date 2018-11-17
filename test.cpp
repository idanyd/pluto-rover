#include "gtest/gtest.h"

#include "..\PlutoRover\PlutoRover.h"

TEST(PlutoRoverTest, TestStartPosition) {

	PlutoRover rover;

	PlutoRover::Position position(0, 0, 'N');

	EXPECT_EQ(position, rover.GetPos());
}