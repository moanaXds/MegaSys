# ✈️ FlightAnalyzer — Flight Operations & Comparison Module

A standalone C++ implementation to model, compare, and analyze flight details such as fares, durations, sources, destinations, and more.  
This module can be integrated into **MegaSys** under transport analytics, booking simulators, or dataset pre-processing tools.

---

## 🚀 Features

- **Full Flight Representation**
  - Stores all relevant flight data: airline, source, destination, timings, fares, aircraft type, travel class, booking source, etc.

- **Combinational & Comparative Analysis**
  - `combineFlight()` merges two flights and aggregates numerical values (e.g., fare, duration).
  - `calculateFareDifference()` finds fare gaps between flights.
  - Comparison functions like:
    - `hasHigherFare()`
    - `hasLowerFare()`
    - `areFlightsEqual()`
    - `areFlightsDifferent()`

- **Value Manipulation**
  - `makeValuesPositive()` and `makeValuesNegative()` to normalize or invert numeric fields.
  - `addFlightValues()` and `subtractFlightValues()` for manual numerical operations.

- **Data Input/Output**
  - `inputFlightDetails()` to capture flight data from the user.
  - `displayFlight()` to print formatted flight info.

---

## 🧩 Example Usage

```cpp
#include "flight_operations.cpp"

int main() {
    Flight f1("United", "LAX", "Los Angeles", "SFO", "San Francisco",
              "2024-12-02", "2024-12-02", 22.0, "None",
              "Airbus A320", "Economy", "Website", 101.0, 210.0, 311.0,
              "Spring", 3);

    Flight f2("Biman", "DAC", "Dhaka", "LHR", "London",
              "2025-04-01", "2025-04-02", 9.0, "Non-stop",
              "F17", "Economy", "Traveloka", 40.0, 51.0, 91.0,
              "Spring", 415);

    Flight combined = f1.combineFlight(f2);
    cout << "Fare difference: " << f1.calculateFareDifference(f2) << endl;
    combined.displayFlight();
}
