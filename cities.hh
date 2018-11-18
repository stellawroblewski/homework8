/*
 * API file for Travelling-Salesperson Cities class and utilities
 */

#pragma once

#include <vector>
#include <iostream>

// Representation of an ordering of cities
class Cities {
 public:

  // A pair of integral coordinates for each city
  using coord_t = std::pair<int, int>;

  // An ordering of the cities in cities_t. Each value represents a unique index
  // into the current city ordering.
  using permutation_t = std::vector<unsigned int>;


  //we need a public vector of cities that doesn't ever get permuted
  //this is like the key to the cities, cities_[0] will always be Portland 
  //and will always have the same coordinates. These keys will be what is
  //permuted in later functions.
  std::vector<coord_t> cities_;

  // Given a permutation, return a new Cities object where the order of the
  // cities reflects the original order of this class after reordering with
  // the given ordering. So for example, the ordering { 1, 0 } simply swaps
  // the first two elements (coordinates) in the new Cities object.
  Cities reorder(const permutation_t& ordering) const;

  // For a given permutation of the cities in this object,
  // compute how long (distance) it would take to traverse all the cities in the
  // order of the permutation, and then returning to the first city.
  // The distance between any two cities is computed as the Euclidean 
  // distance on a plane between their coordinates.
  double total_path_distance(const permutation_t& ordering) const;



  permutation_t get_permutation(){return order_of_cities;}

  //this returns a random permutation of cities
  permutation_t random_permutation(unsigned len);

  permutation_t order_of_cities;

private:
  

  double path_between(coord_t t1, coord_t t2) const;

  
};


//Implement operator>> (std::istream&, Cities&) to allow for the reading  / filling of a Cities object from a stream. 
std::istream& operator>>(std::istream& is, Cities& city);

std::ostream& operator<<(std::ostream& is, Cities& city);