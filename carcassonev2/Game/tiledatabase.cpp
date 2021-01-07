#include "tiledatabase.h"

TileDatabase::TileDatabase()
{
    const GameTile RIVER_START = {1, {river, field, field, field}, {{1,0,1},{1,1,1},{1,1,1},{1,1,1}}, "sprites/riverstart.png"};
    const GameTile STRAIGHT_RIVER = {2, {river, field, river, field}, {{1,0,2},{2,2,2},{2,0,1},{1,1,1}}, "sprites/river.png"};
    const GameTile CORNER_RIVER = {3, {river, river, field, field}, {{1,0,2},{2,0,1},{1,1,1},{1,1,1}}, "sprites/corner-river.png"};
    const GameTile RIVER_STRAIGHT_ROAD = {4, {river, road, river, road}, {{2,0,3},{3,1,4},{4,0,5},{5,1,2}}, "sprites/river-straight-road.png"};
    const GameTile RIVER_ROAD_TO_CASTLE = {5, {road, river, castle, river}, {{3,1,4},{4,0,5},{2,2,2},{6,0,3}}, "sprites/river-road-to-castle.png"};
    const GameTile RIVER_MONASTERY = {6, {road, river, field, river}, {{2,1,3},{3,0,4},{4,4,4},{4,0,2}}, "sprites/river-monastery.png", true};
    const GameTile RIVER_2_CASTLES = {7, {castle, river, castle, river}, {{1,1,1},{3,0,4},{2,2,2},{4,0,3}}, "sprites/river-2-castles.png"};
    const GameTile RIVER_ROAD_CORNER = {8, {river, river, road, road}, {{2,0,3},{3,0,2},{2,1,4},{4,1,2}}, "sprites/river-road-corner.png"};
    const GameTile RIVER_CORNER_CASTLE = {9, {river, river, castle, castle}, {{2,0,3},{3,0,2},{1,1,1},{1,1,1}}, "sprites/river-corner-castle.png"};

    const GameTile CASTLE_ON_CORNER = {10, {field, castle, castle, field}, {{2,2,2},{1,1,1},{1,1,1},{2,2,2}}, "sprites/castle-on-corner.png"};
    const GameTile ROAD_TO_CASTLE = {11, {road, castle, castle, castle}, {{4,1,3},{2,2,2},{2,2,2},{2,2,2}}, "sprites/road-to-castle.png"};
    const GameTile X_ROAD = {12, {road, road, road, road}, {{5,1,6},{6,2,7},{7,3,8},{8,4,5}}, "sprites/xroad.png"};
    const GameTile MONASTERY = {13, {field, field, field, field}, {{1,1,1},{1,1,1},{1,1,1},{1,1,1}}, "sprites/monastery.png", true};
    const GameTile ROAD_TO_MONASTERY = {14, {road, field, field, field}, {{2,1,2},{2,2,2},{2,2,2},{2,2,2}}, "sprites/road-to-monastery.png", true};
    const GameTile ALL_CASTLE = {15, {castle, castle, castle, castle}, {{1,1,1},{1,1,1},{1,1,1},{1,1,1}}, "sprites/all-castle.png", false, true};
    const GameTile CASTLE_3_SIDES = {16, {field, castle, castle, castle}, {{2,2,2},{1,1,1},{1,1,1},{1,1,1}}, "sprites/castle-3-sides.png"};
    const GameTile CASTLE_3_SIDES_SIGN = {17, {field, castle, castle, castle}, {{2,2,2},{1,1,1},{1,1,1},{1,1,1}}, "sprites/castle-3-sides-sign.png", false, true};
    const GameTile ROAD_TO_CASTLE_SIGN = {18, {road, castle, castle, castle}, {{4,1,3},{2,2,2},{2,2,2},{2,2,2}}, "sprites/road-to-castle-sign.png",false, true};
    const GameTile CASTLE_CORNER_SIGN = {19, {field, castle, castle, field}, {{2,2,2},{1,1,1},{1,1,1},{2,2,2}}, "sprites/castle-corner-sign.png",false, true};
    const GameTile CORNER_CASTLE_CORNER_ROAD = {20, {road, castle, castle, road}, {{3,1,4},{2,2,2},{2,2,2},{4,1,3}}, "sprites/castle-corner-road.png"};
    const GameTile CORNER_CASTLE_CORNER_ROAD_SIGN = {21, {road, castle, castle, road}, {{3,1,4},{2,2,2},{2,2,2},{4,1,3}}, "sprites/castle-corner-road-sign.png",false, true};
    const GameTile PIPE_CASTLE = {22, {field, castle, field, castle}, {{2,2,2},{1,1,1},{3,3,3},{1,1,1}}, "sprites/pipe-castle.png"};
    const GameTile PIPE_CASTLE_SIGN = {23, {field, castle, field, castle}, {{2,2,2},{1,1,1},{3,3,3},{1,1,1}}, "sprites/pipe-castle-sign.png", false, true};
    const GameTile CORNER_2_CASTLES = {24, {field, castle, castle, field}, {{3,3,3},{1,1,1},{2,2,2},{3,3,3}}, "sprites/corner-2-castles.png"};
    const GameTile SEP_2_CASTLES = {25, {castle, field, castle, field}, {{1,1,1},{3,3,3},{2,2,2},{3,3,3}}, "sprites/sep-2-castles.png"};
    const GameTile SEP_1_CASTLE = {26, {field, field, castle, field}, {{2,2,2},{2,2,2},{1,1,1},{2,2,2}},"sprites/sep-1-castle.png"};
    const GameTile CASTLE_CORNER_ROAD_L = {27, {road, road, castle, field}, {{3,1,4},{4,1,3},{2,2,2},{3,3,3}}, "sprites/castle-corner-road-L.png"};
    const GameTile CASTLE_CORNER_ROAD_R = {28, {road, field, castle, road}, {{3,1,4},{4,4,4},{2,2,2},{4,1,3}}, "sprites/castle-corner-road-R.png"};
    const GameTile CASTLE_ROAD_CROSSING = {29, {road, road, castle, road}, {{5,1,6},{6,2,7},{3,3,3},{7,4,5}}, "sprites/castle-road-crossing.png"};
    const GameTile CASTLE_STRAIGHT_ROAD = {30, {field, road, castle, road}, {{3,3,3},{3,1,4},{2,2,2},{4,1,3}},"sprites/castle-straight-road.png"};
    const GameTile STRAIGHT_ROAD = {31, {road, field, road, field}, {{2,1,3},{3,3,3},{3,1,2},{2,2,2}}, "sprites/straight-road.png"};
    const GameTile CORNER_ROAD = {32, {road, road, field, field}, {{2,1,3},{3,1,2},{2,2,2},{2,2,2}}, "sprites/corner-road.png"};
    const GameTile T_JUNKTION = {33, {road, road, field, road}, {{4,1,5},{5,2,6},{6,6,6},{6,3,4}}, "sprites/t-junktion.png"};

    riverPhase_ = {
        {RIVER_START, 2}, {RIVER_ROAD_TO_CASTLE, 1}, {RIVER_MONASTERY, 1}, {RIVER_2_CASTLES, 1},
        {RIVER_ROAD_CORNER, 1}, {CORNER_RIVER, 1}, {RIVER_CORNER_CASTLE, 1}, {STRAIGHT_RIVER, 2},
        {RIVER_STRAIGHT_ROAD, 1}
    };

    mainPhase_ = {
        {MONASTERY, 4}, {ROAD_TO_MONASTERY, 2}, {ALL_CASTLE, 1}, {CASTLE_3_SIDES, 3}, {CASTLE_3_SIDES_SIGN, 1},
        {ROAD_TO_CASTLE, 1}, {ROAD_TO_CASTLE_SIGN, 2}, {CASTLE_ON_CORNER, 3}, {CASTLE_CORNER_SIGN, 2},
        {CORNER_CASTLE_CORNER_ROAD, 3}, {CORNER_CASTLE_CORNER_ROAD_SIGN, 2}, {PIPE_CASTLE, 1}, {PIPE_CASTLE_SIGN, 2},
        {CORNER_2_CASTLES, 2}, {SEP_2_CASTLES, 3}, {SEP_1_CASTLE, 5}, {CASTLE_CORNER_ROAD_L, 3},
        {CASTLE_CORNER_ROAD_R, 3}, {CASTLE_ROAD_CROSSING, 3}, {CASTLE_STRAIGHT_ROAD, 4}, {STRAIGHT_ROAD, 8},
        {CORNER_ROAD, 9}, {T_JUNKTION, 4}, {X_ROAD, 1},
    };

    allTilesByID_ = {
        {1, RIVER_START}, {2, STRAIGHT_RIVER}, {3, CORNER_RIVER},
        {4, RIVER_STRAIGHT_ROAD}, {5, RIVER_ROAD_TO_CASTLE},
        {6, RIVER_MONASTERY}, {7, RIVER_2_CASTLES}, {8, RIVER_ROAD_CORNER},
        {9, RIVER_CORNER_CASTLE}, {10, CASTLE_ON_CORNER}, {11, ROAD_TO_CASTLE},
        {12, X_ROAD}, {13, MONASTERY}, {14, ROAD_TO_MONASTERY}, {15, ALL_CASTLE},
        {16, CASTLE_3_SIDES}, {17, CASTLE_3_SIDES_SIGN}, {18, ROAD_TO_CASTLE_SIGN},
        {19, CASTLE_CORNER_SIGN}, {20, CORNER_CASTLE_CORNER_ROAD}, {21,CORNER_CASTLE_CORNER_ROAD_SIGN},
        {22, PIPE_CASTLE}, {23, PIPE_CASTLE_SIGN}, {24, CORNER_2_CASTLES}, {25, SEP_2_CASTLES},
        {26, SEP_1_CASTLE}, {27, CASTLE_CORNER_ROAD_L}, {28, CASTLE_CORNER_ROAD_R}, {29, CASTLE_ROAD_CROSSING},
        {30,CASTLE_STRAIGHT_ROAD}, {31,STRAIGHT_ROAD}, {32,CORNER_ROAD}, {33,T_JUNKTION}
    };

}

