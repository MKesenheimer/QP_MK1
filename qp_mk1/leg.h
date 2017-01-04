#ifndef LEG_H
#define LEG_H

// dimensions in mm
// distance hip - knee axis
#define COXA    12.0
// distance knee - ankle axis
#define FEMUR   42.0
// distance ankle - ground
#define TIBIA   37.0
// distance hip - base
#define BASE    34.0

const signed char LEG_X[4] = {-1, -1, 1, 1};
const signed char LEG_Y[4] = {1, -1, -1, 1};
extern double leg_position[4][3];
const double HOME = (COXA + FEMUR) / SQRT2;

bool move_leg(unsigned char leg, double x, double y, double z);
bool move_leg_by(unsigned char leg, double dx, double dy, double dz);
bool rotate_leg_by(unsigned char leg, double angle);

#endif
