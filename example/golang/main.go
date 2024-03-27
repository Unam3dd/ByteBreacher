package main

import (
    "fmt"
    "os"
    "strconv"
)

func sum(a int, b int) int {
    return (a + b)
}

func main() {

    a, err := strconv.Atoi(os.Args[1])
    
    if err != nil {
        fmt.Println("Error when Atoi was called !")
        return
    }

    b, err := strconv.Atoi(os.Args[2])

    if err != nil {
        fmt.Println("Error when Atoi was called !")
        return
    }

    fmt.Println("Sum is ", sum(a, b))
}
