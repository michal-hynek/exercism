package darts

import "math"

func distanceToCenter(x, y float64) float64 {
	return math.Sqrt(x*x + y*y)
}

func Score(x, y float64) int {
	dist := distanceToCenter(x, y)

	if dist <= 1.0 {
		return 10
	} else if dist <= 5.0 {
		return 5
	} else if dist <= 10.0 {
		return 1
	} else {
		return 0
	}
}
