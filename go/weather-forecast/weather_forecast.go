// Package weather provides a function that returns weather information.
package weather

// CurrentCondition contains the description of current weather conditions.
var CurrentCondition string
// CurrentLocation contains the name of the location for which the weather is displayed.
var CurrentLocation string

// Forecast updates the weather conditions for the given city and returns readable weather conditions.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
