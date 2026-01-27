package lasagna

func PreparationTime(layers []string, timePerLayer int) int {
    if timePerLayer == 0 {
        return 2 * len(layers)
    }

    return timePerLayer * len(layers)
}

func Quantities(layers []string) (int, float64) {
    sauceLayers, noodleLayers := 0, 0
    
    for _, layer := range layers {
        if layer == "sauce" {
            sauceLayers++
        } else if layer == "noodles" {
        	noodleLayers++
        }
    }

    return 50 * noodleLayers, float64(0.2) * float64(sauceLayers)
}

func AddSecretIngredient(friendsList []string, myList []string) {
    myList[len(myList)-1] = friendsList[len(friendsList)-1]
}

func ScaleRecipe(quantities []float64, portions int) []float64 {
    scaledQuantities := make([]float64, 0, len(quantities))

    for _, q := range quantities {
        scaledQuantities = append(scaledQuantities, q * float64(portions) / float64(2))
    }

    return scaledQuantities
}
