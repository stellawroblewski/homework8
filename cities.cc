#include "cities.hh"
#include <cmath>
#include <random>
#include <algorithm>
#include <iterator>

std::istream & operator>>(std::istream & is, Cities& city){
    int x;
    int y;
    std::vector<Cities::coord_t> list;
    while (is>>x){
        Cities::coord_t pair;
        pair.first = x;
        is >> y;
        pair.second = y;
        list.push_back(pair);
    }
    city.cities_ = list;
    return is;
}

//maybe have to use make_pair()? but no compiler errors with this
std::ostream & operator<<(std::ostream & os, Cities& city){
    int x;
    int y;
    Cities::permutation_t list;
    list = city.order_of_cities;
    Cities::coord_t pair;
    for (int i = 0; i < list.size(); i ++){
        x = city.cities_[list[i]].first;
        y = city.cities_[list[i]].second;
        os<<x;
        os<<y;
    }
    return os;

}

double Cities::path_between(coord_t t1, coord_t t2) const{
    int difference_first = (t1.first - t2.first);
    int difference_second = (t1.second - t2.second);
    return sqrt((pow(difference_first, 2) + pow(difference_second, 2)));
}

double Cities::total_path_distance(const permutation_t& ordering) const{
    double total;
    for (int i = 0; i < ordering.size() - 1; i++){
        unsigned int currentIdx = ordering[i];
        unsigned int nextIdx = ordering[i+1];
        total += path_between(cities_[currentIdx],cities_[nextIdx]);
    }
    total += path_between(cities_[0], cities_[ordering.size() - 1]); //no viable conversion from 'const value_type'(aka 'const int') to 'coord_t' (aka 'pair<int, int>')
    const double ans = total;
    return ans;
}

Cities Cities::reorder(const permutation_t& ordering) const{
    Cities new_city;
    for (int i = 0; i < ordering.size() - 1; i++){
        //if ordering is 4,3,2,1 and i is 1 for example, this should push 
        //the 3rd element of this Cities's cities_ list to the new_city's
        //cities_ list.
        new_city.cities_.push_back(cities_[ordering[i]]);
    }
    return new_city;
}

Cities::permutation_t Cities::random_permutation(unsigned len){
    permutation_t v(len);
    //creates a new vector with a permutation ready to be shuffled
    for (int i = 0; i < len; i ++) {
        v.push_back(i);
    }

    //borrowed from:
    //https://en.cppreference.com/w/cpp/algorithm/random_shuffle
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(),v.end(),g);

    return (v);
}