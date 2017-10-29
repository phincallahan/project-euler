package main

import (
	"fmt"
	"io/ioutil"
	"strings"
	"strconv"
	"sort"
	"github.com/spakin/disjoint"
)

type Edge struct { w, i, j int }
type ByWeight []Edge

func (e ByWeight) Len() int { return len(e) }
func (e ByWeight) Less(i, j int) bool { return e[i].w < e[j].w }
func (e ByWeight) Swap(i, j int) {  
	e[i], e[j] = e[j], e[i]
}

const path = "p107_network.txt"

func main() {
	const N int = 40 
	comps, min, total := N, 0, 0

	edges := readEdges(path, N)
	sort.Sort(ByWeight(edges))

	var nodes [40]*disjoint.Element
	for i := 0; i < 40; i++ {
		nodes[i] = disjoint.NewElement()
	}

	for _, e := range(edges) {
		if nodes[e.i].Find() != nodes[e.j].Find() {
			disjoint.Union(nodes[e.i], nodes[e.j])
			min += e.w
			comps--
		}

		if e.i >= e.j { total += e.w }
	}

	fmt.Println("Savings: ", total - min)
}


func readEdges(path string, N int) []Edge {
	edges := make([]Edge, 0)

	if dat, err := ioutil.ReadFile(path); err != nil {
		panic(err)
	} else {
		wl := getWeightList(dat)
		for i, ws := range(wl) {
			if w, err := strconv.ParseInt(ws, 10, 0); err == nil {
				newEdge := Edge{ int(w), i / N, i % N }
				edges = append(edges, newEdge)
			}
		}
	}

	return edges 
}

func getWeightList(dat []byte) []string {
	weightString := strings.Replace(string(dat), "\n", ",", -1)
	return strings.Split(weightString, ",")
}