fn main() {
    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    let s = line1.trim().parse::<String>().ok().unwrap();

    let mut line2 = String::new();
    std::io::stdin().read_line(&mut line2).ok();
    let p = line2.trim().parse::<String>().ok().unwrap();

    let s_first = &s[0..p.chars().count()];

    let s = format!("{}{}", s, s_first);

    if s.contains(&p) {
        println!("Yes");
    } else {
        println!("No");
    }
}
