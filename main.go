package main

import (
	"fmt"
	"io/ioutil"
)

func main() {
	b, err := ioutil.ReadFile("prince-ascii.txt")
	if err != nil {
		fmt.Println(err)
	}

	str := string(b)

	fmt.Println(str)
}
