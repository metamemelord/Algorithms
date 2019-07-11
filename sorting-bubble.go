package main

import "fmt"

func BubbleSort(array []int) []int {
	for idx, _ := range array {
		for j:=idx+1; j < len(array);j++ {
			if(array[idx] > array[j]) {
				array[idx], array[j] = array[j], array[idx]
			}
		}
	}
	return array
}

func main() {
	fmt.Println(BubbleSort([]int{4, 5, 3, 2, 5, 9,87,22}))
}