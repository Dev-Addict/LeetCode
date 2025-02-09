package main

import "C"
import "sort"

type NumberContainers struct {
	record map[int]int
	group  map[int][]int
}

func Constructor() NumberContainers {
	return NumberContainers{
		record: make(map[int]int),
		group:  make(map[int][]int),
	}
}

func (nc *NumberContainers) Change(index int, number int) {
	nc.record[index] = number

	if _, ok := nc.group[number]; !ok {
		nc.group[number] = []int{index}
	} else {
		nc.group[number] = append(nc.group[number], index)
	}
}

func (nc *NumberContainers) Find(number int) int {
	sort.Ints(nc.group[number])

	for _, v := range nc.group[number] {
		if nc.record[v] == number {
			return v
		}
	}

	return -1
}
