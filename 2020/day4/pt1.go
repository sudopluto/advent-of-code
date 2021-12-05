package main

import (
    "fmt"
    "bufio"
    "strings"
    "os"
)


func main() {
    scanner := bufio.NewScanner(os.Stdin)

    count := 0

    entries := map[string]string {
        "byr" : "",
        "iyr" : "",
        "hgt" : "",
        "hcl" : "",
        "ecl" : "",
        "pid" : "",
        "cid" : "",
    }

    for scanner.Scan() {
        line := scanner.Text()

        if len(line) > 0 {
            kvs := strings.Split(strings.ReplaceAll(line, ":", " "), " ")

            for i := 0; i < len(kvs) -1; i += 2 {
                entries[kvs[i]] = kvs[i + 1]
            }

        // parsing 
        } else {
            valid := true
            for k := range entries {
                if len(entries[k]) == 0 && k != "cid" {
                    valid = false
                }
                entries[k] = ""
            }
            if valid {
                count += 1
            }
        }
    }
    valid := true
    for k := range entries {
        if len(entries[k]) == 0 && k != "cid" {
            valid = false
        }
        entries[k] = ""
    }
    if valid {
        count += 1
    }

    fmt.Println(count)
}
