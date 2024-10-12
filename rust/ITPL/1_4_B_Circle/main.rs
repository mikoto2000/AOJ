use std::str::FromStr;
use std::f64::consts::PI;

fn main() {

    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    line1 = line1.trim().parse::<String>().ok().unwrap();
    let line1: Vec<&str> = line1.split_whitespace().collect();
    let r: f64 = FromStr::from_str(&line1[0]).unwrap();

    println!("{} {}", r * r * PI, 2.0 * r * PI);
}
