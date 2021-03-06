//
//  TSP_NearestHeighbor.h
//  TravelingSalesman
//
//  Created by Anton Logunov on 3/29/14.
//  Copyright (c) 2014 Anton Logunov. All rights reserved.
//

#ifndef __TravelingSalesman__TSP_NearestHeighbor__
#define __TravelingSalesman__TSP_NearestHeighbor__

#include <iostream>
#include <chrono>
#include <random>


#include "tsp.hpp"

struct TSP_NearestNeighbor : TSP {
    vector<City> solve(const vector<Point>& points) override {
        vector<City> cities(points.size());
        for (City c = 0; c < points.size(); c++) cities[c] = c;
        swap(cities[0],cities[random(points.size())]);
        City i = 0;
        // last city has no nearest point
        while (++i < points.size()-1) {
            swap(cities[i], 
                 cities[NearestPoint(
                            points, 
                            vector<City>(cities.begin()+i, cities.end()), 
                            points[cities[i-1]])]);
        }
        return cities;
    }
};

#endif /* defined(__TravelingSalesman__TSP_NearestHeighbor__) */
