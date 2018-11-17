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

TEST(PlutoRoverTest, TestSimpleCommand) {

	PlutoRover rover;

	PlutoRover::Position position(2, 2, 'E');

	std::string commands("FFRFF");
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}

TEST(PlutoRoverTest, TestSimpleCommandWithUnhandledcharacters) {

	PlutoRover rover;

	PlutoRover::Position position(2, 2, 'E');

	std::string commands("Ff2F7jR<>qF88888888kljahdf*F+*/!£$%"); // Same as "FFRFF"
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}

TEST(PlutoRoverTest, TestChainedCommands) {

	PlutoRover rover;

	PlutoRover::Position position(1, 5, 'N');

	std::string commands1("FFRFF");
	std::string commands2("LLFRFFF");
	rover.Go(commands1);
	rover.Go(commands2);

	ASSERT_EQ(position, rover.GetPos());
}
