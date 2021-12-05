package main

import (
    "fmt"
)

func main() {

    // parse lines where
    // cmnd <intval>

    var cmd string
    var val int

    x := 0
    depth := 0
    aim := 0

    for ;; {
        n, err := fmt.Scanf("%s %d", &cmd, &val)

        if n != 2 {
            break
        } else if err != nil {
            panic(err)
        } else {
            fmt.Printf("%s %d\n", cmd, val)
            switch cmd {
            case "forward":
                x += val
                depth += (aim * val)
            case "down":
                aim += val
            case "up":
                aim -= val
            default:
                fmt.Println("nani", cmd)
            }
        }
    }

    fmt.Println(x * depth)
}
