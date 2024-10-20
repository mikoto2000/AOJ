use std::str::FromStr;

fn main() {

    loop {
        let mut line1 = String::new();
        std::io::stdin().read_line(&mut line1).ok();
        line1 = line1.trim().parse::<String>().ok().unwrap();
        let line1: Vec<&str> = line1.split_whitespace().collect();
        let n: u32 = FromStr::from_str(&line1[0]).unwrap();
        let x: u32 = FromStr::from_str(&line1[1]).unwrap();

        if n == 0 && x == 0 {
            break;
        }

        let mut count = 0;
        for k in 3..n+1 {
            for j in 2..k {
                for i in 1..j {
                    if i + j + k == x {
                        count = count + 1;
                    }
                }
            }
        }

        println!("{}", count);
    }
}
