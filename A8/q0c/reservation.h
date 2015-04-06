#include <stdbool.h>

// a manifest represents seat reservations for a flight
// the flight has first class and economy seats, and 
// an array of bool indicating whether the seat is free
// the first class seats are stored in seats[0] through seats[num_fc-1]
// the economy seats are stored in seats[num_fc] to seats[num_fc+num_ec-1]

struct manifest {
  bool *seats;
  int num_fc;       // number of first class seats
  int num_ec;       // number of economy class seats
};

// create_manifest(num_fc, num_ec) returns a new manifest structure 
//     with num_fc First Class seats and num_ec Economy Class seats.
//   requires:  num_fc >= 0, num_ec >= 0, num_fc + num_ec > 0
//   effects: allocates a new struct manifest
//         all seats are initialized to false
//         caller must eventually call destroy_manifest to free
//   TIME: O(n), where n = num_fc + num_ec
struct manifest *create_manifest(int num_fc, int num_ec);

// destroy_manifest(m) first frees the seats
//     and then frees the manifest m
//   requires:  m is a valid manifest created by create_manifest
//   effects: m is deallocated (no longer valid)
//   TIME: O(1)
void destroy_manifest(struct manifest *m);

