package main

import "fmt"

func InsertionSort(array []int) []int {
	for i := 0; i <= len(array); i++ {
		j := i - 1
		for j > 0 && array[j] < array[j-1] {
			array[j], array[j-1] = array[j-1], array[j]
			j--
		}
	}
	return array
}

func main() {
	fmt.Println(InsertionSort([]int{4, 5, 3, 2, 5, 9, 87, 22, 1}))
}
