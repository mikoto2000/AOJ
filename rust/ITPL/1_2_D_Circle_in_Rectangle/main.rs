fn main() {
    use std::str::FromStr;

    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    line1 = line1.trim().parse::<String>().ok().unwrap();
    let line1: Vec<&str> = line1.split_whitespace().collect();
    let width: i32 = FromStr::from_str(&line1[0]).unwrap();
    let height: i32 = FromStr::from_str(&line1[1]).unwrap();
    let x: i32 = FromStr::from_str(&line1[2]).unwrap();
    let y: i32 = FromStr::from_str(&line1[3]).unwrap();
    let r: i32 = FromStr::from_str(&line1[4]).unwrap();

    let over_left = x - r < 0;
    let over_right = x + r > width;
    let over_bottom = y - r < 0;
    let over_top = y + r > height;

    if over_left || over_right || over_bottom || over_top {
        println!("No");
    } else {
        println!("Yes");
    }
}
