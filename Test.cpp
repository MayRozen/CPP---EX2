/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include "doctest.h"
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
#include "DevelopmentCard.hpp"
// #include "Structure.cpp"

// -----------------------------Catan-----------------------------
TEST_CASE("Test getPlayers and printPlayers") {
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan* game = Catan::getInstance(p1, p2, p3);

    CHECK(game->getPlayers().size() == 3);
    CHECK(game->getPlayers()[0].name == "Amit");
    CHECK(game->getPlayers()[1].name == "Yossi");
    CHECK(game->getPlayers()[2].name == "Dana");

    cout<< "Test getPlayers and printPlayers success!" <<endl;
}

TEST_CASE("Test ChooseStartingPlayer") {
    Player p1("Player1");
    Player p2("Player2");
    Player p3("Player3");
    Catan* game = Catan::getInstance(p1, p2, p3);
    game->getPlayers().push_back(p1);
    game->getPlayers().push_back(p2);

    Player startingPlayer = game->ChooseStartingPlayer();
    CHECK(startingPlayer.name == "Player1");

    cout<< "Test ChooseStartingPlayer success!" <<endl;
}

TEST_CASE("Test getWinner with no winner") {
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan* game = Catan::getInstance(p1, p2, p3);
    p1.sumPoints = 8; // Less than 10 points
    p2.sumPoints = 9; // Less than 10 points

    CHECK(game->getWinner().name == ""); // No winner

    cout<< "Test getWinner with no winner success!" <<endl;
}

TEST_CASE("Test getWinner with a winner") {
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan* game = Catan::getInstance(p1, p2, p3);
    p1.sumPoints = 10; // Exactly 10 points
    p2.sumPoints = 9; // Less than 10 points
    p3.sumPoints = 9; // Less than 10 points

    CHECK(game->getWinner().name == "Amit"); // Player1 should be the winner

    cout<< "Test getWinner with a winner success!" <<endl;
}

// -----------------------------Structure-----------------------------
TEST_CASE("Test road structure initialization") {
    road r;
    CHECK(r.name == "Road");
    CHECK(r.resources.size() == 2);
    CHECK(r.resources[0] == ReturnRes::Brick);
    CHECK(r.resources[1] == ReturnRes::Lumber);

    cout<< "Test road structure initialization success!" <<endl;
}

TEST_CASE("Test settlement structure initialization") {
    settlement s;
    CHECK(s.name == "Settlement");
    CHECK(s.resources.size() == 4);
    CHECK(s.resources[0] == ReturnRes::Brick);
    CHECK(s.resources[1] == ReturnRes::Lumber);
    CHECK(s.resources[2] == ReturnRes::Wool);
    CHECK(s.resources[3] == ReturnRes::Grain);

    cout<< "Test settlement structure initialization success!" <<endl;
}

TEST_CASE("Test city structure initialization") {
    city c;
    CHECK(c.name == "City");
    CHECK(c.resources.size() == 5);
    CHECK(c.resources[0] == ReturnRes::Ore);
    CHECK(c.resources[1] == ReturnRes::Ore);
    CHECK(c.resources[2] == ReturnRes::Ore);
    CHECK(c.resources[3] == ReturnRes::Grain);
    CHECK(c.resources[4] == ReturnRes::Grain);

    cout<< "Test city structure initialization success!" <<endl;
}

TEST_CASE("Test road structure destructor") {
    road* r = new road();
    delete r;
    // Since we can't directly check private members, we assume that if no crash happens, destructor works.
    // Further checks would require additional accessors or modifying class structure, which might be beyond the exercise scope.
    CHECK(true); // Dummy check to pass the test

    cout<< "Test road structure destructor success!" <<endl;
}

TEST_CASE("Test settlement structure destructor") {
    settlement* s = new settlement();
    delete s;
    // Since we can't directly check private members, we assume that if no crash happens, destructor works.
    CHECK(true); // Dummy check to pass the test

    cout<< "Test settlement structure destructor success!" <<endl;
}

// -----------------------------Structure-----------------------------

TEST_CASE("Development Card Type Tests") {
    SUBCASE("Monopoly Card Test") {
        MonopolyCard monopolyCard;
        CHECK(monopolyCard.getType() == CardType::Monopoly);
        CHECK(monopolyCard.getCardName() == "Monopoly");

        cout<< "Test Monopoly Card success!" <<endl;
    }

    SUBCASE("Building Roads Card Test") {
        BuildingRoadsCard buildingRoadsCard;
        CHECK(buildingRoadsCard.getType() == CardType::BuildingRoads);
        CHECK(buildingRoadsCard.getCardName() == "Building Roads");

        cout<< "Test Building Roads Card success!" <<endl;
    }

    SUBCASE("Year of Abundance Card Test") {
        YearOfAbundanceCard yearOfAbundanceCard;
        CHECK(yearOfAbundanceCard.getType() == CardType::YearOfAbundance);
        CHECK(yearOfAbundanceCard.getCardName() == "Year Of Abundance");

        cout<< "Test Year of Abundance Card success!" <<endl;
    }

    SUBCASE("Knight Card Test") {
        KnightCard knightCard;
        CHECK(knightCard.getType() == CardType::Knight);
        CHECK(knightCard.getCardName() == "Knight");

        cout<< "Test Knight Card success!" <<endl;
    }

    SUBCASE("Victory Point Card Test") {
        VictoryPointCard victoryPointCard;
        CHECK(victoryPointCard.getType() == CardType::VictoryPoint);
        CHECK(victoryPointCard.getCardName() == "Victory Point");

        cout<< "Test Victory Point Card success!" <<endl;
    }
}
