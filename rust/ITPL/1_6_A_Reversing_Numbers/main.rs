fn main() {
    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();

    let mut line2 = String::new();
    std::io::stdin().read_line(&mut line2).ok();
    line2 = line2.trim().parse::<String>().ok().unwrap();
    let mut line2: Vec<&str> = line2.split_whitespace().collect();
    line2.reverse();
    println!("{}", line2.join(" "));


}
