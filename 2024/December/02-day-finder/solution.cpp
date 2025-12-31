#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <stdexcept>

class DateConverter
{
private:
    std::unordered_map<std::string, int> month_map;

    void init_month_map()
    {
        std::vector<std::string> months = {
            "january", "february", "march", "april", "may", "june",
            "july", "august", "september", "october", "november", "december"};

        for (int i = 0; i < months.size(); i++)
        {
            month_map[months[i]] = i + 1;
        }
    }

    bool is_leap_year(int year) const
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool validate_date(int day, int month, int year)
    {
        if (month < 1 || month > 12)
            return false;
        if (day < 1 || day > 31)
            return false;

        // Days in each month (1-indexed)
        const int days_in_month[] = {31, 28, 31, 30, 31, 30,
                                     31, 31, 30, 31, 30, 31};

        int max_days = days_in_month[month - 1];
        if (month == 2 && is_leap_year(year))
        {
            max_days = 29;
        }

        return day <= max_days;
    }

    // Alternative: Using Sakamoto's algorithm (more efficient)
    int sakamoto_algorithm(int day, int month, int year)
    {
        // Sakamoto's algorithm
        int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

        if (month < 3)
        {
            year--;
        }

        return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
    }

    // Zeller's Congruence implementation
    int zeller_congruence(int day, int month, int year)
    {
        if (month < 3)
        {
            month += 12;
            year--;
        }

        int k = year % 100;
        int j = year / 100;

        return (day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    }

    std::string to_lower(const std::string &s)
    {
        std::string lower = s;
        std::transform(lower.begin(), lower.end(), lower.begin(),
                       [](unsigned char c)
                       { return std::tolower(c); });
        return lower;
    }

public:
    DateConverter()
    {
        init_month_map();
    }

    std::string get_day_of_week(const std::string &date_str)
    {
        int day, month, year;
        std::string month_name;

        // Try parsing as "MM/DD/YYYY"
        char delimiter;
        std::istringstream iss1(date_str);
        if (iss1 >> month >> delimiter >> day >> delimiter >> year)
        {
            // Check if parsing succeeded and format is correct
            if (delimiter == '/')
            {
                if (!validate_date(day, month, year))
                {
                    throw std::invalid_argument("Invalid date");
                }
                int day_index = sakamoto_algorithm(day, month, year);
                return day_index_to_name(day_index);
            }
        }

        // Try parsing as "Month Day, Year"
        std::istringstream iss2(date_str);
        if (iss2 >> month_name >> day >> delimiter >> year)
        {
            if (delimiter == ',')
            {
                std::string lower_month = to_lower(month_name);
                if (month_map.find(lower_month) != month_map.end())
                {
                    month = month_map[lower_month];
                    if (!validate_date(day, month, year))
                    {
                        throw std::invalid_argument("Invalid date");
                    }
                    int day_index = sakamoto_algorithm(day, month, year);
                    return day_index_to_name(day_index);
                }
            }
        }

        throw std::invalid_argument("Invalid date format");
    }

private:
    std::string day_index_to_name(int index)
    {
        const std::vector<std::string> days = {
            "Sunday", "Monday", "Tuesday", "Wednesday",
            "Thursday", "Friday", "Saturday"};
        return days[index];
    }
};

int main()
{
    DateConverter converter;

    // Test cases
    std::vector<std::string> test_dates = {
        "11/19/2019",         // Tuesday
        "July 4, 2023",       // Tuesday
        "1/1/2000",           // Saturday
        "December 25, 2024",  // Wednesday
        "February 29, 2020",  // Saturday
        "March 1, 2024",      // Friday
        "September 11, 2001", // Tuesday
    };

    for (const auto &date : test_dates)
    {
        try
        {
            std::cout << "Input:  " << date << std::endl;
            std::cout << "Output: " << converter.get_day_of_week(date) << std::endl;
            std::cout << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl
                      << std::endl;
        }
    }

    return 0;
}