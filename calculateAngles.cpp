// Copyright (c) 2022 Ioana Marinescu All rights reserved.
// Created By: Ioana Marinescu

// Date: Dec. 12, 2022
// a program that calculates the angles of a right
// angle triangle given the side lengths


#include <iomanip>
#include <cmath>
#include <iostream>

// function calculates the angle theta given the hypotenuse and the opposite
float calcAngle(float opposite, float hypotenuse) {
    // variables
    float hypOverOpp, angleTheta;

    // calculates the angle theta
    hypOverOpp = opposite / hypotenuse;
    angleTheta = asin(hypOverOpp) * 57.2958;

    // returns final value
    return angleTheta;
}

// function checks if the user's input is valid or not
float isValid(std::string userInputStr) {
    // try catch
    try {
        // from string to float
        float userInputFl = stof(userInputStr);

        // num is not positive
        if (userInputFl < 1) {
            std::cout << "Side length must be at least 1 unit long!"
                      << std::endl;
            return 0;
        // user num is positive
        } else {
            return userInputFl;
        }

    // user input is invalid
    } catch (std::invalid_argument) {
        std::cout << "Input invalid! Please enter a valid number!" << std::endl;
        return 0;
    }
}

int main() {
    while (true) {
        // variables
        std::string leg1Str, leg2Str, hypotenuseStr;
        float leg1Fl, leg2Fl, hypotenuseFl, theta1, theta2;

        // getting user input for the first leg
        std::cout << "Enter the length of one of the legs (no units): ";
        std::cin >> leg1Str;
        // input is valid
        if (isValid(leg1Str) != 0) {
            leg1Fl = isValid(leg1Str);
        // input is invalid
        } else {
            break;
        }

        // getting user input for the other leg
        std::cout << "Enter the length of the other leg (no units): ";
        std::cin >> leg2Str;
        // input is valid
        if (isValid(leg2Str) != 0) {
            leg2Fl = isValid(leg2Str);
        // input is invalid
        } else {
            break;
        }

        // getting user input of the hypotenuse
        std::cout << "Enter the length of the hypotenuse (no units): ";
        std::cin >> hypotenuseStr;
        // input is valid
        if (isValid(hypotenuseStr) != 0) {
            hypotenuseFl = isValid(hypotenuseStr);
            // input is invalid
        } else {
            break;
        }

        // function call to calculate the unkown angles
        theta1 = calcAngle(leg1Fl, hypotenuseFl);
        theta2 = calcAngle(leg2Fl, hypotenuseFl);

        // displays the results
        std::cout << std::endl;
        std::cout << "The angle opposite to the side with the length "
                  << leg1Str << " units, is " << std::fixed
                  << std::setprecision(2) << std::setfill('0')
                  << theta1 << "°, and the angle opposite"
                  << " to  the side with the length "
                  << leg1Str << " units, is " << theta2 << "°."
                  << std::endl;
        std::cout << std::endl;
        break;
    }
}
