package booking

import "time"

// Schedule returns a time.Time from a string containing a date.
func Schedule(date string) time.Time {
	layout := "1/02/2006 15:04:05"
	parsedDate, error := time.Parse(layout, date)

	if error != nil {
		panic(error)
	}

	return parsedDate
}

// HasPassed returns whether a date has passed.
func HasPassed(date string) bool {
	layout := "January 2, 2006 15:04:05"
	parsedDate, error := time.Parse(layout, date)

	if error != nil {
		panic(error)
	}

	return time.Now().After(parsedDate)
}

// IsAfternoonAppointment returns whether a time is in the afternoon.
func IsAfternoonAppointment(date string) bool {
	layout := "Monday, January 2, 2006 15:04:05"
	parsedDate, error := time.Parse(layout, date)

	if error != nil {
		panic(error)
	}

	return parsedDate.Hour() >= 12 && parsedDate.Hour() <= 18
}

// Description returns a formatted string of the appointment time.
func Description(date string) string {
	parsedDate, error := time.Parse("1/2/2006 15:04:05", date)

	if error != nil {
		panic(error)
	}

	formattedDate := parsedDate.Format("Monday, January 2, 2006, at 15:04")
	return "You have an appointment on " + formattedDate + "."
}

// AnniversaryDate returns a Time with this year's anniversary.
func AnniversaryDate() time.Time {
	return time.Date(time.Now().Year(), time.September, 15, 0, 0, 0, 0, time.UTC)
}
