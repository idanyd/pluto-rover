#include "gtest/gtest.h"

#include "..\PlutoRover\PlutoRover.h"

#include <vector>

TEST(PlutoRoverTest, TestStartPosition) {

	PlutoRover rover(10, 10);

	PlutoRover::Position position(0, 0, 'N');

	ASSERT_EQ(position, rover.GetPos());
}

TEST(PlutoRoverTest, TestForwardCommand) {

	PlutoRover rover(10, 10);

	PlutoRover::Position position(0, 1, 'N');

	std::string commands("F");
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}

TEST(PlutoRoverTest, TestSimpleCommand) {

	PlutoRover rover(10, 10);

	PlutoRover::Position position(2, 2, 'E');

	std::string commands("FFRFF");
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}

TEST(PlutoRoverTest, TestSimpleCommandWithUnhandledcharacters) {

	PlutoRover rover(10, 10);

	PlutoRover::Position position(2, 2, 'E');

	std::string commands("Ff2F7jR<>qF88888888kljahdf*F+*/!£$%"); // Same as "FFRFF"
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}

TEST(PlutoRoverTest, TestChainedCommands) {

	PlutoRover rover(10, 10);

	PlutoRover::Position position(1, 5, 'N');

	std::string commands1("FFRFF");
	std::string commands2("LLFRFFF");
	rover.Go(commands1);
	rover.Go(commands2);

	ASSERT_EQ(position, rover.GetPos());
}

TEST(PlutoRoverTest, TestWrapping) {

	PlutoRover rover(10, 10);

	PlutoRover::Position position(0, 9, 'N');


	std::string commands("B");
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}

TEST(PlutoRoverTest, TestComplexWrapping) {

	PlutoRover rover(10, 10);

	PlutoRover::Position position(0, 0, 'N');


	std::string commands("BRBRBRBR");
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}

// verifies that the code doesn't overflow for large grids
TEST(PlutoRoverTest, TestGridOverflow) {

	PlutoRover rover(ULONG_MAX, ULONG_MAX);

	PlutoRover::Position position(0, 0, 'N');

	std::string commands("BRBRBRBR");
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}
