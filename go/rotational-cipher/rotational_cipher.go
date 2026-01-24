package rotationalcipher

func isUpperCase(c byte) bool {
	return c >= 'A' && c <= 'Z'
}

func isLowerCase(c byte) bool {
	return c >= 'a' && c <= 'z'
}

func encodeChar(c byte, shiftKey int) byte {
	if isUpperCase(c) {
		charOrd := (c + byte(shiftKey) - byte('A')) % 26
		return byte('A') + charOrd
	} else if isLowerCase(c) {
		charOrd := (c + byte(shiftKey) - byte('a')) % 26
		return byte('a') + charOrd
	} else {
		return c
	}
}

func RotationalCipher(plain string, shiftKey int) string {
	if shiftKey < 0 || shiftKey >= 27 {
		panic("invalid key")
	}

	encoded := make([]byte, len(plain))

	for i := 0; i < len(plain); i++ {
		encoded[i] = encodeChar(plain[i], shiftKey)
	}

	return string(encoded)
}