GameTile TileDatabase::getTile(TileID id)
{
    auto tile = allTilesByID_.find(id);
    if (tile != allTilesByID_.end()) {
        return tile.value();
    } else {
        return ERROR_TILE;
    }
}

TileID TileDatabase::getID(GameTile tile)
{
    for(int i = 0; i < allTilesByID_.size(); i++) {
        if (allTilesByID_[i] == tile) {
            return i;
        }
    }
    return ERROR_ID;
}

std::vector<TilePosition> TileDatabase::getTilePositions(TileID tileID)
{
    std::vector<TilePosition> retVect;

    switch (tileID) {
    case 1: {
        TilePosition field = {0.13, 0.72, LandTypes::field, {0,2}}; // 1
        retVect = {field};
        break;
    }
    case 2: {
        TilePosition field1 = {0.15, 0.35, LandTypes::field, {0,2}}; // 2
        TilePosition field2 = {0.65, 0.40, LandTypes::field, {0,0}}; // 1
        retVect = {field1, field2};
        break;
    }
    case 3: {
        TilePosition field1 = {0.15, 0.72, LandTypes::field, {0,2}}; // 2
        TilePosition field2 = {0.73, 0.17, LandTypes::field, {0,0}}; // 1
        retVect = {field1, field2};
        break;
    }

    case 4: {
        TilePosition field1 = {0.72, 0.70, LandTypes::field, {0,0}}; // 2
        TilePosition field2 = {0.16, 0.71, LandTypes::field, {0,2}}; // 3
        TilePosition field3 = {0.14, 0.15, LandTypes::field, {1,2}}; // 4
        TilePosition field4 = {0.70, 0.17, LandTypes::field, {2,2}}; // 5
        TilePosition road = {0.65, 0.40, LandTypes::road, {1,1}}; // 1
        retVect = {field1, field2, field3, field4, road};
        break;
    }

    case 5: {
        TilePosition field1 = {0.72, 0.70, LandTypes::field, {0,0}}; // 3
        TilePosition field2 = {0.16, 0.71, LandTypes::field, {0,2}}; // 4
        TilePosition field3 = {0.14, 0.2, LandTypes::field, {1,2}}; // 5
        TilePosition field4 = {0.70, 0.2, LandTypes::field, {3,0}}; // 6
        TilePosition road = {0.375, 0.7, LandTypes::road, {0,1}}; // 1
        TilePosition castle = {0.37, 0.05, LandTypes::castle, {2,1}}; // 2

        retVect = {field1, field2, field3, field4, road, castle};
        break;
    }

    case 6: {
        TilePosition field1 = {0.72, 0.70, LandTypes::field, {0,0}}; // 2
        TilePosition field2 = {0.15, 0.70, LandTypes::field, {0,2}}; // 3
        TilePosition field3 = {0.14, 0.13, LandTypes::field, {1,2}}; // 4
        TilePosition road = {0.375, 0.7, LandTypes::road, {0,1}}; // 1
        TilePosition monastery = {0.375, 0.2, LandTypes::monastery, {5,5}}; // monastery

        retVect = {field1, field2, field3, road, monastery};
        break;
    }
    case 7: {
        TilePosition field1 = {0.35, 0.25, LandTypes::field, {1,2}}; // 4
        TilePosition field2 = {0.4, 0.55, LandTypes::field, {1,0}}; // 3
        TilePosition castle1 = {0.375, 0.75, LandTypes::castle, {0,1}}; // 1
        TilePosition castle2 = {0.375, 0.02, LandTypes::castle, {2,1}}; // 2

        retVect = {field1, field2, castle1, castle2};
        break;
    }

    case 8: {
        TilePosition field1 = {0.1, 0.12, LandTypes::field, {0,0}}; // 2
        TilePosition field2 = {0.12, 0.73, LandTypes::field, {0,2}}; // 3
        TilePosition field3 = {0.73, 0.05, LandTypes::field, {2,2}}; // 4
        TilePosition road = {0.65, 0.4, LandTypes::road, {2,1}}; // 1

        retVect = {field1, field2, field3, road};
        break;

    }

    case 9: {
        TilePosition field1 = {0.08, 0.16, LandTypes::field, {0,0}}; // 2
        TilePosition field2 = {0.12, 0.73, LandTypes::field, {0,2}}; // 3
        TilePosition castle = {0.73, 0.11, LandTypes::castle, {2,1}}; // 1

        retVect = {field1, field2, castle};
        break;

    }

    case 10: {
        TilePosition field = {0.75, 0.73, LandTypes::field, {0,0}}; // 2
        TilePosition castle = {0.15, 0.16, LandTypes::castle, {1,1}}; // 1

        retVect = {field, castle};
        break;
    }

    case 11: {
        TilePosition field1 = {0.2, 0.75, LandTypes::field, {0,2}}; // 3
        TilePosition field2 = {0.7, 0.76, LandTypes::field, {0,0}}; // 4
        TilePosition road = {0.375, 0.76, LandTypes::road, {0,1}}; // 1
        TilePosition castle = {0.37, 0.38, LandTypes::castle, {2,1}}; // 2

        retVect = {field1, field2, road, castle};
        break;
    }

    case 12: {
        TilePosition field1 = {0.75, 0.75, LandTypes::field, {0,0}}; // 5
        TilePosition field2 = {0, 0.75, LandTypes::field, {0,2}}; // 6
        TilePosition field3 = {0, 0, LandTypes::field, {1,2}}; // 7
        TilePosition field4 = {0.75, 0, LandTypes::field, {2,2}}; // 8
        TilePosition road1 = {0.375, 0.72, LandTypes::road, {0,1}}; // 1
        TilePosition road2 = {0.03, 0.375, LandTypes::road, {1,1}}; // 2
        TilePosition road3 = {0.375, 0.03, LandTypes::road, {2,1}}; // 3
        TilePosition road4 = {0.72, 0.375, LandTypes::road, {3,1}}; // 4

        retVect = {field1, field2, field3, field4, road1, road2, road3, road4};
        break;
    }

    case 13: {
        TilePosition field = {0.02, 0.04, LandTypes::field, {0,0}}; // 1
        TilePosition monastery = {0.375, 0.375, LandTypes::monastery, {5,5}}; // monastery

        retVect = {field, monastery};
        break;
    }

    case 14: {
        TilePosition field = {0.02, 0.04, LandTypes::field, {0,0}}; // 2
        TilePosition road = {0.375, 0.72, LandTypes::road, {0,1}}; // 1
        TilePosition monastery = {0.375, 0.375, LandTypes::monastery, {5,5}}; // monastery

        retVect = {field, road, monastery};
        break;
    }

    case 15: {
        TilePosition castle = {0.375, 0.375, LandTypes::castle, {0,0}}; // 1

        retVect = {castle};
        break;
    }


    case 16: {
        TilePosition field = {0.375, 0.75, LandTypes::field, {0,0}}; // 2
        TilePosition castle = {0.35, 0.3, LandTypes::castle, {1,2}}; // 1

        retVect = {field, castle};
        break;
    }

    case 17: {
        TilePosition field = {0.375, 0.75, LandTypes::field, {0,0}}; // 2
        TilePosition castle = {0.35, 0.3, LandTypes::castle, {1,2}}; // 1

        retVect = {field, castle};
        break;
    }

    case 18: {
        TilePosition field1 = {0.2, 0.75, LandTypes::field, {0,2}}; // 3
        TilePosition field2 = {0.7, 0.76, LandTypes::field, {0,0}}; // 4
        TilePosition road = {0.375, 0.76, LandTypes::road, {0,1}}; // 1
        TilePosition castle = {0.37, 0.38, LandTypes::castle, {2,1}}; // 2

        retVect = {field1, field2, road, castle};
        break;
    }

    case 19: {
        TilePosition field = {0.75, 0.73, LandTypes::field, {0,0}}; // 2
        TilePosition castle = {0.15, 0.16, LandTypes::castle, {1,1}}; // 1

        retVect = {field, castle};
        break;
    }

    case 20: {
        TilePosition road = {0.5, 0.5, LandTypes::road, {0,1}}; // 1
        TilePosition castle = {0.15, 0.15, LandTypes::castle, {1,1}}; // 2
        TilePosition field1 = {0.72, 0.72, LandTypes::field, {0,0}}; // 3
        TilePosition field2 = {0.2, 0.7, LandTypes::field, {0,2}}; // 4

        retVect = {road, castle, field1, field2};
        break;
    }

    case 21: {
        TilePosition road = {0.5, 0.5, LandTypes::road, {0,1}}; // 1
        TilePosition castle = {0.15, 0.15, LandTypes::castle, {1,1}}; // 2
        TilePosition field1 = {0.72, 0.72, LandTypes::field, {0,0}}; // 3
        TilePosition field2 = {0.2, 0.7, LandTypes::field, {0,2}}; // 4

        retVect = {road, castle, field1, field2};
        break;
    }

    case 22: {
        TilePosition field1 = {0.37, 0.75, LandTypes::field, {0,1}}; // 2
        TilePosition field2 = {0.38, 0, LandTypes::field, {2,1}}; // 3
        TilePosition castle = {0.375, 0.375, LandTypes::castle, {1,1}}; // 1

        retVect = {field1, field2, castle};
        break;
    }

    case 23: {
        TilePosition field1 = {0.37, 0, LandTypes::field, {0,1}}; // 2
        TilePosition field2 = {0.38, 0.75, LandTypes::field, {2,1}}; // 3
        TilePosition castle = {0.375, 0.375, LandTypes::castle, {1,1}}; // 1

        retVect = {field1, field2, castle};
        break;
    }

    case 24: {
        TilePosition field = {0.4, 0.4, LandTypes::field, {0,1}}; // 3
        TilePosition castle1 = {0, 0.375, LandTypes::castle, {1,1}}; // 1
        TilePosition castle2 = {0.375, 0, LandTypes::castle, {2,1}}; // 2

        retVect = {field, castle1, castle2};
        break;
    }

    case 25: {
        TilePosition field = {0.375, 0.375, LandTypes::field, {1,1}}; // 3
        TilePosition castle1 = {0.38, 0.75, LandTypes::castle, {0,1}}; // 1
        TilePosition castle2 = {0.36, 0, LandTypes::castle, {2,1}}; // 2

        retVect = {field, castle1, castle2};
        break;
    }

    case 26: {
        TilePosition field = {0.39, 0.55, LandTypes::field, {1,1}}; // 2
        TilePosition castle = {0.375, 0, LandTypes::castle, {2,1}}; // 1

        retVect = {field, castle};
        break;
    }

    case 27: {
        TilePosition field1 = {0.55, 0.65, LandTypes::field, {0,0}}; // 3
        TilePosition field2 = {0, 0.75, LandTypes::field, {0,2}}; // 4
        TilePosition road = {0.2, 0.375, LandTypes::road, {0,1}}; // 1
        TilePosition castle = {0.375, 0, LandTypes::castle, {2,1}}; // 2

        retVect = {field1, field2, road, castle};
        break;
    }

    case 28: {
        TilePosition field1 = {0.75, 0.75, LandTypes::field, {0,0}}; // 3
        TilePosition field2 = {0.1, 0.6, LandTypes::field, {0,2}}; // 4
        TilePosition road = {0.375, 0.7, LandTypes::road, {0,1}}; // 1
        TilePosition castle = {0.375, 0, LandTypes::castle, {2,1}}; // 2

        retVect = {field1, field2, road, castle};
        break;
    }

    case 29: {
        TilePosition field1 = {0.75, 0.75, LandTypes::field, {0,0}}; // 5
        TilePosition field2 = {0, 0.75, LandTypes::field, {0,2}}; // 6
        TilePosition field3 = {0.375, 0.26, LandTypes::field, {1,2}}; // 7
        TilePosition road1 = {0.375, 0.75, LandTypes::road, {0,1}}; // 1
        TilePosition road2 = {0, 0.375, LandTypes::road, {1,1}}; // 2
        TilePosition road3 = {0.75, 0.375, LandTypes::road, {3,1}}; // 4
        TilePosition castle = {0.375, 0, LandTypes::castle, {2,1}}; // 3

        retVect = {field1, field2, field3, road1, road2, road3, castle};
        break;
    }

    case 30: {
        TilePosition road = {0.375, 0.375, LandTypes::road, {1,1}}; // 1
        TilePosition castle = {0.375, 0.05, LandTypes::castle, {2,1}}; // 2
        TilePosition field1 = {0.36, 0.73, LandTypes::field, {0,0}}; // 3
        TilePosition field2 = {0.5, 0.25, LandTypes::field, {1,2}}; // 4

        retVect = {road, castle, field1, field2};
        break;
    }

    case 31: {
        TilePosition field1 = {0.68, 0.4, LandTypes::field, {0,0}}; // 2
        TilePosition field2 = {0.07, 0.35, LandTypes::field, {0,2}};  // 3
        TilePosition road = {0.375, 0.375, LandTypes::road, {0,1}}; // 1

        retVect = {field1, field2, road};
        break;
    }

    case 32: {
        TilePosition field1 = {0.6, 0.12, LandTypes::field, {0,0}}; // 2
        TilePosition field2 = {0, 0.75, LandTypes::field, {0,2}};  // 3
        TilePosition road = {0.375, 0.7, LandTypes::road, {0,1}}; // 1

        retVect = {field1, field2, road};
        break;
    }

    case 33: {
        TilePosition field1 = {0.75, 0.75, LandTypes::field, {0,0}}; // 4
        TilePosition field2 = {0, 0.75, LandTypes::field, {0,2}};  // 5
        TilePosition field3 = {0.3, 0.13, LandTypes::field, {1,2}};  // 6
        TilePosition road1 = {0.375, 0.7, LandTypes::road, {0,1}}; // 1
        TilePosition road2 = {0.1, 0.375, LandTypes::road, {1,1}}; // 2
        TilePosition road3 = {0.6, 0.375, LandTypes::road, {3,1}}; // 3

        retVect = {field1, field2, field3, road1, road2, road3};
        break;
    }

    }


    return retVect;
}
