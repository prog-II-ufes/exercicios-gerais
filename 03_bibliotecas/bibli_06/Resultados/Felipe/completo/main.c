#include <stdio.h>
#include "temperature_conversor.h"

int main(int argc, char const *argv[])
{
    float temperature;
    char unit1, unit2;

    scanf("%f %c %c", &temperature, &unit1, &unit2);

    if (unit1 == 'k') {
        temperature = convert_kelvin_to_celsius(temperature);
    } else if (unit1 == 'f') {
        temperature = convert_fahrenheit_to_celsius(temperature);
    }

    if (unit2 == 'c') {
        printf("Temperature: %.2fCº", temperature);
    } else if (unit2 == 'f') {
        printf("Temperature: %.2fFº", convert_celsius_to_fahrenheit(temperature));
    } else {
        printf("Temperature: %.2fK", convert_celsius_to_kelvin(temperature));
    }

    return 0;
}
