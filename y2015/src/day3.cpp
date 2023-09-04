#include <iostream>
#include <D3_2015/day3.hpp>
#include <fstream>

int main (int argc, char *argv[]) {
    std::string file_name = "../src/files/day3.txt";
    std::string line;
    std::ifstream file(file_name);
    std::getline(file, line);

    d3::Grid g;
    g.performRide(line);
    std::cout << "At least received 1 present " << g.totalVisited()
        << " houses\n";

    d3::Grid santa, robot;
    std::string path_santa, path_robot;
    d3::split(line, path_santa, path_robot);
    santa.performRide(path_santa);
    robot.performRide(path_robot);
    santa.combineGrids(robot);
    std::cout << "With both working together, at least received 1 present " <<
        santa.totalVisited() << " houses\n";

    return 0;
}
