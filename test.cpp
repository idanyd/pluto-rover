#include "gtest/gtest.h"

#include "..\PlutoRover\PlutoRover.h"

#include <vector>

class PlutoRoverTest : public testing::Test {
public:
	std::vector<std::vector<uint8_t>> grid;
	PlutoRover rover;
	PlutoRoverTest() : grid(10, std::vector<uint8_t>(10)), rover(grid) {}
};

TEST_F(PlutoRoverTest, TestStartPosition) {

	PlutoRover::Position position(0, 0, 'N');

	ASSERT_EQ(position, rover.GetPos());
}

TEST_F(PlutoRoverTest, TestForwardCommand) {

	PlutoRover::Position position(0, 1, 'N');

	std::string commands("F");
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}

TEST_F(PlutoRoverTest, TestSimpleCommand) {

	PlutoRover::Position position(2, 2, 'E');

	std::string commands("FFRFF");
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}

TEST_F(PlutoRoverTest, TestSimpleCommandWithUnhandledcharacters) {

	PlutoRover::Position position(2, 2, 'E');

	std::string commands("Ff2F7jR<>qF88888888kljahdf*F+*/!£$%"); // Same as "FFRFF"
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}

TEST_F(PlutoRoverTest, TestChainedCommands) {

	PlutoRover::Position position(1, 5, 'N');

	std::string commands1("FFRFF");
	std::string commands2("LLFRFFF");
	rover.Go(commands1);
	rover.Go(commands2);

	ASSERT_EQ(position, rover.GetPos());
}

TEST_F(PlutoRoverTest, TestWrapping) {

	PlutoRover::Position position(0, 9, 'N');

	std::string commands("B");
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}

TEST_F(PlutoRoverTest, TestComplexWrapping) {

	PlutoRover::Position position(0, 0, 'N');

	std::string commands("BRBRBRBR");
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}

TEST_F(PlutoRoverTest, TestObstacles) {

	// Create a 3X3 grid with an obstacle in its centre
	std::vector<std::vector<uint8_t>> grid{ {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };

	PlutoRover rover(grid);

	PlutoRover::Position position(0, 1, 'E');

	std::string commands("FRFF");
	rover.Go(commands);

	ASSERT_EQ(position, rover.GetPos());
}
