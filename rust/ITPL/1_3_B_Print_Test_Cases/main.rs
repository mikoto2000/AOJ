fn main() {
    let mut count = 0;

    loop {
        use std::str::FromStr;

        let mut line1 = String::new();
        std::io::stdin().read_line(&mut line1).ok();
        line1 = line1.trim().parse::<String>().ok().unwrap();
        let line1: Vec<&str> = line1.split_whitespace().collect();
        let v: u32 = FromStr::from_str(&line1[0]).unwrap();

        if v == 0 {
            break;
        }

        count = count + 1;

        println!("Case {}: {}", count, v);
    }
}
