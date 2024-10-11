fn main() {
    use std::str::FromStr;

    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    line1 = line1.trim().parse::<String>().ok().unwrap();
    let line1: Vec<&str> = line1.split_whitespace().collect();
    let height: u32 = FromStr::from_str(&line1[0]).unwrap();
    let width: u32 = FromStr::from_str(&line1[1]).unwrap();

    let area = height * width;
    let circumference = (height * 2) + (width * 2);

    println!("{} {}", area, circumference);
}
