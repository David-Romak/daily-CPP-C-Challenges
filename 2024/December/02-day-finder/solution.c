#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int month_name_to_number(const char *month_name) {
    char lower_month[20];
    for (int i = 0; month_name[i]; i++) {
        lower_month[i] = tolower(month_name[i]);
    }
    lower_month[strlen(month_name)] = '\0';
    
    const char *months[] = {
        "january", "february", "march", "april", "may", "june",
        "july", "august", "september", "october", "november", "december"
    };

    
    for (int i = 0; i < 12; i++) {
        if (strcmp(lower_month, months[i]) == 0) {
            return i + 1;  
        }
    }
    return -1;  
}

// Zeller's Congruence algorithm for Gregorian calendar
// Returns: 0=Saturday, 1=Sunday, 2=Monday, ..., 6=Friday
int zeller_congruence(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    
    int k = year % 100;  
    int j = year / 100;  
    
    // Zeller's formula
    int h = (day + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7;
    
    return h;
}

const char* get_day_of_week(const char *date_str) {
    int day, month, year;
    char month_name[20];
    
    // Try parsing as "MM/DD/YYYY" format
    if (sscanf(date_str, "%d/%d/%d", &month, &day, &year) == 3) {
    }

    else if (sscanf(date_str, "%s %d, %d", month_name, &day, &year) == 3) {
        month = month_name_to_number(month_name);
        if (month == -1) {
            return "Invalid month name";
        }
    }
    else {
        return "Invalid date format";
    }
    
    if (month < 1 || month > 12) return "Invalid month";
    if (day < 1 || day > 31) return "Invalid day";
    
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return "Invalid day for this month";
    }
    if (month == 2) {
        if (is_leap_year(year) && day > 29) return "Invalid day for February (leap year)";
        if (!is_leap_year(year) && day > 28) return "Invalid day for February";
    }
    
    int day_index = zeller_congruence(day, month, year);
    
    const char *days_of_week[] = {
        "Saturday", "Sunday", "Monday", "Tuesday", 
        "Wednesday", "Thursday", "Friday"
    };
    
    return days_of_week[day_index];
}

int main() {
    // Test cases
    const char *test_dates[] = {
        "12/31/2025",        // Tuesday
        "July 4, 2023",      // Tuesday
        "1/1/2000",          // Saturday
        "12/25/2024",        // Wednesday
        "February 29, 2020", // Saturday (valid leap year)
        "February 29, 2019", // Should be invalid
        "13/45/2023",        // Invalid date
        "Random text",       // Invalid format
    };
    
    for (int i = 0; i < sizeof(test_dates) / sizeof(test_dates[0]); i++) {
        printf("Input:  %s\n", test_dates[i]);
        printf("Output: %s\n\n", get_day_of_week(test_dates[i]));
    }
    
    return 0;
}