use std::io::{self, BufRead};
use std::collections::HashMap;

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

    let mut r_list_hist = HashMap::new();

    for x in r_list {
        match r_list_hist.get(&x) {
            Some(val) => r_list_hist.insert(x, val + 1),
            None      => r_list_hist.insert(x, 1),
        };
    }

    let mut res = 0;
    for x in l_list {
        match r_list_hist.get(&x) {
            Some(val) => res += x * val,
            None      => (),
        };
    }
    println!("{}", res);

}
