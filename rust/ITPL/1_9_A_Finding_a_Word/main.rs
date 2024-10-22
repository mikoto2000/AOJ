fn main() {
    let mut line1 = String::new();
    std::io::stdin().read_line(&mut line1).ok();
    line1 = line1.trim().parse::<String>().ok().unwrap();
    let line1 = line1.to_lowercase();

    let mut count = 0;

    loop {
        let mut line2 = String::new();
        std::io::stdin().read_line(&mut line2).ok();
        line2 = line2.trim().parse::<String>().ok().unwrap();

        if line2 == "END_OF_TEXT" {
            break;
        }

        let line2 = line2.to_lowercase();
        let line2: Vec<&str> = line2.split_whitespace().collect();

        for v in &line2 {
            if *v == line1 {
                count += 1;
            }
        }
    }

    println!("{}", count);
}
