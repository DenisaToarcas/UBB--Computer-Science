# Trip Planner Mobile Application: Requirements
# TripTracker

## Non-Technical Overview
This mobile application will help users plan trips and keep track of their travel itineraries, stops, and destinations. The app will allow users to add, view, update, and delete trips, providing detailed information on each trip. It will also synchronize trip data with a remote server and provide offline handling, ensuring that the user experience is uninterrupted even without an internet connection.

### Main Features
1. **View All Trips (Main Screen):**
   - The user can see a list of all registered trips. Each trip will display essential information like destination, date, and key stops.
   - A button on the main screen will navigate the user to a "New Trip" page where they can add a new trip to the app.

2. **Add Trip:**
   - Users will fill in required details such as destination, date, key stops, and optional notes.
   - The form should include validation to ensure required fields are filled out.

3. **View Trip Details:**
   - Clicking on a trip in the list will take the user to the details page of that specific trip, showing all related information.
   - Users can edit the trip’s details or delete it from the list.

4. **Update Trip:**
   - Users can modify any field of the trip, including destination, stops, and notes via the "Edit" option on the trip’s details page.
   - Updated data should be persisted locally and synced with the server when online.

5. **Delete Trip:**
   - Users can delete a trip, removing it from both the local database and the server when online.

---

## Problem Domain Overview

### Entity to be Persisted: `Trip`
Fields for a **Trip** entity:
  - **Destination**: `string` – The name of the destination city or country.
  - **Start Date**: `date` – The start date of the trip.
  - **End Date**: `date` – The end date of the trip.
  - **Key Stops**: `string` – Stops or important places the user plans to visit during the trip.
  - **Notes**: `string` – Additional notes or details about the trip. The user can include information about prices or the budget needed for the trip itself, or may use the notes as an items' list for when he's packing.

### Actions (CRUD Operations)
1. **Create/Add Trip:**  
   Allows users to create and add a new trip with all the necessary details.
   
2. **Read/View Trips:**  
   Shows a list of all registered trips, allowing users to see them in summary form.
   
3. **Update Trip:**  
   Users can edit any field of a trip to update their travel plans.
   
4. **Delete Trip:**  
   Users can remove a trip from their record permanently.

---

## Persistence Details
- The application will persist all trip data locally in a database.
- Data will also synchronize with a remote server when an internet connection is available, ensuring that all CRUD operations are stored both locally and remotely.

---

## Offline App Handling
The application will support offline access with the following behaviors:

- **Create (Offline Mode):**  
  The app will allow users to add new trips offline, saving the information in the local database. When online, it will automatically synchronize and push new trips to the server.

- **Read (Offline Mode):**  
  Users will be able to view trips from the local database with a message notifying them that they are offline.

- **Update (Offline Mode):**  
  Users will be prevented from updating a trip while offline, with a message indicating that the operation requires an internet connection.

- **Delete (Offline Mode):**  
  Deletion of trips will be restricted while offline, with a notification that the app is not connected to the server.

By having both offline and online functionality, the app ensures users can manage their trips regardless of their connectivity status.

---

## App MockUp

**Main Page**

![TripTracker](https://github.com/user-attachments/assets/742ff5f8-0839-4528-b1bf-ecdfb79e5a91)


**Add a new trip page**

![TripTracker (1)](https://github.com/user-attachments/assets/e5eace21-d5d8-4ef3-8c4b-733cbb974fa8)
