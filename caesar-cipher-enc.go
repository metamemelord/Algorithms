package main

import "fmt"

func CaesarCipherEncryptor(str string, key int) string {
	var ans []byte
	key = key % 26
	for _, i := range []byte(str) {
		ans = append(ans, (i-97+byte(key))%26+97)
	}
	return string(ans)
}

func main() {
	fmt.Print(CaesarCipherEncryptor("asbz", 2))
}
