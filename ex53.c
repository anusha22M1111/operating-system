#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a customer's booking
struct CustomerBooking {
    char name[50];
    int distance; // Distance from the delivery location
    int arrivalTime; // Booking time
    int isFrequentCustomer; // 1 if frequent customer with discount code, 0 otherwise
};

// Function to compare arrival times for SJF scheduling
int compareArrivalTime(const void *a, const void *b) {
    return ((struct CustomerBooking *)a)->arrivalTime - ((struct CustomerBooking *)b)->arrivalTime;
}

// Function to compare distances for SJF scheduling
int compareDistance(const void *a, const void *b) {
    return ((struct CustomerBooking *)a)->distance - ((struct CustomerBooking *)b)->distance;
}

int main() {
    int numBookings;
    printf("Enter the number of customer bookings: ");
    scanf("%d", &numBookings);

    // Allocate memory for customer bookings
    struct CustomerBooking *bookings = (struct CustomerBooking *)malloc(numBookings * sizeof(struct CustomerBooking));

    // Input customer booking details
    for (int i = 0; i < numBookings; i++) {
        printf("Enter customer name: ");
        scanf("%s", bookings[i].name);
        printf("Enter distance from delivery location for %s: ", bookings[i].name);
        scanf("%d", &bookings[i].distance);
        printf("Enter arrival time for %s: ", bookings[i].name);
        scanf("%d", &bookings[i].arrivalTime);
        printf("Is %s a frequent customer with discount code? (1 for yes, 0 for no): ", bookings[i].name);
        scanf("%d", &bookings[i].isFrequentCustomer);
    }

    // Sort the bookings based on arrival time using SJF
    qsort(bookings, numBookings, sizeof(struct CustomerBooking), compareArrivalTime);

    // Check for frequent customers and prioritize their delivery
    for (int i = 0; i < numBookings; i++) {
        if (bookings[i].isFrequentCustomer) {
            // Deliver to the frequent customer first
            printf("Delivering to %s (Frequent Customer with Discount Code) - Distance: %d km\n", bookings[i].name, bookings[i].distance);
            // Remove the customer from the list
            for (int j = i; j < numBookings - 1; j++) {
                bookings[j] = bookings[j + 1];
            }
            numBookings--;
            break;
        }
    }

    // Sort the remaining bookings based on distance using SJF
    qsort(bookings, numBookings, sizeof(struct CustomerBooking), compareDistance);

    // Deliver to the remaining customers based on distance
    for (int i = 0; i < numBookings; i++) {
        printf("Delivering to %s - Distance: %d km\n", bookings[i].name, bookings[i].distance);
    }

    // Free allocated memory
    free(bookings);

    return 0;
}
