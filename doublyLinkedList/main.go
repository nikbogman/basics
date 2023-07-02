package main

import "fmt"

type Data interface{}

type Node struct {
	data Data
	next *Node
	prev *Node
}

type LinkedList struct {
	head *Node
}

func (list *LinkedList) push(data Data) {
	newNode := &Node{data: data, next: nil, prev: nil}

	if list.head == nil {
		list.head = newNode
		return
	}

	last := list.head
	for last.next != nil {
		last = last.next
	}
	last.next = newNode
	newNode.prev = last
}

func (list *LinkedList) preappend(data Data) {
	newNode := &Node{data: data, next: list.head, prev: nil}
	if list.head != nil {
		list.head.prev = newNode
	}
	list.head = newNode
}

func (list *LinkedList) pop() Data {
	if list.head == nil {
		return nil
	}
	if list.head.next == nil && list.head.prev == nil {
		removed := list.head.data
		list.head = nil
		return removed
	}

	last := list.head
	for last.next.next != nil {
		last = last.next
	}
	removed := last.next.data
	last.next = nil
	return removed
}

func (list *LinkedList) shift() Data {
	if list.head == nil {
		return nil
	}
	if list.head.next == nil && list.head.prev == nil {
		removed := list.head.data
		list.head = nil
		return removed
	}
	removed := list.head.data
	newHead := list.head.next
	newHead.prev = nil
	list.head = newHead
	return removed
}

func (list *LinkedList) print() {
	if list.head == nil {
		fmt.Println("EMPTY")
		return
	}

	current := list.head
	for current != nil {
		fmt.Print(current.data)
		if current.next != nil {
			fmt.Print(" <-> ")
		}
		current = current.next
	}
	fmt.Println()
}

func (list *LinkedList) at(idx int) Data {
	current := list.head
	i := 0
	for i < idx {
		current = current.next
		if current == nil {
			return nil
		}
		i++
	}
	return current.data
}

func (list *LinkedList) first() Data {
	if list.head == nil {
		return nil
	}
	return list.head.data
}

func (list *LinkedList) last() Data {
	if list.head == nil {
		return nil
	}
	last := list.head
	for last.next != nil {
		last = last.next
	}
	return last.data
}

func main() {
	list := LinkedList{}
	list.push(1)
	list.push(2)
	list.preappend(3)
	list.print()
}
