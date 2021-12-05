package main

import (
    "fmt"
)

// func that takes list of bin numbers, and return the most common bit in that post
func most_common_bit(bin_nums *[]string, idx int) byte {

    cnt := 0
    for i, _ := range *bin_nums {
        if (*bin_nums)[i][idx] == '1' {
            cnt += 1
        }
    }

    choose_one := false
    if cnt >= (len(*bin_nums) - cnt) {
        choose_one = true
    }

    fmt.Println("idx, and most common dig", idx, cnt, choose_one)
    if choose_one {
        return '1'
    } else {
        return '0'
    }
}

// filters given bin_num list by if byte at index matches given byte
func filter(bin_nums *[]string, idx int, ch byte) {
    fmt.Println("\n heres contents of list, and idx and byte", idx, ch)
    for _, num := range *bin_nums {
        fmt.Println(num)
    }
    fmt.Println("\n")

    ret := []string{}
    for _, num := range *bin_nums {
        if num[idx] == ch {
            ret = append(ret, num)
        }
    }
    *bin_nums = ret
}

// type is either oxy or cotwo
func drive(bin_nums *[]string, t string) int {
    idx := 0
    for len(*bin_nums) != 1 {
        common_bit := most_common_bit(bin_nums, idx)
        if t == "cotwo" {
            if common_bit == '1' {
                common_bit = '0'
            } else {
                common_bit = '1'
            }
        }

        filter(bin_nums, idx, common_bit)
        idx += 1
    }

    val := 0
    fmt.Println("heres our valid num: ", (*bin_nums)[0])
    for i, _ := range (*bin_nums)[0] {
        val <<= 1

        bool_set := 0
        if (*bin_nums)[0][i] == '1' {
            bool_set = 1
        }

        val |= bool_set
    }
    fmt.Printf("%#b\n", val)
    return val
}

func main() {

    bin_nums_oxy := []string{}
    bin_nums_cotwo := []string{}
    var bin string

    // each bin number
    for ;; {
        n, err := fmt.Scanf("%s", &bin)

        // insert into oxy and into co2

        if n != 1 {
            break
        } else if err != nil {
            panic(err)
        } else {
            bin_nums_oxy = append(bin_nums_oxy, bin)
            bin_nums_cotwo = append(bin_nums_cotwo, bin)
        }
    }

    oxy := drive(&bin_nums_oxy, "oxy")
    cotwo := drive(&bin_nums_cotwo, "cotwo")

    fmt.Println(oxy)
    fmt.Println(cotwo)

    fmt.Println(oxy * cotwo)
}
