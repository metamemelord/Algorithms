package main

import "fmt"

func InsertionSort(array []int) []int {
	for i := 0; i < len(array)-1; i++ {
		mnIdx := i
		for j := i + 1; j < len(array); j++ {
			if array[mnIdx] > array[j] {
				mnIdx = j
			}
		}
		if mnIdx != i {
			array[mnIdx], array[i] = array[i], array[mnIdx]
		}
	}
	return array
}

func main() {
	fmt.Println(InsertionSort([]int{4, 5, 3, 2, 5, 9, 87, 22}))
}
