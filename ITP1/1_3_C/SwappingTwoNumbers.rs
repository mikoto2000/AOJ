use std::str::FromStr;

fn main() {
    loop {
        let mut line1 = String::new();
        std::io::stdin().read_line(&mut line1).ok();
        line1 = line1.trim().parse::<String>().ok().unwrap();
        let line1: Vec<&str> = line1.split_whitespace().collect();
        let l: u32 = FromStr::from_str(&line1[0]).unwrap();
        let r: u32 = FromStr::from_str(&line1[1]).unwrap();

        if l == 0 && r == 0 {
            return;
        }

        if l < r {
            println!("{} {}", l, r);
        } else {
            println!("{} {}", r, l);
        }
    }
}
