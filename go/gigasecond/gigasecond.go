// contains functionality to operate on time and gigaseconds
package gigasecond

import "time"

// Add one gigasecond (1 billion seconds) to the time t
func AddGigasecond(t time.Time) time.Time {
	gigaSecond, _ := time.ParseDuration("1000000000s")

	return t.Add(gigaSecond)
}
