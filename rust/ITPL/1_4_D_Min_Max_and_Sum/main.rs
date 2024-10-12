use std::str::FromStr;

fn main() {

    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    line1 = line1.trim().parse::<String>().ok().unwrap();
    let _: Vec<&str> = line1.split_whitespace().collect();

    let mut line2 = String::new();
    std::io::stdin().read_line(&mut line2).ok();
    line2 = line2.trim().parse::<String>().ok().unwrap();
    let line2: Vec<i64> = line2
            .split_whitespace()
            .map( |e|
                FromStr::from_str(&e).unwrap()
            ).collect();

    println!("{} {} {}",
        line2.iter().min().unwrap(),
        line2.iter().max().unwrap(),
        line2.iter().sum::<i64>());
}
