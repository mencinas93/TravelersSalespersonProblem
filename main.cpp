
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;
//creating structre for each individual city
struct city {
    double x, y;
};
//distanceformula. using math libraries like square root so i do not have to create more formulas. Euclid
double DistanceFormula(const city& cityA, const city& cityB){
    return sqrt((cityA.x - cityB.x) * (cityA.x - cityB.x) + (cityA.y - cityB.y) * (cityA.y - cityB.y));
}
// the path is the order traveled and the cities are the city objects.
double TotalDistance(const vector<int>& path, const vector<city>& cities) {
    double totalDistanceTraveled = 0;
    int numberOfCities = path.size();
    

    for (int i = 0; i < numberOfCities; i++) {
        const city& cityA = cities[path[i]];
        //city index
        const city& cityB = cities[path[(i + 1) % numberOfCities]];
        //CityA and CityB being added to path vector and number of cities is moduled so when it equals 0 it stops. As it goes along it adds up until its 0.
        totalDistanceTraveled += DistanceFormula(cityA, cityB);
    }

    return totalDistanceTraveled;
}

int main() {
     
    vector<city> cities = {
          {87.951292, 2.658162},
          {33.466597, 66.682943},
          {91.778314, 53.807184},
          {20.526749, 47.633290}
      };

      int numberofCities = cities.size();
    //number of cities.
      vector<int> cityIndex(numberofCities);
    //vector index loop
      for (int i = 0; i < numberofCities; i++) {
          cityIndex[i] = i;
      }

      double minDistance = numeric_limits<double>::infinity();
      // built in large finite number called infinity. Do not know my limits to stop.
      vector<int> LowestRoute;
        // using parameters for total distance function for city numbers and city vectors.
    // if total distance lower than minimum ten total is now minimum and lowest route path is the city index.
      do {
          double totalDistance = TotalDistance(cityIndex, cities);
          if (totalDistance < minDistance) {
              minDistance = totalDistance;
              LowestRoute = cityIndex;
          }
      } while (next_permutation(cityIndex.begin(), cityIndex.end()));
// huge loop running every possible path keeping memory. Huge exponential time complexity
    cout << "Optimal Travelers salesperson path:";
    for (int i = 0; i < LowestRoute.size(); ++i) {
        cout << " " << LowestRoute[i] + 1;  // Adding 1 to convert from 0-based index to 1-based 
    }
    cout << "\nLowest distance for salesperson: " << minDistance << endl;

      return 0;
  }

