fn main() {
    use std::str::FromStr;

    loop {
        let mut line1 = String::new();
        std::io::stdin().read_line(&mut line1).ok();
        line1 = line1.trim().parse::<String>().ok().unwrap();
        let line1: Vec<&str> = line1.split_whitespace().collect();
        let a: i32 = FromStr::from_str(&line1[0]).unwrap();
        let op: &str = &line1[1];
        let b: i32 = FromStr::from_str(&line1[2]).unwrap();

        if op == "?" {
            break;
        }

        let answer = match op {
            "+" => a + b,
            "-" => a - b,
            "*" => a * b,
            "/" => a / b,
            _ => panic!(),
        };

        println!("{}", answer);
    }
}
