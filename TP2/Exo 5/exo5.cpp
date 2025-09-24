#include "Trajectory.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(NULL))); // pour random dans Point3D

    Trajectory traj(3); // 3 points

    traj.getPoint(0).setXYZ(0, 0, 0);
    traj.getPoint(1).setXYZ(1, 0, 0);
    traj.getPoint(2).setXYZ(1, 1, 0);

    traj.print();

    std::cout << "Distance totale = " << traj.getTotalDistance() << std::endl;

    return 0;
}
