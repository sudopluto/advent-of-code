use std::io::{self, BufRead};

fn main() {

    let stdin = io::stdin();

    let mut l_list: Vec<i32> = Vec::new();
    let mut r_list: Vec<i32> = Vec::new();

    for line_in in stdin.lock().lines() {

        let line_in = line_in.expect("Unable to parse line");

        if line_in.trim().is_empty() {
            continue;
        }

        let num_strs: Vec<&str> = line_in.split_whitespace().collect();

        let x: i32 = num_strs[0]
            .parse()
            .expect("Unable to parse to i32");
            
        let y: i32 = num_strs[1]
            .parse()
            .expect("Unable to parse to i32");

        l_list.push(x);
        r_list.push(y);
    }

    l_list.sort();
    r_list.sort();

    let mut res = 0;
    for i in 0..l_list.len() {
        res += (l_list[i] - r_list[i]).abs()
    }
    println!("{}", res);

}
