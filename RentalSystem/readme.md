# 🚗 RentalSystem — Vehicle Rental Reservation Module

A robust C++ class for handling rental car reservations with validation, pricing logic, customer eligibility checks, and advanced calculation features.  
Designed to be integrated as part of **MegaSys**, this module can simulate booking, rental rate computation, and discount systems for car rentals.

---

## ⚙️ Key Features

### 🧩 Data Modeling
Each `RentalReservation` object encapsulates:
- Reservation metadata (`reservationID`, `customerName`, `customerLoyaltyTier`)
- Car info (`carMakeModel`, `carCategory`)
- Rental details (`pickupDate`, `returnDate`, `duration`, `locations`)
- Pricing factors (`baseRentalRate`, `seasonalMultiplier`, `surcharges`, `loyaltyDiscount`)
- Insurance and driver data

---

### ✅ Validation Methods
- **`validateReservationID()`** – Ensures ID format (8 chars, 4 digits, 2 specials, sum < 18).  
- **`validateCarMakeModel()`** – Checks against available fleet models.  
- **`validateDateRange()`** – Verifies logical pickup/return range and duration.  
- **`validateCustomerEligibility()`** – Confirms category-tier compatibility (e.g., *Gold → 5 sitter*).

---

### 💰 Calculation Methods
- **`calculateRentalRate()`** – Computes rate based on car type, make, multiplier, and surcharge.  
- **`calculateSeasonalAdjustment()`** – Adjusts pricing depending on pickup date/month.  
- **`calculateLocationSurcharge()`** – Adds extra fees based on pickup/return cities.  
- **`calculateLoyaltyDiscount()`** – Returns applicable tier-based discount.  
- **`calculateInsuranceCost()`** – Determines insurance cost by plan type.  
- **`calculateRentalTotal()`** – Returns final calculated total.

---

### 🔧 Extendable Features (to implement)
These methods are declared but not yet defined — ideal for further MegaSys integration:
- `updateReservation(field, value)`
- `addInsurance(option)`
- `addAdditionalDriver(count)`
- `applyPromotionCode(code)`
- `calculateCancellationFee(cancellationDate)`
- `getSimilarVehicleOptions()`
- `calculateUpgradePrice(newCarModel)`
- `isEligibleForFreeUpgrade()`

Each can be expanded later for system-wide data management, GUI inputs, or booking APIs.

---


