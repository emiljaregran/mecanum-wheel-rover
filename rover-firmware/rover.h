#ifndef ROVER_H
#define ROVER_H

void rover_move_north(const uint8_t speed);
void rover_move_south(const uint8_t speed);
void rover_move_east(const uint8_t speed);
void rover_move_west(const uint8_t speed);
void rover_move_north_west(const uint8_t speed);
void rover_move_north_east(const uint8_t speed);
void rover_move_south_west(const uint8_t speed);
void rover_move_south_east(const uint8_t speed);
void rover_rotate_cw(const uint8_t speed);
void rover_rotate_ccw(const uint8_t speed);

#endif // ROVER_H

