fn main() {
    use std::str::FromStr;

    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    line1 = line1.trim().parse::<String>().ok().unwrap();
    let line1: Vec<&str> = line1.split_whitespace().collect();
    let in_seconds: u32 = FromStr::from_str(&line1[0]).unwrap();

    let seconds = in_seconds % 60;
    let in_min = in_seconds / 60;
    let min = in_min % 60;
    let in_hour = in_min / 60;
    let hour = in_hour;

    println!("{}:{}:{}", hour, min, seconds);
}
